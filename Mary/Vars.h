#pragma once
#include "../Core/DataTypes.h"

enum ACTOR_
{
	ACTOR_ONE,
	ACTOR_TWO,
	ACTOR_THREE,
	ACTOR_FOUR,
	MAX_ACTOR,
};

enum MODE_
{
	MODE_EASY,
	MODE_NORMAL,
	MODE_HARD,
	MODE_VERY_HARD,
	MODE_DANTE_MUST_DIE,
	MAX_MODE,
};

enum CHAR_
{
	CHAR_DANTE,
	CHAR_VERGIL,
	MAX_CHAR,
};

enum CHAR_LOGIC_
{
	CHAR_LOGIC_DANTE,
	CHAR_LOGIC_BOB,
	CHAR_LOGIC_LADY,
	CHAR_LOGIC_VERGIL,
	MAX_CHAR_LOGIC,
};

enum COSTUME_LOGIC_DANTE_
{
	COSTUME_LOGIC_DANTE_DEFAULT,
	COSTUME_LOGIC_DANTE_DEFAULT_NO_COAT,
	COSTUME_LOGIC_DANTE_DEFAULT_TORN,
	COSTUME_LOGIC_DANTE_DMC1,
	COSTUME_LOGIC_DANTE_DMC1_NO_COAT,
	COSTUME_LOGIC_DANTE_SPARDA,
	COSTUME_LOGIC_DANTE_DEFAULT_TORN_INFINITE_MAGIC_POINTS,
	COSTUME_LOGIC_DANTE_SPARDA_INFINITE_MAGIC_POINTS,
	MAX_COSTUME_LOGIC_DANTE,
};

enum COSTUME_LOGIC_VERGIL_
{
	COSTUME_LOGIC_VERGIL_DEFAULT,
	COSTUME_LOGIC_VERGIL_DEFAULT_NO_COAT,
	COSTUME_LOGIC_VERGIL_DEFAULT_INFINITE_MAGIC_POINTS,
	COSTUME_LOGIC_VERGIL_SPARDA,
	COSTUME_LOGIC_VERGIL_SPARDA_INFINITE_MAGIC_POINTS,
	MAX_COSTUME_LOGIC_VERGIL,
};

enum STYLE_DANTE_
{
	STYLE_DANTE_SWORDMASTER,
	STYLE_DANTE_GUNSLINGER,
	STYLE_DANTE_TRICKSTER,
	STYLE_DANTE_ROYALGUARD,
	STYLE_DANTE_QUICKSILVER,
	STYLE_DANTE_DOPPELGANGER,
	MAX_STYLE_DANTE,
};

enum STYLE_VERGIL_
{
	STYLE_VERGIL_DARK_SLAYER = 2,
	MAX_STYLE_VERGIL = 1,
};

enum STYLE_
{
	MAX_STYLE = 6,
};

enum WEAPON_DANTE_
{
	WEAPON_DANTE_REBELLION,
	WEAPON_DANTE_CERBERUS,
	WEAPON_DANTE_AGNI_RUDRA,
	WEAPON_DANTE_NEVAN,
	WEAPON_DANTE_BEOWULF,
	WEAPON_DANTE_EBONY_IVORY,
	WEAPON_DANTE_SHOTGUN,
	WEAPON_DANTE_ARTEMIS,
	WEAPON_DANTE_SPIRAL,
	WEAPON_DANTE_KALINA_ANN,
	MAX_WEAPON_DANTE,
};

enum WEAPON_VERGIL_
{
	WEAPON_VERGIL_YAMATO = 11,
	WEAPON_VERGIL_BEOWULF,
	WEAPON_VERGIL_FORCE_EDGE,
	MAX_WEAPON_VERGIL = 3,
};

enum WEAPON_
{
	MAX_WEAPON = 16,
	WEAPON_VOID = 255,
};




















enum COSTUME_DANTE_
{
	COSTUME_DANTE_DEFAULT,
	COSTUME_DANTE_DEFAULT_NO_COAT,
	COSTUME_DANTE_DEFAULT_TORN,
	COSTUME_DANTE_DMC1,
	COSTUME_DANTE_DMC1_NO_COAT,
	COSTUME_DANTE_SPARDA,
	MAX_COSTUME_DANTE,
};

enum COSTUME_VERGIL_
{
	COSTUME_VERGIL_DEFAULT,
	COSTUME_VERGIL_DEFAULT_NO_COAT,
	COSTUME_VERGIL_SPARDA,
	MAX_COSTUME_VERGIL,
};

enum DEVIL_DANTE_
{
	DEVIL_DANTE_REBELLION,
	DEVIL_DANTE_CERBERUS,
	DEVIL_DANTE_AGNI_RUDRA,
	DEVIL_DANTE_NEVAN,
	DEVIL_DANTE_BEOWULF,
	DEVIL_DANTE_SPARDA,
	MAX_DEVIL_DANTE,
};

