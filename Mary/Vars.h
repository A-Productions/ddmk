#pragma once
#include "../Core/DataTypes.h"











enum PLAYER
{
	MAX_PLAYER = 4,
};





enum ENTITY
{
	ENTITY_MAIN,
	ENTITY_CLONE,
	MAX_ENTITY,
};


enum WEAPON_STATUS
{
	WEAPON_STATUS_READY,
	WEAPON_STATUS_ACTIVE,
	WEAPON_STATUS_RETURN,
	WEAPON_STATUS_END,
	WEAPON_STATUS_DISABLED,
};



//
//enum GAMEPAD
//{
//	MAX_GAMEPAD = 4,
//};
//



enum ACTOR
{
	MAX_ACTOR = 4
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
	CHAR_BOB,
	CHAR_LADY,
	CHAR_VERGIL,
	CHAR_VOID = 255,
	MAX_CHAR = 4,
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
	MAX_COSTUME_DANTE = 8,
	MAX_COSTUME_VERGIL = 5,
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
	MAX_MELEE_WEAPON = 5,
	MAX_RANGED_WEAPON = 5,
	MAX_MELEE_WEAPON_DANTE = 5,
	MAX_RANGED_WEAPON_DANTE = 5,
	MAX_MELEE_WEAPON_VERGIL = 3,
};

// $ActorDataStart
// $ActorDataEnd

//constexpr const char * enum_WEAPON_DANTE_REBELLION = "WEAPON_DANTE_REBELLION";
//constexpr const char * enum_WEAPON_DANTE_CERBERUS = "WEAPON_DANTE_CERBERUS";
//constexpr const char * enum_WEAPON_DANTE_AGNI_RUDRA = "WEAPON_DANTE_AGNI_RUDRA";
//constexpr const char * enum_WEAPON_DANTE_NEVAN = "WEAPON_DANTE_NEVAN";
//constexpr const char * enum_WEAPON_DANTE_BEOWULF = "WEAPON_DANTE_BEOWULF";
//constexpr const char * enum_WEAPON_DANTE_EBONY_IVORY = "WEAPON_DANTE_EBONY_IVORY";
//constexpr const char * enum_WEAPON_DANTE_SHOTGUN = "WEAPON_DANTE_SHOTGUN";
//constexpr const char * enum_WEAPON_DANTE_ARTEMIS = "WEAPON_DANTE_ARTEMIS";
//constexpr const char * enum_WEAPON_DANTE_SPIRAL = "WEAPON_DANTE_SPIRAL";
//constexpr const char * enum_WEAPON_DANTE_KALINA_ANN = "WEAPON_DANTE_KALINA_ANN";
//constexpr const char * enum_WEAPON_BOB_YAMATO = "WEAPON_BOB_YAMATO";
//constexpr const char * enum_WEAPON_LADY_KALINA_ANN = "WEAPON_LADY_KALINA_ANN";
//constexpr const char * enum_WEAPON_LADY_UNKNOWN = "WEAPON_LADY_UNKNOWN";
//constexpr const char * enum_WEAPON_VERGIL_YAMATO = "WEAPON_VERGIL_YAMATO";
//constexpr const char * enum_WEAPON_VERGIL_BEOWULF = "WEAPON_VERGIL_BEOWULF";
//constexpr const char * enum_WEAPON_VERGIL_FORCE_EDGE = "WEAPON_VERGIL_FORCE_EDGE";
//constexpr const char * enum_WEAPON_VOID = "WEAPON_VOID";
//constexpr const char * enum_MAX_WEAPON = "MAX_WEAPON";
//constexpr const char * enum_MAX_MELEE_WEAPON_DANTE = "MAX_MELEE_WEAPON_DANTE";
//constexpr const char * enum_MAX_RANGED_WEAPON_DANTE = "MAX_RANGED_WEAPON_DANTE";
//constexpr const char * enum_MAX_MELEE_WEAPON_VERGIL = "MAX_MELEE_WEAPON_VERGIL";
//
//
//
//
//
//#ifndef enum_name
//#define enum_name(var) enum_##var
//#endif
//
//constexpr const char * enum_greatness = enum_name(WEAPON_DANTE_AGNI_RUDRA);
//
//// Enums.h
//// EnumNames.h






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

// @Todo: Check Vergil.

enum NEXT_ACTION_REQUEST_POLICY
{
	NEXT_ACTION_REQUEST_POLICY_IGNORE,
	NEXT_ACTION_REQUEST_POLICY_BUFFER,
	NEXT_ACTION_REQUEST_POLICY_EXECUTE,
	// Indices
	NEXT_ACTION_REQUEST_POLICY_MELEE_ATTACK = 0,
	NEXT_ACTION_REQUEST_POLICY_SWORDMASTER_GUNSLINGER = 4,
	NEXT_ACTION_REQUEST_POLICY_JUMP_ROLL = 5,
	NEXT_ACTION_REQUEST_POLICY_ROYALGUARD = 6,
	NEXT_ACTION_REQUEST_POLICY_TRICKSTER_DARK_SLAYER = 8,
	NEXT_ACTION_REQUEST_POLICY_RANGED_ATTACK = 10,
	NEXT_ACTION_REQUEST_POLICY_END = 15,
};














