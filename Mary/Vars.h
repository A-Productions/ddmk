#pragma once
#include "../Core/DataTypes.h"

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
	CHAR_BOB,
	CHAR_LADY,
	CHAR_VERGIL,
	MAX_CHAR,
};

enum COSTUME_
{
	COSTUME_DANTE_DEFAULT,
	COSTUME_DANTE_DEFAULT_NO_COAT,
	COSTUME_DANTE_DEFAULT_TORN,
	COSTUME_DANTE_DMC1,
	COSTUME_DANTE_DMC1_NO_COAT,
	COSTUME_DANTE_SPARDA,
	COSTUME_DANTE_DEFAULT_TORN_INFINITE_MAGIC_POINTS,
	COSTUME_DANTE_SPARDA_INFINITE_MAGIC_POINTS,
	COSTUME_VERGIL_DEFAULT = 0,
	COSTUME_VERGIL_DEFAULT_NO_COAT,
	COSTUME_VERGIL_DEFAULT_INFINITE_MAGIC_POINTS,
	COSTUME_VERGIL_SPARDA,
	COSTUME_VERGIL_SPARDA_INFINITE_MAGIC_POINTS,
	MAX_COSTUME = 8,
};

enum DEVIL_
{
	DEVIL_DANTE_REBELLION,
	DEVIL_DANTE_CERBERUS,
	DEVIL_DANTE_AGNI_RUDRA,
	DEVIL_DANTE_NEVAN,
	DEVIL_DANTE_BEOWULF,
	DEVIL_DANTE_SPARDA,
	DEVIL_VERGIL_YAMATO,
	DEVIL_VERGIL_BEOWULF = 4,
	DEVIL_VERGIL_NERO_ANGELO = 6,
	MAX_DEVIL = 7,
};

enum STYLE_
{
	STYLE_DANTE_SWORDMASTER,
	STYLE_DANTE_GUNSLINGER,
	STYLE_DANTE_TRICKSTER,
	STYLE_DANTE_ROYALGUARD,
	STYLE_DANTE_QUICKSILVER,
	STYLE_DANTE_DOPPELGANGER,
	STYLE_VERGIL_DARK_SLAYER = 2,
	MAX_STYLE = 6,
};

enum WEAPON_
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
	WEAPON_BOB_YAMATO = 14,
	WEAPON_LADY_KALINA_ANN = 9,
	WEAPON_LADY_UNKNOWN = 11,
	WEAPON_VERGIL_YAMATO = 11,
	WEAPON_VERGIL_BEOWULF,
	WEAPON_VERGIL_FORCE_EDGE,
	WEAPON_VOID = 255,
	MAX_WEAPON = 16,
};

enum WEAPON_TYPE_
{
	WEAPON_TYPE_MELEE,
	WEAPON_TYPE_RANGED,
};

