#ifndef __MODULE_UPDATE__
#define __MODULE_UPDATE__

module;
#include "../Core/Core.h"

#include "Vars.h"
export module ModuleName(Update);

import ModuleName(Actor);
import ModuleName(Config);
import ModuleName(Event);
import ModuleName(Input);
import ModuleName(State);

#ifdef __INTELLISENSE__
#include "Actor.ixx"
#include "Config.ixx"
#include "Event.ixx"
#include "Input.ixx"
#include "State.ixx"
#endif

uint64 ticksPerSecond      = 0;
uint64 ticksPerMillisecond = 0;
uint64 savedTickCount      = 0;

uint64 g_mainLoopCounter = 0;
uint64 g_actorLoopCounter = 0;

uint8 g_relativeTiltDirection = 0;























constexpr uint8 swordmasterDante [MAX_MELEE_WEAPON_DANTE ][MAX_TILT_DIRECTION][2] =
{
	// Rebellion
	{
		// Neutral
		{
			ACTION_DANTE_REBELLION_PROP_SHREDDER_1,
			ACTION_DANTE_REBELLION_AERIAL_RAVE_PART_1,
		},
		// Up
		{
			ACTION_DANTE_REBELLION_SWORD_PIERCE,
			0,
		},
		// Right
		{
			0,
			0,
		},
		// Down
		{
			ACTION_DANTE_REBELLION_DANCE_MACABRE_PART_1,
			0,
		},
		// Left
		{
			0,
			0,
		},
	},
	// Cerberus
	{
		// Neutral
		{
			ACTION_DANTE_CERBERUS_FLICKER,
			ACTION_DANTE_CERBERUS_AIR_FLICKER,
		},
		// Up
		{
			ACTION_DANTE_CERBERUS_CRYSTAL,
			0,
		},
		// Right
		{
			0,
			0,
		},
		// Down
		{
			ACTION_DANTE_CERBERUS_ICE_AGE,
			0,
		},
		// Left
		{
			0,
			0,
		},
	},
	// Agni & Rudra
	{
		// Neutral
		{
			ACTION_DANTE_AGNI_RUDRA_CROSSED_SWORDS,
			ACTION_DANTE_AGNI_RUDRA_SKY_DANCE_PART_1,
		},
		// Up
		{
			ACTION_DANTE_AGNI_RUDRA_CRAWLER,
			0,
		},
		// Right
		{
			0,
			0,
		},
		// Down
		{
			ACTION_DANTE_AGNI_RUDRA_TWISTER,
			0,
		},
		// Left
		{
			0,
			0,
		},
	},
	// Nevan
	{
		// Neutral
		{
			ACTION_DANTE_NEVAN_SLASH,
			ACTION_DANTE_NEVAN_AIR_SLASH_PART_1,
		},
		// Up
		{
			ACTION_DANTE_NEVAN_FEEDBACK,
			0,
		},
		// Right
		{
			0,
			0,
		},
		// Down
		{
			ACTION_DANTE_NEVAN_DISTORTION,
			0,
		},
		// Left
		{
			0,
			0,
		},
	},
	// Beowulf
	{
		// Neutral
		{
			ACTION_DANTE_BEOWULF_ZODIAC,
			ACTION_DANTE_BEOWULF_THE_HAMMER,
		},
		// Up
		{
			ACTION_DANTE_BEOWULF_VOLCANO,
			ACTION_DANTE_BEOWULF_AIR_VOLCANO,
		},
		// Right
		{
			0,
			0,
		},
		// Down
		{
			ACTION_DANTE_BEOWULF_REAL_IMPACT,
			0,
		},
		// Left
		{
			0,
			0,
		},
	},
};
constexpr uint8 gunslingerDante  [MAX_RANGED_WEAPON_DANTE][MAX_TILT_DIRECTION][2] =
{
	// Ebony & Ivory
	{
		// Neutral
		{
			ACTION_DANTE_EBONY_IVORY_TWOSOME_TIME,
			ACTION_DANTE_EBONY_IVORY_RAIN_STORM,
		},
		// Up
		{
			0,
			0,
		},
		// Right
		{
			0,
			0,
		},
		// Down
		{
			0,
			0,
		},
		// Left
		{
			0,
			0,
		},
	},
	// Shotgun
	{
		// Neutral
		{
			ACTION_DANTE_SHOTGUN_FIREWORKS,
			ACTION_DANTE_SHOTGUN_AIR_FIREWORKS,
		},
		// Up
		{
			ACTION_DANTE_SHOTGUN_GUN_STINGER,
			0,
		},
		// Right
		{
			0,
			0,
		},
		// Down
		{
			0,
			0,
		},
		// Left
		{
			0,
			0,
		},
	},
	// Artemis
	{
		// Neutral
		{
			ACTION_DANTE_ARTEMIS_MULTI_LOCK_SHOT,
			ACTION_DANTE_ARTEMIS_AIR_MULTI_LOCK_SHOT,
		},
		// Up
		{
			ACTION_DANTE_ARTEMIS_SPHERE,
			0,
		},
		// Right
		{
			0,
			0,
		},
		// Down
		{
			0,
			0,
		},
		// Left
		{
			0,
			0,
		},
	},
	// Spiral
	{
		// Neutral
		{
			ACTION_DANTE_SPIRAL_TRICK_SHOT,
			0,
		},
		// Up
		{
			ACTION_DANTE_SPIRAL_SNIPER,
			0,
		},
		// Right
		{
			0,
			0,
		},
		// Down
		{
			0,
			0,
		},
		// Left
		{
			0,
			0,
		},
	},
	// Kalina Ann
	{
		// Neutral
		{
			ACTION_DANTE_KALINA_ANN_HYSTERIC,
			0,
		},
		// Up
		{
			ACTION_DANTE_KALINA_ANN_GRAPPLE,
			0,
		},
		// Right
		{
			0,
			0,
		},
		// Down
		{
			0,
			0,
		},
		// Left
		{
			0,
			0,
		},
	},
};
constexpr uint8 royalguardDante                           [MAX_TILT_DIRECTION][2] =
{
	// Neutral
	{
		0,
		0,
	},
	// Up
	{
		ACTION_DANTE_ROYALGUARD_RELEASE_1,
		ACTION_DANTE_ROYALGUARD_AIR_RELEASE_1,
	},
	// Right
	{
		0,
		0,
	},
	// Down
	{
		0,
		0,
	},
	// Left
	{
		0,
		0,
	},
};
constexpr uint8 tricksterDante                            [MAX_TILT_DIRECTION][2] =
{
	// Neutral
	{
		ACTION_DANTE_TRICKSTER_DASH,
		ACTION_DANTE_TRICKSTER_SKY_STAR,
	},
	// Up
	{
		ACTION_DANTE_TRICKSTER_AIR_TRICK,
		ACTION_DANTE_TRICKSTER_AIR_TRICK,
	},
	// Right
	{
		0,
		0,
	},
	// Down
	{
		0,
		0,
	},
	// Left
	{
		0,
		0,
	},
};






