enum DEVIL_VERGIL_
{
	DEVIL_VERGIL_YAMATO,
	DEVIL_VERGIL_BEOWULF,
	MAX_DEVIL_VERGIL,
};


enum MODEL_PART_
{
	MODEL_PART_BASE,
	MODEL_PART_AMULET,
	MODEL_PART_COAT,
	MODEL_MAX_PART,
};

enum DEVIL_MODEL_PART_
{
	DEVIL_MODEL_PART_BASE,
	DEVIL_MODEL_PART_WINGS,
	DEVIL_MODEL_PART_COAT,
	DEVIL_MODEL_MAX_PART,
};






















enum CACHE_FILE_
{
	// Dante
	pl000,
	pl011,
	pl013,
	pl015,
	pl016,
	pl018,
	pl005,
	pl006,
	pl007,
	pl008,
	pl009,
	pl017,
	plwp_sword,
	plwp_nunchaku,
	plwp_2sword,
	plwp_guitar,
	plwp_fight,
	plwp_gun,
	plwp_shotgun,
	plwp_laser,
	plwp_rifle,
	plwp_ladygun,
	plwp_sword2,
	plwp_sword3,
	pl000_00_0,
	pl000_00_1,
	pl000_00_2,
	pl000_00_3,
	pl000_00_4,
	pl000_00_5,
	pl000_00_6,
	pl000_00_7,
	pl000_00_8,
	pl000_00_9,
	pl000_00_10,
	pl000_00_11,
	pl000_00_12,
	pl000_00_13,
	pl000_00_14,
	pl000_00_15,
	pl000_00_16,
	pl000_00_17,
	pl000_00_18,
	pl000_00_19,
	pl000_00_20,
	pl000_00_21,
	pl000_00_22,
	pl000_00_23,
	pl000_00_24,
	pl000_00_25,
	pl000_00_26,
	// Bob
	pl001,
	plwp_vergilsword,
	pl001_00_0,
	pl001_00_1,
	pl001_00_2,
	pl001_00_31,
	// Lady
	pl002,
	pl002_00_0,
	pl002_00_1,
	pl002_00_2,
	// Vergil
	pl021,
	pl023,
	pl026,
	pl010,
	pl014,
	pl025,
	plwp_newvergilsword,
	plwp_newvergilfight,
	plwp_forceedge,
	plwp_nerosword,
	pl021_00_0,
	pl021_00_1,
	pl021_00_2,
	pl021_00_3,
	pl021_00_4,
	pl021_00_5,
	pl021_00_6,
	pl021_00_7,
	pl021_00_8,
	pl021_00_9,
	em034,
	MAX_CACHE_FILE,
};

constexpr const char * cacheFilename[MAX_CACHE_FILE] =
{
	// Dante
	"pl000.pac",
	"pl011.pac",
	"pl013.pac",
	"pl015.pac",
	"pl016.pac",
	"pl018.pac",
	"pl005.pac",
	"pl006.pac",
	"pl007.pac",
	"pl008.pac",
	"pl009.pac",
	"pl017.pac",
	"plwp_sword.pac",
	"plwp_nunchaku.pac",
	"plwp_2sword.pac",
	"plwp_guitar.pac",
	"plwp_fight.pac",
	"plwp_gun.pac",
	"plwp_shotgun.pac",
	"plwp_laser.pac",
	"plwp_rifle.pac",
	"plwp_ladygun.pac",
	"plwp_sword2.pac",
	"plwp_sword3.pac",
	"pl000_00_0.pac",
	"pl000_00_1.pac",
	"pl000_00_2.pac",
	"pl000_00_3.pac",
	"pl000_00_4.pac",
	"pl000_00_5.pac",
	"pl000_00_6.pac",
	"pl000_00_7.pac",
	"pl000_00_8.pac",
	"pl000_00_9.pac",
	"pl000_00_10.pac",
	"pl000_00_11.pac",
	"pl000_00_12.pac",
	"pl000_00_13.pac",
	"pl000_00_14.pac",
	"pl000_00_15.pac",
	"pl000_00_16.pac",
	"pl000_00_17.pac",
	"pl000_00_18.pac",
	"pl000_00_19.pac",
	"pl000_00_20.pac",
	"pl000_00_21.pac",
	"pl000_00_22.pac",
	"pl000_00_23.pac",
	"pl000_00_24.pac",
	"pl000_00_25.pac",
	"pl000_00_26.pac",
	// Bob
	"pl001.pac",
	"plwp_vergilsword.pac",
	"pl001_00_0.pac",
	"pl001_00_1.pac",
	"pl001_00_2.pac",
	"pl001_00_31.pac",
	// Lady
	"pl002.pac",
	"pl002_00_0.pac",
	"pl002_00_1.pac",
	"pl002_00_2.pac",
	// Vergil
	"pl021.pac",
	"pl023.pac",
	"pl026.pac",
	"pl010.pac",
	"pl014.pac",
	"pl025.pac",
	"plwp_newvergilsword.pac",
	"plwp_newvergilfight.pac",
	"plwp_forceedge.pac",
	"plwp_nerosword.pac",
	"pl021_00_0.pac",
	"pl021_00_1.pac",
	"pl021_00_2.pac",
	"pl021_00_3.pac",
	"pl021_00_4.pac",
	"pl021_00_5.pac",
	"pl021_00_6.pac",
	"pl021_00_7.pac",
	"pl021_00_8.pac",
	"pl021_00_9.pac",
	"em034.pac",
};

