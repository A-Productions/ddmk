
// @Todo: Better names.
// For example: TargetAlloc or RangeAlloc.

#include "Memory.h"

constexpr bool debug = true;

byte8 * appBaseAddr = 0;
HWND mainWindow = 0;

SYSTEM_INFO si = {};
uint32 appSize = 0;

byte8 * mainChunk = 0;
extern uint32 mainChunkSize;
uint32 mainChunkPos = 0;

byte8 * Alloc
(
	uint32 size,
	uint64 pos,
	uint64 end
)
{
	if constexpr (debug)
	{
		LogFunction();
		Log("size %X", size);
		Log("pos  %llX", pos);
		Log("end  %llX", end);
	}

	MEMORY_BASIC_INFORMATION mbi;
	bool match = false;

	do
	{
		VirtualQuery((void *)pos, &mbi, sizeof(mbi));
		if ((mbi.RegionSize >= size) && (mbi.State == MEM_FREE))
		{
			if constexpr (debug)
			{
				Log("pos        %llX", pos);
				Log("regionSize %llX", mbi.RegionSize);
				Log("state      %X", mbi.State);
			}
			auto result = Align<uint64>(pos, si.dwAllocationGranularity);
			if (!result)
			{
				match = true;
				break;
			}
			continue;
		}
		pos += mbi.RegionSize;
	}
	while (pos < end);

	if (!match)
	{
		return 0;
	}

	byte8 * addr = (byte8 *)mbi.BaseAddress;
	byte32 error = 0;

	SetLastError(0);
	addr = (byte8 *)VirtualAlloc(addr, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	error = GetLastError();
	if (!addr)
	{
		Log("VirtualAlloc failed. %X", error);
		return 0;
	}

	VirtualQuery(addr, &mbi, sizeof(mbi));
	Log("addr  %llX", addr);
	Log("state %X", mbi.State);

	return addr;
}

byte8 * HighAlloc(uint32 size)
{
	LogFunction();
	auto pos = (uint64)(appBaseAddr + appSize);
	auto end = (uint64)(appBaseAddr + 0x7FFFFFFF);
	return Alloc(size, pos, end);
}

void WriteAddress
(
	byte8  * addr,
	byte8  * dest,
	uint32   size,
	byte8    header,
	uint32   padSize,
	byte8    padValue
)
{
	byte32 protection = 0;
	VirtualProtect(addr, (size + padSize), PAGE_EXECUTE_READWRITE, &protection);
	{
		if (header)
		{
			addr[0] = header;
		}
		if (size == 2)
		{
			*(int8 *)(addr + (size - 1)) = (int8)(dest - addr - size);
		}
		else
		{
			*(int32 *)(addr + (size - 4)) = (int32)(dest - addr - size);
		}
		if (padSize)
		{
			memset((addr + size), padValue, padSize);
		}
	}
	VirtualProtect(addr, (size + padSize), protection, &protection);
}

void vp_memset
(
	void   * addr,
	byte8    value,
	uint32   size
)
{
	byte32 protection = 0;
	VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &protection);
	{
		memset(addr, value, size);
	}
	VirtualProtect(addr, size, protection, &protection);
}

void vp_memcpy
(
	void   * dest,
	void   * addr,
	uint32   size
)
{
	byte32 protection = 0;
	VirtualProtect(dest, size, PAGE_EXECUTE_READWRITE, &protection);
	{
		memcpy(dest, addr, size);
	}
	VirtualProtect(dest, size, protection, &protection);
}















// @Todo: Add lambda.

#define Feed()                                   \
memcpy((payload + pos), buffer, sizeof(buffer)); \
pos += sizeof(buffer);

