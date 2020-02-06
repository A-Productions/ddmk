

// @Todo: Create Archive module.
// @Todo: Create Edit and Restore functions.
// @Todo: Merge with Weapon module.
// @Todo: Create session data struct.
// @Todo: 
// @Todo: 
// @Todo: 



// @Todo: Auto vars.

#include "Actor.h"

bool System_Actor_enableArrayExtension    = false;
bool System_Actor_enableCreateActor       = false;
bool System_Actor_enableUpdateActor       = false;
bool System_Actor_enableDoppelgangerFixes = false;
bool System_Actor_enableModelFixes        = false;

byte8 * System_Actor_actorBaseAddr[MAX_ACTOR] = {};

System_Actor_UpdateDevilForm_t     System_Actor_UpdateDevilForm     = 0;
System_Actor_UpdateFlux_t          System_Actor_UpdateFlux          = 0;
System_Actor_Relax_t               System_Actor_Relax               = 0;

byte8 * OnUpdate[2] = {};

byte8 * CreateActorOneProxy = 0;
byte8 * UpdateActorProxy    = 0;
















PrivateStart;





typedef byte8 *(* InternalCreateActor_t)(uint8 character, uint8 actor, bool isDoppelganger);

InternalCreateActor_t InternalCreateActor = 0;




// FILE_ITEM


// UpdateFileItem(FILE_ITEM ** fileItem, STRING_ITEM ** stringItem


//
//
//struct FileItemHelper
//{
//	uint16 fileItemId;
//	uint16 stringItemId;
//	uint16 cacheFileId;
//	void Update()
//	{
//		FILE_ITEM   * fileItemAddr   = (FILE_ITEM   *)(appBaseAddr + 0xC99D30); // dmc3.exe+1DF64B - 48 8D 0D DEA6AB00 - lea rcx,[dmc3.exe+C99D30]
//		STRING_ITEM * stringItemAddr = (STRING_ITEM *)(appBaseAddr + 0x5B08C0); // dmc3.exe+1B8F9A - 48 8D 05 CF793F00 - lea rax,[dmc3.exe+5B0970]
//
//		FILE_ITEM   & fileItem   = fileItemAddr[fileItemId];
//		STRING_ITEM & stringItem = stringItemAddr[stringItemId];
//
//		memset(&fileItem, 0, sizeof(FILE_ITEM));
//
//		fileItem.status     = FILE_ITEM_READY;
//		fileItem.stringItem = &stringItem;
//		fileItem.file       = System_Cache_file[cacheFileId];
//	};
//};



// Merge all of them.

// OHHHHHH

// just put it before create main actor

// put that shit in event


//
//
//struct CostumeHelper
//{
//	uint16 stringItemId;
//	uint16 cacheFileId;
//};
//
//CostumeHelper costumeHelperDante[] =
//{
//	{ 0, pl000 },
//	{ 1, pl011 },
//	{ 2, pl013 },
//	{ 3, pl015 },
//	{ 4, pl016 },
//	{ 5, pl018 },
//	{ 2, pl013 },
//	{ 5, pl018 },
//};
//
//CostumeHelper costumeHelperBob[] =
//{
//	{ 6, pl001 },
//};
//
//CostumeHelper costumeHelperLady[] =
//{
//	{ 7, pl002 },
//};
//
//CostumeHelper costumeHelperVergil[] =
//{
//	{ 8 , pl021 },
//	{ 9 , pl023 },
//	{ 8 , pl021 },
//	{ 10, pl026 },
//	{ 10, pl026 },
//};
//
//CostumeHelper * costumeHelper[] =
//{
//	costumeHelperDante,
//	costumeHelperBob,
//	costumeHelperLady,
//	costumeHelperVergil,
//};
//
//uint8 costumeHelperCount[] =
//{
//	countof(costumeHelperDante),
//	countof(costumeHelperBob),
//	countof(costumeHelperLady),
//	countof(costumeHelperVergil),
//};




struct MotionHelper
{
	uint8 motionId;
	uint16 cacheFileId;
};

MotionHelper motionHelperDante[] =
{
	{ MOT_DANTE_BASE                  , pl000_00_0  },
	{ MOT_DANTE_DAMAGE                , pl000_00_1  },
	{ MOT_DANTE_TAUNTS                , pl000_00_2  },
	{ MOT_DANTE_REBELLION             , pl000_00_3  },
	{ MOT_DANTE_CERBERUS              , pl000_00_4  },
	{ MOT_DANTE_AGNI_RUDRA            , pl000_00_5  },
	{ MOT_DANTE_NEVAN                 , pl000_00_6  },
	{ MOT_DANTE_BEOWULF               , pl000_00_7  },
	{ MOT_DANTE_EBONY_IVORY           , pl000_00_8  },
	{ MOT_DANTE_SHOTGUN               , pl000_00_9  },
	{ MOT_DANTE_ARTEMIS               , pl000_00_10 },
	{ MOT_DANTE_SPIRAL                , pl000_00_11 },
	{ MOT_DANTE_KALINA_ANN            , pl000_00_12 },
	{ MOT_DANTE_SWORDMASTER_REBELLION , pl000_00_13 },
	{ MOT_DANTE_SWORDMASTER_CERBERUS  , pl000_00_14 },
	{ MOT_DANTE_SWORDMASTER_AGNI_RUDRA, pl000_00_15 },
	{ MOT_DANTE_SWORDMASTER_NEVAN     , pl000_00_16 },
	{ MOT_DANTE_SWORDMASTER_BEOWULF   , pl000_00_17 },
	{ MOT_DANTE_GUNSLINGER_EBONY_IVORY, pl000_00_18 },
	{ MOT_DANTE_GUNSLINGER_SHOTGUN    , pl000_00_19 },
	{ MOT_DANTE_GUNSLINGER_ARTEMIS    , pl000_00_20 },
	{ MOT_DANTE_GUNSLINGER_SPIRAL     , pl000_00_21 },
	{ MOT_DANTE_GUNSLINGER_KALINA_ANN , pl000_00_22 },
	{ MOT_DANTE_TRICKSTER             , pl000_00_23 },
	{ MOT_DANTE_ROYALGUARD            , pl000_00_24 },
	{ MOT_DANTE_QUICKSILVER           , pl000_00_25 },
	{ MOT_DANTE_DOPPELGANGER          , pl000_00_26 },
};

MotionHelper motionHelperBob[] =
{
	{ MOT_BOB_BASE       , pl001_00_0  },
	{ MOT_BOB_DAMAGE     , pl001_00_1  },
	{ MOT_BOB_TAUNTS     , pl001_00_2  },
	{ MOT_BOB_MELEE_STYLE, pl001_00_31 },
};

MotionHelper motionHelperLady[] =
{
	{ MOT_LADY_BASE      , pl002_00_0  },
	{ MOT_LADY_DAMAGE    , pl002_00_1  },
	{ MOT_LADY_TAUNTS    , pl002_00_2  },
	{ MOT_LADY_KALINA_ANN, pl000_00_12 },
};

MotionHelper motionHelperVergil[] =
{
	{ MOT_VERGIL_BASE                  , pl021_00_0 },
	{ MOT_VERGIL_DAMAGE                , pl021_00_1 },
	{ MOT_VERGIL_TAUNTS                , pl021_00_2 },
	{ MOT_VERGIL_YAMATO                , pl021_00_3 },
	{ MOT_VERGIL_BEOWULF               , pl021_00_4 },
	{ MOT_VERGIL_FORCE_EDGE            , pl021_00_5 },
	{ MOT_VERGIL_DARK_SLAYER           , pl021_00_6 },
	{ MOT_VERGIL_NERO_ANGELO_YAMATO    , pl021_00_7 },
	{ MOT_VERGIL_NERO_ANGELO_BEOWULF   , pl021_00_8 },
	{ MOT_VERGIL_NERO_ANGELO_FORCE_EDGE, pl021_00_9 },
};

MotionHelper * motionHelper[] =
{
	motionHelperDante,
	motionHelperBob,
	motionHelperLady,
	motionHelperVergil,
};