constexpr uint8 rangedAttackDante[MAX_RANGED_WEAPON_DANTE][MAX_TILT_DIRECTION][2] =
{
	// Ebony & Ivory
	{
		// Neutral
		{
			ACTION_DANTE_EBONY_IVORY_NORMAL_SHOT,
			ACTION_DANTE_EBONY_IVORY_AIR_NORMAL_SHOT,
		},
		// Up
		{
			0,
			0,
		},
		// Right
		{
			0,
			0,
		},
		// Down
		{
			0,
			0,
		},
		// Left
		{
			0,
			0,
		},
	},
	// Shotgun
	{
		// Neutral
		{
			ACTION_DANTE_SHOTGUN_NORMAL_SHOT,
			ACTION_DANTE_SHOTGUN_AIR_NORMAL_SHOT,
		},
		// Up
		{
			0,
			0,
		},
		// Right
		{
			0,
			0,
		},
		// Down
		{
			0,
			0,
		},
		// Left
		{
			0,
			0,
		},
	},
	// Artemis
	{
		// Neutral
		{
			ACTION_DANTE_ARTEMIS_NORMAL_SHOT,
			ACTION_DANTE_ARTEMIS_AIR_NORMAL_SHOT,
		},
		// Up
		{
			0,
			0,
		},
		// Right
		{
			0,
			0,
		},
		// Down
		{
			0,
			0,
		},
		// Left
		{
			0,
			0,
		},
	},
	// Spiral
	{
		// Neutral
		{
			ACTION_DANTE_SPIRAL_NORMAL_SHOT,
			0,
		},
		// Up
		{
			0,
			0,
		},
		// Right
		{
			0,
			0,
		},
		// Down
		{
			0,
			0,
		},
		// Left
		{
			0,
			0,
		},
	},
	// Kalina Ann
	{
		// Neutral
		{
			ACTION_DANTE_KALINA_ANN_NORMAL_SHOT,
			0,
		},
		// Up
		{
			0,
			0,
		},
		// Right
		{
			0,
			0,
		},
		// Down
		{
			0,
			0,
		},
		// Left
		{
			0,
			0,
		},
	},
};


constexpr uint8 darkSlayerVergil                          [MAX_TILT_DIRECTION][2] =
{
	// Neutral
	{
		ACTION_VERGIL_DARK_SLAYER_AIR_TRICK,
		ACTION_VERGIL_DARK_SLAYER_AIR_TRICK,
	},
	// Up
	{
		ACTION_VERGIL_DARK_SLAYER_TRICK_UP,
		ACTION_VERGIL_DARK_SLAYER_TRICK_UP,
	},
	// Right
	{
		0,
		0,
	},
	// Down
	{
		ACTION_VERGIL_DARK_SLAYER_TRICK_DOWN,
		ACTION_VERGIL_DARK_SLAYER_TRICK_DOWN,
	},
	// Left
	{
		0,
		0,
	},
};

























