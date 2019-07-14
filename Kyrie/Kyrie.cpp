#include "../Core/Core.h"

#include "Hooks.h"

#include "System/Actor.h"
#include "System/File.h"
#include "System/Media.h"
#include "System/Memory.h"
#include "System/Path.h"
#include "System/Window.h"

const char * Log_directory = "logs";
const char * Log_file      = "Kyrie.txt";

uint32 mainChunkSize = (64 * 1024 * 1024);

DWORD DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		Log_Init();
		Log("Session started.");
		if (!Memory_Init())
		{
			return 0;
		}
		Config_Init();
		LoadConfig();
		Hooks_Init();

		System_Actor_Init();
		System_Actor_Toggle(true);

		System_File_Init();
		System_File_Toggle(true);






		System_Media_Init();
		System_Media_ToggleSkipIntro(Config.System.Media.skipIntro);

		System_Memory_Init();
		System_Memory_Toggle(true);






		System_Path_Init();
		System_Window_Init();

		Write<BYTE>((appBaseAddr + 0xB569  ), 0xEB); // Intro Button Infinite Timer
		//Write<BYTE>((appBaseAddr + 0xF362  ), 0xEB); // Skip Dialog
		Write<BYTE>((appBaseAddr + 0x1540E1), 0xEB); // Disable Timer
	}
	return 1;
}