enum MOTION_GROUP_
{
	MOTION_GROUP_DANTE_BASE,
	MOTION_GROUP_DANTE_DAMAGE,
	MOTION_GROUP_DANTE_TAUNTS,
	MOTION_GROUP_DANTE_REBELLION,
	MOTION_GROUP_DANTE_CERBERUS,
	MOTION_GROUP_DANTE_AGNI_RUDRA,
	MOTION_GROUP_DANTE_NEVAN,
	MOTION_GROUP_DANTE_BEOWULF,
	MOTION_GROUP_DANTE_EBONY_IVORY,
	MOTION_GROUP_DANTE_SHOTGUN,
	MOTION_GROUP_DANTE_ARTEMIS,
	MOTION_GROUP_DANTE_SPIRAL,
	MOTION_GROUP_DANTE_KALINA_ANN,
	MOTION_GROUP_DANTE_SWORDMASTER_REBELLION,
	MOTION_GROUP_DANTE_SWORDMASTER_CERBERUS,
	MOTION_GROUP_DANTE_SWORDMASTER_AGNI_RUDRA,
	MOTION_GROUP_DANTE_SWORDMASTER_NEVAN,
	MOTION_GROUP_DANTE_SWORDMASTER_BEOWULF,
	MOTION_GROUP_DANTE_GUNSLINGER_EBONY_IVORY,
	MOTION_GROUP_DANTE_GUNSLINGER_SHOTGUN,
	MOTION_GROUP_DANTE_GUNSLINGER_ARTEMIS,
	MOTION_GROUP_DANTE_GUNSLINGER_SPIRAL,
	MOTION_GROUP_DANTE_GUNSLINGER_KALINA_ANN,
	MOTION_GROUP_DANTE_TRICKSTER,
	MOTION_GROUP_DANTE_ROYALGUARD,
	MOTION_GROUP_DANTE_QUICKSILVER,
	MOTION_GROUP_DANTE_DOPPELGANGER,
	MOTION_GROUP_BOB_BASE = 0,
	MOTION_GROUP_BOB_DAMAGE,
	MOTION_GROUP_BOB_TAUNTS,
	MOTION_GROUP_BOB_MELEE_STYLE = 31,
	MOTION_GROUP_LADY_BASE = 0,
	MOTION_GROUP_LADY_DAMAGE,
	MOTION_GROUP_LADY_TAUNTS,
	MOTION_GROUP_LADY_KALINA_ANN = 12,
	MOTION_GROUP_VERGIL_BASE = 0,
	MOTION_GROUP_VERGIL_DAMAGE,
	MOTION_GROUP_VERGIL_TAUNTS,
	MOTION_GROUP_VERGIL_YAMATO,
	MOTION_GROUP_VERGIL_BEOWULF,
	MOTION_GROUP_VERGIL_FORCE_EDGE,
	MOTION_GROUP_VERGIL_DARK_SLAYER,
	MOTION_GROUP_VERGIL_NERO_ANGELO_YAMATO,
	MOTION_GROUP_VERGIL_NERO_ANGELO_BEOWULF,
	MOTION_GROUP_VERGIL_NERO_ANGELO_FORCE_EDGE,
	MAX_MOTION_GROUP = 32,
};

enum NEXT_ACTION_REQUEST_POLICY
{
	NEXT_ACTION_REQUEST_POLICY_IGNORE,
	NEXT_ACTION_REQUEST_POLICY_BUFFER,
	NEXT_ACTION_REQUEST_POLICY_EXECUTE,
};




enum PERMISSION
{
	PERMISSION_DEFAULT = 1,
	PERMISSION_WALK_RUN = 2,
	PERMISSION_JUMP_ROLL = 8,
	PERMISSION_TARGET = 0x10,
	PERMISSION_RELEASE = 0x20,
	PERMISSION_INTERACTION_STYLE_ATTACK = 0x400,
};






enum STATE
{
	STATE_ON_FLOOR = 1,
	STATE_IN_AIR = 2,
	STATE_BUSY = 0x10000,
};


//enum MOTION_STATE
//{
//	MOTION_STATE_BUFFER = 1,
//	MOTION_STATE_EXECUTE = 2,
//	//MOTION_STATE_BUSY = 0x10000,
//
//	ALLOW_MOVE = 2,
//	ALLOW_JUMP = 8,
//
//
//
//
//	MOTION_STATE_FLOOR = 1,
//	MOTION_STATE_AIR = 2,
//	MOTION_STATE_ACTION = 0x10000,
//
//
//
//
//	//MOTION_STATE_CAN_INTERACT = 1,
//
//
//
//
//
//
//	//MOTION_STATE_BLOCK_ACTION = 0x10000,
//
//
//
//
//
//};

enum BODY_PART_
{
	BODY_PART_LOWER,
	BODY_PART_UPPER,
};

enum MODEL_PART_
{
	MODEL_PART_BASE,
	MODEL_PART_AMULET,
	MODEL_PART_COAT,
	MAX_MODEL_PART,
};

enum DEVIL_MODEL_PART_
{
	DEVIL_MODEL_PART_BASE,
	DEVIL_MODEL_PART_WINGS,
	DEVIL_MODEL_PART_COAT,
	MAX_DEVIL_MODEL_PART,
};