template <typename T>
void EndMotion(T & actorData)
{
	//actorData.var_3E00[0] = 2;
	//actorData.var_3E00[0] = 2;
	actorData.eventData[0].index = 2;
}

template <typename T>
void EnableControl(T & actorData)
{
	actorData.newButtonMask = 0xFFFF;
	actorData.newEnableLeftStick = true;
}

template <typename T>
void DisableControl(T & actorData)
{
	actorData.newButtonMask = 0;
	actorData.newEnableLeftStick = false;
}

//template <typename T1, typename T2>
//void CopyPosition(T1 & target, T2 & source)
//{
//	target.position = source.position;
//	target.direction = source.direction;
//}



template <typename T>
void FixPull(T & actorData)
{
	if (actorData.state & STATE_ON_FLOOR)
	{
		actorData.pull = 0;
		actorData.pullMultiplier = 0;
	}
	else
	{
		actorData.pull = 0;
		actorData.pullMultiplier = -1.5;
	}
}











































// auto & gamepad = GetGamepad(0);

// #define GetAction(actorData, binding, __DEST__)\
// uint8 action = 0;\
// for_each(uint8, tiltDirection, TILT_DIRECTION_UP, MAX_TILT_DIRECTION)\
// {\
// 	if\
// 	(\
// 		(gamepad.buttons[0] & GetBinding(BINDING_LOCK_ON)) &&\
// 		(GetRelativeTiltDirection(actorData) == tiltDirection) &&\
// 		(gamepad.buttons[0] & GetBinding(binding))\
// 	)\
// 	{\
// 		action = __DEST__[tiltDirection][state];\
// 		break;\
// 	}\
// }\
// if (!action)\
// {\
// 	if (gamepad.buttons[0] & GetBinding(binding))\
// 	{\
// 		action = __DEST__[TILT_DIRECTION_NEUTRAL][state];\
// 	}\
// }\







#define _Merge(a, b) a##b
#define Merge(a, b) _Merge(a, b)

#define _ToString(a) #a
#define ToString(a) _ToString(a)






// @Research: Maybe templates are better suited for this after all.
// @Todo: Check for input charge.

#define BufferExecute(activeActorData, idleActorData, policy, binding, __DEST__, sect)\
if (activeActorData.nextActionRequestPolicy[policy] == NEXT_ACTION_REQUEST_POLICY_BUFFER)\
{\
	GetAction(activeActorData, binding, __DEST__);\
	if (action)\
	{\
		idleActorData.bufferedAction = action;\
		idleActorData.newBufferedActionPolicy = policy;\
		idleActorData.state |= STATE_BUSY;\
		MessageBoxA(0, Merge("BUFFER\n", ToString(policy)), 0, 0);\
	}\
}\
else if (activeActorData.nextActionRequestPolicy[policy] == NEXT_ACTION_REQUEST_POLICY_EXECUTE)\
{\
	if (idleActorData.bufferedAction && (idleActorData.newBufferedActionPolicy == policy))\
	{\
		idleActorData.newBufferedActionPolicy = 0;\
		idleActorData.state &= ~STATE_BUSY;\
		EndMotion(activeActorData);\
		MessageBoxA(0, Merge("BUFFER TRIGGERED FROM EXECUTE\n", ToString(policy)), 0, 0);\
		goto sect;\
	}\
	GetAction(activeActorData, binding, __DEST__);\
	if (action)\
	{\
		idleActorData.bufferedAction = action;\
		EndMotion(activeActorData);\
		MessageBoxA(0, Merge("EXECUTE\n", ToString(policy)), 0, 0);\
	}\
}\


/*

style stuff


weapon stuff

if active

check buffer

else

switch to actor and weapon

OnceStart
OnceEnd



CopyPosition

*/



















#define OnceEnable(actorData, index) actorData.newSect[index] = true
#define OnceDisable(actorData, index) actorData.newSect[index] = false
#define OnceStart(actorData, index) if (actorData.newSect[index]) { OnceDisable(actorData, index)
#define OnceEnd }



// template <typename T>
// bool IsVergilMeleeWeaponSelected(T & actorData)
// {
// 	auto & meleeWeapon = actorData.newMeleeWeapons[actorData.newMeleeWeaponIndex];
// 	if ((meleeWeapon >= WEAPON_YAMATO_VERGIL) && (meleeWeapon <= WEAPON_FORCE_EDGE))
// 	{
// 		return true;
// 	}
// 	return false;
// }

// template <typename T>
// bool IsDanteMeleeWeaponSelected(T & actorData)
// {
// 	auto weapon = actorData.newMeleeWeapons[actorData.newMeleeWeaponIndex];
// 	if ((weapon >= WEAPON_REBELLION) && (weapon <= WEAPON_BEOWULF_DANTE))
// 	{
// 		return true;
// 	}

