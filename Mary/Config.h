#pragma once
#include "../Core/Core.h"

#include "Vars.h"

#pragma pack(push, 1)
struct CONFIG
{
	struct
	{
		float32 height      = 140;
		float32 tilt        = 0.25f;
		float32 zoom        = 460;
		float32 zoomLockOn  = 400;
		bool    applyConfig = false;
		uint32  rate        = 1000;
	}
	Camera;
	struct
	{
		struct
		{
			float32 base  = 1;
			float32 turbo = 1.2f;
			float32 actor = 1;
			float32 enemy = 1;
		}
		Main;
		struct
		{
			float32 dante[6] =
			{
				1.1f,
				1.2f,
				1.05f,
				1.1f,
				1.05f,
				1.1f,
			};
			float32 vergil[3] =
			{
				1.2f,
				1.2f,
				1.2f,
			};
			float32 neroAngelo[3] =
			{
				1,
				1,
				1,
			};
		}
		Devil;
		struct
		{
			float32 actor = 1.05f;
			float32 enemy = 0.33f;
		}
		Quicksilver;
	}
	Speed;
	struct
	{
		struct
		{
			bool forceSingleActor = false;
			bool disableIdleTimer = false;
		}
		Actor;
		struct
		{
			bool invertX = false;
		}
		Camera;
		struct
		{
			bool skipIntro     = false;
			bool skipCutscenes = false;
		}
		Event;
		struct
		{
			bool preferLocalFiles = true;
		}
		File;
		struct
		{
			uint32 frameRate = 60;
			uint8  vSync     = 0;
		}
		Graphics;
		struct
		{
			bool hideMouseCursor = true;
		}
		Input;
		struct
		{
			bool forceFocus = true;
		}
		Window;
	}
	System;
	struct
	{
		struct
		{
			bool   enable         = false;
			uint32 mission        = 1;
			uint32 mode           = MODE_NORMAL;
			uint16 room           = 0;
			bool   ignoreRoom     = false;
			uint16 position       = 0;
			bool   ignorePosition = false;
			struct
			{
				uint8 floor = 0;
			}
			BloodyPalace;
			uint8  character    = CHAR_DANTE;
			uint8  costume      = 0;
			uint32 style        = STYLE_TRICKSTER;
			uint8  equipment[4] =
			{
				WEAPON_REBELLION,
				WEAPON_CERBERUS,
				WEAPON_EBONY_IVORY,
				WEAPON_SHOTGUN,
			};
			float32 hitPoints   = 6000;
			float32 magicPoints = 3000;
		}
		Arcade;
		struct
		{
			bool enable = false;
			struct
			{
				bool skipJester = false;
			}
			Mission5;
			struct
			{
				bool skipJester = false;
				bool skipGeryonBridgeBattle = false;
			}
			Mission12;
			struct
			{
				bool skipJester = false;
			}
			Mission17;
			struct
			{
				bool skipFirstPart = false;
			}
			Mission19;
		}
		BossRush;
		struct
		{
			bool enable = false;
			struct
			{
				bool infiniteSwordPierce = false;
				bool unlockQuickDrive    = false;
			}
			Rebellion;
			struct
			{
				bool foursomeTime      = false;
				bool infiniteRainStorm = false;
			}
			EbonyIvory;
			struct
			{
				bool swap    = false;
				bool instant = false;
			}
			Artemis;
			struct
			{
				bool coreAbility = false;
			}
			AirHike;
			struct
			{
				uint8 levelMultiplier = 6;
			}
			CrazyCombo;
			struct
			{
				float32 melee  = 12;
				float32 ranged = 12;
			}
			WeaponSwitchTimeout;
		}
		Dante;
		struct
		{
			bool  enable             = false;
			uint8 character          = CHAR_DANTE;
			bool  enableDevilTrigger = false;
		}
		Doppelganger;
		struct
		{
			bool enable = false;
			struct MOBILITY
			{
				struct
				{
					uint8 airHike = 1;
					uint8 dash[3] =
					{
						1,
						2,
						3,
					};
					uint8 skyStar  = 1;
					uint8 airTrick = 1;
				}
				Dante;
				struct
				{
					uint8 airTrick  = 1;
					uint8 trickUp   = 1;
					uint8 trickDown = 1;
				}
				Vergil;
			};
			MOBILITY Human;
			MOBILITY Devil;
		}
		Mobility;
		struct
		{
			bool  enable                      = false;
			uint8 actorCount                  = 1;
			uint8 character [(MAX_ACTOR - 1)] = {};
			uint8 costume   [(MAX_ACTOR - 1)] = {};
		}
		Multiplayer;
		struct
		{
			bool  enable   = false;
			float32 orbReach = 300;
			struct
			{
				float32 devil        = 11;
				float32 quicksilver  = 16.5f;
				float32 doppelganger = 16.5f;
			}
			MagicPointsDepletionRate;
		}
		Other;
		struct
		{
			bool   enable = false;
			byte16 button = GAMEPAD_UP;
		}
		ResetMotionState;
		struct
		{
			bool enable               = false;
			bool noDoubleTap          = false;
		}
		StyleSwitcher;
		struct
		{
			bool enable              = false;
			bool infiniteHitPoints   = false;
			bool infiniteMagicPoints = false;
			bool disableTimer        = false;
		}
		Training;
		struct
		{
			bool enable = false;
			struct
			{
				bool infiniteRoundTrip = false;
			}
			ForceEdge;
			struct
			{
				bool chronoSwords = false;
			}
			SummonedSwords;
			struct
			{
				float32 melee = 8;
			}
			WeaponSwitchTimeout;
		}
		Vergil;
		struct
		{
			bool  enable = false;
			uint8 devil  = DEVIL_DANTE_REBELLION;
			uint8 sword  = 0;
			struct
			{
				uint8 count     = 5;
				uint8 weapon[5] =
				{
					WEAPON_REBELLION,
					WEAPON_CERBERUS,
					WEAPON_AGNI_RUDRA,
					WEAPON_NEVAN,
					WEAPON_BEOWULF,
				};
			}
			Melee;
			struct
			{
				uint8 count     = 5;
				uint8 weapon[5] =
				{
					WEAPON_EBONY_IVORY,
					WEAPON_SHOTGUN,
					WEAPON_ARTEMIS,
					WEAPON_SPIRAL,
					WEAPON_KALINA_ANN,
				};
			}
			Ranged;
		}
		WeaponSwitcher;
	}
	Game;
	struct
	{
		struct
		{
			struct
			{
				float32 dante[5][4] =
				{
					{ 128,   0,   0, 200 },
					{  96, 128, 144, 200 },
					{ 160,  64,  16, 200 },
					{ 112,  64, 160, 200 },
					{ 128, 128, 128, 200 },
				};
				float32 vergil[1][4] =
				{
					{ 32, 64, 128, 200 },
				};
				float32 neroAngelo[1][4] =
				{
					{ 64, 0, 255, 200 },
				};
			}
			Aura;
			struct
			{
				float32 trickster[1][4] =
				{
					{ 255, 0, 0, 200 },
				};
				float32 royalguard[1][4] =
				{
					{ 143, 112, 48, 200 },
				};
				float32 doppelganger[1][4] =
				{
					{ 16, 16, 16, 48 },
				};
			}
			Style;
			struct
			{
				float32 dante[5][4] =
				{
					{ 128,   0,   0, 200 },
					{  96, 128, 144, 200 },
					{ 160,  64,  16, 200 },
					{ 112,  64, 160, 200 },
					{ 128, 128, 128, 200 },
				};
			}
			AirHike;
		}
		Color;
		struct
		{
			struct
			{
				bool hideModel = false;
			}
			Beowulf;
		}
		Dante;
		struct
		{
			bool noColor = false;
		}
		Doppelganger;