uint8 motionHelperCount[] =
{
	countof(motionHelperDante),
	countof(motionHelperBob),
	countof(motionHelperLady),
	countof(motionHelperVergil),
};

PrivateEnd;

// @Todo: Obsolete.

uint8 System_Actor_GetActorId(byte8 * baseAddr)
{
	for (uint8 actor = 0; actor < MAX_ACTOR; actor++)
	{
		if (System_Actor_actorBaseAddr[actor] == baseAddr)
		{
			return actor;
		}
	}
	return 0;
}

uint8 System_Actor_GetActorCount()
{
	uint8 count = 0;
	for (uint8 actor = 0; actor < MAX_ACTOR; actor++)
	{
		if (!System_Actor_actorBaseAddr[actor])
		{
			break;
		}
		count++;
	}
	return count;
}

PrivateStart;

void CreateActors()
{
	LogFunction();






	if (Config.Game.Multiplayer.enable)
	{
		for (uint8 index = 0; index < Config.Game.Multiplayer.actorCount; index++)
		{
			uint8 actor = (ACTOR_TWO + index);
			auto & character = Config.Game.Multiplayer.character[index];
			InternalCreateActor(character, actor, false);
		}
	}
	else
	{
		uint8 & characterActorOne = *(uint8 *)(System_Actor_actorBaseAddr[ACTOR_ONE] + 0x78);
		uint8 character = (Config.Game.Doppelganger.enable) ? Config.Game.Doppelganger.character : characterActorOne;
		InternalCreateActor(character, ACTOR_TWO, false);
	}
}

void CreateActorOne(byte8 * baseAddr)
{
	LogFunction(baseAddr);
	memset(System_Actor_actorBaseAddr, 0, sizeof(System_Actor_actorBaseAddr));
	System_Actor_actorBaseAddr[ACTOR_ONE] = baseAddr;
	if (Config.System.Actor.forceSingleActor)
	{
		return;
	}
	CreateActors();
}

//void UpdateCostume(byte8 * baseAddr)
//{
//	uint8 actor = System_Actor_GetActorId(baseAddr);
//	uint8 character = *(uint8 *)(baseAddr + 0x78);
//	if (character >= MAX_CHAR)
//	{
//		character = 0;
//	}
//	uint8 & costume = *(uint8 *)(baseAddr + 0x3E9E);
//	if (Config.Game.Multiplayer.enable && (actor != ACTOR_ONE))
//	{
//		costume = Config.Game.Multiplayer.costume[(actor - 1)];
//	}
//	if (costume >= costumeHelperCount[character])
//	{
//		costume = 0;
//	}
//	fileItemHelper[character][0].stringItemId = costumeHelper[character][costume].stringItemId;
//	fileItemHelper[character][0].cacheFileId  = costumeHelper[character][costume].cacheFileId;
//}

void UpdateBaseAddress(byte8 * baseAddr)
{
	uint8 actor = System_Actor_GetActorId(baseAddr);
	byte8 ** data = *(byte8 ***)(appBaseAddr + 0xC90E28);
	if (!data)
	{
		return;
	}
	switch (actor)
	{
	case ACTOR_ONE:
		data[3] = baseAddr;
		break;
	case ACTOR_TWO:
		data[4] = baseAddr;
		break;
	}
}

void UpdateActor(byte8 * baseAddr)
{
	Log("%s %llX", FUNC_NAME, baseAddr);

	uint8 character = *(uint8 *)(baseAddr + 0x78);
	if (character >= MAX_CHAR)
	{
		character = 0;
	}

	//// Update File Items
	//{
	//	UpdateCostume(baseAddr);
	//	auto & count = fileItemHelperCount[character];
	//	for (uint8 index = 0; index < count; index++)
	//	{
	//		fileItemHelper[character][index].Update();
	//	}
	//}

	//UpdateBaseAddress(baseAddr);


	System_File_UpdateFileItems((ACTOR_DATA *)baseAddr);











	LogFunctionEnd();
}

void UpdateMotion(byte8 * baseAddr)
{
	LogFunction(baseAddr);
	uint8 character = *(uint8 *)(baseAddr + 0x78);
	if (character >= MAX_CHAR)
	{
		character = 0;
	}
	byte ** motion = (byte **)(baseAddr + 0x38A0);
	memset(motion, 0, (MAX_MOT * 8));
	auto & count = motionHelperCount[character];
	for (uint8 index = 0; index < count; index++)
	{
		auto & motionId    = motionHelper[character][index].motionId;
		auto & cacheFileId = motionHelper[character][index].cacheFileId;

		//motion[motionId] = System_Cache_file[cacheFileId];

		motion[motionId] = System_File_cacheFile[cacheFileId];


	}
}

PrivateEnd;

// @Todo: Review.

void System_Actor_ResetDevilModel()
{
	LogFunction();
	// Loop Count
	{
		byte buffer[] =
		{
			0x0F, 0x45, 0xC1, //cmovne eax,ecx
		};
		vp_memcpy((appBaseAddr + 0x2130E5), buffer, sizeof(buffer));
	}
	// Sparda
	{
		byte buffer[] =
		{
			0x0F, 0x85, 0xCB, 0x03, 0x00, 0x00, //jne dmc3.exe+21353F
		};
		vp_memcpy((appBaseAddr + 0x21316E), buffer, sizeof(buffer));
	}
	// Other Models
	{
		byte buffer[] =
		{
			0x41, 0x0F, 0xBE, 0x0C, 0x0C, //movsx ecx,byte ptr [r12+rcx]
		};
		vp_memcpy((appBaseAddr + 0x21353F), buffer, sizeof(buffer));
	}
	// Aura
	WriteAddress((appBaseAddr + 0x1F9393), (appBaseAddr + 0x1F93AB), 2);
	WriteAddress((appBaseAddr + 0x1F9433), (appBaseAddr + 0x1F9440), 2);
	Write<uint8>((appBaseAddr + 0x1F943B), DEVIL_DANTE_SPARDA);
}

void System_Actor_UpdateDevilModel(uint8 model)
{
	LogFunction();
	System_Actor_ResetDevilModel();
	vp_memset((appBaseAddr + 0x2130E5), 0x90, 3);
	if (model == DEVIL_DANTE_SPARDA)
	{
		WriteAddress((appBaseAddr + 0x21316E), (appBaseAddr + 0x213174), 6);
	}
	else
	{
		Write<word>((appBaseAddr + 0x21316E), 0xE990);
		{
			byte buffer[] =
			{
				0x31, 0xC9, //xor ecx,ecx
				0xB1, 0x00, //mov cl,model
				0x90,       //nop
			};
			vp_memcpy((appBaseAddr + 0x21353F), buffer, sizeof(buffer));
			Write<uint8>((appBaseAddr + 0x213542), model);
		}
	}
	WriteAddress((appBaseAddr + 0x1F9393), (appBaseAddr + 0x1F9395), 2);
	WriteAddress((appBaseAddr + 0x1F9433), (appBaseAddr + 0x1F9435), 2);
	Write<uint8>((appBaseAddr + 0x1F943B), model);
}

PrivateStart;


void UpdateActorAttributes(byte8 * baseAddr)
{
	LogFunction(baseAddr);



	//auto & ad = (*(ACTOR_DATA *)baseAddr);
	//auto & ad = *(ACTOR_DATA *)baseAddr;


	//auto & ad = *((ACTOR_DATA *)baseAddr);

	//auto & ad = *(ACTOR_DATA *)baseAddr;

	//ad.isDoppelganger = true;



	















	auto & character      = *(uint8  *)(baseAddr + 0x78  );
	auto & isDoppelganger = *(uint32 *)(baseAddr + 0x11C );
	auto & visible        = *(uint32 *)(baseAddr + 0x120 );
	auto & shadow         = *(uint32 *)(baseAddr + 0x3A18);



	if (Config.Game.Multiplayer.enable)
	{
		return;
	}
	if (baseAddr != System_Actor_actorBaseAddr[ACTOR_TWO])
	{
		return;
	}
	isDoppelganger = 1;
	if (Config.Cosmetics.Doppelganger.noColor)
	{
		return;
	}
	Cosmetics_Color_ApplyColor(baseAddr, 6, 0);
}