// 	return false;
// }










template
<
	typename T1,
	typename T2
>
bool BufferFunction
(
	T1 & activeActorData,
	T2 & idleActorData,
	uint8 policy,
	uint8 binding,
	uint8(&map)[MAX_TILT_DIRECTION][2]
)
{

	
	


	if (IsActive(actorData))
	{
		if (actorData.nextActionRequestPolicy[policy] == NEXT_ACTION_REQUEST_POLICY_BUFFER)
		{
			auto action = GetAction(actorData, binding, map);
			if (action)
			{
				actorData.newExecute[0] = false;

				actorData.newEnable = false;
				cloneActorData.newEnable = true;
				cloneActorData.bufferedAction = action;
				cloneActorData.state |= STATE_BUSY;
			}
		}
		else if (actorData.nextActionRequestPolicy[policy] == NEXT_ACTION_REQUEST_POLICY_EXECUTE)
		{
			auto action = GetAction(actorData, binding, map);
			if (action)
			{
				actorData.newExecute[0] = false;

				actorData.newEnable = false;
				cloneActorData.newEnable = true;
				cloneActorData.bufferedAction = action;
				cloneActorData.state &= ~STATE_BUSY;
			}
		}
	}
	else
	{
		actorData.newExecute[0] = false;

		actorData.newEnable = false;
		cloneActorData.newEnable = true;
	}




}















bool executeCharacterSwitch[MAX_PLAYER] = {};












