constexpr uint32 stringItemOff[MAX_CACHE_FILE] =
{
	0x4EA570, // obj\pl000.pac
	0x4EA580, // obj\pl011.pac
	0x4EA590, // obj\pl013.pac
	0x4EA5A0, // obj\pl015.pac
	0x4EA5B0, // obj\pl016.pac
	0x4EA5C0, // obj\pl018.pac
	0x4EA620, // obj\pl005.pac
	0x4EA630, // obj\pl006.pac
	0x4EA640, // obj\pl007.pac
	0x4EA650, // obj\pl008.pac
	0x4EA660, // obj\pl009.pac
	0x4EA670, // obj\pl017.pac
	0x4EB050, // obj\plwp_sword.pac
	0x4EB068, // obj\plwp_nunchaku.pac
	0x4EB080, // obj\plwp_2sword.pac
	0x4EB098, // obj\plwp_guitar.pac
	0x4EB0B0, // obj\plwp_fight.pac
	0x4EB0C8, // obj\plwp_gun.pac
	0x4EB0E0, // obj\plwp_shotgun.pac
	0x4EB0F8, // obj\plwp_laser.pac
	0x4EB110, // obj\plwp_rifle.pac
	0x4EB128, // obj\plwp_ladygun.pac
	0x4EB1C8, // obj\plwp_sword2.pac
	0x4EB1E0, // obj\plwp_sword3.pac
	0x4EA6B0, // motion\pl000\pl000_00_0.pac
	0x4EA6D0, // motion\pl000\pl000_00_1.pac
	0x4EA6F0, // motion\pl000\pl000_00_2.pac
	0x4EA710, // motion\pl000\pl000_00_3.pac
	0x4EA730, // motion\pl000\pl000_00_4.pac
	0x4EA750, // motion\pl000\pl000_00_5.pac
	0x4EA770, // motion\pl000\pl000_00_6.pac
	0x4EA790, // motion\pl000\pl000_00_7.pac
	0x4EA7B0, // motion\pl000\pl000_00_8.pac
	0x4EA7D0, // motion\pl000\pl000_00_9.pac
	0x4EA7F0, // motion\pl000\pl000_00_10.pac
	0x4EA810, // motion\pl000\pl000_00_11.pac
	0x4EA830, // motion\pl000\pl000_00_12.pac
	0x4EA850, // motion\pl000\pl000_00_13.pac
	0x4EA870, // motion\pl000\pl000_00_14.pac
	0x4EA890, // motion\pl000\pl000_00_15.pac
	0x4EA8B0, // motion\pl000\pl000_00_16.pac
	0x4EA8D0, // motion\pl000\pl000_00_17.pac
	0x4EA8F0, // motion\pl000\pl000_00_18.pac
	0x4EA910, // motion\pl000\pl000_00_19.pac
	0x4EA930, // motion\pl000\pl000_00_20.pac
	0x4EA950, // motion\pl000\pl000_00_21.pac
	0x4EA970, // motion\pl000\pl000_00_22.pac
	0x4EA990, // motion\pl000\pl000_00_23.pac
	0x4EA9B0, // motion\pl000\pl000_00_24.pac
	0x4EA9D0, // motion\pl000\pl000_00_25.pac
	0x4EA9F0, // motion\pl000\pl000_00_26.pac
	// Bob
	0x4EA5D0, // obj\pl001.pac
	0x4EB1A8, // obj\plwp_vergilsword.pac
	0x4EAAB0, // motion\pl001\pl001_00_0.pac
	0x4EAAD0, // motion\pl001\pl001_00_1.pac
	0x4EAAF0, // motion\pl001\pl001_00_2.pac
	0x4EAE90, // motion\pl001\pl001_00_31.pac
	// Lady
	0x4EA5E0, // obj\pl002.pac
	0x4EAFF0, // motion\pl002\pl002_00_0.pac
	0x4EB010, // motion\pl002\pl002_00_1.pac
	0x4EB030, // motion\pl002\pl002_00_2.pac
	// Vergil
	0x4EA5F0, // obj\pl021.pac
	0x4EA600, // obj\pl023.pac
	0x4EA610, // obj\pl026.pac
	0x4EA680, // obj\pl010.pac
	0x4EA690, // obj\pl014.pac
	0x4EA6A0, // obj\pl025.pac
	0x4EB158, // obj\plwp_newvergilsword.pac
	0x4EB1F8, // obj\plwp_newvergilfight.pac
	0x4EB190, // obj\plwp_forceedge.pac
	0x4EB218, // obj\plwp_nerosword.pac
	0x4EAEB0, // motion\pl021\pl021_00_0.pac
	0x4EAED0, // motion\pl021\pl021_00_1.pac
	0x4EAEF0, // motion\pl021\pl021_00_2.pac
	0x4EAF10, // motion\pl021\pl021_00_3.pac
	0x4EAF30, // motion\pl021\pl021_00_4.pac
	0x4EAF50, // motion\pl021\pl021_00_5.pac
	0x4EAF70, // motion\pl021\pl021_00_6.pac
	0x4EAF90, // motion\pl021\pl021_00_7.pac
	0x4EAFB0, // motion\pl021\pl021_00_8.pac
	0x4EAFD0, // motion\pl021\pl021_00_9.pac
};






