PrivateEnd;









typedef void (__fastcall * func_8B470_t)
(
	byte8  * dest,
	uint32   flag
);

typedef void (__fastcall * func_89960_t)
(
	byte8 * dest,
	byte8 * modelFile,
	byte8 * textureFile
);

typedef byte8 * (__fastcall * func_89DE0_t)
(
	byte8 * dest
);

typedef void (__fastcall * func_8BC60_t)
(
	byte8 * dest,
	byte8 * addr,
	byte8 * shadowFile
);

typedef void (__fastcall * func_305D80_t)
(
	byte8 * dest
);

typedef void (__fastcall * func_8A000_t)
(
	byte8  * dest,
	uint64   unknown,
	byte8  * addr
);

// @Research: Maybe add const.

typedef uint32 (__fastcall * func_2C9F40_t)
(
	byte8 * clothFile
);

typedef void (__fastcall * func_2CA1D0_t)
(
	byte8  * dest,
	byte8  * addr,
	byte8  * clothFile,
	uint32   index
);

typedef void (__fastcall * func_2CA2F0_t)
(
	byte8  * dest,
	byte8  * addr,
	byte8  * unknown,
	byte8  * modelData,
	uint32   count
);

typedef void(__fastcall * func_1EF040_t)
(
	byte8  * baseAddr,
	uint32   index
);





/*
dmc3.exe+2141A7 - E8 94AEFDFF           - call dmc3.exe+1EF040

*/








func_8B470_t  func_8B470  = 0;
func_89960_t  func_89960  = 0;
func_89DE0_t  func_89DE0  = 0;
func_8BC60_t  func_8BC60  = 0;
func_305D80_t func_305D80 = 0;
func_8A000_t  func_8A000  = 0;
func_2C9F40_t func_2C9F40 = 0;
func_2CA1D0_t func_2CA1D0 = 0;
func_2CA2F0_t func_2CA2F0 = 0;
func_1EF040_t func_1EF040 = 0;

/*
[rax + 150] dmc3.exe+8A000
[rdx +   8] dmc3.exe+89DE0
[rdx +  68] dmc3.exe+211C10
[rdi +   8] dmc3.exe+8BC60
[ r8 +  38] dmc3.exe+8B470
[ r9 +  50] dmc3.exe+89960
*/

void HumanDante(byte8 * baseAddr)
{
	byte8 * textureFile = 0;
	byte8 * modelFile   = 0;
	byte8 * shadowFile  = 0;
	byte8 * clothFile   = 0;
	byte8 * addr = 0;
	uint32 count = 0;
	auto actorData = (ACTOR_DATA *)baseAddr;
	auto & md = actorData->modelData;
	vec4 * g_vertex     = 0;
	vec4 * g_coatVertex = 0;
	//byte8 * coatShadowFile = 0;
	byte8 * addr2 = 0;
	byte8 * coatShadowFile = 0;




	textureFile = System_File_GetFile(System_File_cacheFile[pl000], 0);
	modelFile   = System_File_GetFile(System_File_cacheFile[pl000], 1);
	func_8B470((baseAddr + 0x200), 1);
	func_89960((baseAddr + 0x200), modelFile, textureFile);

	shadowFile = System_File_GetFile(System_File_cacheFile[pl000], 8);
	addr = func_89DE0((baseAddr + 0x200));
	func_8BC60((baseAddr + 0x9AD0), addr, shadowFile);

	addr = func_89DE0((baseAddr + 0x200));
	func_305D80(addr);

	g_vertex = (vec4 *)(appBaseAddr + 0x58B260);

	md[0].count = 4;
	md[0].vertex[0] = g_vertex[0];
	md[0].vertex[1] = g_vertex[1];
	md[0].vertex[2] = g_vertex[2];

	md[1].count = 4;
	md[1].vertex[0] = g_vertex[3];
	md[1].vertex[1] = g_vertex[4];
	md[1].vertex[2] = g_vertex[5];

	md[2].count = 4;
	md[2].vertex[0] = g_vertex[6];
	md[2].vertex[1] = g_vertex[7];
	md[2].vertex[2] = g_vertex[8];

	md[3].count = 4;
	md[3].vertex[0] = g_vertex[9];
	md[3].vertex[1] = g_vertex[10];
	md[3].vertex[2] = g_vertex[11];

	md[4].count = 4;
	md[4].vertex[0] = g_vertex[12];
	md[4].vertex[1] = g_vertex[13];
	md[4].vertex[2] = g_vertex[14];

	md[5].count = 4;
	md[5].vertex[0] = g_vertex[15];
	md[5].vertex[1] = g_vertex[16];
	md[5].vertex[2] = g_vertex[17];







	// No Coat

	//textureFile = System_File_GetFile(System_File_cacheFile[pl011], 0 );
	//modelFile   = System_File_GetFile(System_File_cacheFile[pl011], 12);
	//func_8B470((baseAddr + 0x7540), 1);
	//func_89960((baseAddr + 0x7540), modelFile, textureFile);
	//*(uint8 *)(baseAddr + 0x9AC0) = 1;
	//func_8A000((baseAddr + 0x7540), 0, (baseAddr + 0xA0D0));

	//md[0].count = 4;
	//md[0].vertex[0] = g_vertex[23];
	//md[0].vertex[1] = g_vertex[24];
	//md[0].vertex[2] = g_vertex[25];



	//	byte8 * dest = (baseAddr + 0xA210);
	//clothFile = System_File_GetFile(System_File_cacheFile[pl011], 13);
	//count = func_2C9F40(clothFile);
	//for (uint32 index = 0; index < count; index++)
	//{
	
	//	func_2CA1D0(dest, (baseAddr + 0xA0D0), clothFile, index);
	//	dest += 0xF0;
	//}

	//func_2CA2F0
	//(
	//	(baseAddr + 0xA210),
	//	(baseAddr + 0x1880),
	//	(appBaseAddr + 0x58B054),
	//	(baseAddr + 0xB630),
	//	1
	//);


	//actorData->costume = 1;
	// DonDanteCoatless
	// DonDanteBase
	// DonAmuletDante
	// DonAmuletVergil





	// Coat


	textureFile = System_File_GetFile(System_File_cacheFile[pl000], 0 );
	modelFile   = System_File_GetFile(System_File_cacheFile[pl000], 12);
	func_8B470((baseAddr + 0x7540), 1);
	func_89960((baseAddr + 0x7540), modelFile, textureFile);
	func_8A000((baseAddr + 0x7540), 0, (baseAddr + 0xA0D0));

	g_coatVertex = (vec4 *)(appBaseAddr + 0x35D580);
	addr2 = *(byte8 **)(baseAddr + 0xA0D0);
	addr2 = *(byte8 **)(addr2 + 0x108);

	auto coatVertex = (vec4 *)addr2;

	coatVertex[0] = g_coatVertex[0];
	coatVertex[1] = g_coatVertex[1];
	coatVertex[2] = g_coatVertex[2];
	coatVertex[3] = g_coatVertex[3];

	md[0].count = 4;
	md[0].vertex[0] = g_vertex[0];
	md[0].vertex[1] = g_vertex[1];
	md[0].vertex[2] = g_vertex[2];

	md[1].count = 4;
	md[1].vertex[0] = g_vertex[3];
	md[1].vertex[1] = g_vertex[4];
	md[1].vertex[2] = g_vertex[5];

	md[2].count = 4;
	md[2].vertex[0] = g_vertex[6];
	md[2].vertex[1] = g_vertex[7];
	md[2].vertex[2] = g_vertex[8];

	md[3].count = 4;
	md[3].vertex[0] = g_vertex[9];
	md[3].vertex[1] = g_vertex[10];
	md[3].vertex[2] = g_vertex[11];

	md[4].count = 4;
	md[4].vertex[0] = g_vertex[12];
	md[4].vertex[1] = g_vertex[13];
	md[4].vertex[2] = g_vertex[14];

	md[5].count = 4;
	md[5].vertex[0] = g_vertex[15];
	md[5].vertex[1] = g_vertex[16];
	md[5].vertex[2] = g_vertex[17];

	clothFile = System_File_GetFile(System_File_cacheFile[pl000], 13);
	count = func_2C9F40(clothFile);


	byte8 * dest = (baseAddr + 0xA210);

	for (uint32 index = 0; index < count; index++)
	{
		
		func_2CA1D0(dest, (baseAddr + 0xA0D0), clothFile, index);
		dest += 0xF0;
	}

	func_2CA2F0
	(
		(baseAddr + 0xA210),
		(baseAddr + 0x1880),
		(appBaseAddr + 0x58B380),
		(baseAddr + 0xB630),
		6
	);


	// Can be merged into a Register or Apply Shadow function.

	coatShadowFile = System_File_GetFile(System_File_cacheFile[pl000], 14);
	addr = func_89DE0((baseAddr + 0x7540));
	func_8BC60((baseAddr + 0x9D10), addr, coatShadowFile);



	addr = func_89DE0((baseAddr + 0x7540));
	func_305D80(addr);
}