void DanteVergil2(byte8 * baseAddr)
{
	auto & parentActorData = *reinterpret_cast<ActorDataDante *>(baseAddr);
	if (parentActorData.character != CHAR_DANTE)
	{
		return;
	}
	if (parentActorData.newParentBaseAddr)
	{
		return;
	}
	if (!parentActorData.newChildBaseAddr)
	{
		return;
	}
	auto & childActorData = *reinterpret_cast<ActorDataVergil *>(parentActorData.newChildBaseAddr);
	if (childActorData.character != CHAR_VERGIL)
	{
		return;
	}
	auto & gamepad = GetGamepad(0);


	



	// Only one actor can be active at any given time.

	// Active

	//if (IsActive(parentActorData))
	//{
	//	CopyPosition(parentActorData, childActorData);
	//}

	//if (IsActive(childActorData))
	//{
	//	CopyPosition(childActorData, parentActorData);
	//}

	// Idle

	if (!IsVergilMeleeWeaponSelected(parentActorData) && !IsActive(childActorData))
	{
		//CopyPosition(parentActorData, childActorData);
		OnceStart(parentActorData, 1);
		{
			FixPull(parentActorData);
		}
		OnceEnd;
	}
	else
	{
		OnceEnable(parentActorData, 1);
	}

	if (IsVergilMeleeWeaponSelected(parentActorData) && !IsActive(parentActorData))
	{
		//CopyPosition(childActorData, parentActorData);
		OnceStart(parentActorData, 0);
		{
			FixPull(childActorData);
		}
		OnceEnd;
	}
	else
	{
		OnceEnable(parentActorData, 0);
	}































	// Parent

	if (IsVergilMeleeWeaponSelected(parentActorData))
	{
		DisableControl(parentActorData);
	}

	if (!IsVergilMeleeWeaponSelected(parentActorData))
	{
		if (!IsActive(childActorData))
		{
			EnableControl(parentActorData);
		}
	}









	if (!IsVergilMeleeWeaponSelected(parentActorData))
	{
		if (IsActive(childActorData))
		{
			auto style = parentActorData.style;
			if (style > STYLE_DOPPELGANGER)
			{
				style = STYLE_SWORDMASTER;
			}

			auto meleeWeapon = parentActorData.weapons[parentActorData.meleeWeaponIndex];
			if (meleeWeapon > WEAPON_BEOWULF_DANTE)
			{
				meleeWeapon = WEAPON_REBELLION;
			}



			auto rangedWeapon = parentActorData.weapons[parentActorData.rangedWeaponIndex];
			if (rangedWeapon > WEAPON_KALINA_ANN)
			{
				rangedWeapon = WEAPON_EBONY_IVORY;
			}
			if (rangedWeapon >= WEAPON_EBONY_IVORY)
			{
				rangedWeapon -= WEAPON_EBONY_IVORY;
			}

			uint8 state = (childActorData.state & STATE_ON_FLOOR) ? 0 : 1;









			//BufferExecute(childActorData, parentActorData, NEXT_ACTION_REQUEST_POLICY_MELEE_ATTACK, BINDING_MELEE_ATTACK, meleeAttackDante[meleeWeapon], BufferExecuteEndDante);


			BufferExecute
			(
				childActorData,
				parentActorData,
				NEXT_ACTION_REQUEST_POLICY_MELEE_ATTACK,
				BINDING_MELEE_ATTACK,
				meleeAttackDante[meleeWeapon],
				BufferExecuteEndDante
			);






			switch (style)
			{
			case STYLE_DANTE_SWORDMASTER:
			{
				BufferExecute(childActorData, parentActorData, NEXT_ACTION_REQUEST_POLICY_SWORDMASTER_GUNSLINGER, BINDING_STYLE_ACTION, swordmasterDante[meleeWeapon], BufferExecuteEndDante);
				break;
			}
			case STYLE_DANTE_GUNSLINGER:
			{
				BufferExecute(childActorData, parentActorData, NEXT_ACTION_REQUEST_POLICY_SWORDMASTER_GUNSLINGER, BINDING_STYLE_ACTION, gunslingerDante[rangedWeapon], BufferExecuteEndDante);
				break;
			}
			case STYLE_DANTE_TRICKSTER:
			{
				BufferExecute(childActorData, parentActorData, NEXT_ACTION_REQUEST_POLICY_TRICKSTER_DARK_SLAYER, BINDING_STYLE_ACTION, tricksterDante, BufferExecuteEndDante);
				break;
			}
			case STYLE_DANTE_ROYALGUARD:
			{
				BufferExecute(childActorData, parentActorData, NEXT_ACTION_REQUEST_POLICY_ROYALGUARD, BINDING_STYLE_ACTION, royalguardDante, BufferExecuteEndDante);
				break;
			}
			}
			BufferExecute(childActorData, parentActorData, NEXT_ACTION_REQUEST_POLICY_RANGED_ATTACK, BINDING_SHOOT, rangedAttackDante[rangedWeapon], BufferExecuteEndDante);
			// Special case. Never has buffer state. Is run at the very end.
			if (childActorData.nextActionRequestPolicy[NEXT_ACTION_REQUEST_POLICY_END] == NEXT_ACTION_REQUEST_POLICY_EXECUTE)
			{
				EndMotion(childActorData);
			}
			BufferExecuteEndDante:;
		}
	}



























	// Child

	if (!IsVergilMeleeWeaponSelected(parentActorData))
	{
		DisableControl(childActorData);
	}

	if (IsVergilMeleeWeaponSelected(parentActorData))
	{
		if (!IsActive(parentActorData))
		{
			EnableControl(childActorData);
		}
	}

	if (IsVergilMeleeWeaponSelected(parentActorData))
	{
		if (IsActive(parentActorData))
		{
			auto meleeWeapon = childActorData.weapons[childActorData.queuedMeleeWeaponIndex];
			if (meleeWeapon > WEAPON_FORCE_EDGE)
			{
				meleeWeapon = WEAPON_YAMATO;
			}
			if (meleeWeapon >= WEAPON_YAMATO)
			{
				meleeWeapon -= WEAPON_YAMATO;
			}

			uint8 state = (parentActorData.state & STATE_ON_FLOOR) ? 0 : 1;

			BufferExecute(parentActorData, childActorData, NEXT_ACTION_REQUEST_POLICY_MELEE_ATTACK         , BINDING_MELEE_ATTACK, meleeAttackVergil[meleeWeapon], BufferExecuteEndVergil);
			BufferExecute(parentActorData, childActorData, NEXT_ACTION_REQUEST_POLICY_TRICKSTER_DARK_SLAYER, BINDING_STYLE_ACTION, darkSlayerVergil              , BufferExecuteEndVergil);
			if (parentActorData.nextActionRequestPolicy[NEXT_ACTION_REQUEST_POLICY_END] == NEXT_ACTION_REQUEST_POLICY_EXECUTE)
			{
				EndMotion(parentActorData);
			}
			BufferExecuteEndVergil:;
		}
	}















}

#undef BufferExecute
#undef ToString
#undef _ToString
#undef Merge
#undef _Merge
#undef GetAction
#undef OnceEnd
#undef OnceStart
#undef OnceDisable
#undef OnceEnable








void ActorLoop(byte8 * baseAddr)
{
	g_actorLoopCounter++;
	DanteVergil(baseAddr);







}





//void MainLoop()
//{
//
//	if (spawnActors)
//	{
//		spawnActors = false;
//		SpawnActors();
//		SetMainActor(Actor_actorBaseAddr[2]);
//	}
//
//
//}











// action on update

void AttackDataDante(byte8 * baseAddr)
{
	auto & actorData = *reinterpret_cast<ActorDataDante *>(baseAddr);
	auto & gamepad = GetGamepad(actorData.newGamepad);

	if (actorData.action == ACTION_DANTE_REBELLION_HELM_BREAKER)
	{











		if
		(
			(gamepad.buttons[0] & GetBinding(BINDING_LOCK_ON)) &&
			(GetRelativeTiltDirection(actorData) == TILT_DIRECTION_UP) &&
			(gamepad.buttons[0] & GetBinding(BINDING_MELEE_ATTACK))
		)
		{
			actorData.action = ACTION_DANTE_REBELLION_STINGER_LEVEL_2;
		}
	}
}
