// @Todo: Add missing events.

enum EVENT_
{
	EVENT_GAME     = 1,
	EVENT_TELEPORT = 2,
};












enum GAMEPAD_
{
	GAMEPAD_VOID           = 0x0000,
	GAMEPAD_LEFT_TRIGGER   = 0x0001,
	GAMEPAD_RIGHT_TRIGGER  = 0x0002,
	GAMEPAD_LEFT_SHOULDER  = 0x0004,
	GAMEPAD_RIGHT_SHOULDER = 0x0008,
	GAMEPAD_Y              = 0x0010,
	GAMEPAD_B              = 0x0020,
	GAMEPAD_A              = 0x0040,
	GAMEPAD_X              = 0x0080,
	GAMEPAD_BACK           = 0x0100,
	GAMEPAD_LEFT_THUMB     = 0x0200,
	GAMEPAD_RIGHT_THUMB    = 0x0400,
	GAMEPAD_START          = 0x0800,
	// Direction ids are the same for dpad, left stick and right stick.
	GAMEPAD_UP             = 0x1000,
	GAMEPAD_RIGHT          = 0x2000,
	GAMEPAD_DOWN           = 0x4000,
	GAMEPAD_LEFT           = 0x8000,
};

// @Todo: Rename to Binding or Action.

enum CMD_
{
	CMD_VOID,
	CMD_ITEM_SCREEN,
	CMD_EQUIP_SCREEN,
	CMD_MAP_SCREEN,
	CMD_FILE_SCREEN,
	CMD_MELEE_ATTACK,
	CMD_JUMP,
	CMD_STYLE_ACTION,
	CMD_SHOOT,
	CMD_DEVIL_TRIGGER,
	CMD_CHANGE_GUN,
	CMD_CHANGE_TARGET,
	CMD_LOCK_ON,
	CMD_CHANGE_DEVIL_ARMS,
	CMD_DEFAULT_CAMERA,
	CMD_TAUNT,
	MAX_CMD,
};










// @Research: Change to MOTION_FILE and add single ids if necessary.

enum MOT_DANTE_
{
	MOT_DANTE_BASE,
	MOT_DANTE_DAMAGE,
	MOT_DANTE_TAUNTS,
	MOT_DANTE_REBELLION,
	MOT_DANTE_CERBERUS,
	MOT_DANTE_AGNI_RUDRA,
	MOT_DANTE_NEVAN,
	MOT_DANTE_BEOWULF,
	MOT_DANTE_EBONY_IVORY,
	MOT_DANTE_SHOTGUN,
	MOT_DANTE_ARTEMIS,
	MOT_DANTE_SPIRAL,
	MOT_DANTE_KALINA_ANN,
	MOT_DANTE_SWORDMASTER_REBELLION,
	MOT_DANTE_SWORDMASTER_CERBERUS,
	MOT_DANTE_SWORDMASTER_AGNI_RUDRA,
	MOT_DANTE_SWORDMASTER_NEVAN,
	MOT_DANTE_SWORDMASTER_BEOWULF,
	MOT_DANTE_GUNSLINGER_EBONY_IVORY,
	MOT_DANTE_GUNSLINGER_SHOTGUN,
	MOT_DANTE_GUNSLINGER_ARTEMIS,
	MOT_DANTE_GUNSLINGER_SPIRAL,
	MOT_DANTE_GUNSLINGER_KALINA_ANN,
	MOT_DANTE_TRICKSTER,
	MOT_DANTE_ROYALGUARD,
	MOT_DANTE_QUICKSILVER,
	MOT_DANTE_DOPPELGANGER,
	MAX_MOT_DANTE,
};

enum MOT_BOB_
{
	MOT_BOB_BASE,
	MOT_BOB_DAMAGE,
	MOT_BOB_TAUNTS,
	MOT_BOB_MELEE_STYLE = 31,
	MAX_MOT_BOB         = 4,
};









enum MOT_LADY_
{
	MOT_LADY_BASE,
	MOT_LADY_DAMAGE,
	MOT_LADY_TAUNTS,
	MOT_LADY_KALINA_ANN = 12,
	MAX_MOT_LADY        = 4,
};

