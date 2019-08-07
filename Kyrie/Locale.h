#pragma once
#include "../Core/Core.h"

struct LOCALE
{
	struct
	{
		const char * label[4] =
		{
			"Game",
			"System",
			"Tools",
			"Debug",
		};
	}
	Main;
	struct
	{
		struct
		{
			const char * header = "Arcade";
			const char * enable = "Enable";
			struct
			{
				const char * label = "Character";
				const char * items[5] =
				{
					"Dante",
					"Nero",
					"Vergil",
					"Trish",
					"Lady",
				};
			}
			Character;













			const char * reset = "Reset";

		}
		Arcade;
		struct
		{
			const char * header = "Multiplayer";
			const char * enable = "Enable";
			struct
			{
				const char * items[5] =
				{
					"Dante",
					"Nero",
					"Vergil",
					"Trish",
					"Lady",
				};
			}
			Character;
			const char * spawnDelay = "Spawn Delay";
			const char * reset = "Reset";
		}
		Multiplayer;
		struct
		{
			const char * header = "Training";
			const char * enable = "Enable";
			const char * infiniteHitPoints = "Infinite Hit Points";
			const char * infiniteMagicPoints = "Infinite Magic Points";
			const char * disableTimer = "Disable Timer";
			const char * reset = "Reset";
		}
		Training;
	}
	Game;
	struct
	{
		//struct
		//{
		//	const char * header = "Media";
		//	const char * skipIntro = "Skip Intro";
		//	struct
		//	{
		//		const char * label = "Game";
		//		const char * items[3] =
		//		{
		//			"Dante / Nero",
		//			"Vergil",
		//			"Trish / Lady",
		//		};
		//	}
		//	skipIntroGame;
		//}
		//Media;
		//struct
		//{
		//	const char * header = "Speed";
		//	const char * global = "Global";
		//	const char * menu = "Menu";
		//	const char * reset = "Reset";

		//}
		//Speed;
		struct
		{
			const char * header = "Window";
			const char * forceFocus = "Force Focus";
			const char * borderless = "Borderless";

		}
		Window;
	}
	System;
	//struct
	//{
	//	struct
	//	{
	//		const char * header = "Fixes";
	//		const char * replaceMemoryAllocationFunctions = "Replace Memory Allocation Functions";
	//	}
	//	Fixes;
	//	struct
	//	{
	//		const char * header = "Timers";
	//		const char * disableActorIdleTimer = "Disable Actor Idle Timer";
	//		const char * disableAutosaveMenuTimer = "Disable Autosave Menu Timer";
	//		const char * disableMainMenuTimer = "Disable Main Menu Timer";
	//	}
	//	Timers;
	//}
	//Debug;











	const char * restart = "Restart App!";
};

extern LOCALE Locale;