void SetAction(byte8 * baseAddr)
{
	auto & actorData = *reinterpret_cast<ActorData *>(baseAddr);
	auto & gamepad = GetGamepad(actorData.newGamepad);

	if (actorData.action == ACTION_DANTE_REBELLION_HELM_BREAKER)
	{
		if
		(
			(gamepad.buttons[0] & GetBinding(BINDING_LOCK_ON)) &&
			(GetRelativeTiltDirection(actorData) == TILT_DIRECTION_UP) &&
			(gamepad.buttons[0] & GetBinding(BINDING_MELEE_ATTACK))
		)
		{
			if (actorData.newAirStingerCount > 0)
			{
				actorData.newAirStingerCount--;
				actorData.action = ACTION_DANTE_REBELLION_STINGER_LEVEL_2;
			}
		}
	}
}





//void SetStartPosition(byte8 * baseAddr)
//{
//	LogFunction(baseAddr);
//
//	auto & actorData = *reinterpret_cast<ActorData *>(baseAddr);
//
//	actorData.var_3E10[8] = 0;
//}







//void ResetMobilityCounters(byte8 * baseAddr)
//{
//	auto & actorData = *reinterpret_cast<ActorData *>(baseAddr);
//
//	actorData.newAirStingerCount = 2;
//
//
//
//
//}