enum MOT_VERGIL_
{
	MOT_VERGIL_BASE,
	MOT_VERGIL_DAMAGE,
	MOT_VERGIL_TAUNTS,
	MOT_VERGIL_YAMATO,
	MOT_VERGIL_BEOWULF,
	MOT_VERGIL_FORCE_EDGE,
	MOT_VERGIL_DARK_SLAYER,
	MOT_VERGIL_NERO_ANGELO_YAMATO,
	MOT_VERGIL_NERO_ANGELO_BEOWULF,
	MOT_VERGIL_NERO_ANGELO_FORCE_EDGE,
	MAX_MOT_VERGIL,
};

enum MOT_
{
	//MOT_DANTE  = MAX_MOT_DANTE,
	//MOT_BOB    = MAX_MOT_BOB,
	//MOT_LADY   = MAX_MOT_LADY,
	//MOT_VERGIL = MAX_MOT_VERGIL,
	MAX_MOT    = 32,
};
























enum WEAPON_ICON_SIDE_
{
	WEAPON_ICON_SIDE_LEFT,
	WEAPON_ICON_SIDE_RIGHT,
};

enum FILE_ITEM_STATUS_
{
	FILE_ITEM_READY = 3,
};

enum SPEED_DEVIL_
{
	SPEED_DEVIL_DANTE_REBELLION,
	SPEED_DEVIL_DANTE_CERBERUS,
	SPEED_DEVIL_DANTE_AGNI_RUDRA,
	SPEED_DEVIL_DANTE_NEVAN,
	SPEED_DEVIL_DANTE_BEOWULF,
	SPEED_DEVIL_DANTE_SPARDA,
	SPEED_DEVIL_VERGIL_YAMATO = 8,
	SPEED_DEVIL_VERGIL_BEOWULF,
	SPEED_DEVIL_VERGIL_FORCE_EDGE,
	SPEED_DEVIL_NERO_ANGELO_YAMATO,
	SPEED_DEVIL_NERO_ANGELO_BEOWULF,
	SPEED_DEVIL_NERO_ANGELO_FORCE_EDGE,
};

enum FILE_MODE_
{
	FILE_MODE_MEMORY,
	FILE_MODE_ARCHIVE,
	FILE_MODE_LOCAL,
};
























#define _Merge(a, b) a##b
#define Merge(a, b) _Merge(a, b)

#define _(size) struct { byte8 Merge(padding, __LINE__)[size]; }

#pragma pack(push, 1)

















// @Todo: Update types.

struct PS2_GAMEPAD
{
	uint32 ready;
	// @Todo: Add _.
	uint32 reserved[3];
	uint8  vibration[4];
	word   buttons[6];
	uint8  rightStickX;
	uint8  rightStickY;
	uint8  leftStickX;
	uint8  leftStickY;
	// @Todo: Add _.
	uint32 unknown[3];
	uint16 rightStickDirection[4];
	uint16 leftStickDirection[4];
	uint16 rightStickDirectionFast[2];
	uint16 leftStickDirectionFast[2];
	uint16 rightStickPosition;
	uint16 leftStickPosition;
	uint16 rightStickDifference;
	uint16 leftStickDifference;
};

// @Todo: Change to ENGINE_GAMEPAD.

struct CAPCOM_GAMEPAD
{
	word   buttons[4];
	uint16 buttonsTimer[2];
	uint16 rightStickDirection[4];
	uint16 rightStickTimer[2];
	uint16 rightStickPosition[2];
	uint16 leftStickDirection[4];
	uint16 leftStickTimer[2];
	uint16 leftStickPosition[2];
};















struct STRING_ITEM
{

	// @Todo: Add _(8);
	byte8 unknown[8];
	const char * string;
};

struct FILE_ITEM
{
	// @Todo: Same as above.

	uint32        category;
	uint32        status;
	uint16        id;
	byte8         padding[6];
	void        * callback;
	STRING_ITEM * stringItem;
	byte8       * file;
	byte8         unknown[32];
};






// @Todo: Specifiy and auto vars.

// EVENT_VARS
// LIVE_VARS
// CHAR_VARS
// ACTOR_VARS
// CAMERA_VARS

struct VARS
{
	bool     init;
	uint32 * room;
	uint32 * position;
	uint32 * event;
	uint16 * nextRoom;
	uint16 * nextPosition;
	byte32 * flags;
	uint32 * mission;
	VARS()
	{
		memset(this, 0, sizeof(*this));
		{
			byte8 ** addr = *(byte8 ***)(appBaseAddr + 0xCA8918); // EVENT_DATA
			if (!addr)
			{
				return;
			}
			if (!addr[8])
			{
				return;
			}
			room     = (uint32 *)(addr[8] + 0x18);
			position = (uint32 *)(addr[8] + 0x1C);
			event    = (uint32 *)(addr[8] + 0x20);
			if (!addr[12])
			{
				return;
			}
			nextRoom     = (uint16 *)(addr[12] + 0x164); // NEXT_EVENT_DATA
			nextPosition = (uint16 *)(addr[12] + 0x166);
		}
		{
			byte8 ** addr = *(byte8 ***)(appBaseAddr + 0xC90E30); // MISSION_DATA
			if (!addr)
			{
				return;
			}
			if (!addr[1])
			{
				return;
			}
			flags = (byte32 *)addr[1];
		}
		mission = (uint32 *)(appBaseAddr + 0xC8F250); // SESSION_DATA
		init = true;
	}
};