		struct
		{
			struct
			{
				MODEL_FILE_DATA modelFile[MAX_MODEL] =
				{
					{ pl000, 1  },
					{ pl000, 12 },
				};
				MODEL_FILE_DATA textureFile[MAX_MODEL] =
				{
					{ pl000, 0 },
					{ pl000, 0 },
				};
				MODEL_FILE_DATA shadowFile[MAX_MODEL] =
				{
					{ pl000, 0 },
					{ pl000, 0 },
				};
				MODEL_FILE_DATA physicsFile[MAX_MODEL] =
				{
					{ pl000, 0 },
					{ pl000, 0 },
				};
			}
			DanteDefault;
			struct
			{
				MODEL_FILE_DATA modelFile[MAX_MODEL] =
				{
					{ pl011, 1  },
					{ pl011, 12 },
				};
				MODEL_FILE_DATA textureFile[MAX_MODEL] =
				{
					{ pl011, 0 },
					{ pl011, 0 },
				};
				MODEL_FILE_DATA shadowFile[MAX_MODEL] =
				{
					{ pl011, 0 },
					{ pl011, 0 },
				};
				MODEL_FILE_DATA physicsFile[MAX_MODEL] =
				{
					{ pl011, 0 },
					{ pl011, 0 },
				};
			}
			DanteDefaultNoCoat;
			struct
			{
				MODEL_FILE_DATA modelFile[MAX_MODEL] =
				{
					{ pl013, 1  },
					{ pl013, 12 },
				};
				MODEL_FILE_DATA textureFile[MAX_MODEL] =
				{
					{ pl013, 0 },
					{ pl013, 0 },
				};
				MODEL_FILE_DATA shadowFile[MAX_MODEL] =
				{
					{ pl013, 0 },
					{ pl013, 0 },
				};
				MODEL_FILE_DATA physicsFile[MAX_MODEL] =
				{
					{ pl013, 0 },
					{ pl013, 0 },
				};
			}
			DanteDefaultTorn;
			struct
			{
				MODEL_FILE_DATA modelFile[MAX_MODEL] =
				{
					{ pl015, 1  },
					{ pl015, 12 },
				};
				MODEL_FILE_DATA textureFile[MAX_MODEL] =
				{
					{ pl015, 0 },
					{ pl015, 0 },
				};
				MODEL_FILE_DATA shadowFile[MAX_MODEL] =
				{
					{ pl015, 0 },
					{ pl015, 0 },
				};
				MODEL_FILE_DATA physicsFile[MAX_MODEL] =
				{
					{ pl015, 0 },
					{ pl015, 0 },
				};
			}
			DanteDMC1;
			struct
			{
				MODEL_FILE_DATA modelFile[MAX_MODEL] =
				{
					{ pl016, 1  },
					{ pl016, 12 },
				};
				MODEL_FILE_DATA textureFile[MAX_MODEL] =
				{
					{ pl016, 0 },
					{ pl016, 0 },
				};
				MODEL_FILE_DATA shadowFile[MAX_MODEL] =
				{
					{ pl016, 0 },
					{ pl016, 0 },
				};
				MODEL_FILE_DATA physicsFile[MAX_MODEL] =
				{
					{ pl016, 0 },
					{ pl016, 0 },
				};
			}
			DanteDMC1NoCoat;
			struct
			{
				MODEL_FILE_DATA modelFile[MAX_MODEL] =
				{
					{ pl018, 1  },
					{ pl018, 12 },
				};
				MODEL_FILE_DATA textureFile[MAX_MODEL] =
				{
					{ pl018, 0 },
					{ pl018, 0 },
				};
				MODEL_FILE_DATA shadowFile[MAX_MODEL] =
				{
					{ pl018, 0 },
					{ pl018, 0 },
				};
				MODEL_FILE_DATA physicsFile[MAX_MODEL] =
				{
					{ pl018, 0 },
					{ pl018, 0 },
				};
			}
			DanteSparda;
		}
		ModelHelper;
		struct
		{
			struct
			{
				MODEL_FILE_DATA modelFile[MAX_MODEL] =
				{
					{ pl005, 1  },
					{ pl005, 12 },
				};
				MODEL_FILE_DATA textureFile[MAX_MODEL] =
				{
					{ pl005, 0 },
					{ pl005, 0 },
				};
				MODEL_FILE_DATA shadowFile[MAX_MODEL] =
				{
					{ pl005, 0 },
					{ pl005, 0 },
				};
				MODEL_FILE_DATA physicsFile[MAX_MODEL] =
				{
					{ pl005, 0 },
					{ pl005, 0 },
				};
			}
			DanteRebellion;
			struct
			{
				MODEL_FILE_DATA modelFile[MAX_MODEL] =
				{
					{ pl006, 1  },
					{ pl006, 12 },
				};
				MODEL_FILE_DATA textureFile[MAX_MODEL] =
				{
					{ pl006, 0 },
					{ pl006, 0 },
				};
				MODEL_FILE_DATA shadowFile[MAX_MODEL] =
				{
					{ pl006, 0 },
					{ pl006, 0 },
				};
				MODEL_FILE_DATA physicsFile[MAX_MODEL] =
				{
					{ pl006, 0 },
					{ pl006, 0 },
				};
			}
			DanteCerberus;
			struct
			{
				MODEL_FILE_DATA modelFile[MAX_MODEL] =
				{
					{ pl007, 1  },
					{ pl007, 12 },
				};
				MODEL_FILE_DATA textureFile[MAX_MODEL] =
				{
					{ pl007, 0 },
					{ pl007, 0 },
				};
				MODEL_FILE_DATA shadowFile[MAX_MODEL] =
				{
					{ pl007, 0 },
					{ pl007, 0 },
				};
				MODEL_FILE_DATA physicsFile[MAX_MODEL] =
				{
					{ pl007, 0 },
					{ pl007, 0 },
				};
			}
			DanteAgniRudra;
			struct
			{
				MODEL_FILE_DATA modelFile[MAX_MODEL] =
				{
					{ pl008, 1  },
					{ pl008, 12 },
				};
				MODEL_FILE_DATA textureFile[MAX_MODEL] =
				{
					{ pl008, 0 },
					{ pl008, 0 },
				};
				MODEL_FILE_DATA shadowFile[MAX_MODEL] =
				{
					{ pl008, 0 },
					{ pl008, 0 },
				};
				MODEL_FILE_DATA physicsFile[MAX_MODEL] =
				{
					{ pl008, 0 },
					{ pl008, 0 },
				};
			}
			DanteNevan;
			struct
			{
				MODEL_FILE_DATA modelFile[MAX_MODEL] =
				{
					{ pl009, 1  },
					{ pl009, 12 },
				};
				MODEL_FILE_DATA textureFile[MAX_MODEL] =
				{
					{ pl009, 0 },
					{ pl009, 0 },
				};
				MODEL_FILE_DATA shadowFile[MAX_MODEL] =
				{
					{ pl009, 0 },
					{ pl009, 0 },
				};
				MODEL_FILE_DATA physicsFile[MAX_MODEL] =
				{
					{ pl009, 0 },
					{ pl009, 0 },
				};
			}
			DanteBeowulf;
			struct
			{
				MODEL_FILE_DATA modelFile[MAX_MODEL] =
				{
					{ pl017, 1  },
					{ pl017, 12 },
				};
				MODEL_FILE_DATA textureFile[MAX_MODEL] =
				{
					{ pl017, 0 },
					{ pl017, 0 },
				};
				MODEL_FILE_DATA shadowFile[MAX_MODEL] =
				{
					{ pl017, 0 },
					{ pl017, 0 },
				};
				MODEL_FILE_DATA physicsFile[MAX_MODEL] =
				{
					{ pl017, 0 },
					{ pl017, 0 },
				};
			}
			DanteSparda;
		}
		DevilModelHelper;
		struct
		{
			bool noDevilForm = false;
		}
		Other;
		struct
		{
			struct
			{
				bool hideModel = false;
			}
			Beowulf;
		}
		Vergil;
	}
	Cosmetics;
	struct
	{
		struct
		{
			bool    enable        = false;
			float32 x             = 0;
			float32 y             = 0;
			uint8   fontSizeIndex = 2;
			float32 color[4]      = { 1, 0, 0, 1 };
			bool    focus         = true;
			bool    memory        = true;
		}
		Overlay;
	}
	Tools;
};
#pragma pack(pop)

extern CONFIG Config;
extern CONFIG DefaultConfig;