enum CACHE_FILE
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
	id100,
	id100V,
	demo_pl000_00_0,
	demo_pl000_00_1,
	demo_pl000_00_2,
	demo_pl000_00_3,
	demo_pl000_00_4,
	demo_pl000_00_5,
	demo_pl000_00_6,
	demo_pl000_00_7,
	demo_pl000_00_8,
	demo_pl000_00_9,
	demo_pl000_00_10,
	demo_pl000_00_11,
	demo_pl000_00_12,
	demo_pl000_00_13,
	demo_pl000_00_14,
	demo_pl000_00_15,
	demo_pl000_00_16,
	demo_pl000_00_17,
	demo_pl000_00_18,
	demo_pl000_00_19,
	demo_pl000_00_20,
	demo_pl000_00_21,
	demo_pl000_00_22,
	demo_pl000_00_23,
	demo_pl000_00_24,
	demo_pl000_00_25,
	demo_pl000_00_26,
	demo_pl000_00_27,
	demo_pl000_00_28,
	demo_pl000_00_29,
	demo_pl000_00_30,
	demo_pl000_00_31,
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
	"id100.pac",
	"id100V.pac",
	"demo_pl000_00_0.pac",
	"demo_pl000_00_1.pac",
	"demo_pl000_00_2.pac",
	"demo_pl000_00_3.pac",
	"demo_pl000_00_4.pac",
	"demo_pl000_00_5.pac",
	"demo_pl000_00_6.pac",
	"demo_pl000_00_7.pac",
	"demo_pl000_00_8.pac",
	"demo_pl000_00_9.pac",
	"demo_pl000_00_10.pac",
	"demo_pl000_00_11.pac",
	"demo_pl000_00_12.pac",
	"demo_pl000_00_13.pac",
	"demo_pl000_00_14.pac",
	"demo_pl000_00_15.pac",
	"demo_pl000_00_16.pac",
	"demo_pl000_00_17.pac",
	"demo_pl000_00_18.pac",
	"demo_pl000_00_19.pac",
	"demo_pl000_00_20.pac",
	"demo_pl000_00_21.pac",
	"demo_pl000_00_22.pac",
	"demo_pl000_00_23.pac",
	"demo_pl000_00_24.pac",
	"demo_pl000_00_25.pac",
	"demo_pl000_00_26.pac",
	"demo_pl000_00_27.pac",
	"demo_pl000_00_28.pac",
	"demo_pl000_00_29.pac",
	"demo_pl000_00_30.pac",
	"demo_pl000_00_31.pac",
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


enum LEFT_STICK
{
	LEFT_STICK_DEADZONE = 52,
};