void DevilCerberus(byte8 * baseAddr)
{

	
	auto g_coatVertex = (vec4 *)(appBaseAddr + 0x35D580);

	byte8 * r12 = 0;
	byte8 * addr = 0;
	uint32 rbx = 0;
	byte8 * rcx = 0;
	
	byte8 * rsp50 = 0;



	byte8 * textureFile = 0;
	byte8 * modelFile   = 0;
	byte8 * shadowFile  = 0;
	byte8 * clothFile   = 0;

	uint32 r13d = 2;
	// r13 0000000000000002
	// nr13 

	uint64 r13 = r13d;

	uint32 edi = r13d;


	byte8 * rsi = baseAddr;
	// rsi 00000000045ECE70
	// nrsi 


	uint32 r14d = 3;
	// r14 0000000000000003
	// nr14 

	uint64 r14 = r14d;

	uint32 r15d = 0x24;
	// r15 0000000000000024
	// nr15 

	uint64 r15 = r15d;





	{
		*(uint32 *)(rsi + 0x3E74 + (edi * 4)) = 1;
		// rsi 00000000045ECE70
		// rdi 0000000000000002
		// nrsi 
		// nrdi 



		textureFile = System_File_GetFile(System_File_cacheFile[pl006], 0);
		// rax 00000000207BA020
		// nrax 00000000207BA020

		modelFile   = System_File_GetFile(System_File_cacheFile[pl006], 1);
		// rax 00000000207E5820
		// nrax 00000000207E5820

		r12 = baseAddr;

		r12 += (edi * 0x780);

		r12 += 0x200;

		// rcx 00000000045EDF70
		// rdx 0000000000000001
		// nrcx 00000000045EDF70
		// nrdx 0000000000000001
		func_8B470(r12, 1);

		// rcx 00000000045EDF70
		// rdx 00000000207E5820
		// r8  00000000207BA020
		// nrcx 00000000045EDF70
		// nrdx 00000000207E5820
		// nr8  00000000207BA020
		func_89960(r12, modelFile, textureFile);


		// 0 0
		// 1 0x18
		// 2 0x30

		// rax 0000000000000030
		// r13 0000000000000002
		*(uint8 *)(rsi + 0xB609) = 0x30;
		*(uint8 *)(rsi + 0xB608) = (uint8)r13d;


		// rcx 00000000045ECE70
		// rdx 0000000000000002
		// nrcx 00000000045ECE70
		// nrdx 0000000000000002
		func_1EF040(rsi, r13d);
	}

	{
		shadowFile = System_File_GetFile(System_File_cacheFile[pl006], 4);
		// rax 000000002080C3F0
		// nrax 000000002080C3F0

		// r13 no longer valid here!

		// rcx 00000000045EDF70
		// nrcx 00000000045EDF70
		addr = func_89DE0(r12);
		// rax 00000000045EDFF0
		// nrax 00000000045EDFF0

		rbx = (edi * 0xC0);

		rcx = (rsi + 0x9AD0);

		rcx += rbx;

		// rcx 00000000045F6AC0
		// rdx 00000000045EDFF0
		// r8  000000002080C3F0
		// nrcx 00000000045F6AC0
		// nrdx 00000000045EDFF0
		// nr8  000000002080C3F0
		func_8BC60(rcx, addr, shadowFile);


		// rcx 00000000045EDF70
		// nrcx 00000000045EDF70
		addr = func_89DE0(r12);
		// rax 00000000045EDFF0
		// nrax 00000000045EDFF0


		// rcx 00000000045EDFF0
		// nrcx 00000000045EDFF0
		func_305D80(addr);
	}



	{
		textureFile = System_File_GetFile(System_File_cacheFile[pl006], 0);
		// rax 00000000207BA020
		// nrax 00000000207BA020

		modelFile = System_File_GetFile(System_File_cacheFile[pl006], 2);
		// rax 000000002080A520
		// nrax 000000002080A520

		

		r13d = r14d;

		r12 = baseAddr;
		r12 += (r13d * 0x780);
		r12 += 0x7540;

		// rcx 00000000045F5A30
		// rdx 0000000000000001
		// nrcx 00000000045F5A30
		// nrdx 0000000000000001
		func_8B470(r12, 1);

		// rcx 00000000045F5A30
		// rdx 000000002080A520
		// r8  00000000207BA020
		// nrcx 00000000045F5A30
		// nrdx 000000002080A520
		// nr8  00000000207BA020
		func_89960(r12, modelFile, textureFile);

		// 1 0
		// 2 0x24

		


		uint32 eax = r15d;

		uint64 rax = eax;

		rax += 0x1460;

		byte8 * rcx = (rsi + (rax * 8));
	

		rsp50 = rcx;


		byte8 * r8 = rcx;

		// rcx 00000000045F5A30
		// rdx 0000000000000000
		// r8  00000000045F7290
		// nrcx 00000000045F5A30
		// nrdx 0000000000000000
		// nr8  00000000045F7290
		func_8A000(r12, 0, r8);







		shadowFile = System_File_GetFile(System_File_cacheFile[pl006], 5);
		// rax 000000002080FAC0
		// nrax 000000002080FAC0

		uint64 rbx = (r13 * 0xC0);

		// rcx 00000000045F5A30
		// nrcx 
		addr = func_89DE0(r12);
		// rax 00000000045F5AB0
		// nrax 

		rcx = (baseAddr + 0x9D10);
	
		rcx += rbx;

		// rcx 00000000045F6DC0
		// rdx 00000000045F5AB0
		// r8  000000002080FAC0
		// nrcx 00000000045F6D00
		// nrdx 00000000045F5AB0
		// nr8  000000002080FAC0
		func_8BC60(rcx, addr, shadowFile);

		// rcx 00000000045F5A30
		// nrcx 00000000045F5A30
		addr = func_89DE0(r12);
		// rax 00000000045F5AB0
		// nrax 00000000045F5AB0

		// rcx 00000000045F5AB0
		// nrcx 00000000045F5AB0
		func_305D80(addr);

		// rsi 00000000045ECE70
		// r13 0000000000000003
		*(uint8 *)(rsi + r13 + 0x9AC0) = 1;
	}










	clothFile = System_File_GetFile(System_File_cacheFile[pl006], 3);
	// rax 000000002080C240
	// nrax 000000002080C240

	// r12 no longer valid here!

	// rcx 000000002080C240
	// nrcx 000000002080C240
	uint32 count = func_2C9F40(clothFile);
	// rax 0000000000000001
	// nrax 0000000000000001


	byte8 * dest = (baseAddr + 0xA540);
	for (uint32 index = 0; index < count; index++)
	{
		// rcx 00000000045F7590
		// rdx 00000000045F7290
		// r8  000000002080C240
		// r9  0000000000000000
		// nrcx 00000000045F73B0
		// nrdx 00000000045F7290
		// nr8  000000002080C240
		// nr9  0000000000000000
		func_2CA1D0(dest, rsp50, clothFile, index);

		dest += 0xF0;
	}







	



	uint32 ebp = 2;

	r13d = 1; // slot

	uint64 r8 = (ebp * 0x300);

	// r8 0000000000000600
	// nr8 

	{
		uint32 eax = (r15 + 1);
		// eax 0000000000000025
		// neax 

		byte8 * rdx = (baseAddr + 0xAA00);
		// rdx 00000000045F7870
		// nrdx 

		rdx += r8;
		// rdx 00000000045F7E70
		// nrdx 00000000045F7E70

		byte8 * rax = (baseAddr + (eax * 8) + 0xA300);

		// __WRONG__

		// rax 0000000004619E70
		// nrax 

		*(byte8 **)(rax + 0x100) = rdx;

		vec4 * coat = (vec4 *)(rdx + 0x80);
		coat[0] = g_coatVertex[0];
		coat[1] = g_coatVertex[1];
		coat[2] = g_coatVertex[2];
		coat[3] = g_coatVertex[3];

		eax = *(uint8 *)(baseAddr + 0xB609);
		// eax 0000000000000030
		// neax 0000000000000030

		eax += 3;
		// eax 0000000000000033
		// neax 

		byte8 * rcx = (baseAddr + (eax * 8) + 0x1880);

		// __WRONG__

		// rcx 0000000004605670
		// nrcx 000000000460DE70

		rax = *(byte8 **)(rcx + 0x110);
		// rax 000000000465E730
		// nrax 

		*(byte8 **)(rdx + 0x30) = rax;
		// rdx 00000000045F7E70
		// nrdx 

		*(uint32 *)(rdx + 0x28) = r13d;
		// rdx 00000000045F7E70
		// nrdx 
	}

	


	{
		uint32 eax = (r15 + 2);
		// eax 0000000000000026
		// neax 

		byte8 * rdx = (baseAddr + 0xAAC0);
		// rdx 00000000045F7930
		// nrdx 

		rdx += r8;
		// rdx 00000000045F7F30
		// nrdx 

		byte8 * rax = (baseAddr + (eax * 8) + 0xA300);
		// rax 000000000461A270
		// nrax 

		*(byte8 **)(rax + 0x100) = rdx;
		// rax 000000000461A270
		// rdx 00000000045F7F30
		// nrax 
		// nrdx 

		vec4 * coat = (vec4 *)(rdx + 0x80);
		coat[0] = g_coatVertex[0];
		coat[1] = g_coatVertex[1];
		coat[2] = g_coatVertex[2];
		coat[3] = g_coatVertex[3];

		eax = *(uint8 *)(baseAddr + 0xB609);
		// eax 0000000000000030
		// neax 

		eax += 6;
		// eax 0000000000000036
		// neax 

		byte8 * rcx = (baseAddr + (eax * 8) + 0x1880);
		// rcx 0000000004606270
		// nrcx 

		rax = *(byte8 **)(rcx + 0x110);
		// rax 000000000465E7F0
		// nrax 

		*(byte8 **)(rdx + 0x30) = rax;
		// rax 000000000465E7F0
		// rdx 00000000045F7F30
		// nrax 
		// nrdx 

		*(uint32 *)(rdx + 0x28) = r13d;
		// rdx  00000000045F7F30
		// r13d 0000000000000001
		// nrdx  
		// nr13d 
	}

	{
		uint32 eax = (r15 + 8);
		// eax 000000000000002C
		// neax 

		byte8 * rdx = (baseAddr + 0xAB80);
		// rdx 00000000045F79F0
		// nrdx 

		rdx += r8;
		// rdx 00000000045F7FF0
		// nrdx 

		byte8 * rax = (baseAddr + (eax * 8) + 0xA300);
		// rax 000000000461BA70
		// nrax 

		*(byte8 **)(rax + 0x100) = rdx;
		// rax 000000000461BA70
		// rdx 00000000045F7FF0
		// nrax 
		// nrdx 

		vec4 * coat = (vec4 *)(rdx + 0x80);
		coat[0] = g_coatVertex[0];
		coat[1] = g_coatVertex[1];
		coat[2] = g_coatVertex[2];
		coat[3] = g_coatVertex[3];

		eax = *(uint8 *)(baseAddr + 0xB609);
		// eax 0000000000000030
		// neax 

		eax += 10;
		// eax 000000000000003A
		// neax 

		byte8 * rcx = (baseAddr + (eax * 8) + 0x1880);
		// rcx 0000000004607270
		// nrcx 

		rax = *(byte8 **)(rcx + 0x110);
		// rax 000000000465E8F0
		// nrax 

		*(byte8 **)(rdx + 0x30) = rax;
		// rax 000000000465E8F0
		// rdx 00000000045F7FF0
		// nrax 
		// nrdx 

		*(uint32 *)(rdx + 0x28) = r13d;
		// rdx  00000000045F7FF0
		// r13d 0000000000000001
		// nrdx  
		// nr13d 
	}



	*(uint8 *)(rsi + 0xB60C) = (uint8)ebp;
	// ebp 0000000000000002
	// nebp 

	*(uint8 *)(rsi + 0xB60A) = (uint8)r14;
	// r14 0000000000000003
	// nr14 

	*(uint8 *)(rsi + 0xB60B) = (uint8)r15;
	// nr15 

}





