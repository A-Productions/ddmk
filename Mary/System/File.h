#pragma once
#include "../../Core/Core.h"

#define ZIP_STATIC
#include "../../Zip/zip.h"

#include "../Config.h"
#include "../Vars.h"

#include "Memory.h"

extern byte8 * System_File_cacheFile[MAX_CACHE_FILE];
extern byte8 * demo_pl000_00_3;

bool System_File_ExtractFile(const char * filename);
byte8 * System_File_LoadFile
(
	const char * filename,
	uint32     * size        = 0,
	byte8      * dest        = 0,
	bool         skipArchive = false
);
void System_File_AdjustPointers(byte8 * archive);
byte8 * System_File_PushFile(const char * filename);
__declspec(noinline) byte8 * System_File_GetFile
(
	byte8  * archive,
	uint32   fileIndex
);
void System_File_UpdateFileItems(ACTOR_DATA * actorData);
void System_File_UpdateMotion(ACTOR_DATA * actorData);
void System_File_Init();
