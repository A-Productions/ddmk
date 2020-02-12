#include "HUD.h"

bool System_HUD_updateStyleIcon = false;

System_HUD_UpdateStyleIcon_t System_HUD_UpdateStyleIcon = 0;

void System_HUD_Update()
{
	auto & update = System_HUD_updateStyleIcon;
	if (!update)
	{
		return;
	}
	if (!HUD_IsVisible())
	{
		return;
	}
	update = false;
	System_HUD_UpdateStyleIcon();
}

void System_HUD_Init()
{
	LogFunction();
	{
		byte8 sect1[] =
		{
			0x4C, 0x8B, 0x25, 0x00, 0x00, 0x00, 0x00,       //mov r12,[dmc3.exe+CF2680]
			0x49, 0x8D, 0x8C, 0x24, 0x80, 0x3B, 0x00, 0x00, //lea rcx,[r12+00003B80]
			0xE8, 0x00, 0x00, 0x00, 0x00,                   //call dmc3.exe+897B0


			0x49, 0x8D, 0x8C, 0x24, 0x80, 0x3B, 0x00, 0x00, //lea rcx,[r12+00003B80]
			0xE8, 0x00, 0x00, 0x00, 0x00,                   //call dmc3.exe+89450




			0x48, 0x31, 0xC0,                               //xor rax,rax
			0xB9, 0x80, 0x07, 0x00, 0x00,                   //mov ecx,00000780
			0x49, 0x8D, 0xBC, 0x24, 0x80, 0x3B, 0x00, 0x00, //lea rdi,[r12+00003B80]
			0xF3, 0xAA,                                     //repe stosb



			0x49, 0x8D, 0x8C, 0x24, 0x80, 0x3B, 0x00, 0x00, //lea rcx,[r12+00003B80]
			0xE8, 0x00, 0x00, 0x00, 0x00,                   //call dmc3.exe+89270



			0x48, 0x8B, 0x05, 0x00, 0x00, 0x00, 0x00,       //mov rax,[dmc3.exe+C90E28]
			0x48, 0x8B, 0x40, 0x18,                         //mov rax,[rax+18]
			0x8B, 0x80, 0x38, 0x63, 0x00, 0x00,             //mov eax,[rax+00006338]
			0x48, 0x8D, 0x0D, 0x00, 0x00, 0x00, 0x00,       //lea rcx,[dmc3.exe+4E9070]
			0x0F, 0xB6, 0x04, 0x08,                         //movzx eax,byte ptr [rax+rcx]
			0x41, 0x88, 0x84, 0x24, 0x0E, 0x69, 0x00, 0x00, //mov [r12+0000690E],al
			0x00, 0xC0,                                     //add al,al

			0x49, 0x8B, 0x4C, 0x24, 0x60,                   //mov rcx,[r12+60]
			0x8D, 0x50, 0x12,                               //lea edx,[rax+12]
			0x48, 0x8B, 0xD8,                               //mov rbx,rax
			0xE8, 0x00, 0x00, 0x00, 0x00,                   //call dmc3.exe+16FBF0

			0x49, 0x8B, 0x4C, 0x24, 0x60,                   //mov rcx,[r12+60]
			0x8D, 0x53, 0x13,                               //lea edx,[rbx+13]
			0x48, 0x8B, 0xD8,                               //mov rbx,rax
			0xE8, 0x00, 0x00, 0x00, 0x00,                   //call dmc3.exe+16FBF0

			0x49, 0x8D, 0x8C, 0x24, 0x80, 0x3B, 0x00, 0x00, //lea rcx,[r12+00003B80]
			0x48, 0x8B, 0xD0,                               //mov rdx,rax
			0x4C, 0x8B, 0xC3,                               //mov r8,rbx
			0xE8, 0x00, 0x00, 0x00, 0x00,                   //call dmc3.exe+89960

			0x49, 0x8D, 0x8C, 0x24, 0x80, 0x3B, 0x00, 0x00, //lea rcx,[r12+00003B80]
			0xBA, 0x01, 0x00, 0x00, 0x00,                   //mov edx,00000001
			0xE8, 0x00, 0x00, 0x00, 0x00,                   //call dmc3.exe+89E30
		};
		FUNC func = CreateFunction(0, 0, true, true, 0, sizeof(sect1));
		memcpy(func.sect1, sect1, sizeof(sect1));
		WriteAddress ( func.sect1        , (appBaseAddr + 0xCF2680), 7);
		WriteCall    ((func.sect1 + 0xF ), (appBaseAddr + 0x897B0 )   );
		WriteCall    ((func.sect1 + 0x1C), (appBaseAddr + 0x89450 )   );
		WriteCall    ((func.sect1 + 0x3B), (appBaseAddr + 0x89270 )   );
		WriteAddress ((func.sect1 + 0x40), (appBaseAddr + 0xC90E28), 7);
		WriteAddress ((func.sect1 + 0x51), (appBaseAddr + 0x4E9070), 7);
		WriteCall    ((func.sect1 + 0x71), (appBaseAddr + 0x16FBF0)   );
		WriteCall    ((func.sect1 + 0x81), (appBaseAddr + 0x16FBF0)   );
		WriteCall    ((func.sect1 + 0x94), (appBaseAddr + 0x89960 )   );
		WriteCall    ((func.sect1 + 0xA6), (appBaseAddr + 0x89E30 )   );
		System_HUD_UpdateStyleIcon = (System_HUD_UpdateStyleIcon_t)func.addr;
	}
}