/*
[rax + 150] dmc3.exe+8A000
[rdx +   8] dmc3.exe+89DE0
[rdx +  68] dmc3.exe+211C10
[rdi +   8] dmc3.exe+8BC60
[ r8 +  38] dmc3.exe+8B470
[ r9 +  50] dmc3.exe+89960
*/



















void HumanVergil(byte8 * baseAddr)
{
	byte8 * textureFile = 0;
	byte8 * modelFile   = 0;
	byte8 * shadowFile  = 0;
	byte8 * clothFile   = 0;
	byte8 * addr = 0;
	uint32 count = 0;

	vec4 * g_vertex     = 0;

	byte8 * dest = 0;
	byte8 * addr2 = 0;



	textureFile = System_File_GetFile(System_File_cacheFile[em034], 31);
	modelFile   = System_File_GetFile(System_File_cacheFile[em034], 32);
	func_8B470((baseAddr + 0x200), 1);
	func_89960((baseAddr + 0x200), modelFile, textureFile);

	shadowFile = System_File_GetFile(System_File_cacheFile[pl021], 8);
	addr = func_89DE0((baseAddr + 0x200));
	func_8BC60((baseAddr + 0x9AF0), addr, shadowFile);
	addr = func_89DE0((baseAddr + 0x200));
	func_305D80(addr);

	g_vertex = (vec4 *)(appBaseAddr + 0x58B260);
	auto md = (MODEL_DATA *)(baseAddr + 0xB640);

	md[0].count = 4;
	md[0].vertex[0] = g_vertex[0];
	md[0].vertex[1] = g_vertex[1];
	md[0].vertex[2] = g_vertex[2];

	md[1].count = 4;
	md[1].vertex[0] = g_vertex[3];
	md[1].vertex[1] = g_vertex[4];
	md[1].vertex[2] = g_vertex[5];

	md[2].count = 4;
	md[2].vertex[0] = g_vertex[6];
	md[2].vertex[1] = g_vertex[7];
	md[2].vertex[2] = g_vertex[8];

	md[3].count = 4;
	md[3].vertex[0] = g_vertex[9];
	md[3].vertex[1] = g_vertex[10];
	md[3].vertex[2] = g_vertex[11];

	md[4].count = 4;
	md[4].vertex[0] = g_vertex[12];
	md[4].vertex[1] = g_vertex[13];
	md[4].vertex[2] = g_vertex[14];

	md[5].count = 4;
	md[5].vertex[0] = g_vertex[15];
	md[5].vertex[1] = g_vertex[16];
	md[5].vertex[2] = g_vertex[17];





	// No Coat

	//textureFile = System_File_GetFile(System_File_cacheFile[pl023], 0 );
	//modelFile   = System_File_GetFile(System_File_cacheFile[pl023], 12);
	//func_8B470((baseAddr + 0x7540), 1);
	//func_89960((baseAddr + 0x7540), modelFile, textureFile);
	//*(uint8 *)(baseAddr + 0x9AC0) = 1;
	//func_8A000((baseAddr + 0x7540), 0, (baseAddr + 0xA0F0));

	//md[0].count = 4;
	//md[0].vertex[0] = g_vertex[23];
	//md[0].vertex[1] = g_vertex[24];
	//md[0].vertex[2] = g_vertex[25];




	//clothFile = System_File_GetFile(System_File_cacheFile[pl023], 13);
	//count = func_2C9F40(clothFile);

	//byte8 * dest = (baseAddr + 0xA230);
	//for (uint32 index = 0; index < count; index++)
	//{
	//	func_2CA1D0(dest, (baseAddr + 0xA0F0), clothFile, index);
	//	dest += 0xF0;
	//}

	//func_2CA2F0
	//(
	//	(baseAddr + 0xA230),
	//	(baseAddr + 0x1880),
	//	(appBaseAddr + 0x58B054),
	//	(baseAddr + 0xB640),
	//	1
	//);




	textureFile = System_File_GetFile(System_File_cacheFile[pl021], 0 );
	// rax 00000000213B9080
	// nrax 00000000213B9080

	modelFile   = System_File_GetFile(System_File_cacheFile[pl021], 12);
	// rax 00000000214E6E70
	// nrax 00000000214E6E70

	// rcx 00000000045F43B0
	// rdx 0000000000000001
	// nrcx 00000000045F43B0
	// nrdx 0000000000000001
	func_8B470((baseAddr + 0x7540), 1);



	// rcx 00000000045F43B0
	// rdx 00000000214E6E70
	// r8  00000000213B9080
	// nrcx 00000000045F43B0
	// nrdx 00000000214E6E70
	// nr8  00000000213B9080
	func_89960((baseAddr + 0x7540), modelFile, textureFile);

	*(uint8 *)(baseAddr + 0x9AC0) = 1;

	// rcx 00000000045F43B0
	// rdx 0000000000000000
	// r8  00000000045F6F60
	// nrcx 00000000045F43B0
	// nrdx 0000000000000000
	// nr8  00000000045F6F60
	func_8A000((baseAddr + 0x7540), 0, (baseAddr + 0xA0F0));




	addr2 = *(byte8 **)(baseAddr + 0xA0F0);
	// rax 0000000004623270
	// nrax 0000000004623270

	addr2 = *(byte8 **)(addr2 + 0x108);
	// rcx 00000000046232B0
	// nrcx 00000000046232B0


	auto g_coatVertex = (vec4 *)(appBaseAddr + 0x35D580);


	auto coatVertex = (vec4 *)addr2;

	coatVertex[0] = g_coatVertex[0];
	coatVertex[1] = g_coatVertex[1];
	coatVertex[2] = g_coatVertex[2];
	coatVertex[3] = g_coatVertex[3];



	md[0].count = 4;
	md[0].vertex[0] = g_vertex[0];
	md[0].vertex[1] = g_vertex[1];
	md[0].vertex[2] = g_vertex[2];

	md[1].count = 4;
	md[1].vertex[0] = g_vertex[3];
	md[1].vertex[1] = g_vertex[4];
	md[1].vertex[2] = g_vertex[5];

	md[2].count = 4;
	md[2].vertex[0] = g_vertex[6];
	md[2].vertex[1] = g_vertex[7];
	md[2].vertex[2] = g_vertex[8];

	md[3].count = 4;
	md[3].vertex[0] = g_vertex[9];
	md[3].vertex[1] = g_vertex[10];
	md[3].vertex[2] = g_vertex[11];

	md[4].count = 4;
	md[4].vertex[0] = g_vertex[12];
	md[4].vertex[1] = g_vertex[13];
	md[4].vertex[2] = g_vertex[14];

	md[5].count = 4;
	md[5].vertex[0] = g_vertex[15];
	md[5].vertex[1] = g_vertex[16];
	md[5].vertex[2] = g_vertex[17];








	clothFile = System_File_GetFile(System_File_cacheFile[pl021], 13);
	// rax 00000000214ED330
	// nrax 00000000214ED330


	// rcx 00000000214ED330
	// nrcx 00000000214ED330
	count = func_2C9F40(clothFile);
	// rax 0000000000000001
	// nrax 0000000000000001



	dest = (baseAddr + 0xA230);
	for (uint32 index = 0; index < count; index++)
	{

		// rcx 00000000045F70A0
		// rdx 00000000045F6F60
		// r8  00000000214ED330
		// r9  0000000000000000
		// nrcx 00000000045F70A0
		// nrdx 00000000045F6F60
		// nr8  00000000214ED330
		// nr9  0000000000000000
		func_2CA1D0(dest, (baseAddr + 0xA0F0), clothFile, index);
		dest += 0xF0;
	}



	// rcx    00000000045F70A0
	// rdx    00000000045EE6F0
	// r8     00007FF6817FB380
	// r9     00000000045F84B0
	// rsp+20 0000000000000006
	// nrcx    00000000045F70A0
	// nrdx    00000000045EE6F0
	// nr8     00007FF6817FB380
	// nr9     00000000045F84B0
	// nrsp+20 0000000000000006
	func_2CA2F0
	(
		(baseAddr + 0xA230),
		(baseAddr + 0x1880),
		(appBaseAddr + 0x58B380),
		(baseAddr + 0xB640),
		6
	);



	auto coatShadowFile = System_File_GetFile(System_File_cacheFile[pl021], 14);
	// rax 00000000214ED6A0
	// nrax 00000000214ED6A0


	// rcx 00000000045F43B0
	// nrcx 00000000045F43B0
	addr = func_89DE0((baseAddr + 0x7540));
	// rax 00000000045F4430
	// nrax 00000000045F4430


	// rcx 00000000045F6BA0
	// rdx 00000000045F4430
	// r8  00000000214ED6A0
	// nrcx 00000000045F6BA0
	// nrdx 00000000045F4430
	// nr8  00000000214ED6A0
	func_8BC60((baseAddr + 0x9D30), addr, coatShadowFile);


	// rcx 00000000045F43B0
	// nrcx 00000000045F43B0
	addr = func_89DE0((baseAddr + 0x7540));
	// rax 00000000045F4430
	// nrax 00000000045F4430


	// rcx 00000000045F4430
	// nrcx 00000000045F4430
	func_305D80(addr);






}









































