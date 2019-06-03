#include "Input.h"

bool System_Input_extend = false;
WORD buttonMask[17] =
{
	GAMEPAD_VOID,
	GAMEPAD_LEFT_TRIGGER,
	GAMEPAD_RIGHT_TRIGGER,
	GAMEPAD_LEFT_SHOULDER,
	GAMEPAD_RIGHT_SHOULDER,
	GAMEPAD_Y,
	GAMEPAD_B,
	GAMEPAD_A,
	GAMEPAD_X,
	GAMEPAD_BACK,
	GAMEPAD_LEFT_THUMB,
	GAMEPAD_RIGHT_THUMB,
	GAMEPAD_START,
	GAMEPAD_DPAD_UP,
	GAMEPAD_DPAD_RIGHT,
	GAMEPAD_DPAD_DOWN,
	GAMEPAD_DPAD_LEFT,
};

WORD GetButtonState(uint8 actorId)
{
	return ((CAPCOM_GAMEPAD *)(appBaseAddr + 0xD54A10 + 0x550))[actorId].buttons[0];
}

WORD GetBinding(uint8 commandId)
{
	return *(WORD *)(appBaseAddr + 0xD6CE88 + (commandId * 2));
}

void System_Input_Init()
{
	LogFunction();
	


	if (!System_Input_extend)
	{
		return;
	}
	// Extend Gamepad Range
	WriteAddress((appBaseAddr + 0x32D0AA), (appBaseAddr + 0x32D0B0), 6);
	Write<uint8>((appBaseAddr + 0x2AF91), 3);
	{
		vp_memset((appBaseAddr + 0x2AFAA), 0x90, 28);
		BYTE buffer[] =
		{
			0x44, 0x8B, 0xC7, //mov r8d,edi
		};
		vp_memcpy((appBaseAddr + 0x2AFAA), buffer, sizeof(buffer));
	}
	Write<DWORD>((appBaseAddr + 0x32CFB9), 0x63C);
	WriteAddress((appBaseAddr + 0x1EBD1E), (appBaseAddr + 0x1EBD24), 6);
	// Redirect Input
	{
		BYTE sect0[] =
		{
			0x0F, 0xB6, 0x93, 0x18, 0x01, 0x00, 0x00, //movzx edx,byte ptr [rbx+00000118]
		};
		BYTE * jumpAddr[] =
		{
			(appBaseAddr + 0x32CC70),
			(appBaseAddr + 0x32CC80),
			(appBaseAddr + 0x32CC10),
			(appBaseAddr + 0x32CC10),
			(appBaseAddr + 0x32CC50),
			(appBaseAddr + 0x32CC50),
		};
		BYTE * writeAddr[] =
		{
			(appBaseAddr + 0x1EBD2D),
			(appBaseAddr + 0x1EBD42),
			(appBaseAddr + 0x1EBD7E),
			(appBaseAddr + 0x1EBD97),
			(appBaseAddr + 0x1EBDAF),
			(appBaseAddr + 0x1EBE98),
		};
		for (uint8 i = 0; i < countof(writeAddr); i++)
		{
			FUNC func = CreateFunction(0, jumpAddr[i], false, true, sizeof(sect0));
			memcpy(func.sect0, sect0, sizeof(sect0));
			WriteCall(writeAddr[i], func.addr);
		}
	}
}