enum BINDING
{
	BINDING_ITEM_SCREEN,
	BINDING_EQUIP_SCREEN,
	BINDING_MAP_SCREEN,
	BINDING_FILE_SCREEN,
	BINDING_MELEE_ATTACK,
	BINDING_JUMP,
	BINDING_STYLE_ACTION,
	BINDING_SHOOT,
	BINDING_DEVIL_TRIGGER,
	BINDING_CHANGE_GUN,
	BINDING_CHANGE_TARGET,
	BINDING_LOCK_ON,
	BINDING_CHANGE_DEVIL_ARMS,
	BINDING_DEFAULT_CAMERA,
	BINDING_TAUNT,
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






struct MotionHelper
{
	uint8 motionId;
	uint16 cacheFileId;
};

constexpr MotionHelper motionHelperDante[] =
{
	{ MOTION_GROUP_DANTE_BASE                  , pl000_00_0  },
	{ MOTION_GROUP_DANTE_DAMAGE                , pl000_00_1  },
	{ MOTION_GROUP_DANTE_TAUNTS                , pl000_00_2  },
	{ MOTION_GROUP_DANTE_REBELLION             , pl000_00_3  },
	{ MOTION_GROUP_DANTE_CERBERUS              , pl000_00_4  },
	{ MOTION_GROUP_DANTE_AGNI_RUDRA            , pl000_00_5  },
	{ MOTION_GROUP_DANTE_NEVAN                 , pl000_00_6  },
	{ MOTION_GROUP_DANTE_BEOWULF               , pl000_00_7  },
	{ MOTION_GROUP_DANTE_EBONY_IVORY           , pl000_00_8  },
	{ MOTION_GROUP_DANTE_SHOTGUN               , pl000_00_9  },
	{ MOTION_GROUP_DANTE_ARTEMIS               , pl000_00_10 },
	{ MOTION_GROUP_DANTE_SPIRAL                , pl000_00_11 },
	{ MOTION_GROUP_DANTE_KALINA_ANN            , pl000_00_12 },
	{ MOTION_GROUP_DANTE_SWORDMASTER_REBELLION , pl000_00_13 },
	{ MOTION_GROUP_DANTE_SWORDMASTER_CERBERUS  , pl000_00_14 },
	{ MOTION_GROUP_DANTE_SWORDMASTER_AGNI_RUDRA, pl000_00_15 },
	{ MOTION_GROUP_DANTE_SWORDMASTER_NEVAN     , pl000_00_16 },
	{ MOTION_GROUP_DANTE_SWORDMASTER_BEOWULF   , pl000_00_17 },
	{ MOTION_GROUP_DANTE_GUNSLINGER_EBONY_IVORY, pl000_00_18 },
	{ MOTION_GROUP_DANTE_GUNSLINGER_SHOTGUN    , pl000_00_19 },
	{ MOTION_GROUP_DANTE_GUNSLINGER_ARTEMIS    , pl000_00_20 },
	{ MOTION_GROUP_DANTE_GUNSLINGER_SPIRAL     , pl000_00_21 },
	{ MOTION_GROUP_DANTE_GUNSLINGER_KALINA_ANN , pl000_00_22 },
	{ MOTION_GROUP_DANTE_TRICKSTER             , pl000_00_23 },
	{ MOTION_GROUP_DANTE_ROYALGUARD            , pl000_00_24 },
	{ MOTION_GROUP_DANTE_QUICKSILVER           , pl000_00_25 },
	{ MOTION_GROUP_DANTE_DOPPELGANGER          , pl000_00_26 },
};

constexpr MotionHelper motionHelperBob[] =
{
	{ MOTION_GROUP_BOB_BASE       , pl001_00_0  },
	{ MOTION_GROUP_BOB_DAMAGE     , pl001_00_1  },
	{ MOTION_GROUP_BOB_TAUNTS     , pl001_00_2  },
	{ MOTION_GROUP_BOB_MELEE_STYLE, pl001_00_31 },
};

constexpr MotionHelper motionHelperLady[] =
{
	{ MOTION_GROUP_LADY_BASE      , pl002_00_0  },
	{ MOTION_GROUP_LADY_DAMAGE    , pl002_00_1  },
	{ MOTION_GROUP_LADY_TAUNTS    , pl002_00_2  },
	{ MOTION_GROUP_LADY_KALINA_ANN, pl000_00_12 },
};

constexpr MotionHelper motionHelperVergil[] =
{
	{ MOTION_GROUP_VERGIL_BASE                  , pl021_00_0 },
	{ MOTION_GROUP_VERGIL_DAMAGE                , pl021_00_1 },
	{ MOTION_GROUP_VERGIL_TAUNTS                , pl021_00_2 },
	{ MOTION_GROUP_VERGIL_YAMATO                , pl021_00_3 },
	{ MOTION_GROUP_VERGIL_BEOWULF               , pl021_00_4 },
	{ MOTION_GROUP_VERGIL_FORCE_EDGE            , pl021_00_5 },
	{ MOTION_GROUP_VERGIL_DARK_SLAYER           , pl021_00_6 },
	{ MOTION_GROUP_VERGIL_NERO_ANGELO_YAMATO    , pl021_00_7 },
	{ MOTION_GROUP_VERGIL_NERO_ANGELO_BEOWULF   , pl021_00_8 },
	{ MOTION_GROUP_VERGIL_NERO_ANGELO_FORCE_EDGE, pl021_00_9 },
};

















#define _Merge(a, b) a##b
#define Merge(a, b) _Merge(a, b)

#define _(size) struct { byte8 Merge(padding, __LINE__)[size]; }

#pragma pack(push, 1)




struct STRING_ITEM
{
	_(8);
	const char * string;
};

struct FILE_ITEM
{
	uint32        category;
	uint32        status;
	uint16        id;
	_(6);
	void        * callback;
	STRING_ITEM * stringItem;
	byte8       * file;
	_(32);
};


struct FileItemHelper
{
	uint16 fileItemId;
	uint16 cacheFileId;
};

// @Todo: Add motion items.
constexpr FileItemHelper fileItemHelper[] =
{
	// Dante
	{ 0  , pl000               },
	{ 200, pl005               },
	{ 201, pl006               },
	{ 202, pl007               },
	{ 203, pl008               },
	{ 204, pl009               },
	{ 205, pl017               },
	{ 140, plwp_sword          },
	{ 141, plwp_nunchaku       },
	{ 142, plwp_2sword         },
	{ 143, plwp_guitar         },
	{ 144, plwp_fight          },
	{ 145, plwp_gun            },
	{ 146, plwp_shotgun        },
	{ 147, plwp_laser          },
	{ 148, plwp_rifle          },
	{ 149, plwp_ladygun        },
	// Bob
	{ 1  , pl001               },
	{ 207, pl010               },
	{ 169, plwp_vergilsword    },
	// Lady
	{ 2  , pl002               },
	// Vergil
	{ 3  , pl021               },
	{ 221, pl010               },
	{ 222, pl014               },
	{ 223, pl025               },
	{ 196, plwp_newvergilsword },
	{ 189, plwp_newvergilfight },
	{ 198, plwp_forceedge      },
	{ 187, plwp_nerosword      },
};





















// @Todo: Update types.

struct PS2_GAMEPAD
{
	uint32 ready;
	// @Todo: Add _.
	uint32 reserved[3];
	uint8  vibration[4];
	byte16   buttons[6];
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
	byte16   buttons[4];
	uint16 buttonsTimer[2];
	uint16 rightStickDirection[4];
	uint16 rightStickTimer[2];
	uint16 rightStickPosition[2];
	uint16 leftStickDirection[4];
	uint16 leftStickTimer[2];
	uint16 leftStickPosition[2];
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












// @Todo: Add MODEL_DATA for 0x780.






struct MODEL_METADATA
{
	uint8 count;
	_(15);
	vec4 vertices[3];
	_(16);
};

//
//struct DEVIL_MODEL_METADATA_DANTE_REBELLION : DEVIL_MODEL_METADATA
//{
//	DEVIL_SUBMODEL_METADATA submodelMetadata[2];
//};
//
//struct DEVIL_MODEL_METADATA_DANTE_CERBERUS : DEVIL_MODEL_METADATA
//{
//	DEVIL_SUBMODEL_METADATA submodelMetadata;
//};


struct DEVIL_MODEL_METADATA;
struct DEVIL_SUBMODEL_METADATA;
struct DEVIL_MODEL_METADATA_ONE;
struct DEVIL_MODEL_METADATA_TWO;

struct DEVIL_MODEL_METADATA
{
	uint8 modelIndex;
	uint8 modelOff;