// Modify
// Restore
// Update
// Edit




// @Research: Clarify. Does this really create the actor or does it create an additional actor?

// Yup, definitely crap.

// Nope, both.




void System_Actor_Init()
{
	LogFunction();
	{
		byte sect1[] =
		{
			0x48, 0x31, 0xC0,                                           //xor rax,rax
			0x84, 0xD2,                                                 //test dl,dl
			0x74, 0x77,                                                 //je short
			0x48, 0xBB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //mov rbx,System_Actor_actorBaseAddr
			0x48, 0x0F, 0xB6, 0xF1,                                     //movzx rsi,cl
			0x48, 0x0F, 0xB6, 0xFA,                                     //movzx rdi,dl
			0x4D, 0x0F, 0xB6, 0xE0,                                     //movzx r12,r8l

			0x48, 0x8B, 0x4C, 0xFB, 0xF8,                               //mov rcx,[rbx+rdi*8-08]
			0x48, 0x85, 0xC9,                                           //test rcx,rcx
			0x74, 0x57,                                                 //je short

			0x48, 0x8D, 0x89, 0x10, 0x64, 0x00, 0x00,                   //lea rcx,[rcx+00006410]
			0xBA, 0x3C, 0x00, 0x00, 0x00,                               //mov edx,0000003C
			0xE8, 0x00, 0x00, 0x00, 0x00,                               //call dmc3.exe+2EE060 // __NOPE__

			0x8B, 0xCE,                                                 //mov ecx,esi
			0x8B, 0xD7,                                                 //mov edx,edi
			0x45, 0x8B, 0xC4,                                           //mov r8d,r12d
			0xE8, 0x00, 0x00, 0x00, 0x00,                               //call dmc3.exe+1DE820 // __TRUE__ create actor object
			0x4C, 0x8B, 0xE8,                                           //mov r13,rax
			0x48, 0x89, 0x04, 0xFB,                                     //mov [rbx+rdi*8],rax

			0x48, 0x8B, 0xCB,                                           //mov rcx,rbx
			0x8B, 0xD7,                                                 //mov edx,edi
			0xE8, 0x00, 0x00, 0x00, 0x00,                               //call dmc3.exe+1BB390 // __NOPE__

			0x49, 0x8B, 0xCD,                                           //mov rcx,r13
			0x48, 0x8B, 0x15, 0x00, 0x00, 0x00, 0x00,                   //mov rdx,[dmc3.exe+C90E28]
			0x48, 0x8B, 0x52, 0x08,                                     //mov rdx,[rdx+08]
			0x48, 0x81, 0xC2, 0x6C, 0x01, 0x00, 0x00,                   //add rdx,0000016C
			0xE8, 0x00, 0x00, 0x00, 0x00,                               //call dmc3.exe+1DF240 // __TRUE__ register actor files

			0x48, 0x8B, 0x4C, 0xFB, 0xF8,                               //mov rcx,[rbx+rdi*8-08]
			0x4C, 0x89, 0xA9, 0x78, 0x64, 0x00, 0x00,                   //mov [rcx+00006478],r13
			0x49, 0x8B, 0xC5,                                           //mov rax,r13
		};
		FUNC func = CreateFunction(0, 0, true, false, 0, sizeof(sect1));
		memcpy(func.sect1, sect1, sizeof(sect1));
		*(byte8 ***)(func.sect1 + 9) = System_Actor_actorBaseAddr;
		WriteCall((func.sect1 + 0x33), (appBaseAddr + 0x2EE060));
		WriteCall((func.sect1 + 0x3F), (appBaseAddr + 0x1DE820));
		WriteCall((func.sect1 + 0x50), (appBaseAddr + 0x1BB390));
		WriteAddress((func.sect1 + 0x58), (appBaseAddr + 0xC90E28), 7);
		WriteCall((func.sect1 + 0x6A), (appBaseAddr + 0x1DF240));

		// More like queue an additional actor.

		InternalCreateActor = (InternalCreateActor_t)func.addr;
	}
	{
		FUNC func = CreateFunction((appBaseAddr + 0x1FB020), 0);
		System_Actor_UpdateDevilForm = (System_Actor_UpdateDevilForm_t)func.addr;
	}
	{
		FUNC func = CreateFunction((appBaseAddr + 0x1F94D0), 0);
		System_Actor_UpdateFlux = (System_Actor_UpdateFlux_t)func.addr;
	}
	{
		byte sect1[] =
		{
			0x48, 0x8B, 0xD9,                         //mov rbx,rcx
			0x31, 0xD2,                               //xor edx,edx
			0xE8, 0x00, 0x00, 0x00, 0x00,             //call dmc3.exe+1F92C0
			0x48, 0x8B, 0x83, 0xE8, 0x3D, 0x00, 0x00, //mov rax,[rbx+00003DE8]
			0x8B, 0x80, 0xF0, 0x01, 0x00, 0x00,       //mov eax,[rax+000001F0]
			0x89, 0x83, 0xC4, 0x3E, 0x00, 0x00,       //mov [rbx+00003EC4],eax
			0x31, 0xD2,                               //xor edx,edx
			0x48, 0x8B, 0xCB,                         //mov rcx,rbx
			0xE8, 0x00, 0x00, 0x00, 0x00,             //call dmc3.exe+1F97F0
		};
		FUNC func = CreateFunction(0, 0, true, true, 0, sizeof(sect1));
		memcpy(func.sect1, sect1, sizeof(sect1));
		WriteCall((func.sect1 + 5), (appBaseAddr + 0x1F92C0));
		WriteCall((func.sect1 + 0x22), (appBaseAddr + 0x1F97F0));
		System_Actor_Relax = (System_Actor_Relax_t)func.addr;
	}
	{
		byte sect0[] =
		{
			0x49, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //mov r8,actorBaseAddr
			0x4D, 0x8B, 0x04, 0xC0,                                     //mov r8,[r8+rax*8]
			0x4D, 0x8B, 0xD0,                                           //mov r10,r8
		};
		FUNC func = CreateFunction(0, (appBaseAddr + 0x1BA572), false, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		*(byte ***)(func.sect0 + 2) = System_Actor_actorBaseAddr;
		OnUpdate[0] = func.addr;
	}
	{
		byte sect0[] =
		{
			0x48, 0xBD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //mov rbp,actorBaseAddr
			0x4A, 0x8B, 0x6C, 0xC5, 0x00,                               //mov rbp,[rbp+r8*8+00]
		};
		FUNC func = CreateFunction(0, (appBaseAddr + 0x1BC0CA), false, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		*(byte ***)(func.sect0 + 2) = System_Actor_actorBaseAddr;
		OnUpdate[1] = func.addr;
	}
	{
		byte8 sect1[] =
		{
			0x48, 0x8B, 0xC8, //mov rcx,rax
		};
		byte sect2[] =
		{
			0xE8, 0x00, 0x00, 0x00, 0x00, //call dmc3.exe+1BB470
		};
		FUNC func = CreateFunction(CreateActorOne, (appBaseAddr + 0x23C79F), true, true, 0, sizeof(sect1), sizeof(sect2));
		memcpy(func.sect1, sect1, sizeof(sect1));
		memcpy(func.sect2, sect2, sizeof(sect2));
		WriteCall(func.sect2, (appBaseAddr + 0x1BB470));
		CreateActorOneProxy = func.addr;
	}
	{
		byte sect2[] =
		{
			0xFF, 0x90, 0x80, 0x00, 0x00, 0x00, //call qword ptr [rax+00000080]
		};
		FUNC func = CreateFunction(UpdateActor, (appBaseAddr + 0x1DF2CA), true, true, 0, 0, sizeof(sect2));
		memcpy(func.sect2, sect2, sizeof(sect2));
		UpdateActorProxy = func.addr;
	}
	{
		byte sect1[] =
		{
			0x48, 0x8B, 0xCB, //mov rcx,rbx
		};
		FUNC func = CreateFunction(UpdateMotion, (appBaseAddr + 0x1DF2CA), true, true, 0, sizeof(sect1));
		memcpy(func.sect1, sect1, sizeof(sect1));
		WriteJump((UpdateActorProxy + 0x52), func.addr);
	}



	{
		byte8 sect1[] =
		{
			0x48, 0x8B, 0xCB, //mov rcx,rbx
		};
		byte8 sect2[] =
		{
			0x48, 0x8B, 0x5C, 0x24, 0x58, //mov rbx,[rsp+58]
		};
		FUNC func = CreateFunction(UpdateActorAttributes, (appBaseAddr + 0x1F7D8C), true, true, 0, sizeof(sect1), sizeof(sect2));
		memcpy(func.sect1, sect1, sizeof(sect1));
		memcpy(func.sect2, sect2, sizeof(sect2));
		WriteJump((appBaseAddr + 0x1F7D87), func.addr);
	}




	{
		auto func = CreateFunction(HumanDante);
		Log("HumanDante %llX", func.addr);
	}
	{
		auto func = CreateFunction(HumanVergil);
		Log("HumanVergil %llX", func.addr);
		//WriteCall((appBaseAddr + 0x220A30), func.addr); // Vergil Human Model Texture Update
	}
	{
		auto func = CreateFunction(DevilCerberus);
		Log("DevilCerberus %llX", func.addr);
	}




	{
		auto func = CreateFunction((appBaseAddr + 0x8B470));
		func_8B470 = (func_8B470_t)func.addr;
	}
	{
		auto func = CreateFunction((appBaseAddr + 0x89960));
		func_89960 = (func_89960_t)func.addr;
	}
	{
		auto func = CreateFunction((appBaseAddr + 0x89DE0), 0, true, false);
		func_89DE0 = (func_89DE0_t)func.addr;
	}
	{
		auto func = CreateFunction((appBaseAddr + 0x8BC60));
		func_8BC60 = (func_8BC60_t)func.addr;
	}
	{
		auto func = CreateFunction((appBaseAddr + 0x305D80));
		func_305D80 = (func_305D80_t)func.addr;
	}
	{
		auto func = CreateFunction((appBaseAddr + 0x8A000));
		func_8A000 = (func_8A000_t)func.addr;
	}
	{
		auto func = CreateFunction((appBaseAddr + 0x2C9F40), 0, true, false);
		func_2C9F40 = (func_2C9F40_t)func.addr;
	}
	{
		auto func = CreateFunction((appBaseAddr + 0x2CA1D0));
		func_2CA1D0 = (func_2CA1D0_t)func.addr;
	}
	{
		auto func = CreateFunction((appBaseAddr + 0x2CA2F0), 0, true, true, 0, 0, 0, 0, 1);
		func_2CA2F0 = (func_2CA2F0_t)func.addr;
	}
	{
		auto func = CreateFunction((appBaseAddr + 0x1EF040));
		func_1EF040 = (func_1EF040_t)func.addr;
	}











}

#pragma region Ignore

void System_Actor_ToggleArrayExtension(bool enable)
{
	LogFunction(enable);
	System_Actor_enableArrayExtension = enable;
	if (enable)
	{
		// OnUpdate
		WriteJump((appBaseAddr + 0x1BA569), OnUpdate[0]);
		vp_memset((appBaseAddr + 0x1BA5C5), 0x90, 4);
		Write<byte8>((appBaseAddr + 0x1BA5C9), 0x45);
		Write<byte8>((appBaseAddr + 0x1BA5CB), 0x9A);
		WriteJump((appBaseAddr + 0x1BC0C5), OnUpdate[1]);
		// OnEvent


		// What event? Sheesh.

		// @Todo: Put into on demand edits.


		// Actor Heap Stuff

		Write<byte8>((appBaseAddr + 0x1BB397), 0x1C);
		Write<byte8>((appBaseAddr + 0x1BB399), 0x90);



		Write<byte16>((appBaseAddr + 0x1BB408), 0x9003);



		Write<byte16>((appBaseAddr + 0x1BB457), 0x9003);





	}
	else
	{
		{
			byte buffer[] =
			{
				0x4C, 0x8B, 0x44, 0xC1, 0x18, //mov r8,[rcx+rax*8+18]
			};
			vp_memcpy((appBaseAddr + 0x1BA569), buffer, sizeof(buffer));
		}
		{
			byte buffer[] =
			{
				0x49, 0x8B, 0x42, 0x18, //mov rax,[r10+18]
			};
			vp_memcpy((appBaseAddr + 0x1BA5C5), buffer, sizeof(buffer));
		}
		Write<byte8>((appBaseAddr + 0x1BA5C9), 0x44);
		Write<byte8>((appBaseAddr + 0x1BA5CB), 0x98);
		{
			byte buffer[] =
			{
				0x4A, 0x8B, 0x6C, 0xC0, 0x18, //mov rbp,[rax+r8*8+18]
			};
			vp_memcpy((appBaseAddr + 0x1BC0C5), buffer, sizeof(buffer));
		}
		Write<byte8>((appBaseAddr + 0x1BB397), 0x5C);
		Write<byte8>((appBaseAddr + 0x1BB399), 0x18);
		Write<byte16>((appBaseAddr + 0x1BB408), 0x1843);
		Write<byte16>((appBaseAddr + 0x1BB457), 0x1843);
	}
}

void System_Actor_ToggleCreateActorOne(bool enable)
{
	LogFunction(enable);
	System_Actor_enableCreateActor = enable;
	if (enable)
	{
		WriteJump((appBaseAddr + 0x23C79A), CreateActorOneProxy);
	}
	else
	{
		WriteCall((appBaseAddr + 0x23C79A), (appBaseAddr + 0x1BB470));
	}
}

void System_Actor_ToggleUpdateActor(bool enable)
{
	LogFunction(enable);
	System_Actor_enableUpdateActor = enable;
	if (enable)
	{
		WriteJump((appBaseAddr + 0x1DF2C4), UpdateActorProxy, 1);
	}
	else
	{
		byte buffer[] =
		{
			0xFF, 0x90, 0x80, 0x00, 0x00, 0x00, //call qword ptr [rax+00000080]
		};
		vp_memcpy((appBaseAddr + 0x1DF2C4), buffer, sizeof(buffer));
	}
}

void System_Actor_ToggleDoppelgangerFixes(bool enable)
{
	LogFunction(enable);
	System_Actor_enableDoppelgangerFixes = enable;

	// Disable Bob visibility exception.
	WriteAddress((appBaseAddr + 0x1F83D5), (enable) ? (appBaseAddr + 0x1F83D7) : (appBaseAddr + 0x1F8428), 2);


	/*
	dmc3.exe+1F83D5 - 74 51                 - je dmc3.exe+1F8428
	dmc3.exe+1F83D7 - 48 8B 0D 4A8AA900     - mov rcx,[dmc3.exe+C90E28] { (01A44800) }
	*/


	if (enable)
	{
		vp_memset((appBaseAddr + 0x1DF291), 0x90, 7); // Disable linked actor base address reset.
		// Make IsDoppelganger check always return false.
		{
			byte * addr = (appBaseAddr + 0x1F78B0);
			vp_memset(addr, 0x90, 7);
			byte buffer[] =
			{
				0x30, 0xC0, //xor al,al
				0xC3,       //ret
			};
			vp_memcpy(addr, buffer, sizeof(buffer));
		}
		Write<byte16>((appBaseAddr + 0x2134A3), 0xE990); // Skip clone creation.
		// @Todo: Clarify.
		Write<byte8>((appBaseAddr + 0x1F92E0), 0x00); // Devil Form: Disable Doppelganger check.
		Write<byte8>((appBaseAddr + 0x1F92F8), 0xEB); // Devil Form: Disable isDoppelganger check.
	}
	else
	{
		{
			byte buffer[] =
			{
				0x48, 0x89, 0x81, 0x78, 0x64, 0x00, 0x00, //mov [rcx+00006478],rax
			};
			vp_memcpy((appBaseAddr + 0x1DF291), buffer, sizeof(buffer));
		}
		{
			byte buffer[] =
			{
				0x83, 0xB9, 0x1C, 0x01, 0x00, 0x00, 0x01, //cmp dword ptr [rcx+0000011C],01
			};
			vp_memcpy((appBaseAddr + 0x1F78B0), buffer, sizeof(buffer));
		}
		Write<byte16>((appBaseAddr + 0x2134A3), 0x840F);
		Write<byte8>((appBaseAddr + 0x1F92E0), 0x0D);
		Write<byte8>((appBaseAddr + 0x1F92F8), 0x75);
	}
}

void System_Actor_ToggleModelFixes(bool enable)
{
	LogFunction(enable);
	if (enable)
	{
		vp_memset((appBaseAddr + 0x215577), 0x90, 5); // Disable Object Partition Update Dante
	}
	else
	{
		WriteCall((appBaseAddr + 0x215577), (appBaseAddr + 0x2169F0));
	}
}

void System_Actor_ToggleDisableIdleTimer(bool enable)
{
	LogFunction(enable);
	if (enable)
	{
		vp_memset((appBaseAddr + 0x1F2A38), 0x90, 5); // Dante
		vp_memset((appBaseAddr + 0x1F29AE), 0x90, 5); // Vergil
	}
	else
	{
		byte8 buffer[] =
		{
			0xF3, 0x0F, 0x5C, 0x4B, 0x14, //subss xmm1,[rbx+14]
		};
		vp_memcpy((appBaseAddr + 0x1F2A38), buffer, sizeof(buffer));
		vp_memcpy((appBaseAddr + 0x1F29AE), buffer, sizeof(buffer));
	}
}

#pragma endregion
