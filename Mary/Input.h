#pragma once
#include "../Core/Core.h"

#include "ActorData.h"
#include "Vars.h"

enum TILT_DIRECTION
{
	TILT_DIRECTION_NEUTRAL,
	TILT_DIRECTION_UP,
	TILT_DIRECTION_RIGHT,
	TILT_DIRECTION_DOWN,
	TILT_DIRECTION_LEFT,
	MAX_TILT_DIRECTION,
};

inline ENGINE_GAMEPAD & GetGamepad(uint8 index)
{
	return (reinterpret_cast<ENGINE_GAMEPAD *>(appBaseAddr + 0xD54A10 + 0x550))[index];
}

inline byte16 GetBinding(uint8 index)
{
	return (reinterpret_cast<byte16 *>(appBaseAddr + 0xD6CE80 + 0xA))[index];
}

inline uint8 GetRelativeTiltDirection(byte8 * baseAddr)
{
	auto & gamepad = GetGamepad(0);
	auto & actorData = *reinterpret_cast<ACTOR_DATA *>(baseAddr);
	uint16 relativeTilt = 0;
	if (gamepad.leftStickRadius < LEFT_STICK_DEADZONE)
	{
		return TILT_DIRECTION_NEUTRAL;
	}
	relativeTilt = (actorData.actorCameraDirection - gamepad.leftStickPosition);
	{
		uint16 value = (relativeTilt - 0x6000);
		if (value <= 0x4000)
		{
			return TILT_DIRECTION_UP;
		}
	}
	{
		uint16 value = (relativeTilt + 0x6000);
		if (value <= 0x4000)
		{
			return TILT_DIRECTION_RIGHT;
		}
	}
	{
		uint16 value = (relativeTilt + 0x2000);
		if (value <= 0x4000)
		{
			return TILT_DIRECTION_DOWN;
		}
	}
	{
		uint16 value = (relativeTilt - 0x2000);
		if (value <= 0x4000)
		{
			return TILT_DIRECTION_LEFT;
		}
	}
	return TILT_DIRECTION_NEUTRAL;
}