struct MEMORY_OBJECT
{
	byte8 * addr;
	byte8 * end;
	uint32 last;
	uint32 boundary;
	uint32 size;
	uint32 pipe;
	uint32 count;
	byte8 padding[4];
};
















struct MOTION_DATA
{
	uint8 index;
	uint8 group;
};









struct INPUT_DATA
{
	byte8 flags[8];
	float32 value;
};



















struct MODEL_DATA
{
	uint8 count;
	_(15);
	vec4 vertices[3];
	_(16);
};

struct DEVIL_SUBMODEL_DATA
{
	uint8 submodelIndex;
	uint8 devilModelOff;
	uint8 devilSubmodelIndex;
};

struct DEVIL_MODEL_DATA
{
	uint8 modelIndex;
	uint8 modelOff;
	DEVIL_SUBMODEL_DATA submodelData[2];
};










struct MODEL_FILE_HELPER
{
	struct Data
	{
		uint16 cacheFileId;
		uint8  fileIndex;
	};
	Data model;
	Data texture;
	Data shadow;
	Data physics;
};

typedef MODEL_FILE_HELPER DEVIL_MODEL_FILE_HELPER;






struct ACTOR_DATA
{
	_(120);
	uint8 characterLogic; // 0x78
	_(7);
	vec4 position; // 0x80
	_(48);
	uint16 direction; // 0xC0
	_(86);
	uint8 actorId; // 0x118
	_(3);
	bool isDoppelganger; // 0x11C
	_(3);
	uint8 visible; // 0x120
	_(14207);
	byte8 * motionFile[32]; // 0x38A0
	_(16);
	MOTION_DATA motionData[5]; // 0x39B0
	_(94);
	uint8 shadow; // 0x3A18
	_(15);
	byte32 color; // 0x3A28
	_(980);
	byte32 motionState1[4]; // 0x3E00
	_(10);
	uint16 chargedShotAir; // 0x3E1A
	_(6);
	uint16 chargedShot; // 0x3E22
	_(20);
	float32 idleTimer; // 0x3E38
	_(36);
	byte32 motionState2[3]; // 0x3E60
	uint8 activeModel; // 0x3E6C
	_(3);
	uint8 queuedModel; // 0x3E70
	_(3);
	uint32 modelIndex[3]; // 0x3E74
	uint8 modelState; // 0x3E80
	_(3);
	bool lockOn; // 0x3E84
	_(3);
	uint8 modelIndexMirror; // 0x3E88
	_(11);
	uint8 devilState; // 0x3E94
	_(6);
	bool devil; // 0x3E9B
	_(2);
	uint8 costume; // 0x3E9E
	bool specialCostume; // 0x3E9F
	_(24);
	float32 magicPoints; // 0x3EB8
	float32 maxMagicPoints; // 0x3EBC
	_(228);
	uint8 move; // 0x3FA4
	uint8 lastMove; // 0x3FA5
	_(6);
	uint8 chainCount; // 0x3FAC
	_(63);
	byte32 expertise[16]; // 0x3FEC
	_(192);
	float32 maxHitPoints; // 0x40EC
	_(44);
	float32 hitPoints; // 0x411C
	_(8712);
	byte8 * targetBaseAddr; // 0x6328
	_(8);
	uint8 style; // 0x6338
	_(31);
	uint8 styleLevel; // 0x6358
	_(3);
	uint8 dashCount; // 0x635C
	uint8 skyStarCount; // 0x635D
	uint8 airTrickCount; // 0x635E
	uint8 trickUpCount; // 0x635F
	uint8 trickDownCount; // 0x6360
	bool quicksilver; // 0x6361
	bool doppelganger; // 0x6362
	_(1);
	float32 styleExperience; // 0x6364
	_(236);
	bool controlLinkedActor; // 0x6454
	_(35);
	byte8 * linkedActorBaseAddr; // 0x6478
	_(8);
	uint8 selectedMeleeWeaponVergil; // 0x6488
	_(4);
	uint8 activeWeapon; // 0x648D
	_(2);
	uint8 selectedMeleeWeapon; // 0x6490
	_(3);
	uint8 selectedRangedWeapon; // 0x6494
	_(3);
	uint8 equipment[4]; // 0x6498
	_(4);
	byte8 * weaponMetadata[4]; // 0x64A0
	_(8);
	byte32 weaponFlags[4]; // 0x64C8
	_(24);
	uint8 activeMeleeWeapon; // 0x64F0
	uint8 activeRangedWeapon; // 0x64F1
	_(2);
	float32 weaponTimer[4]; // 0x64F4
	_(12);
	uint8 styleRank; // 0x6510
	_(3);
	float32 styleMeter; // 0x6514
	_(348);
	INPUT_DATA inputData[58]; // 0x6674
	_(2344);
	uint32 collisionIndex; // 0x7254
	_(520);
	vec4 interactionData[8]; // 0x7460
	byte16 buttonInput[4]; // 0x74E0
	_(16712);
	MODEL_DATA modelData[6]; // 0xB630
	_(88);
	float32 artemisChargeValue[2]; // 0xB868
	_(12);
	byte32 artemisChargeFlags[2]; // 0xB87C
	_(60);
	uint8 character; // 0xB8C0
	bool noCollision; // 0xB8C1
	_(6);
	byte8 * parentBaseAddr; // 0xB8C8
	byte8 * childBaseAddr[4]; // 0xB8D0
	bool hide; // 0xB8F0
	uint8 gamepad; // 0xB8F1
	byte16 buttonMask; // 0xB8F2
	byte16 leftStickMask; // 0xB8F4
	_(2);
	uint8 styleMap[6][2]; // 0xB8F8
	uint8 meleeWeaponCount; // 0xB904
	_(3);
	uint8 meleeWeaponMap[5]; // 0xB908
	uint8 rangedWeaponCount; // 0xB90D
	_(2);
	uint8 rangedWeaponMap[5]; // 0xB910
};