export void Update_Init()
{
	LogFunction();
	Windows_GetTicksPerSecond(&ticksPerSecond);
	ticksPerMillisecond = (ticksPerSecond / 1000);
	Windows_GetTickCount(&savedTickCount);


	//vp_memset((appBaseAddr + 0x1F9189), 0x90, 8); // disable sub
	



	return;




	//{
	//	auto func = CreateFunction(SetStartPosition);
	//	WriteJump((appBaseAddr + 0x1DFD04), func.addr);
	//	/*
	//	dmc3.exe+1DFD04 - C3 - ret
	//	*/
	//}



















	//{
	//	constexpr byte8 sect0[] =
	//	{
	//		0x80, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x01, //cmp byte ptr [rcx+0000B8C0],01
	//		0x75, 0x05,                               //jne 7FF65022000E
	//		0xE8, 0x00, 0x00, 0x00, 0x00,             //call dmc3.exe+1DFDA0
	//	};
	//	auto func = CreateFunction(0, (appBaseAddr + 0x1E7BF7), false, true, sizeof(sect0));
	//	memcpy(func.sect0, sect0, sizeof(sect0));
	//	*reinterpret_cast<uint32 *>(func.sect0 + 2) = offsetof(ActorData, newEnable);
	//	WriteCall((func.sect0 + 9), (appBaseAddr + 0x1DFDA0));
	//	WriteJump((appBaseAddr + 0x1E7BF2), func.addr);
	//	/*
	//	dmc3.exe+1E7BF2 - E8 A981FFFF - call dmc3.exe+1DFDA0
	//	dmc3.exe+1E7BF7 - B0 01       - mov al,01
	//	*/
	//}




























	//{
	//	constexpr byte8 sect0[] =
	//	{
	//		0x41, 0x83, 0x78, 0x78, 0x00,                                     //cmp dword ptr [r8+78],00
	//		0x41, 0xC7, 0x80, 0x74, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //mov [r8+00006374],00000000
	//		0x41, 0xC6, 0x80, 0xAE, 0x3F, 0x00, 0x00, 0x00,                   //mov byte ptr [r8+00003FAE],00
	//		0x74, 0x10,                                                       //je dmc3.exe+1E0FF5
	//		0x41, 0xC6, 0x80, 0x13, 0x3F, 0x00, 0x00, 0x00,                   //mov byte ptr [r8+00003F13],00
	//		0x41, 0xC6, 0x80, 0x11, 0x3F, 0x00, 0x00, 0x00,                   //mov byte ptr [r8+00003F11],00
	//	};
	//	constexpr byte8 sect1[] =
	//	{
	//		0x49, 0x8B, 0xC8, //mov rcx,r8
	//	};
	//	constexpr byte8 sect2[] =
	//	{
	//		0xC3, //ret
	//	};
	//	auto func = CreateFunction(ResetMobilityCounters, 0, true, true, sizeof(sect0), sizeof(sect1), sizeof(sect2));
	//	memcpy(func.sect0, sect0, sizeof(sect0));
	//	memcpy(func.sect1, sect1, sizeof(sect1));
	//	memcpy(func.sect2, sect2, sizeof(sect2));
	//	//WriteJump((appBaseAddr + 0x1E0FCB), func.addr);
	//	/*
	//	dmc3.exe+1E0FCB - 41 83 78 78 00             - cmp dword ptr [r8+78],00
	//	dmc3.exe+1E0FD0 - 41 C7 80 74630000 00000000 - mov [r8+00006374],00000000
	//	dmc3.exe+1E0FDB - 41 C6 80 AE3F0000 00       - mov byte ptr [r8+00003FAE],00
	//	dmc3.exe+1E0FE3 - 74 10                      - je dmc3.exe+1E0FF5
	//	dmc3.exe+1E0FE5 - 41 C6 80 133F0000 00       - mov byte ptr [r8+00003F13],00
	//	dmc3.exe+1E0FED - 41 C6 80 113F0000 00       - mov byte ptr [r8+00003F11],00
	//	dmc3.exe+1E0FF5 - C3                         - ret
	//	*/
	//}




	////{
	////	constexpr byte8 sect0[] =
	////	{
	////		0x41, 0x88, 0x88, 0x5D, 0x63, 0x00, 0x00, //mov [r8+0000635D],cl
	////	};
	////	constexpr byte8 sect1[] =
	////	{
	////		0x49, 0x8B, 0xC8, //mov rcx,r8
	////	};
	////	auto func = CreateFunction(ResetMobilityCounters, (appBaseAddr + 0x1E0F6B), true, true, sizeof(sect0), sizeof(sect1));
	////	memcpy(func.sect0, sect0, sizeof(sect0));
	////	memcpy(func.sect1, sect1, sizeof(sect1));
	////	WriteJump((appBaseAddr + 0x1E0F64), func.addr, 2);
	////	/*
	////	dmc3.exe+1E0F64 - 41 88 88 5D630000- mov [r8+0000635D],cl
	////	dmc3.exe+1E0F6B - EB 5E            - jmp dmc3.exe+1E0FCB
	////	*/
	////}











	//{
	//	constexpr byte8 sect0[] =
	//	{
	//		0x88, 0x83, 0xA4, 0x3F, 0x00, 0x00, //mov [rbx+00003FA4],al
	//	};
	//	constexpr byte8 sect1[] =
	//	{
	//		0x48, 0x8B, 0xCB, //mov rcx,rbx
	//	};
	//	auto func = CreateFunction(SetAction, (appBaseAddr + 0x1E6D90), true, true, sizeof(sect0), sizeof(sect1));
	//	memcpy(func.sect0, sect0, sizeof(sect0));
	//	memcpy(func.sect1, sect1, sizeof(sect1));
	//	WriteJump((appBaseAddr + 0x1E6D8A), func.addr, 1);
	//	/*
	//	dmc3.exe+1E6D8A - 88 83 A43F0000        - mov [rbx+00003FA4],al
	//	dmc3.exe+1E6D90 - 48 63 83 90640000     - movsxd  rax,dword ptr [rbx+00006490]
	//	*/
	//}







	//// Skip and permissions when in air.
	//{
	//	constexpr byte8 sect0[] =
	//	{
	//		0xF7, 0x87, 0x64, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //test [rdi+00003E64],0002
	//		0x75, 0x05,                                                 //jne 7FF64D220011
	//		0xE8, 0x00, 0x00, 0x00, 0x00,                               //call dmc3.exe+1E0B60
	//	};
	//	auto func = CreateFunction(0, (appBaseAddr + 0x2093F2), false, true, sizeof(sect0));
	//	memcpy(func.sect0, sect0, sizeof(sect0));
	//	*reinterpret_cast<uint32 *>(func.sect0 + 6) = STATE_IN_AIR;
	//	WriteCall((func.sect0 + 0xC), (appBaseAddr + 0x1E0B60));
	//	WriteJump((appBaseAddr + 0x2093ED), func.addr);
	//	/*
	//	dmc3.exe+2093ED - E8 6E77FDFF      - call dmc3.exe+1E0B60
	//	dmc3.exe+2093F2 - 0FB7 87 C0000000 - movzx eax,word ptr [rdi+000000C0]
	//	*/
	//}

	//// Skip leap when in air.
	//{
	//	constexpr byte8 sect0[] =
	//	{
	//		0xF7, 0x87, 0x64, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //test [rdi+00003E64],0002
	//		0x0F, 0x85, 0x00, 0x00, 0x00, 0x00,                         //jne dmc3.exe+2094A7
	//		0x80, 0xBF, 0x2A, 0x3E, 0x00, 0x00, 0x01,                   //cmp byte ptr [rdi+00003E2A],01
	//		0x0F, 0x85, 0x00, 0x00, 0x00, 0x00,                         //jne dmc3.exe+2094A7
	//	};
	//	auto func = CreateFunction(0, (appBaseAddr + 0x209462), false, true, sizeof(sect0));
	//	memcpy(func.sect0, sect0, sizeof(sect0));
	//	*reinterpret_cast<uint32 *>(func.sect0 + 6) = STATE_IN_AIR;
	//	WriteAddress((func.sect0 + 0xA), (appBaseAddr + 0x2094A7), 6);
	//	WriteAddress((func.sect0 + 0x17), (appBaseAddr + 0x2094A7), 6);
	//	WriteJump((appBaseAddr + 0x209459), func.addr, 2);
	//	/*
	//	dmc3.exe+209459 - 80 BF 2A3E0000 01 - cmp byte ptr [rdi+00003E2A],01
	//	dmc3.exe+209460 - 75 45             - jne dmc3.exe+2094A7
	//	dmc3.exe+209462 - 0FB7 97 C0000000  - movzx edx,word ptr [rdi+000000C0]
	//	*/
	//}






	









	// @Research: Where did I get this from?
	// Maybe prefer root update.


	//{
	//	constexpr byte8 sect1[] =
	//	{
	//		0x48, 0x8B, 0xCB, //mov rcx,rbx
	//	};
	//	constexpr byte8 sect2[] =
	//	{
	//		0x48, 0x83, 0xC4, 0x20, //add rsp,20
	//		0x5B,                   //pop rbx
	//	};
	//	auto func = CreateFunction(ActorLoop, (appBaseAddr + 0x1DFAB4), true, true, 0, sizeof(sect1), sizeof(sect2));
	//	memcpy(func.sect1, sect1, sizeof(sect1));
	//	memcpy(func.sect2, sect2, sizeof(sect2));
	//	WriteJump((appBaseAddr + 0x1DFAAF), func.addr);
	//	/*
	//	dmc3.exe+1DFAAF - 48 83 C4 20 - add rsp,20
	//	dmc3.exe+1DFAB3 - 5B          - pop rbx
	//	dmc3.exe+1DFAB4 - E9 C7711400 - jmp dmc3.exe+326C80
	//	*/
	//}
	//{
	//	byte8 sect0[] =
	//	{
	//		0xE8, 0x00, 0x00, 0x00, 0x00, //call dmc3.exe+23B060
	//	};
	//	auto func = CreateFunction(MainLoop, (appBaseAddr + 0x23D4B7), true, true, sizeof(sect0));
	//	memcpy(func.sect0, sect0, sizeof(sect0));
	//	WriteCall(func.sect0, (appBaseAddr + 0x23B060));
	//	WriteJump((appBaseAddr + 0x23D4B2), func.addr);
	//	/*
	//	dmc3.exe+23D4B2 - E8 A9DBFFFF - call dmc3.exe+23B060
	//	dmc3.exe+23D4B7 - 84 C0       - test al,al
	//	*/
	//}
}