enum ACTION
{
	ACTION_DANTE_REBELLION_COMBO_1_PART_1 = 1,
	ACTION_DANTE_REBELLION_COMBO_1_PART_2,
	ACTION_DANTE_REBELLION_COMBO_1_PART_3,
	ACTION_DANTE_REBELLION_COMBO_2_PART_2,
	ACTION_DANTE_REBELLION_COMBO_2_PART_3,
	ACTION_DANTE_REBELLION_HELM_BREAKER,
	ACTION_DANTE_REBELLION_STINGER_LEVEL_1,
	ACTION_DANTE_REBELLION_STINGER_LEVEL_2,
	ACTION_DANTE_REBELLION_LEAP,
	ACTION_DANTE_REBELLION_HIGH_TIME,
	ACTION_DANTE_REBELLION_HIGH_TIME_LAUNCH,
	ACTION_DANTE_REBELLION_KICK_1,
	ACTION_DANTE_REBELLION_DRIVE_1,
	ACTION_DANTE_REBELLION_MILLION_STAB,
	ACTION_DANTE_REBELLION_SWORD_PIERCE,
	ACTION_DANTE_REBELLION_PROP_SHREDDER_1,
	ACTION_DANTE_REBELLION_DIVEKICK,
	ACTION_DANTE_REBELLION_KICK_2,
	ACTION_DANTE_REBELLION_AERIAL_RAVE_PART_1,
	ACTION_DANTE_REBELLION_AERIAL_RAVE_PART_2,
	ACTION_DANTE_REBELLION_AERIAL_RAVE_PART_3,
	ACTION_DANTE_REBELLION_AERIAL_RAVE_PART_4,
	ACTION_DANTE_REBELLION_SWORD_PIERCE_RETURN,
	ACTION_DANTE_REBELLION_PROP_SHREDDER_2,
	ACTION_DANTE_REBELLION_DRIVE_2,
	ACTION_DANTE_CERBERUS_COMBO_1_PART_1 = 30,
	ACTION_DANTE_CERBERUS_COMBO_1_PART_2,
	ACTION_DANTE_CERBERUS_COMBO_1_PART_3,
	ACTION_DANTE_CERBERUS_COMBO_1_PART_4,
	ACTION_DANTE_CERBERUS_COMBO_1_PART_5,
	ACTION_DANTE_CERBERUS_COMBO_2_PART_3,
	ACTION_DANTE_CERBERUS_COMBO_2_PART_4,
	ACTION_DANTE_CERBERUS_WINDMILL,
	ACTION_DANTE_CERBERUS_REVOLVER_LEVEL_1,
	ACTION_DANTE_CERBERUS_REVOLVER_LEVEL_2,
	ACTION_DANTE_CERBERUS_SWING,
	ACTION_DANTE_CERBERUS_SATELLITE,
	ACTION_DANTE_CERBERUS_FLICKER,
	ACTION_DANTE_CERBERUS_AIR_FLICKER,
	ACTION_DANTE_CERBERUS_CRYSTAL,
	ACTION_DANTE_CERBERUS_MILLION_CARATS,
	ACTION_DANTE_CERBERUS_ICE_AGE,
	ACTION_DANTE_AGNI_RUDRA_COMBO_1_PART_1 = 50,
	ACTION_DANTE_AGNI_RUDRA_COMBO_1_PART_2,
	ACTION_DANTE_AGNI_RUDRA_COMBO_1_PART_3,
	ACTION_DANTE_AGNI_RUDRA_COMBO_1_PART_4,
	ACTION_DANTE_AGNI_RUDRA_COMBO_1_PART_5,
	ACTION_DANTE_AGNI_RUDRA_COMBO_2_PART_2,
	ACTION_DANTE_AGNI_RUDRA_COMBO_2_PART_3,
	ACTION_DANTE_AGNI_RUDRA_COMBO_3_PART_3,
	ACTION_DANTE_AGNI_RUDRA_JET_STREAM_LEVEL_1,
	ACTION_DANTE_AGNI_RUDRA_JET_STREAM_LEVEL_2,
	ACTION_DANTE_AGNI_RUDRA_JET_STREAM_LEVEL_3,
	ACTION_DANTE_AGNI_RUDRA_AERIAL_CROSS,
	ACTION_DANTE_AGNI_RUDRA_WHIRLWIND,
	ACTION_DANTE_AGNI_RUDRA_WHIRLWIND_LAUNCH,
	ACTION_DANTE_AGNI_RUDRA_MILLION_SLASH,
	ACTION_DANTE_AGNI_RUDRA_CROSSED_SWORDS,
	ACTION_DANTE_AGNI_RUDRA_CRAWLER,
	ACTION_DANTE_AGNI_RUDRA_TWISTER,
	ACTION_DANTE_AGNI_RUDRA_SKY_DANCE_PART_1,
	ACTION_DANTE_AGNI_RUDRA_SKY_DANCE_PART_2,
	ACTION_DANTE_AGNI_RUDRA_SKY_DANCE_PART_3,
	ACTION_DANTE_AGNI_RUDRA_TEMPEST,
	ACTION_DANTE_NEVAN_TUNE_UP = 80,
	ACTION_DANTE_NEVAN_COMBO_1,
	ACTION_DANTE_NEVAN_COMBO_2,
	ACTION_DANTE_NEVAN_JAM_SESSION,
	ACTION_DANTE_NEVAN_BAT_RIFT_LEVEL_1,
	ACTION_DANTE_NEVAN_BAT_RIFT_LEVEL_2,
	ACTION_DANTE_NEVAN_REVERB_SHOCK_LEVEL_1,
	ACTION_DANTE_NEVAN_REVERB_SHOCK_LEVEL_2,
	ACTION_DANTE_NEVAN_AIR_PLAY,
	ACTION_DANTE_NEVAN_SLASH,
	ACTION_DANTE_NEVAN_AIR_SLASH_PART_1,
	ACTION_DANTE_NEVAN_AIR_SLASH_PART_2,
	ACTION_DANTE_NEVAN_FEEDBACK,
	ACTION_DANTE_NEVAN_CRAZY_ROLL,
	ACTION_DANTE_NEVAN_DISTORTION,
	ACTION_DANTE_NEVAN_VORTEX,
	ACTION_DANTE_NEVAN_THUNDER_BOLT,
	ACTION_DANTE_BEOWULF_COMBO_1_PART_1 = 110,
	ACTION_DANTE_BEOWULF_COMBO_1_PART_2,
	ACTION_DANTE_BEOWULF_COMBO_1_PART_3,
	ACTION_DANTE_BEOWULF_COMBO_2_PART_3,
	ACTION_DANTE_BEOWULF_COMBO_2_PART_4,
	ACTION_DANTE_BEOWULF_HYPER_FIST,
	ACTION_DANTE_BEOWULF_KILLER_BEE,
	ACTION_DANTE_BEOWULF_BEAST_UPPERCUT,
	ACTION_DANTE_BEOWULF_RISING_DRAGON,
	ACTION_DANTE_BEOWULF_RISING_DRAGON_LAUNCH,
	ACTION_DANTE_BEOWULF_RISING_DRAGON_WHIRLWIND,
	ACTION_DANTE_BEOWULF_STRAIGHT_LEVEL_1,
	ACTION_DANTE_BEOWULF_STRAIGHT_LEVEL_2,
	ACTION_DANTE_BEOWULF_ZODIAC,
	ACTION_DANTE_BEOWULF_VOLCANO,
	ACTION_DANTE_BEOWULF_AIR_VOLCANO,
	ACTION_DANTE_BEOWULF_TORNADO,
	ACTION_DANTE_BEOWULF_THE_HAMMER,
	ACTION_DANTE_BEOWULF_REAL_IMPACT,
	ACTION_DANTE_EBONY_IVORY_NORMAL_SHOT = 130,
	ACTION_DANTE_EBONY_IVORY_CHARGED_SHOT,
	ACTION_DANTE_EBONY_IVORY_AIR_NORMAL_SHOT,
	ACTION_DANTE_EBONY_IVORY_AIR_CHARGED_SHOT,
	ACTION_DANTE_EBONY_IVORY_TWOSOME_TIME,
	ACTION_DANTE_EBONY_IVORY_RAIN_STORM,
	ACTION_DANTE_EBONY_IVORY_WILD_STOMP,
	ACTION_DANTE_SHOTGUN_NORMAL_SHOT = 140,
	ACTION_DANTE_SHOTGUN_CHARGED_SHOT,
	ACTION_DANTE_SHOTGUN_AIR_NORMAL_SHOT,
	ACTION_DANTE_SHOTGUN_AIR_CHARGED_SHOT,
	ACTION_DANTE_SHOTGUN_FIREWORKS,
	ACTION_DANTE_SHOTGUN_AIR_FIREWORKS,
	ACTION_DANTE_SHOTGUN_GUN_STINGER,
	ACTION_DANTE_SHOTGUN_POINT_BLANK,
	ACTION_DANTE_ARTEMIS_NORMAL_SHOT = 150,
	ACTION_DANTE_ARTEMIS_AIR_NORMAL_SHOT,
	ACTION_DANTE_ARTEMIS_MULTI_LOCK_SHOT,
	ACTION_DANTE_ARTEMIS_AIR_MULTI_LOCK_SHOT,
	ACTION_DANTE_ARTEMIS_SPHERE,
	ACTION_DANTE_ARTEMIS_ACID_RAIN,
	ACTION_DANTE_SPIRAL_NORMAL_SHOT = 160,
	ACTION_DANTE_SPIRAL_SNIPER,
	ACTION_DANTE_SPIRAL_TRICK_SHOT,
	ACTION_DANTE_KALINA_ANN_NORMAL_SHOT = 170,
	ACTION_DANTE_KALINA_ANN_HYSTERIC,
	ACTION_DANTE_KALINA_ANN_GRAPPLE,
	ACTION_DANTE_TRICKSTER_DASH = 180,
	ACTION_DANTE_TRICKSTER_SKY_STAR,
	ACTION_DANTE_TRICKSTER_AIR_TRICK,
	ACTION_DANTE_TRICKSTER_WALL_HIKE,
	ACTION_DANTE_ROYALGUARD_RELEASE_1 = 190,
	ACTION_DANTE_ROYALGUARD_RELEASE_2,
	ACTION_DANTE_ROYALGUARD_RELEASE_3,
	ACTION_DANTE_ROYALGUARD_RELEASE_4,
	ACTION_DANTE_ROYALGUARD_AIR_RELEASE_1,
	ACTION_DANTE_ROYALGUARD_AIR_RELEASE_2,
	ACTION_DANTE_ROYALGUARD_AIR_RELEASE_3,
	ACTION_DANTE_ROYALGUARD_AIR_RELEASE_4,
	ACTION_DANTE_REBELLION_DANCE_MACABRE_PART_1 = 200,
	ACTION_DANTE_REBELLION_DANCE_MACABRE_PART_2,
	ACTION_DANTE_REBELLION_DANCE_MACABRE_PART_3,
	ACTION_DANTE_REBELLION_DANCE_MACABRE_PART_4,
	ACTION_DANTE_REBELLION_DANCE_MACABRE_PART_5,
	ACTION_DANTE_REBELLION_DANCE_MACABRE_PART_6,
	ACTION_DANTE_REBELLION_DANCE_MACABRE_PART_7,
	ACTION_DANTE_REBELLION_DANCE_MACABRE_PART_8,
	ACTION_DANTE_REBELLION_CRAZY_DANCE,
	ACTION_DANTE_POLE_PLAY,
	ACTION_VERGIL_YAMATO_COMBO_PART_1 = 1,
	ACTION_VERGIL_YAMATO_COMBO_PART_2,
	ACTION_VERGIL_YAMATO_COMBO_PART_3,
	ACTION_VERGIL_YAMATO_RAPID_SLASH_LEVEL_1,
	ACTION_VERGIL_YAMATO_RAPID_SLASH_LEVEL_2,
	ACTION_VERGIL_YAMATO_LEAP,
	ACTION_VERGIL_YAMATO_UPPER_SLASH_PART_1,
	ACTION_VERGIL_YAMATO_UPPER_SLASH_PART_2,
	ACTION_VERGIL_YAMATO_JUDGEMENT_CUT_LEVEL_1,
	ACTION_VERGIL_YAMATO_JUDGEMENT_CUT_LEVEL_2,
	ACTION_VERGIL_YAMATO_AERIAL_RAVE_PART_1,
	ACTION_VERGIL_YAMATO_AERIAL_RAVE_PART_2,
	ACTION_VERGIL_BEOWULF_COMBO_PART_1 = 20,
	ACTION_VERGIL_BEOWULF_COMBO_PART_2,
	ACTION_VERGIL_BEOWULF_COMBO_PART_3,
	ACTION_VERGIL_BEOWULF_STARFALL_LEVEL_1,
	ACTION_VERGIL_BEOWULF_STARFALL_LEVEL_2,
	ACTION_VERGIL_BEOWULF_RISING_SUN,
	ACTION_VERGIL_BEOWULF_LUNAR_PHASE_LEVEL_1,
	ACTION_VERGIL_BEOWULF_LUNAR_PHASE_LEVEL_2,
	ACTION_VERGIL_FORCE_EDGE_COMBO_PART_1 = 30,
	ACTION_VERGIL_FORCE_EDGE_COMBO_PART_2,
	ACTION_VERGIL_FORCE_EDGE_COMBO_PART_3,
	ACTION_VERGIL_FORCE_EDGE_COMBO_PART_4,
	ACTION_VERGIL_FORCE_EDGE_HELM_BREAKER_LEVEL_1,
	ACTION_VERGIL_FORCE_EDGE_HELM_BREAKER_LEVEL_2,
	ACTION_VERGIL_FORCE_EDGE_HIGH_TIME,
	ACTION_VERGIL_FORCE_EDGE_HIGH_TIME_LAUNCH,
	ACTION_VERGIL_FORCE_EDGE_STINGER_LEVEL_1,
	ACTION_VERGIL_FORCE_EDGE_STINGER_LEVEL_2,
	ACTION_VERGIL_FORCE_EDGE_ROUND_TRIP,
	ACTION_VERGIL_FORCE_EDGE_KICK,
	ACTION_VERGIL_SUMMONED_SWORDS_SHOOT = 52,
	ACTION_VERGIL_SUMMONED_SWORDS_SPIRAL_SWORDS,
	ACTION_VERGIL_SUMMONED_SWORDS_BLISTERING_SWORDS,
	ACTION_VERGIL_SUMMONED_SWORDS_SWORD_STORM,
	ACTION_VERGIL_DARK_SLAYER_AIR_TRICK = 60,
	ACTION_VERGIL_DARK_SLAYER_TRICK_UP,
	ACTION_VERGIL_DARK_SLAYER_TRICK_DOWN,
	ACTION_VERGIL_NERO_ANGELO_COMBO_1_PART_1 = 70,
	ACTION_VERGIL_NERO_ANGELO_COMBO_1_PART_2,
	ACTION_VERGIL_NERO_ANGELO_COMBO_1_PART_3,
	ACTION_VERGIL_NERO_ANGELO_HELM_BREAKER,
	ACTION_VERGIL_NERO_ANGELO_HIGH_TIME,
	ACTION_VERGIL_NERO_ANGELO_HIGH_TIME_LAUNCH,
	ACTION_VERGIL_NERO_ANGELO_STINGER,
	ACTION_VERGIL_NERO_ANGELO_FIREBALL_1,
	ACTION_VERGIL_NERO_ANGELO_COMBO_2_PART_1 = 90,
	ACTION_VERGIL_NERO_ANGELO_COMBO_2_PART_2,
	ACTION_VERGIL_NERO_ANGELO_COMBO_2_PART_3,
	ACTION_VERGIL_NERO_ANGELO_DIVEKICK,
	ACTION_VERGIL_NERO_ANGELO_ROUNDHOUSE_KICK,
	ACTION_VERGIL_NERO_ANGELO_UPPERCUT,
	ACTION_VERGIL_NERO_ANGELO_FIREBALL_2,
};