constexpr uint32 adsize = (uint32)sizeof(ACTOR_DATA);



#pragma pack(pop)

#undef _
#undef Merge
#undef _Merge



/*

INTERACTION_DATA


_(528);

vec4 force[8];

actorData.interactionData.force[3].x


actorData.forceData[3].x






*/



#pragma region Review

// @Research: Consider boss ids.

enum ROOM_
{
	ROOM_START_3             = 2,
	ROOM_START_4             = 100,
	ROOM_START_5             = 111,
	ROOM_START_7             = 127,
	ROOM_START_8             = 300,
	ROOM_START_9             = 201,
	ROOM_START_11            = 212,
	ROOM_START_12            = 217,
	ROOM_START_13            = 229,
	ROOM_START_16            = 106,
	ROOM_START_17            = 133,
	ROOM_START_18            = 400,
	ROOM_START_19            = 406,
	ROOM_CERBERUS            = 6,
	ROOM_GIGAPEDE            = 111,
	ROOM_JESTER_1            = 422,
	ROOM_AGNI_RUDRA          = 121,
	ROOM_VERGIL_1            = 144,
	ROOM_LEVIATHAN           = 302,
	ROOM_NEVAN               = 210,
	ROOM_BEOWULF             = 217,
	ROOM_JESTER_2            = 448,
	ROOM_GERYON              = 228,
	ROOM_VERGIL_2            = 234,
	ROOM_LADY                = 115,
	ROOM_JESTER_3            = 449,
	ROOM_DOPPELGANGER        = 139,
	ROOM_TAIZAI_REBORN       = 420,
	ROOM_CERBERUS_REBORN     = 412,
	ROOM_GIGAPEDE_REBORN     = 413,
	ROOM_AGNI_RUDRA_REBORN   = 414,
	ROOM_LEVIATHAN_REBORN    = 419,
	ROOM_NEVAN_REBORN        = 415,
	ROOM_BEOWULF_REBORN      = 416,
	ROOM_GERYON_REBORN       = 417,
	ROOM_DOPPELGANGER_REBORN = 418,
	ROOM_ARKHAM              = 421,
	ROOM_VERGIL_3            = 411,
};

enum POSITION_
{
	POSITION_CERBERUS            = 2,
	POSITION_GIGAPEDE            = 0,
	POSITION_JESTER_1            = 0,
	POSITION_AGNI_RUDRA          = 3,
	POSITION_VERGIL_1            = 0,
	POSITION_LEVIATHAN           = 0,
	POSITION_NEVAN               = 2,
	POSITION_BEOWULF             = 2,
	POSITION_JESTER_2            = 0,
	POSITION_GERYON_BRIDGE       = 0,
	POSITION_GERYON_GROUND       = 2,
	POSITION_VERGIL_2            = 0,
	POSITION_LADY                = 2,
	POSITION_JESTER_3            = 0,
	POSITION_DOPPELGANGER        = 0,
	POSITION_TAIZAI_REBORN       = 0,
	POSITION_CERBERUS_REBORN     = 0,
	POSITION_GIGAPEDE_REBORN     = 0,
	POSITION_AGNI_RUDRA_REBORN   = 0,
	POSITION_LEVIATHAN_REBORN    = 0,
	POSITION_NEVAN_REBORN        = 0,
	POSITION_BEOWULF_REBORN      = 0,
	POSITION_GERYON_REBORN       = 0,
	POSITION_DOPPELGANGER_REBORN = 0,
	POSITION_ARKHAM              = 0,
	POSITION_VERGIL_3            = 0,
};