FUNC CreateFunction
(
	void   * funcAddr,
	byte8  * jumpAddr,
	bool     saveRegisters,
	bool     noResult,
	uint32   size0,
	uint32   size1,
	uint32   size2,
	uint32   cacheSize
)
{
	byte8 payload[2048];
	uint32 pos = 0;

	uint32 off0;
	uint32 off1;
	uint32 off2;
	uint32 offJump;

	off0 = pos;
	pos += size0;

	if (saveRegisters)
	{
		if (noResult)
		{
			byte8 buffer[] =
			{
				0x50, //push rax
			};
			Feed();
		}
		byte8 buffer[] =
		{
			0x51,                   //push rcx
			0x52,                   //push rdx
			0x53,                   //push rbx
			0x54,                   //push rsp
			0x55,                   //push rbp
			0x56,                   //push rsi
			0x57,                   //push rdi
			0x41, 0x50,             //push r8
			0x41, 0x51,             //push r9
			0x41, 0x52,             //push r10
			0x41, 0x53,             //push r11
			0x41, 0x54,             //push r12
			0x41, 0x55,             //push r13
			0x41, 0x56,             //push r14
			0x41, 0x57,             //push r15
			0x9C,                   //pushfq
			0x48, 0x8B, 0xEC,       //mov rbp,rsp
			0x40, 0x80, 0xE4, 0xF0, //and spl,F0
			0x48, 0x83, 0xEC, 0x20, //sub rsp,20
		};
		Feed();
	}

	off1 = pos;
	pos += size1;

	if (funcAddr)
	{
		byte8 buffer[] =
		{
			0x48, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //mov rax,funcAddr
			0xFF, 0xD0,                                                 //call rax
		};
		*(void **)(buffer + 2) = funcAddr;
		Feed();
	}
	if (saveRegisters)
	{
		byte8 buffer[] =
		{
			0x48, 0x8B, 0xE5, //mov rsp,rbp
			0x9D,             //popfq
			0x41, 0x5F,       //pop r15
			0x41, 0x5E,       //pop r14
			0x41, 0x5D,       //pop r13
			0x41, 0x5C,       //pop r12
			0x41, 0x5B,       //pop r11
			0x41, 0x5A,       //pop r10
			0x41, 0x59,       //pop r9
			0x41, 0x58,       //pop r8
			0x5F,             //pop rdi
			0x5E,             //pop rsi
			0x5D,             //pop rbp
			0x5C,             //pop rsp
			0x5B,             //pop rbx
			0x5A,             //pop rdx
			0x59,             //pop rcx
		};
		Feed();
		if (noResult)
		{
			byte8 buffer[] =
			{
				0x58, //pop rax
			};
			Feed();
		}
	}

	off2 = pos;
	pos += size2;

	offJump = pos;
	if (jumpAddr)
	{
		byte8 buffer[] =
		{
			0xE9, 0x00, 0x00, 0x00, 0x00, //jmp
		};
		Feed();
	}
	else
	{
		byte8 buffer[] =
		{
			0xC3, //ret
		};
		Feed();
	}

	FUNC func = {};

	// @Todo: Align.

	//if (mainChunkPos % 0x10)
	//{
	//	mainChunkPos += (0x10 - (mainChunkPos % 0x10));
	//}

	Align<uint32>(mainChunkPos, 0x10);






	func.addr = (mainChunk + mainChunkPos);
	memcpy(func.addr, payload, pos);
	mainChunkPos += pos;

	if (jumpAddr)
	{
		//WriteJump((func.addr + offJump), (byte *)jumpAddr);
		WriteJump((func.addr + offJump), jumpAddr);
	}

	func.sect0 = (func.addr + off0);
	func.sect1 = (func.addr + off1);
	func.sect2 = (func.addr + off2);

	if (cacheSize)
	{
		//if (mainChunkPos % 0x10)
		//{
		//	mainChunkPos += (0x10 - (mainChunkPos % 0x10));
		//}

		Align<uint32>(mainChunkPos, 0x10);

		func.cache = (byte8 **)(mainChunk + mainChunkPos);
		mainChunkPos += cacheSize;
	}

	return func;
}

#undef Feed

bool Memory_Init()
{
	LogFunction();

	MODULEENTRY32 me = {};
	me.dwSize = sizeof(MODULEENTRY32);
	auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, 0);
	Module32First(snapshot, &me);
	appBaseAddr = me.modBaseAddr;
	appSize = me.modBaseSize;

	Log("%u %s", me.th32ProcessID, me.szModule);
	Log("%llX %llX", appBaseAddr, (appBaseAddr + appSize));








	if (!mainChunkSize)
	{
		Log("No chunk desired.");
		return true;
	}



	GetSystemInfo(&si);




	mainChunk = HighAlloc(mainChunkSize);


	if (!mainChunk)
	{
		Log("HighAlloc failed.");
		return false;
	}







	memset(mainChunk, 0xCC, mainChunkSize);
	return true;
}