enum PERMISSION
{
	PERMISSION_UPDATE = 1,
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




// $CacheFileStart

enum CACHE_FILE
{
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
	plwp_sword,
	plwp_sword2,
	plwp_sword3,
	plwp_nunchaku,
	plwp_2sword,
	plwp_guitar,
	plwp_fight,
	plwp_gun,
	plwp_shotgun,
	plwp_laser,
	plwp_rifle,
	plwp_ladygun,
	pl001,
	pl001_00_0,
	pl001_00_1,
	pl001_00_2,
	pl001_00_31,
	plwp_vergilsword,
	pl002,
	pl002_00_0,
	pl002_00_1,
	pl002_00_2,
	pl021,
	pl023,
	pl026,
	pl010,
	pl014,
	pl025,
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
	plwp_newvergilsword,
	plwp_newvergilfight,
	plwp_forceedge,
	plwp_nerosword,
	em034,
	id100,
	id100V,
	MAX_CACHE_FILE,
};

struct CacheFileHelper
{
	const char * name;
	const char * type;
};

constexpr CacheFileHelper cacheFileHelper[MAX_CACHE_FILE] =
{
	{ "pl000.pac", "obj\\pl000.pac" },
	{ "pl011.pac", "obj\\pl011.pac" },
	{ "pl013.pac", "obj\\pl013.pac" },
	{ "pl015.pac", "obj\\pl015.pac" },
	{ "pl016.pac", "obj\\pl016.pac" },
	{ "pl018.pac", "obj\\pl018.pac" },
	{ "pl005.pac", "obj\\pl005.pac" },
	{ "pl006.pac", "obj\\pl006.pac" },
	{ "pl007.pac", "obj\\pl007.pac" },
	{ "pl008.pac", "obj\\pl008.pac" },
	{ "pl009.pac", "obj\\pl009.pac" },
	{ "pl017.pac", "obj\\pl017.pac" },
	{ "pl000_00_0.pac", "motion\\pl000\\pl000_00_0.pac" },
	{ "pl000_00_1.pac", "motion\\pl000\\pl000_00_1.pac" },
	{ "pl000_00_2.pac", "motion\\pl000\\pl000_00_2.pac" },
	{ "pl000_00_3.pac", "motion\\pl000\\pl000_00_3.pac" },
	{ "pl000_00_4.pac", "motion\\pl000\\pl000_00_4.pac" },
	{ "pl000_00_5.pac", "motion\\pl000\\pl000_00_5.pac" },
	{ "pl000_00_6.pac", "motion\\pl000\\pl000_00_6.pac" },
	{ "pl000_00_7.pac", "motion\\pl000\\pl000_00_7.pac" },
	{ "pl000_00_8.pac", "motion\\pl000\\pl000_00_8.pac" },
	{ "pl000_00_9.pac", "motion\\pl000\\pl000_00_9.pac" },
	{ "pl000_00_10.pac", "motion\\pl000\\pl000_00_10.pac" },
	{ "pl000_00_11.pac", "motion\\pl000\\pl000_00_11.pac" },
	{ "pl000_00_12.pac", "motion\\pl000\\pl000_00_12.pac" },
	{ "pl000_00_13.pac", "motion\\pl000\\pl000_00_13.pac" },
	{ "pl000_00_14.pac", "motion\\pl000\\pl000_00_14.pac" },
	{ "pl000_00_15.pac", "motion\\pl000\\pl000_00_15.pac" },
	{ "pl000_00_16.pac", "motion\\pl000\\pl000_00_16.pac" },
	{ "pl000_00_17.pac", "motion\\pl000\\pl000_00_17.pac" },
	{ "pl000_00_18.pac", "motion\\pl000\\pl000_00_18.pac" },
	{ "pl000_00_19.pac", "motion\\pl000\\pl000_00_19.pac" },
	{ "pl000_00_20.pac", "motion\\pl000\\pl000_00_20.pac" },
	{ "pl000_00_21.pac", "motion\\pl000\\pl000_00_21.pac" },
	{ "pl000_00_22.pac", "motion\\pl000\\pl000_00_22.pac" },
	{ "pl000_00_23.pac", "motion\\pl000\\pl000_00_23.pac" },
	{ "pl000_00_24.pac", "motion\\pl000\\pl000_00_24.pac" },
	{ "pl000_00_25.pac", "motion\\pl000\\pl000_00_25.pac" },
	{ "pl000_00_26.pac", "motion\\pl000\\pl000_00_26.pac" },
	{ "plwp_sword.pac", "obj\\plwp_sword.pac" },
	{ "plwp_sword2.pac", "obj\\plwp_sword2.pac" },
	{ "plwp_sword3.pac", "obj\\plwp_sword3.pac" },
	{ "plwp_nunchaku.pac", "obj\\plwp_nunchaku.pac" },
	{ "plwp_2sword.pac", "obj\\plwp_2sword.pac" },
	{ "plwp_guitar.pac", "obj\\plwp_guitar.pac" },
	{ "plwp_fight.pac", "obj\\plwp_fight.pac" },
	{ "plwp_gun.pac", "obj\\plwp_gun.pac" },
	{ "plwp_shotgun.pac", "obj\\plwp_shotgun.pac" },
	{ "plwp_laser.pac", "obj\\plwp_laser.pac" },
	{ "plwp_rifle.pac", "obj\\plwp_rifle.pac" },
	{ "plwp_ladygun.pac", "obj\\plwp_ladygun.pac" },
	{ "pl001.pac", "obj\\pl001.pac" },
	{ "pl001_00_0.pac", "motion\\pl001\\pl001_00_0.pac" },
	{ "pl001_00_1.pac", "motion\\pl001\\pl001_00_1.pac" },
	{ "pl001_00_2.pac", "motion\\pl001\\pl001_00_2.pac" },
	{ "pl001_00_31.pac", "motion\\pl001\\pl001_00_31.pac" },
	{ "plwp_vergilsword.pac", "obj\\plwp_vergilsword.pac" },
	{ "pl002.pac", "obj\\pl002.pac" },
	{ "pl002_00_0.pac", "motion\\pl002\\pl002_00_0.pac" },
	{ "pl002_00_1.pac", "motion\\pl002\\pl002_00_1.pac" },
	{ "pl002_00_2.pac", "motion\\pl002\\pl002_00_2.pac" },
	{ "pl021.pac", "obj\\pl021.pac" },
	{ "pl023.pac", "obj\\pl023.pac" },
	{ "pl026.pac", "obj\\pl026.pac" },
	{ "pl010.pac", "obj\\pl010.pac" },
	{ "pl014.pac", "obj\\pl014.pac" },
	{ "pl025.pac", "obj\\pl025.pac" },
	{ "pl021_00_0.pac", "motion\\pl021\\pl021_00_0.pac" },
	{ "pl021_00_1.pac", "motion\\pl021\\pl021_00_1.pac" },
	{ "pl021_00_2.pac", "motion\\pl021\\pl021_00_2.pac" },
	{ "pl021_00_3.pac", "motion\\pl021\\pl021_00_3.pac" },
	{ "pl021_00_4.pac", "motion\\pl021\\pl021_00_4.pac" },
	{ "pl021_00_5.pac", "motion\\pl021\\pl021_00_5.pac" },
	{ "pl021_00_6.pac", "motion\\pl021\\pl021_00_6.pac" },
	{ "pl021_00_7.pac", "motion\\pl021\\pl021_00_7.pac" },
	{ "pl021_00_8.pac", "motion\\pl021\\pl021_00_8.pac" },
	{ "pl021_00_9.pac", "motion\\pl021\\pl021_00_9.pac" },
	{ "plwp_newvergilsword.pac", "obj\\plwp_newvergilsword.pac" },
	{ "plwp_newvergilfight.pac", "obj\\plwp_newvergilfight.pac" },
	{ "plwp_forceedge.pac", "obj\\plwp_forceedge.pac" },
	{ "plwp_nerosword.pac", "obj\\plwp_nerosword.pac" },
	{ "em034.pac", "obj\\em034.pac" },
	{ "id100.pac", "id\\id100\\id100.pac" },
	{ "id100V.pac", "id\\id100\\id100V.pac" },
};

// $CacheFileEnd












// @Todo: Add missing events.

enum EVENT_
{
	EVENT_MAIN      = 1,
	EVENT_TELEPORT  = 2,
	EVENT_PAUSE     = 3,
	EVENT_CUSTOMIZE = 6,
};












enum GAMEPAD
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
	MAX_GAMEPAD = 4,
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






enum ACTOR_EVENT
{
	ACTOR_EVENT_DANTE_DASH = 22,
	ACTOR_EVENT_DANTE_SKY_STAR,
	ACTOR_EVENT_DANTE_AIR_TRICK,
	ACTOR_EVENT_VERGIL_AIR_TRICK = 27,
	ACTOR_EVENT_VERGIL_TRICK_UP,
	ACTOR_EVENT_VERGIL_TRICK_DOWN,
};


















#define _(size) struct { byte8 Prep_Merge(padding_, __LINE__)[size]; }

#pragma pack(push, 1)


































struct ACTOR_EVENT_DATA
{
	uint32 index;
	uint32 lastIndex;
};














// $SessionDataStart

struct SESSION_DATA
{
	uint32 mission; // 0
	_(8);
	uint32 mode; // 0xC
	bool oneHitKill; // 0x10
	_(1);
	bool enableTutorial; // 0x12
	bool useGoldOrb; // 0x13
	_(8);
	bool bloodyPalace; // 0x1C
	_(24);
	uint8 goldOrbCount; // 0x35
	_(16);
	bool unlock[14]; // 0x46
	_(48);
	uint8 weapons[4]; // 0x84
	_(72);
	uint8 costume; // 0xD0
	bool unlockDevilTrigger; // 0xD1
	_(2);
	float32 hitPoints; // 0xD4
	float32 magicPoints; // 0xD8
	uint32 style; // 0xDC
	uint32 styleLevel[6]; // 0xE0
	float32 styleExperience[6]; // 0xF8
	byte32 expertise[8]; // 0x110
};

static_assert(offsetof(SESSION_DATA, mission) == 0);
static_assert(offsetof(SESSION_DATA, mode) == 0xC);
static_assert(offsetof(SESSION_DATA, oneHitKill) == 0x10);
static_assert(offsetof(SESSION_DATA, enableTutorial) == 0x12);
static_assert(offsetof(SESSION_DATA, useGoldOrb) == 0x13);
static_assert(offsetof(SESSION_DATA, bloodyPalace) == 0x1C);
static_assert(offsetof(SESSION_DATA, goldOrbCount) == 0x35);
static_assert(offsetof(SESSION_DATA, unlock) == 0x46);
static_assert(offsetof(SESSION_DATA, weapons) == 0x84);
static_assert(offsetof(SESSION_DATA, costume) == 0xD0);
static_assert(offsetof(SESSION_DATA, unlockDevilTrigger) == 0xD1);
static_assert(offsetof(SESSION_DATA, hitPoints) == 0xD4);
static_assert(offsetof(SESSION_DATA, magicPoints) == 0xD8);
static_assert(offsetof(SESSION_DATA, style) == 0xDC);
static_assert(offsetof(SESSION_DATA, styleLevel) == 0xE0);
static_assert(offsetof(SESSION_DATA, styleExperience) == 0xF8);
static_assert(offsetof(SESSION_DATA, expertise) == 0x110);

// $SessionDataEnd

struct EVENT_DATA
{
	_(24);
	uint32 room;
	uint32 position;
	uint32 index;
};

struct NEXT_EVENT_DATA
{
	_(356);
	uint16 room;
	uint16 position;
};

struct STAGE_POSITION_DATA
{
	uint8 event;
	_(3);
	float32 x;
	float32 y;
	float32 z;
	float32 rotation;
	_(28);
};

#define IntroduceSessionData() auto & sessionData = *reinterpret_cast<SESSION_DATA *>(appBaseAddr + 0xC8F250)

#define _IntroduceEventData(name, ...)\
auto name = *reinterpret_cast<byte8 ***>(appBaseAddr + 0xC90E10);\
if (!name)\
{\
	__VA_ARGS__;\
}\
if (!name[8])\
{\
	__VA_ARGS__;\
}\
auto & eventData = *reinterpret_cast<EVENT_DATA *>(name[8])
#define IntroduceEventData(...) _IntroduceEventData(Prep_Merge(pool_, __LINE__), __VA_ARGS__)

#define _IntroduceNextEventData(name, ...)\
auto name = *reinterpret_cast<byte8 ***>(appBaseAddr + 0xC90E10);\
if (!name)\
{\
	__VA_ARGS__;\
}\
if (!name[12])\
{\
	__VA_ARGS__;\
}\
auto & nextEventData = *reinterpret_cast<NEXT_EVENT_DATA *>(name[12])
#define IntroduceNextEventData(...) _IntroduceNextEventData(Prep_Merge(pool_, __LINE__), __VA_ARGS__)

#define _IntroduceEventFlags(name, ...)\
auto name = *reinterpret_cast<byte8 ***>(appBaseAddr + 0xC90E30);\
if (!name)\
{\
	__VA_ARGS__;\
}\
if (!name[1])\
{\
	__VA_ARGS__;\
}\
auto eventFlags = reinterpret_cast<byte32 *>(name[1])
#define IntroduceEventFlags(...) _IntroduceEventFlags(Prep_Merge(pool_, __LINE__), __VA_ARGS__)

#define _IntroduceStagePositionData(name, ...)\
auto name = *reinterpret_cast<byte8 ***>(appBaseAddr + 0xC90E10);\
if (!name)\
{\
	__VA_ARGS__;\
}\
if (!name[8])\
{\
	__VA_ARGS__;\
}\
auto stagePositionData = *reinterpret_cast<STAGE_POSITION_DATA **>(name[8] + 0x2CB0);\
if (!stagePositionData)\
{\
	__VA_ARGS__;\
}
#define IntroduceStagePositionData(...) _IntroduceStagePositionData(Prep_Merge(pool_, __LINE__), __VA_ARGS__)













































struct CAMERA_DATA
{
	_(176);
	byte8 * targetBaseAddr;
	_(24);
	float32 height;
	float32 tilt;
	float32 zoom;
};

static_assert(offsetof(CAMERA_DATA, targetBaseAddr) == 0xB0);
static_assert(offsetof(CAMERA_DATA, height) == 0xD0);
static_assert(offsetof(CAMERA_DATA, tilt) == 0xD4);
static_assert(offsetof(CAMERA_DATA, zoom) == 0xD8);
















struct ARCHIVE_DATA
{
	byte8 signature[4];
	uint32 fileCount;
	uint32 fileOff[128];
};





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

struct ENGINE_GAMEPAD
{
	byte16 buttons[4];
	uint16 buttonsTimer[2];
	uint16 rightStickDirection[4];
	uint16 rightStickTimer[2];
	uint16 rightStickPosition;
	uint16 rightStickRadius;
	uint16 leftStickDirection[4];
	uint16 leftStickTimer[2];
	uint16 leftStickPosition;
	uint16 leftStickRadius;
};


//constexpr uint64 gamepadSize = sizeof(CAPCOM_GAMEPAD);


//static_assert(offsetof(ENGINE_GAMEPAD, rightStickPosition) == 0x18);
//static_assert(offsetof(ENGINE_GAMEPAD, rightStickRadius) == 0x1A);
//
//static_assert(offsetof(ENGINE_GAMEPAD, leftStickPosition) == 0x28);
//static_assert(offsetof(ENGINE_GAMEPAD, leftStickRadius) == 0x2A);
//
//













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
	operator byte8 *()
	{
		return reinterpret_cast<byte8 *>(this);
	}
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









/*
\
\
auto name2 = *reinterpret_cast<byte8 ***>(appBaseAddr + 0xC90E30);\
if (!name2)\
{\
return;\
}\
if (!name2[1])\
{\
return;\
}\
auto eventFlags = reinterpret_cast<byte32 *>(name2[1])
*/



//#define _(size) struct { byte8 Merge(padding, __LINE__)[size]; }



//#define IntroduceEventDataFunction(name1, name2) _IntroduceEventDataFunction(name1, name2)


//#define Expand(a) a

//#define IntroduceEventData IntroduceEventDataFunction(Merge(pool1_, __LINE__), Merge(pool2_, __LINE__))


//#undef Expand

//
//#define IntroduceEventDataFunction(name1, name2) _IntroduceEventDataFunction(name1, name2)
//
//#define _IntroduceEventData IntroduceEventDataFunction(Merge(pool1_, __LINE__), Merge(pool2_, __LINE__))
//
//#define IntroduceEventData _IntroduceEventData










//#define IntroduceEventDataFunction _IntroduceEventDataFunction(Merge(pool1_, __LINE__), Merge(pool2_, __LINE__))

//#define IntroduceEventData IntroduceEventDataFunction








//#define IntroduceEventData _IntroduceEventData(Merge(pool1_, __LINE__), Merge(pool2_, __LINE__))




























#undef _
//#undef Merge
//#undef _Merge



/*

INTERACTION_DATA


_(528);

vec4 force[8];

actorData.interactionData.force[3].x


actorData.forceData[3].x






*/












struct MissionStartHelper
{
	uint16 room;
	uint16 position;
};

constexpr MissionStartHelper missionStartHelper[] =
{
	{ 0  , 0 }, // Movie
	{ 0  , 0 }, // Mission 1
	{ 1  , 0 }, // Mission 2
	{ 2  , 0 }, // Mission 3
	{ 100, 0 }, // Mission 4
	{ 111, 2 }, // Mission 5
	{ 122, 0 }, // Mission 6
	{ 127, 2 }, // Mission 7
	{ 300, 0 }, // Mission 8
	{ 201, 0 }, // Mission 9
	{ 209, 2 }, // Mission 10
	{ 212, 1 }, // Mission 11
	{ 217, 1 }, // Mission 12
	{ 229, 0 }, // Mission 13
	{ 237, 1 }, // Mission 14
	{ 222, 1 }, // Mission 15
	{ 106, 0 }, // Mission 16
	{ 133, 1 }, // Mission 17
	{ 400, 0 }, // Mission 18
	{ 406, 0 }, // Mission 19
	{ 411, 0 }, // Mission 20
	{ 423, 0 }, // Bloody Palace
};




















struct FloorHelper
{
	uint16 room;
	uint16 position;
};

constexpr FloorHelper Arcade_floorHelper[] =
{
	{ 423, 0 }, // Floor 1
{ 424, 0 }, // Floor 2
{ 425, 0 }, // Floor 3
{ 426, 0 }, // Floor 4
{ 427, 0 }, // Floor 5
{ 428, 0 }, // Floor 6
{ 429, 0 }, // Floor 7
{ 430, 0 }, // Floor 8
{ 431, 0 }, // Floor 9
{ 432, 0 }, // Floor 10
{ 433, 0 }, // Cerberus
{ 434, 0 }, // Gigapede
{ 435, 0 }, // Agni & Rudra
{ 436, 0 }, // Nevan
{ 437, 0 }, // Beowulf
{ 438, 2 }, // Geryon
{ 439, 0 }, // Doppelganger
{ 440, 0 }, // Heart of Leviathan
{ 441, 0 }, // Damned Chessmen
{ 442, 0 }, // Vergil 1
{ 443, 0 }, // Vergil 2
{ 444, 0 }, // Vergil 3
{ 445, 2 }, // Lady
{ 446, 0 }, // Arkham
{ 422, 0 }, // Jester 1
{ 448, 0 }, // Jester 2
{ 449, 0 }, // Jester 3
};










enum BOSS
{
	BOSS_CERBERUS,
	BOSS_GIGAPEDE,
	BOSS_JESTER_1,
	BOSS_AGNI_RUDRA,
	BOSS_VERGIL_1,
	BOSS_LEVIATHAN,
	BOSS_NEVAN,
	BOSS_BEOWULF,
	BOSS_JESTER_2,
	BOSS_GERYON_PART_1,
	BOSS_GERYON_PART_2,
	BOSS_VERGIL_2,
	BOSS_LADY,
	BOSS_JESTER_3,
	BOSS_DOPPELGANGER,
	BOSS_TAIZAI_REBORN,
	BOSS_CERBERUS_REBORN,
	BOSS_GIGAPEDE_REBORN,
	BOSS_AGNI_RUDRA_REBORN,
	BOSS_LEVIATHAN_REBORN,
	BOSS_NEVAN_REBORN,
	BOSS_BEOWULF_REBORN,
	BOSS_GERYON_REBORN,
	BOSS_DOPPELGANGER_REBORN,
	BOSS_ARKHAM_PART_1,
	BOSS_ARKHAM_PART_2,
	BOSS_VERGIL_3,
};

struct BossHelper
{
	uint16 room;
	uint16 position;
	const char * track;
};

constexpr BossHelper bossHelper[] =
{
	{ 6  , 2, "afs/sound/Boss_01.adx"    }, // Cerberus
	{ 111, 0, "afs/sound/T_Boss.adx"     }, // Gigapede
	{ 422, 0, "afs/sound/Jester.adx"     }, // Jester 1
	{ 121, 3, "afs/sound/Boss_02.adx"    }, // Agni & Rudra
	{ 144, 0, "afs/sound/Versil_01.adx"  }, // Vergil 1
	{ 302, 0, "afs/sound/Boss_08.adx"    }, // Leviathan
	{ 210, 2, "afs/sound/Boss_03.adx"    }, // Nevan
	{ 217, 2, "afs/sound/Boss_04.adx"    }, // Beowulf
	{ 448, 0, "afs/sound/Jester.adx"     }, // Jester 2
	{ 228, 0, "afs/sound/Boss_05.adx"    }, // Geryon Part 1
	{ 228, 2, "afs/sound/Boss_05.adx"    }, // Geryon Part 2
	{ 234, 0, "afs/sound/Versil_02.adx"  }, // Vergil 2
	{ 115, 2, "afs/sound/Lady.adx"       }, // Lady
	{ 449, 0, "afs/sound/Jester.adx"     }, // Jester 3
	{ 139, 0, "afs/sound/Boss_06.adx"    }, // Doppelganger
	{ 420, 0, "afs/sound/Battle_01B.adx" }, // Taizai Reborn
	{ 412, 0, "afs/sound/Boss_01B.adx"   }, // Cerberus Reborn
	{ 413, 0, "afs/sound/T_BossB.adx"    }, // Gigapede Reborn
	{ 414, 0, "afs/sound/Boss_02B.adx"   }, // Agni & Rudra Reborn
	{ 419, 0, "afs/sound/Boss_08B.adx"   }, // Leviathan Reborn
	{ 415, 0, "afs/sound/Boss_03B.adx"   }, // Nevan Reborn
	{ 416, 0, "afs/sound/Boss_04B.adx"   }, // Beowulf Reborn
	{ 417, 0, "afs/sound/Boss_05B.adx"   }, // Geryon Reborn
	{ 418, 0, "afs/sound/Boss_06B.adx"   }, // Doppelganger Reborn
	{ 421, 0, "afs/sound/Hine_01.adx"    }, // Arkham Part 1
	{ 421, 0, "afs/sound/Hine_02.adx"    }, // Arkham Part 2
	{ 411, 0, "afs/sound/Versil_03.adx"  }, // Vergil 3
};

























enum DEVIL_FLUX_
{
	DEVIL_FLUX_START = 1,
	DEVIL_FLUX_END   = 2,
};














#ifdef __GARBAGE__


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