#define TRACK_CERBERUS            "afs/sound/Boss_01.adx"
#define TRACK_GIGAPEDE            "afs/sound/T_Boss.adx"
#define TRACK_JESTER_1            "afs/sound/Jester.adx"
#define TRACK_AGNI_RUDRA          "afs/sound/Boss_02.adx"
#define TRACK_VERGIL_1            "afs/sound/Versil_01.adx"
#define TRACK_LEVIATHAN           "afs/sound/Boss_08.adx"
#define TRACK_NEVAN               "afs/sound/Boss_03.adx"
#define TRACK_BEOWULF             "afs/sound/Boss_04.adx"
#define TRACK_JESTER_2            "afs/sound/Jester.adx"
#define TRACK_GERYON              "afs/sound/Boss_05.adx"
#define TRACK_VERGIL_2            "afs/sound/Versil_02.adx"
#define TRACK_LADY                "afs/sound/Lady.adx"
#define TRACK_JESTER_3            "afs/sound/Jester.adx"
#define TRACK_DOPPELGANGER        "afs/sound/Boss_06.adx"
#define TRACK_TAIZAI_REBORN       "afs/sound/Battle_01B.adx"
#define TRACK_CERBERUS_REBORN     "afs/sound/Boss_01B.adx"
#define TRACK_GIGAPEDE_REBORN     "afs/sound/T_BossB.adx"
#define TRACK_AGNI_RUDRA_REBORN   "afs/sound/Boss_02B.adx"
#define TRACK_LEVIATHAN_REBORN    "afs/sound/Boss_08B.adx"
#define TRACK_NEVAN_REBORN        "afs/sound/Boss_03B.adx"
#define TRACK_BEOWULF_REBORN      "afs/sound/Boss_04B.adx"
#define TRACK_GERYON_REBORN       "afs/sound/Boss_05B.adx"
#define TRACK_DOPPELGANGER_REBORN "afs/sound/Boss_06B.adx"
#define TRACK_ARKHAM_1            "afs/sound/Hine_01.adx"
#define TRACK_ARKHAM_2            "afs/sound/Hine_02.adx"
#define TRACK_VERGIL_3            "afs/sound/Versil_03.adx"

enum DEVIL_FLUX_
{
	DEVIL_FLUX_START = 1,
	DEVIL_FLUX_END   = 2,
};










#pragma endregion







#define __DDMK_OBSOLETE__
#ifndef __DDMK_OBSOLETE__

enum MODEL_
{
	MODEL_BASE,
	MODEL_COAT,
	MODEL_WINGS,
	MAX_MODEL,
};

enum DEVIL_BOB_
{
	DEVIL_BOB_YAMATO = 1,
};

enum BODY_COUNT_
{
	BODY_COUNT_DANTE  = 7,
	BODY_COUNT_BOB    = 2,
	BODY_COUNT_LADY   = 1,
	BODY_COUNT_VERGIL = 4,
	MAX_BODY_COUNT    = 7,
};

enum MISSION_
{
	MAX_MISSION = 22,
};

enum COSTUME_BOB_
{
	COSTUME_BOB_DEFAULT,
	MAX_COSTUME_BOB,
};

enum COSTUME_LADY_
{
	COSTUME_LADY_DEFAULT,
	MAX_COSTUME_LADY,
};

enum COSTUME_COUNT_
{
	COSTUME_COUNT_DANTE  = MAX_COSTUME_DANTE,
	COSTUME_COUNT_BOB    = MAX_COSTUME_BOB,
	COSTUME_COUNT_LADY   = MAX_COSTUME_LADY,
	COSTUME_COUNT_VERGIL = MAX_COSTUME_VERGIL,
	MAX_COSTUME_COUNT    = MAX_COSTUME_DANTE,
};

enum WEAPON_COUNT_
{
	WEAPON_COUNT_DANTE  = 10,
	WEAPON_COUNT_BOB    = 1,
	WEAPON_COUNT_LADY   = 2,
	WEAPON_COUNT_VERGIL = 3,
};


struct MODEL_FILE_DATA_SINGLE
{
	uint16 cacheFileId;
	uint8 index;
};

struct MODEL_FILE_DATA
{
	MODEL_FILE_DATA_SINGLE modelFile  [MAX_MODEL];
	MODEL_FILE_DATA_SINGLE textureFile[MAX_MODEL];
	MODEL_FILE_DATA_SINGLE shadowFile [MAX_MODEL];
	MODEL_FILE_DATA_SINGLE physicsFile[MAX_MODEL];
};

enum Object_
{
	Object_Dante,
	Object_Lady,
	Object_Rebellion,
	Object_Rebellion2,
	Object_ForceEdgeDante,
	Object_Yamato,
	Object_ForceEdge,
	Object_NeroAngeloSword,
	Object_Count,
};



struct INPUT_BUFFER
{
	_(4);
	uint8 level;
	_(7);
};

struct CHARGE_DATA
{
	byte32 flags[2];
	float32 value;
};





#endif
