#pragma once
#include "../../Core/Core.h"

#include "../Config.h"
#include "../Vars.h"

typedef BYTE *(* LoadFile_t)(BYTE *, const char *, uint32);

extern LoadFile_t LoadFile;

void System_File_Init();
void System_File_Toggle(bool enable);