	operator DEVIL_MODEL_METADATA_TWO &()
	{
		return *(DEVIL_MODEL_METADATA_TWO *)this;
	}
};

struct DEVIL_SUBMODEL_METADATA
{
	uint8 submodelIndex;
	uint8 devilModelOff;
	uint8 devilSubmodelIndex;
};

struct DEVIL_MODEL_METADATA_ONE : DEVIL_MODEL_METADATA
{
	DEVIL_SUBMODEL_METADATA submodelMetadata[1];
};

struct DEVIL_MODEL_METADATA_TWO : DEVIL_MODEL_METADATA
{
	DEVIL_SUBMODEL_METADATA submodelMetadata[2];
};

struct DEVIL_MODEL_METADATA_DANTE
{
	DEVIL_MODEL_METADATA_TWO rebellion;
	DEVIL_MODEL_METADATA_ONE cerberus;
	DEVIL_MODEL_METADATA agniRudra;
	DEVIL_MODEL_METADATA_TWO nevan;
	DEVIL_MODEL_METADATA_ONE beowulf;
	DEVIL_MODEL_METADATA_ONE sparda;

	DEVIL_MODEL_METADATA_TWO & operator[](uint8 index)
	{
		switch (index)
		{
		case DEVIL_DANTE_REBELLION:
			return rebellion;
		case DEVIL_DANTE_CERBERUS:
			return cerberus;
		case DEVIL_DANTE_AGNI_RUDRA:
			return agniRudra;
		case DEVIL_DANTE_NEVAN:
			return nevan;
		case DEVIL_DANTE_BEOWULF:
			return beowulf;
		case DEVIL_DANTE_SPARDA:
			return sparda;
		}
	}
};

constexpr uint32 devilModelMetadataDanteSize = (uint32)sizeof(DEVIL_MODEL_METADATA_DANTE);








































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






//struct MODEL_DATA
//{
//	_(1364);
//	float32 motionDuration1[2];
//	_(56);
//	float32 motionDuration2[2];
//	_(280);
//	float32 motionTimer[2];
//	_(196);
//};


struct MODEL_DATA
{
	_(1280);
	struct
	{
		_(84);
		float32 duration1[2];
		_(56);
		float32 duration2[2];
		_(280);
		float32 timer[2];
		_(196);
	}
	motion;
};

static_assert(offsetof(MODEL_DATA, motion.duration1) == 0x554);
static_assert(offsetof(MODEL_DATA, motion.duration2) == 0x594);
static_assert(offsetof(MODEL_DATA, motion.timer) == 0x6B4);
static_assert(sizeof(MODEL_DATA) == 0x780);





//constexpr uint32 g_off = offsetof(ACTOR_DATA_DANTE, motionData);

























//constexpr auto g_danteOff = offsetof(ACTOR_DATA_DANTE, cloneBaseAddr);




















//constexpr uint32 baseSize = (uint32)sizeof(ACTOR_DATA_BASE);
//constexpr uint32 voidSize = (uint32)sizeof(ACTOR_DATA_CHAR_VOID);






//constexpr uint32 adsizeDante = (uint32)sizeof(ACTOR_DATA_DANTE);
//constexpr uint32 adsizeVergil = (uint32)sizeof(ACTOR_DATA_VERGIL);



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


enum ACTOR_
{
	ACTOR_ONE,
	ACTOR_TWO,
	ACTOR_THREE,
	ACTOR_FOUR,
	MAX_ACTOR,
};










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
	Object_NeroAngeloSbyte16,
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

enum STYLE_
{
	MAX_STYLE = 6,
};

// @Research: Use native instead of logic.

enum NATIVE_STYLE_DANTE_
{
	NATIVE_STYLE_DANTE_Sbyte16MASTER,
	NATIVE_STYLE_DANTE_GUNSLINGER,
	NATIVE_STYLE_DANTE_TRICKSTER,
	NATIVE_STYLE_DANTE_ROYALGUARD,
	NATIVE_STYLE_DANTE_QUICKSILVER,
	NATIVE_STYLE_DANTE_DOPPELGANGER,
	MAX_NATIVE_STYLE_DANTE,
};

enum NATIVE_STYLE_VERGIL_
{
	NATIVE_STYLE_VERGIL_DARK_SLAYER = 2,
	MAX_NATIVE_STYLE_VERGIL = 1,
};






enum NATIVE_WEAPON_DANTE_
{
	NATIVE_WEAPON_DANTE_REBELLION,
	NATIVE_WEAPON_DANTE_CERBERUS,
	NATIVE_WEAPON_DANTE_AGNI_RUDRA,
	NATIVE_WEAPON_DANTE_NEVAN,
	NATIVE_WEAPON_DANTE_BEOWULF,
	NATIVE_WEAPON_DANTE_EBONY_IVORY,
	NATIVE_WEAPON_DANTE_SHOTGUN,
	NATIVE_WEAPON_DANTE_ARTEMIS,
	NATIVE_WEAPON_DANTE_SPIRAL,
	NATIVE_WEAPON_DANTE_KALINA_ANN,
	MAX_NATIVE_WEAPON_DANTE,
};

enum NATIVE_WEAPON_VERGIL_
{
	NATIVE_WEAPON_VERGIL_YAMATO = 11,
	NATIVE_WEAPON_VERGIL_BEOWULF,
	NATIVE_WEAPON_VERGIL_FORCE_EDGE,
	MAX_NATIVE_WEAPON_VERGIL = 3,
};
































































enum WEAPON_
{
	MAX_WEAPON = 16,
	WEAPON_VOID = 255,
};





















// NATIVE_COSTUME_DANTE_
// MAX_NATIVE_COSTUME_DANTE


// original
// native
// logic
// prime








enum DEVIL_VERGIL_
{
	DEVIL_VERGIL_YAMATO,
	DEVIL_VERGIL_BEOWULF = 4,
	DEVIL_VERGIL_NERO_ANGELO = 6,
	MAX_DEVIL_VERGIL,
};





constexpr uint8 costumeMapDante[MAX_COSTUME_DANTE] =
{
	NATIVE_COSTUME_DANTE_DEFAULT,
	NATIVE_COSTUME_DANTE_DEFAULT_NO_COAT,
	NATIVE_COSTUME_DANTE_DEFAULT_TORN,
	NATIVE_COSTUME_DANTE_DMC1,
	NATIVE_COSTUME_DANTE_DMC1_NO_COAT,
	NATIVE_COSTUME_DANTE_SPARDA,
};

constexpr uint8 costumeMapVergil[MAX_COSTUME_VERGIL] =
{
	NATIVE_COSTUME_VERGIL_DEFAULT,
	NATIVE_COSTUME_VERGIL_DEFAULT_NO_COAT,
	NATIVE_COSTUME_VERGIL_SPARDA,
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




enum COSTUME_VERGIL_
{
	COSTUME_VERGIL_DEFAULT,
	COSTUME_VERGIL_DEFAULT_NO_COAT,
	COSTUME_VERGIL_DEFAULT_INFINITE_MAGIC_POINTS,
	COSTUME_VERGIL_SPARDA,
	COSTUME_VERGIL_SPARDA_INFINITE_MAGIC_POINTS,
	MAX_COSTUME_VERGIL,
};




enum NATIVE_STYLE_VERGIL_
{
	NATIVE_STYLE_VERGIL_DARK_SLAYER = 2,
	MAX_NATIVE_STYLE_VERGIL = 1,
};

enum STYLE_VERGIL_
{
	STYLE_VERGIL_DARK_SLAYER,
	STYLE_VERGIL_ROYALGUARD,
	MAX_STYLE_VERGIL,
};











enum STYLE_
{
	STYLE_DANTE_Sbyte16MASTER,
	STYLE_DANTE_GUNSLINGER,
	STYLE_DANTE_TRICKSTER,
	STYLE_DANTE_ROYALGUARD,
	STYLE_DANTE_QUICKSILVER,
	STYLE_DANTE_DOPPELGANGER,
	STYLE_VERGIL_DARK_SLAYER = 2,
	MAX_STYLE = 6,
};












enum WEAPON_
{
	WEAPON_VOID = 255,
};

enum NATIVE_MELEE_WEAPON_DANTE_
{
	NATIVE_MELEE_WEAPON_DANTE_REBELLION,
	NATIVE_MELEE_WEAPON_DANTE_CERBERUS,
	NATIVE_MELEE_WEAPON_DANTE_AGNI_RUDRA,
	NATIVE_MELEE_WEAPON_DANTE_NEVAN,
	NATIVE_MELEE_WEAPON_DANTE_BEOWULF,
	MAX_NATIVE_MELEE_WEAPON_DANTE,
};

enum NATIVE_RANGED_WEAPON_DANTE_
{
	NATIVE_RANGED_WEAPON_DANTE_EBONY_IVORY = 5,
	NATIVE_RANGED_WEAPON_DANTE_SHOTGUN,
	NATIVE_RANGED_WEAPON_DANTE_ARTEMIS,
	NATIVE_RANGED_WEAPON_DANTE_SPIRAL,
	NATIVE_RANGED_WEAPON_DANTE_KALINA_ANN,
	MAX_NATIVE_RANGED_WEAPON_DANTE = 5,
};

enum MELEE_WEAPON_DANTE_
{
	MELEE_WEAPON_DANTE_REBELLION,
	MELEE_WEAPON_DANTE_CERBERUS,
	MELEE_WEAPON_DANTE_AGNI_RUDRA,
	MELEE_WEAPON_DANTE_NEVAN,
	MELEE_WEAPON_DANTE_BEOWULF,
	MELEE_WEAPON_DANTE_YAMATO,
	MAX_MELEE_WEAPON_DANTE,
};

enum RANGED_WEAPON_DANTE_
{
	RANGED_WEAPON_DANTE_EBONY_IVORY,
	RANGED_WEAPON_DANTE_SHOTGUN,
	RANGED_WEAPON_DANTE_ARTEMIS,
	RANGED_WEAPON_DANTE_SPIRAL,
	RANGED_WEAPON_DANTE_KALINA_ANN,
	RANGED_WEAPON_DANTE_SUMMONED_Sbyte16S,
	MAX_RANGED_WEAPON_DANTE,
};

constexpr uint8 rangedWeaponMapDante[MAX_RANGED_WEAPON_DANTE] =
{
	NATIVE_RANGED_WEAPON_DANTE_EBONY_IVORY,
	NATIVE_RANGED_WEAPON_DANTE_SHOTGUN,
	NATIVE_RANGED_WEAPON_DANTE_ARTEMIS,
	NATIVE_RANGED_WEAPON_DANTE_SPIRAL,
	NATIVE_RANGED_WEAPON_DANTE_KALINA_ANN,
	WEAPON_VOID,
};

enum NATIVE_MELEE_WEAPON_VERGIL_
{
	NATIVE_MELEE_WEAPON_VERGIL_YAMATO = 11,
	NATIVE_MELEE_WEAPON_VERGIL_BEOWULF,
	NATIVE_MELEE_WEAPON_VERGIL_FORCE_EDGE,
	MAX_NATIVE_MELEE_WEAPON_VERGIL = 3,
};

enum MELEE_WEAPON_VERGIL_
{
	MELEE_WEAPON_VERGIL_YAMATO,
	MELEE_WEAPON_VERGIL_BEOWULF,
	MELEE_WEAPON_VERGIL_FORCE_EDGE,
	MAX_MELEE_WEAPON_VERGIL,
};




enum NEW_MELEE_WEAPON_VERGIL_
{
	NEW_MELEE_WEAPON_VERGIL_YAMATO = 11,
	NEW_MELEE_WEAPON_VERGIL_BEOWULF,
	NEW_MELEE_WEAPON_VERGIL_FORCE_EDGE,
	//MAX_NEW_MELEE_WEAPON_VERGIL = 3,
};










//enum MOTION_GROUP_BOB_
//{
//	MOTION_GROUP_BOB_BASE,
//	MOTION_GROUP_BOB_DAMAGE,
//	MOTION_GROUP_BOB_TAUNTS,
//	MOTION_GROUP_BOB_MELEE_STYLE = 31,
//	MAX_MOTION_GROUP_BOB         = 4,
//};
//
//
//
//
//
//
//
//
//
//enum MOTION_GROUP_LADY_
//{
//	MOTION_GROUP_LADY_BASE,
//	MOTION_GROUP_LADY_DAMAGE,
//	MOTION_GROUP_LADY_TAUNTS,
//	MOTION_GROUP_LADY_KALINA_ANN = 12,
//	MAX_MOTION_GROUP_LADY        = 4,
//};

enum MOTION_GROUP_VERGIL_
{
	MOTION_GROUP_VERGIL_BASE,
	MOTION_GROUP_VERGIL_DAMAGE,
	MOTION_GROUP_VERGIL_TAUNTS,
	MOTION_GROUP_VERGIL_YAMATO,
	MOTION_GROUP_VERGIL_BEOWULF,
	MOTION_GROUP_VERGIL_FORCE_EDGE,
	MOTION_GROUP_VERGIL_DARK_SLAYER,
	MOTION_GROUP_VERGIL_NERO_ANGELO_YAMATO,
	MOTION_GROUP_VERGIL_NERO_ANGELO_BEOWULF,
	MOTION_GROUP_VERGIL_NERO_ANGELO_FORCE_EDGE,
	MAX_MOTION_GROUP_VERGIL,
};

enum MOTION_GROUP_
{
	//MOTION_GROUP_DANTE  = MAX_MOTION_GROUP_DANTE,
	//MOTION_GROUP_BOB    = MAX_MOTION_GROUP_BOB,
	//MOTION_GROUP_LADY   = MAX_MOTION_GROUP_LADY,
	//MOTION_GROUP_VERGIL = MAX_MOTION_GROUP_VERGIL,
	MAX_MOT    = 32,
};
















#endif