#ifdef __GARBAGE__








auto weapon = actorData.newMeleeWeapon[actorData.newMeleeWeaponIndex];





	if
	(
		IsDanteMeleeWeapon(weapon) &&
		!IsDanteMeleeWeapon(actorData.newLastMeleeWeapon)
	)
	{















		if (!IsDanteMeleeWeapon(acotrData.newLastMeleeWeapon))
		{

		}
		else
		{
			if (actorData.newSect[0])
			{
				actorData.newSect[0] = false;

				cloneActorData.meleeWeaponIndex = weapon;
			}
		}
	}
	else
	{
		actorData.newSect[0] = true;
	}






	if
	(
		IsVergilMeleeWeapon(weapon) &&
		!IsVergilMeleeWeapon(actorData.newLastMeleeWeapon)
	)
	{
		if (IsActive(cloneActorData))
		{
			if (cloneActorData.nextActionRequestPolicy[NEXT_ACTION_REQUEST_POLICY_MELEE_ATTACK] == NEXT_ACTION_REQUEST_POLICY_BUFFER)
			{
				auto action = GetAction(cloneActorData, BINDING_MELEE_ATTACK, meleeAttackVergil[weapon]);
				if (action)
				{
					if (actorData.newSect[1])
					{
						actorData.newSect[1] = false;

						memset(cloneActorData.newEnable, 0, 8);
						memset(actorData.newEnable, 1, 8);

						actorData.bufferedAction = action;
						actorData.state |= STATE_BUSY;
					}
				}
			}
			else if (cloneActorData.nextActionRequestPolicy[NEXT_ACTION_REQUEST_POLICY_MELEE_ATTACK] == NEXT_ACTION_REQUEST_POLICY_EXECUTE)
			{
				auto action = GetAction(cloneActorData, BINDING_MELEE_ATTACK, meleeAttackVergil[weapon]);
				if (action)
				{
					if (actorData.newSect[1])
					{
						actorData.newSect[1] = false;

						memset(cloneActorData.newEnable, 0, 8);
						memset(actorData.newEnable, 1, 8);

						actorData.bufferedAction = action;
						actorData.state &= ~STATE_BUSY;
					}
				}
			}
		}
		else
		{
			if (actorData.newSect[1])
			{
				actorData.newSect[1] = false;

				memset(cloneActorData.newEnable, 0, 8);
				memset(actorData.newEnable, 1, 8);
			}
		}
	}
	else
	{
		actorData.newSect[1] = true;
	}







#endif

#endif
