#ifndef __MODULE_GUI__
#define __MODULE_GUI__

module;
#include "../Core/Core.h"
#include "../Core/GUI.h"

#include "../ImGui/imgui.h"

#include "ActorData.h"
#include "Internal.h"
#include "Locale.h"
#include "Vars.h"
export module ModuleName(GUI);

import ModuleName(Actor);
import ModuleName(Arcade);
import ModuleName(Camera);
import ModuleName(Config);
import ModuleName(Event);
import ModuleName(File);
import ModuleName(Pause);
import ModuleName(Speed);
import ModuleName(State);
import ModuleName(Training);
import ModuleName(Window);

#ifdef __INTELLISENSE__
#include "Actor.ixx"
#include "Arcade.ixx"
#include "Camera.ixx"
#include "Config.ixx"
#include "Event.ixx"
#include "File.ixx"
#include "Pause.ixx"
#include "Speed.ixx"
#include "State.ixx"
#include "Training.ixx"
#include "Window.ixx"
#endif
















enum FONT_
{
	FONT_DEFAULT,
	FONT_MAIN,
	FONT_OVERLAY_8,
	FONT_OVERLAY_16,
	FONT_OVERLAY_32,
	FONT_OVERLAY_64,
	FONT_OVERLAY_128,
};

enum TAB_
{
	TAB_GAME,
	TAB_COSMETICS,
	TAB_TOOLS,
	MAX_TAB,
	TAB_VOID,
};

constexpr bool debug = false;

uint8 activeTab = TAB_VOID;

bool GUI_Overlay_run = false;

ImVec2 GUI_System_size     = ImVec2(300, 500);
ImVec2 GUI_Game_size       = ImVec2(500, 500);
ImVec2 GUI_Cosmetics_size  = ImVec2(400, 500);
ImVec2 GUI_Tools_size      = ImVec2(300, 500);

ImVec2 GUI_Camera_size     = ImVec2(400, 400);
ImVec2 GUI_Speed_size      = ImVec2(300, 180);
ImVec2 GUI_Teleporter_size = ImVec2(120, 180);
ImVec2 GUI_Overlay_size    = ImVec2(300, 300);

bool GUI_Camera_show     = false;
bool GUI_Speed_show      = false;
bool GUI_Teleporter_show = false;


// @Todo: Private.

static void BuildFonts()
{
	ImGuiIO & io = ImGui::GetIO();
	io.Fonts->AddFontDefault();
	char overlayFont[512];
	{
		char buffer[64];
		GetWindowsDirectoryA(buffer, sizeof(buffer));
		snprintf(overlayFont, sizeof(overlayFont), "%s\\Fonts\\consola.ttf", buffer);
	}
	io.Fonts->AddFontFromFileTTF(overlayFont, 17);
	io.Fonts->AddFontFromFileTTF(overlayFont, 8);
	io.Fonts->AddFontFromFileTTF(overlayFont, 16);
	io.Fonts->AddFontFromFileTTF(overlayFont, 32);
	io.Fonts->AddFontFromFileTTF(overlayFont, 64);
	io.Fonts->AddFontFromFileTTF(overlayFont, 128);
	io.Fonts->Build();
}

#pragma region System

void GUI_System_Actor()
{
	GUI_Hyperlink(Locale.System.Actor.header);
	ImGui::Text("");
	GUI_Checkbox
	(
		Locale.System.Actor.forceSingleActor,
		Config.System.Actor.forceSingleActor
	);
	if (GUI_Checkbox
	(
		Locale.System.Actor.disableIdleTimer,
		Config.System.Actor.disableIdleTimer
	))
	{
		//System_Actor_ToggleDisableIdleTimer(Config.System.Actor.disableIdleTimer);
	}
}

void GUI_System_Camera()
{
	GUI_Hyperlink(Locale.System.Camera.header);
	ImGui::Text("");
	if (GUI_Checkbox
	(
		Locale.System.Camera.invertX,
		Config.System.Camera.invertX
	))
	{
		//System_Camera_ToggleInvertX(Config.System.Camera.invertX);
	}
}

//void GUI_System_Event()
//{
//	GUI_Hyperlink(Locale.System.Event.header);
//	ImGui::Text("");
//	if (GUI_Checkbox
//	(
//		Locale.System.Event.skipIntro,
//		Config.System.Event.skipIntro
//	))
//	{
//		Event_ToggleSkipIntro(Config.System.Event.skipIntro);
//	}
//	if (GUI_Checkbox
//	(
//		Locale.System.Event.skipCutscenes,
//		Config.System.Event.skipCutscenes
//	))
//	{
//		Event_ToggleSkipCutscenes(Config.System.Event.skipCutscenes);
//	}
//}
//
//void GUI_System_File()
//{
//	GUI_Hyperlink(Locale.System.File.header);
//	ImGui::Text("");
//	GUI_Checkbox
//	(
//		Locale.System.File.preferLocalFiles,
//		Config.System.File.preferLocalFiles
//	);
//}

//void GUI_System_Graphics()
//{
//	GUI_Hyperlink(Locale.System.Graphics.header);
//	ImGui::Text("");
//	ImGui::PushItemWidth(150);
//	GUI_InputEx<uint32>
//	(
//		Locale.System.Graphics.frameRate,
//		Config.System.Graphics.frameRate
//	);
//	ImGui::SameLine();
//	GUI_Tooltip(Locale.System.Graphics.frameRateHint);
//	GUI_Combo<uint8>
//	(
//		Locale.System.Graphics.VSync.label,
//		Locale.System.Graphics.VSync.items,
//		countof(Locale.System.Graphics.VSync.items),
//		Config.System.Graphics.vSync
//	);
//	ImGui::PopItemWidth();
//}
//
//void GUI_System_Input()
//{
//	GUI_Hyperlink(Locale.System.Input.header);
//	ImGui::Text("");
//	GUI_Checkbox
//	(
//		Locale.System.Input.hideMouseCursor,
//		Config.System.Input.hideMouseCursor
//	);
//}
//
//void GUI_System_Window()
//{
//	GUI_Hyperlink(Locale.System.Window.header);
//	ImGui::Text("");
//	if (GUI_Checkbox(
//		Locale.System.Window.forceFocus,
//		Config.System.Window.forceFocus
//	))
//	{
//		Window_ToggleForceFocus(Config.System.Window.forceFocus);
//	}
//}

void GUI_System_Draw()
{
	static bool run = false;
	if (!run)
	{
		run = true;
		ImGui::SetNextWindowSize(ImVec2(GUI_System_size.x + 16, GUI_System_size.y + 16));
		ImGui::SetNextWindowPos(ImVec2(0, 25));
	}
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(1, 1));
	if (ImGui::Begin("GUI_System", &pause, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
	{
		GUI_System_Actor();
		ImGui::Text("");
		GUI_System_Camera();
	}
	ImGui::End();
	ImGui::PopStyleVar(3);
}

#pragma endregion

#pragma region Game

//void GUI_Arcade()
//{
//
//
//	//static uint8 character = CHAR_DANTE;
//
//	//if (GUI_Button("CreateActor"))
//	//{
//	//	auto baseAddr = CreateActor(CHAR_DANTE, ACTOR_TWO);
//	//	Log("baseAddr %llX", baseAddr);
//	//}
//
//
//
//	//{
//	//	static uint32 arg[3] = {};
//	//	GUI_InputEx<uint32>("arg1", arg[0]);
//	//	GUI_InputEx<uint32>("arg2", arg[1]);
//	//	GUI_InputEx<uint32>("arg3", arg[2]);
//	//	if (GUI_Button("Switch"))
//	//	{
//	//		auto g_pool = *reinterpret_cast<byte8 ***>(appBaseAddr + 0xC90E28);
//	//		auto hud = *reinterpret_cast<byte8 **>(g_pool[11]);
//	//		func_280160(hud, arg[0], arg[1], arg[2]);
//	//	}
//	//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//	//{
//	//	static bool enable = false;
//	//	if (GUI_Checkbox("Toggle Update Weapon", enable))
//	//	{
//	//		//ToggleUpdateWeapon(enable);
//	//	}
//	//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//	ImGui::Text(Locale.Game.Arcade.header);
//	ImGui::SameLine();
//	GUI_Tooltip(Locale.Game.Arcade.description);
//	ImGui::Text("");
//	if (GUI_Checkbox
//	(
//		Locale.Game.Arcade.enable,
//		Config.Game.Arcade.enable
//	))
//	{
//		if (Config.Game.Arcade.enable)
//		{
//			Arcade_Toggle(Config.Game.Arcade.enable);
//		}
//		else
//		{
//			Arcade_Toggle(DefaultConfig.Game.Arcade.enable);
//		}
//	}
//	ImGui::Text("");
//	GUI_PUSH_DISABLE(!Config.Game.Arcade.enable);
//	ImGui::PushItemWidth(200);
//	GUI_Combo<uint32>
//	(
//		Locale.Game.Arcade.Mission.label,
//		Locale.Game.Arcade.Mission.items,
//		countof(Locale.Game.Arcade.Mission.items),
//		Config.Game.Arcade.mission
//	);
//	if ((Config.Game.Arcade.mission != 0) && (Config.Game.Arcade.mission != 21))
//	{
//		if (GUI_Combo<uint8>
//		(
//			Locale.Game.Arcade.Mode.label,
//			Locale.Game.Arcade.Mode.items,
//			countof(Locale.Game.Arcade.Mode.items),
//			Arcade_modeIndex,
//			0,
//			false
//		))
//		{
//			auto & modeIndex = Arcade_modeIndex;
//			auto & modeMap   = Arcade_modeMap;
//			Config.Game.Arcade.mode = modeMap[modeIndex];
//			SaveConfig();
//		}
//		if constexpr (debug)
//		{
//			ImGui::Text("index %u", Arcade_modeIndex);
//			ImGui::Text("true  %X", Config.Game.Arcade.mode);
//		}
//		GUI_InputEx<uint16>
//		(
//			Locale.Game.Arcade.room,
//			Config.Game.Arcade.room
//		);
//		ImGui::SameLine();
//		GUI_Checkbox
//		(
//			Locale.Game.Arcade.ignoreRoom,
//			Config.Game.Arcade.ignoreRoom
//		);
//		GUI_InputEx<uint16>
//		(
//			Locale.Game.Arcade.position,
//			Config.Game.Arcade.position
//		);
//		ImGui::SameLine();
//		GUI_Checkbox
//		(
//			Locale.Game.Arcade.ignorePosition,
//			Config.Game.Arcade.ignorePosition
//		);
//	}
//	else if (Config.Game.Arcade.mission == 21)
//	{
//		GUI_Combo<uint8>
//		(
//			Locale.Game.Arcade.BloodyPalace.Floor.label,
//			Locale.Game.Arcade.BloodyPalace.Floor.items,
//			countof(Locale.Game.Arcade.BloodyPalace.Floor.items),
//			Config.Game.Arcade.BloodyPalace.floor
//		);
//	}
//	GUI_Combo<uint8>
//	(
//		Locale.Game.Arcade.Character.label,
//		Locale.Game.Arcade.Character.items,
//		countof(Locale.Game.Arcade.Character.items),
//		Config.Game.Arcade.character
//	);
//	if (Config.Game.Arcade.mission != 0)
//	{
//		GUI_InputEx<uint8>
//		(
//			Locale.Game.Arcade.costume,
//			Config.Game.Arcade.costume
//		);
//	}
//	if ((Config.Game.Arcade.mission != 0) && (Config.Game.Arcade.character == CHAR_DANTE))
//	{
//		GUI_Combo<uint32>
//		(
//			Locale.Game.Arcade.Style.label,
//			Locale.Game.Arcade.Style.items,
//			countof(Locale.Game.Arcade.Style.items),
//			Config.Game.Arcade.style
//		);
//		for (uint8 index = 0; index < countof(Config.Game.Arcade.equipment); index++)
//		{
//			if (index < 2)
//			{
//				GUI_Combo<uint8>
//				(
//					Locale.Game.Arcade.Equipment.label[index],
//					Locale.Game.Arcade.Equipment.items,
//					5,
//					Config.Game.Arcade.equipment[index]
//				);
//			}
//			else
//			{
//				GUI_Combo<uint8>
//				(
//					Locale.Game.Arcade.Equipment.label[index],
//					Locale.Game.Arcade.Equipment.items,
//					10,
//					Config.Game.Arcade.equipment[index],
//					5
//				);
//			}
//		}
//	}
//	if (Config.Game.Arcade.mission != 0)
//	{
//		GUI_InputEx<float32>
//		(
//			Locale.Game.Arcade.hitPoints,
//			Config.Game.Arcade.hitPoints,
//			1000
//		);
//		GUI_InputEx<float32>
//		(
//			Locale.Game.Arcade.magicPoints,
//			Config.Game.Arcade.magicPoints,
//			1000
//		);
//	}
//	ImGui::PopItemWidth();
//	GUI_SECTION_FOOTER_START(Game.Arcade);
//	Arcade_UpdateModeIndex();
//	Arcade_Toggle(DefaultConfig.Game.Arcade.enable);
//	GUI_SECTION_FOOTER_END;
//}

void GUI_Game_BossRush()
{
	ImGui::Text(Locale.Game.BossRush.header);
	ImGui::SameLine();
	GUI_Tooltip(Locale.Game.BossRush.description);
	ImGui::Text("");
	GUI_Checkbox
	(
		Locale.Game.BossRush.enable,
		Config.Game.BossRush.enable
	);
	ImGui::Text("");
	GUI_PUSH_DISABLE(!Config.Game.BossRush.enable);
	ImGui::Text(Locale.Game.BossRush.Mission5.header);
	GUI_Checkbox
	(
		Locale.Game.BossRush.Mission5.skipJester,
		Config.Game.BossRush.Mission5.skipJester
	);
	ImGui::Text(Locale.Game.BossRush.Mission12.header);
	GUI_Checkbox
	(
		Locale.Game.BossRush.Mission12.skipJester,
		Config.Game.BossRush.Mission12.skipJester
	);
	GUI_Checkbox
	(
		Locale.Game.BossRush.Mission12.skipGeryonBridgeBattle,
		Config.Game.BossRush.Mission12.skipGeryonBridgeBattle
	);
	ImGui::Text(Locale.Game.BossRush.Mission17.header);
	GUI_Checkbox
	(
		Locale.Game.BossRush.Mission17.skipJester,
		Config.Game.BossRush.Mission17.skipJester
	);
	ImGui::Text(Locale.Game.BossRush.Mission19.header);
	GUI_Checkbox
	(
		Locale.Game.BossRush.Mission19.skipFirstPart,
		Config.Game.BossRush.Mission19.skipFirstPart
	);
	GUI_SECTION_FOOTER(Game.BossRush);
}

//void GUI_Game_Dante()
//{
//	auto Toggle = [](CONFIG & config)
//	{
//		//Game_Dante_Rebellion_ToggleInfiniteSwordPierce(config.Game.Dante.Rebellion.infiniteSwordPierce);
//		//Game_Dante_EbonyIvory_ToggleFoursomeTime      (config.Game.Dante.EbonyIvory.foursomeTime      );
//		//Game_Dante_EbonyIvory_ToggleInfiniteRainStorm (config.Game.Dante.EbonyIvory.infiniteRainStorm );
//		//Game_Dante_Artemis_ToggleSwap                 (config.Game.Dante.Artemis.swap                 );
//		//Game_Dante_Artemis_ToggleInstant              (config.Game.Dante.Artemis.instant              );
//		//Game_Dante_AirHike_ToggleCoreAbility          (config.Game.Dante.AirHike.coreAbility          );
//		//Game_Dante_CrazyCombo_SetLevelMultiplier      (config.Game.Dante.CrazyCombo.levelMultiplier   );
//		//Game_Dante_WeaponSwitchTimeout_Melee_Toggle   (config.Game.Dante.WeaponSwitchTimeout.melee    );
//		//Game_Dante_WeaponSwitchTimeout_Ranged_Toggle  (config.Game.Dante.WeaponSwitchTimeout.ranged   );
//	};
//	GUI_SECTION_HEADER_START(Game.Dante);
//	if (Config.Game.Dante.enable)
//	{
//		Toggle(Config);
//	}
//	else
//	{
//		Toggle(DefaultConfig);
//	}
//	GUI_SECTION_HEADER_END(Game.Dante);
//	ImGui::Text(Locale.Game.Dante.Rebellion.header);
//	if (GUI_Checkbox
//	(
//		Locale.Game.Dante.Rebellion.infiniteSwordPierce,
//		Config.Game.Dante.Rebellion.infiniteSwordPierce
//	))
//	{
//		//Game_Dante_Rebellion_ToggleInfiniteSwordPierce(Config.Game.Dante.Rebellion.infiniteSwordPierce);
//	}
//	GUI_Checkbox
//	(
//		Locale.Game.Dante.Rebellion.unlockQuickDrive,
//		Config.Game.Dante.Rebellion.unlockQuickDrive
//	);
//	ImGui::SameLine();
//	GUI_Tooltip(Locale.Game.Dante.Rebellion.unlockQuickDriveDescription);
//	{
//		ImGui::SameLine();
//		auto color = ImVec4(0, 1, 0, 1);
//		if (!demo_pl000_00_3)
//		{
//			color = ImVec4(1, 0, 0, 1);
//		}
//		ImGui::PushStyleColor(ImGuiCol_Text, color);
//		ImGui::Text("demo_pl000_00_3.pac");
//		ImGui::PopStyleColor();
//	}
//	ImGui::Text(Locale.Game.Dante.EbonyIvory.header);
//	if (GUI_Checkbox
//	(
//		Locale.Game.Dante.EbonyIvory.foursomeTime,
//		Config.Game.Dante.EbonyIvory.foursomeTime
//	))
//	{
//		//Game_Dante_EbonyIvory_ToggleFoursomeTime(Config.Game.Dante.EbonyIvory.foursomeTime);
//	}
//	ImGui::SameLine();
//	GUI_Tooltip(Locale.Game.Dante.EbonyIvory.foursomeTimeDescription);
//	if (GUI_Checkbox
//	(
//		Locale.Game.Dante.EbonyIvory.infiniteRainStorm,
//		Config.Game.Dante.EbonyIvory.infiniteRainStorm
//	))
//	{
//		//Game_Dante_EbonyIvory_ToggleInfiniteRainStorm(Config.Game.Dante.EbonyIvory.infiniteRainStorm);
//	}
//	ImGui::Text(Locale.Game.Dante.Artemis.header);
//	if (GUI_Checkbox
//	(
//		Locale.Game.Dante.Artemis.swap,
//		Config.Game.Dante.Artemis.swap
//	))
//	{
//		//Game_Dante_Artemis_ToggleSwap(Config.Game.Dante.Artemis.swap);
//	}
//	if (GUI_Checkbox
//	(
//		Locale.Game.Dante.Artemis.instant,
//		Config.Game.Dante.Artemis.instant
//	))
//	{
//		//Game_Dante_Artemis_ToggleInstant(Config.Game.Dante.Artemis.instant);
//	}
//	ImGui::Text(Locale.Game.Dante.AirHike.header);
//	if (GUI_Checkbox
//	(
//		Locale.Game.Dante.AirHike.coreAbility,
//		Config.Game.Dante.AirHike.coreAbility
//	))
//	{
//		//Game_Dante_AirHike_ToggleCoreAbility(Config.Game.Dante.AirHike.coreAbility);
//	}
//	ImGui::SameLine();
//	GUI_Tooltip(Locale.Game.Dante.AirHike.coreAbilityDescription);
//	ImGui::PushItemWidth(100);
//	ImGui::Text(Locale.Game.Dante.CrazyCombo.header);
//	if (GUI_InputEx
//	(
//		Locale.Game.Dante.CrazyCombo.levelMultiplier,
//		Config.Game.Dante.CrazyCombo.levelMultiplier
//	))
//	{
//		//Game_Dante_CrazyCombo_SetLevelMultiplier(Config.Game.Dante.CrazyCombo.levelMultiplier);
//	}
//	ImGui::PopItemWidth();
//	ImGui::PushItemWidth(150);
//	ImGui::Text(Locale.Game.Dante.WeaponSwitchTimeout.header);
//	if (GUI_InputEx<float32>
//	(
//		Locale.Game.Dante.WeaponSwitchTimeout.melee,
//		Config.Game.Dante.WeaponSwitchTimeout.melee
//	))
//	{
//		//Game_Dante_WeaponSwitchTimeout_Melee_Toggle(Config.Game.Dante.WeaponSwitchTimeout.melee);
//	}
//	if constexpr (debug)
//	{
//		ImGui::Text("%f", Config.Game.Dante.WeaponSwitchTimeout.melee);
//	}
//	if (GUI_InputEx<float32>
//	(
//		Locale.Game.Dante.WeaponSwitchTimeout.ranged,
//		Config.Game.Dante.WeaponSwitchTimeout.ranged
//	))
//	{
//		//Game_Dante_WeaponSwitchTimeout_Ranged_Toggle(Config.Game.Dante.WeaponSwitchTimeout.ranged);
//	}
//	if constexpr (debug)
//	{
//		ImGui::Text("%f", Config.Game.Dante.WeaponSwitchTimeout.ranged);
//	}
//	ImGui::PopItemWidth();
//	GUI_SECTION_FOOTER_START(Game.Dante);
//	Toggle(DefaultConfig);
//	GUI_SECTION_FOOTER_END;
//}

//void GUI_Game_Doppelganger()
//{
//	GUI_SECTION_HEADER_START(Game.Doppelganger);
//	if (Config.Game.Doppelganger.enable)
//	{
//		//Game_Doppelganger_ToggleEnableDevilTrigger(Config.Game.Doppelganger.enableDevilTrigger);
//	}
//	else
//	{
//		//Game_Doppelganger_ToggleEnableDevilTrigger(DefaultConfig.Game.Doppelganger.enableDevilTrigger);
//	}
//	GUI_SECTION_HEADER_END(Game.Doppelganger);
//	ImGui::PushItemWidth(100);
//	GUI_Combo<uint8>
//	(
//		Locale.Game.Doppelganger.Character.label,
//		Locale.Game.Doppelganger.Character.items,
//		countof(Locale.Game.Doppelganger.Character.items),
//		Config.Game.Doppelganger.character
//	);
//	ImGui::PopItemWidth();
//	if (GUI_Checkbox
//	(
//		Locale.Game.Doppelganger.enableDevilTrigger,
//		Config.Game.Doppelganger.enableDevilTrigger
//	))
//	{
//		//Game_Doppelganger_ToggleEnableDevilTrigger(Config.Game.Doppelganger.enableDevilTrigger);
//	}
//	GUI_SECTION_FOOTER_START(Game.Doppelganger);
//	//Game_Doppelganger_ToggleEnableDevilTrigger(DefaultConfig.Game.Doppelganger.enableDevilTrigger);
//	GUI_SECTION_FOOTER_END;
//}

//void GUI_Game_Mobility()
//{
//	auto InputExMobility = []
//	(
//		const char * label,
//		uint8 & human,
//		uint8 & devil
//	)
//	{
//		ImGui::PushItemWidth(29);
//		GUI_InputEx<uint8>("", human, 0);
//		ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
//		GUI_InputEx<uint8>(label, devil, 0);
//		ImGui::PopItemWidth();
//	};
//	ImGui::Text(Locale.Game.Mobility.header);
//	ImGui::SameLine();
//	GUI_Tooltip(Locale.Game.Mobility.description);
//	ImGui::Text("");
//	if (GUI_Checkbox
//	(
//		Locale.Game.Mobility.enable,
//		Config.Game.Mobility.enable
//	))
//	{
//		if (Config.Game.Mobility.enable)
//		{
//			//Game_Mobility_Toggle(Config.Game.Mobility.enable);
//		}
//		else
//		{
//			//Game_Mobility_Toggle(DefaultConfig.Game.Mobility.enable);
//		}
//	}
//	ImGui::Text("");
//	GUI_PUSH_DISABLE(!Config.Game.Mobility.enable);
//	ImGui::Text(Locale.Game.Mobility.Dante.header);
//	InputExMobility
//	(
//		Locale.Game.Mobility.Dante.airHike,
//		Config.Game.Mobility.Human.Dante.airHike,
//		Config.Game.Mobility.Devil.Dante.airHike
//	);
//	for (uint8 index = 0; index < countof(Config.Game.Mobility.Human.Dante.dash); index++)
//	{
//		InputExMobility
//		(
//			Locale.Game.Mobility.Dante.dash[index],
//			Config.Game.Mobility.Human.Dante.dash[index],
//			Config.Game.Mobility.Devil.Dante.dash[index]
//		);
//	}
//	InputExMobility
//	(
//		Locale.Game.Mobility.Dante.skyStar,
//		Config.Game.Mobility.Human.Dante.skyStar,
//		Config.Game.Mobility.Devil.Dante.skyStar
//	);
//	InputExMobility
//	(
//		Locale.Game.Mobility.Dante.airTrick,
//		Config.Game.Mobility.Human.Dante.airTrick,
//		Config.Game.Mobility.Devil.Dante.airTrick
//	);
//	ImGui::Text(Locale.Game.Mobility.Vergil.header);
//	InputExMobility
//	(
//		Locale.Game.Mobility.Vergil.airTrick,
//		Config.Game.Mobility.Human.Vergil.airTrick,
//		Config.Game.Mobility.Devil.Vergil.airTrick
//	);
//	InputExMobility
//	(
//		Locale.Game.Mobility.Vergil.trickUp,
//		Config.Game.Mobility.Human.Vergil.trickUp,
//		Config.Game.Mobility.Devil.Vergil.trickUp
//	);
//	InputExMobility
//	(
//		Locale.Game.Mobility.Vergil.trickDown,
//		Config.Game.Mobility.Human.Vergil.trickDown,
//		Config.Game.Mobility.Devil.Vergil.trickDown
//	);
//	GUI_SECTION_FOOTER_START(Game.Mobility);
//	//Game_Mobility_Toggle(DefaultConfig.Game.Mobility.enable);
//	GUI_SECTION_FOOTER_END;
//}
//
//void GUI_Game_Multiplayer()
//{
//	auto Toggle = [](bool enable)
//	{
//		//System_Input_ToggleRangeExtension  (enable);
//		//System_Input_ToggleMultiplayerFixes(enable);
//	};
//	GUI_PUSH_DISABLE(ActorAvailable());
//	ImGui::Text(Locale.Game.Multiplayer.header);
//	ImGui::SameLine();
//	GUI_Tooltip(Locale.Game.Multiplayer.description);
//	ImGui::Text("");
//	if (GUI_Checkbox
//	(
//		Locale.Game.Multiplayer.enable,
//		Config.Game.Multiplayer.enable
//	))
//	{
//		Toggle(Config.Game.Multiplayer.enable);
//	}
//	ImGui::Text("");
//	GUI_PUSH_DISABLE(!Config.Game.Multiplayer.enable);
//	//constexpr uint8 count = (MAX_ACTOR - 1);
//	constexpr uint8 count = 3;
//	ImGui::PushItemWidth(100);
//	GUI_Slider("", Config.Game.Multiplayer.actorCount, 1, count);
//	for (uint8 index = 0; index < count; index++)
//	{
//		bool skip = (index >= Config.Game.Multiplayer.actorCount) ? true : false;
//		GUI_PUSH_DISABLE(skip);
//		GUI_Combo<uint8>
//		(
//			"",
//			Locale.Game.Multiplayer.Character.items,
//			countof(Locale.Game.Multiplayer.Character.items),
//			Config.Game.Multiplayer.character[index]
//		);
//		ImGui::SameLine();
//		GUI_InputEx("", Config.Game.Multiplayer.costume[index]);
//		GUI_POP_DISABLE(skip);
//	}
//	ImGui::PopItemWidth();
//	GUI_SECTION_FOOTER_START(Game.Multiplayer);
//	Toggle(DefaultConfig.Game.Multiplayer.enable);
//	GUI_SECTION_FOOTER_END;
//	GUI_POP_DISABLE(ActorAvailable());
//}

void GUI_Game_Other()
{
	GUI_SECTION_HEADER_START(Game.Other);
	if (Config.Game.Other.enable)
	{
		//Game_Other_Toggle(Config.Game.Other.enable);
	}
	else
	{
		//Game_Other_Toggle(DefaultConfig.Game.Other.enable);
	}
	GUI_SECTION_HEADER_END(Game.Other);
	ImGui::PushItemWidth(150);
	GUI_InputEx<float32>
	(
		Locale.Game.Other.orbReach,
		Config.Game.Other.orbReach,
		100
	);
	ImGui::Text(Locale.Game.Other.MagicPointsDepletionRate.header);
	GUI_InputEx<float32>
	(
		Locale.Game.Other.MagicPointsDepletionRate.devil,
		Config.Game.Other.MagicPointsDepletionRate.devil,
		1
	);
	GUI_InputEx<float32>
	(
		Locale.Game.Other.MagicPointsDepletionRate.quicksilver,
		Config.Game.Other.MagicPointsDepletionRate.quicksilver,
		1
	);
	GUI_InputEx<float32>
	(
		Locale.Game.Other.MagicPointsDepletionRate.doppelganger,
		Config.Game.Other.MagicPointsDepletionRate.doppelganger,
		1
	);
	ImGui::PopItemWidth();
	GUI_SECTION_FOOTER_START(Game.Other);
	//Game_Other_Toggle(DefaultConfig.Game.Other.enable);
	GUI_SECTION_FOOTER_END;
}

//void GUI_Game_ResetMotionState()
//{
//	//GUI_SECTION_HEADER(Game.ResetMotionState);
//	//ImGui::PushItemWidth(150);
//	//if (GUI_Combo<uint8>
//	//(
//	//	Locale.Game.ResetMotionState.Button.label,
//	//	Locale.Game.ResetMotionState.Button.items,
//	//	countof(Locale.Game.ResetMotionState.Button.items),
//	//	Game_ResetMotionState_buttonIndex,
//	//	0,
//	//	false
//	//))
//	//{
//	//	auto & buttonIndex = Game_ResetMotionState_buttonIndex;
//	//	auto & buttonMap   = Game_ResetMotionState_buttonMap;
//	//	Config.Game.ResetMotionState.button = buttonMap[buttonIndex];
//	//	SaveConfig();
//	//}
//	//ImGui::PopItemWidth();
//	//if constexpr (debug)
//	//{
//	//	ImGui::Text("index %u", Game_ResetMotionState_buttonIndex);
//	//	ImGui::Text("true  %X", Config.Game.ResetMotionState.button);
//	//}
//	//GUI_SECTION_FOOTER_START(Game.ResetMotionState);
//	//Game_ResetMotionState_UpdateButtonIndex();
//	//GUI_SECTION_FOOTER_END;
//}

//void GUI_Game_StyleSwitcher()
//{
//	//GUI_SECTION_HEADER_START(Game.StyleSwitcher);
//	//if (Config.Game.StyleSwitcher.enable)
//	//{
//	//	Game_StyleSwitcher_Toggle(Config.Game.StyleSwitcher.enable);
//	//}
//	//else
//	//{
//	//	Game_StyleSwitcher_Toggle(DefaultConfig.Game.StyleSwitcher.enable);
//	//}
//	//GUI_SECTION_HEADER_END(Game.StyleSwitcher);
//	//GUI_Checkbox
//	//(
//	//	Locale.Game.StyleSwitcher.noDoubleTap,
//	//	Config.Game.StyleSwitcher.noDoubleTap
//	//);
//	//GUI_SECTION_FOOTER_START(Game.StyleSwitcher);
//	//Game_StyleSwitcher_Toggle(DefaultConfig.Game.StyleSwitcher.enable);
//	//GUI_SECTION_FOOTER_END;
//}

//void GUI_Game_Training()
//{
//	auto Toggle = [](CONFIG & config)
//	{
//		Training_ToggleInfiniteHitPoints  (config.Game.Training.infiniteHitPoints  );
//		Training_ToggleInfiniteMagicPoints(config.Game.Training.infiniteMagicPoints);
//		Training_ToggleDisableTimer       (config.Game.Training.disableTimer       );
//	};
//	GUI_SECTION_HEADER_START(Game.Training);
//	if (Config.Game.Training.enable)
//	{
//		Toggle(Config);
//	}
//	else
//	{
//		Toggle(DefaultConfig);
//	}
//	GUI_SECTION_HEADER_END(Game.Training);
//	if (GUI_Checkbox
//	(
//		Locale.Game.Training.infiniteHitPoints,
//		Config.Game.Training.infiniteHitPoints
//	))
//	{
//		Training_ToggleInfiniteHitPoints(Config.Game.Training.infiniteHitPoints);
//	}
//	if (GUI_Checkbox
//	(
//		Locale.Game.Training.infiniteMagicPoints,
//		Config.Game.Training.infiniteMagicPoints
//	))
//	{
//		Training_ToggleInfiniteMagicPoints(Config.Game.Training.infiniteMagicPoints);
//	}
//	if (GUI_Checkbox
//	(
//		Locale.Game.Training.disableTimer,
//		Config.Game.Training.disableTimer
//	))
//	{
//		Training_ToggleDisableTimer(Config.Game.Training.disableTimer);
//	}
//	GUI_SECTION_FOOTER_START(Game.Training);
//	Toggle(DefaultConfig);
//	GUI_SECTION_FOOTER_END;
//}

void GUI_Game_Vergil()
{
	//auto Toggle = [](CONFIG & config)
	//{
	//	//Game_Vergil_ForceEdge_ToggleInfiniteRoundTrip(config.Game.Vergil.ForceEdge.infiniteRoundTrip);
	//	//Game_Vergil_SummonedSwords_ToggleChronoSwords(config.Game.Vergil.SummonedSwords.chronoSwords);
	//	//Game_Vergil_WeaponSwitchTimeout_MeleeToggle  (config.Game.Vergil.WeaponSwitchTimeout.melee  );
	//};
	GUI_SECTION_HEADER_START(Game.Vergil);
	//if (Config.Game.Vergil.enable)
	//{
	//	Toggle(Config);
	//}
	//else
	//{
	//	Toggle(DefaultConfig);
	//}
	GUI_SECTION_HEADER_END(Game.Vergil);
	ImGui::Text(Locale.Game.Vergil.ForceEdge.header);
	if (GUI_Checkbox
	(
		Locale.Game.Vergil.ForceEdge.infiniteRoundTrip,
		Config.Game.Vergil.ForceEdge.infiniteRoundTrip
	))
	{
		//Game_Vergil_ForceEdge_ToggleInfiniteRoundTrip(Config.Game.Vergil.ForceEdge.infiniteRoundTrip);
	}
	ImGui::Text(Locale.Game.Vergil.SummonedSwords.header);
	if (GUI_Checkbox
	(
		Locale.Game.Vergil.SummonedSwords.chronoSwords,
		Config.Game.Vergil.SummonedSwords.chronoSwords
	))
	{
		//Game_Vergil_SummonedSwords_ToggleChronoSwords(Config.Game.Vergil.SummonedSwords.chronoSwords);
	}
	ImGui::SameLine();
	GUI_Tooltip(Locale.Game.Vergil.SummonedSwords.chronoSwordsDescription);
	ImGui::Text(Locale.Game.Vergil.WeaponSwitchTimeout.header);
	ImGui::PushItemWidth(150);
	if (GUI_InputEx<float32>
	(
		Locale.Game.Vergil.WeaponSwitchTimeout.melee,
		Config.Game.Vergil.WeaponSwitchTimeout.melee
	))
	{
		//Game_Vergil_WeaponSwitchTimeout_MeleeToggle(Config.Game.Vergil.WeaponSwitchTimeout.melee);
	}
	ImGui::PopItemWidth();
	GUI_SECTION_FOOTER_START(Game.Vergil);
	//Toggle(DefaultConfig);
	GUI_SECTION_FOOTER_END;
}

//void GUI_Game_WeaponSwitcher()
//{
//	GUI_PUSH_DISABLE(ActorAvailable());
//	GUI_SECTION_HEADER_START(Game.WeaponSwitcher);
//	if (Config.Game.WeaponSwitcher.enable)
//	{
//		//Game_WeaponSwitcher_Toggle(Config.Game.WeaponSwitcher.enable);
//	}
//	else
//	{
//		//Game_WeaponSwitcher_Toggle(DefaultConfig.Game.WeaponSwitcher.enable);
//	}
//	GUI_SECTION_HEADER_END(Game.WeaponSwitcher);
//	ImGui::PushItemWidth(200);
//	if (GUI_Combo<uint8>
//	(
//		Locale.Game.WeaponSwitcher.Devil.label,
//		Locale.Game.WeaponSwitcher.Devil.items,
//		countof(Locale.Game.WeaponSwitcher.Devil.items),
//		Config.Game.WeaponSwitcher.devil
//	))
//	{
//		//System_Actor_UpdateDevilModel(Config.Game.WeaponSwitcher.devil);
//	}
//	GUI_Combo<uint8>
//	(
//		Locale.Game.WeaponSwitcher.Sword.label,
//		Locale.Game.WeaponSwitcher.Sword.items,
//		countof(Locale.Game.WeaponSwitcher.Sword.items),
//		Config.Game.WeaponSwitcher.sword
//	);
//	ImGui::Text(Locale.Game.WeaponSwitcher.Melee.header);
//	GUI_Slider("", Config.Game.WeaponSwitcher.Melee.count, 1, 5);
//	for (uint8 i = 0; i < 5; i++)
//	{
//		bool skip = (i >= Config.Game.WeaponSwitcher.Melee.count) ? true : false;
//		GUI_PUSH_DISABLE(skip);
//		GUI_Combo<uint8>
//		(
//			"",
//			Locale.Game.WeaponSwitcher.Weapon.items,
//			5,
//			Config.Game.WeaponSwitcher.Melee.weapon[i]
//		);
//		GUI_POP_DISABLE(skip);
//	}
//	ImGui::Text(Locale.Game.WeaponSwitcher.Ranged.header);
//	GUI_Slider("", Config.Game.WeaponSwitcher.Ranged.count, 1, 5);
//	for (uint8 i = 0; i < 5; i++)
//	{
//		bool skip = (i >= Config.Game.WeaponSwitcher.Ranged.count) ? true : false;
//		GUI_PUSH_DISABLE(skip);
//		GUI_Combo<uint8>
//		(
//			"",
//			Locale.Game.WeaponSwitcher.Weapon.items,
//			10,
//			Config.Game.WeaponSwitcher.Ranged.weapon[i],
//			5
//		);
//		GUI_POP_DISABLE(skip);
//	}
//	ImGui::PopItemWidth();
//	GUI_SECTION_FOOTER_START(Game.WeaponSwitcher);
//	//Game_WeaponSwitcher_Toggle(DefaultConfig.Game.WeaponSwitcher.enable);
//	GUI_SECTION_FOOTER_END;
//	GUI_POP_DISABLE(ActorAvailable());
//}

void GUI_Game_Draw()
{
	static bool run = false;
	if (!run)
	{
		run = true;
		ImGui::SetNextWindowSize(ImVec2(GUI_Game_size.x + 16, GUI_Game_size.y + 16));
		ImGui::SetNextWindowPos(ImVec2(0, 25));
	}
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(1, 1));
	if (ImGui::Begin("GUI_Game", &pause, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
	{
		//GUI_Arcade();
		//ImGui::Text("");
		GUI_Game_BossRush();
		ImGui::Text("");
		//GUI_Game_Dante();
		//ImGui::Text("");
		//GUI_Game_Doppelganger();
		//ImGui::Text("");
		//GUI_Game_Mobility();
		//ImGui::Text("");
		//GUI_Game_Multiplayer();
		//ImGui::Text("");
		GUI_Game_Other();
		ImGui::Text("");
		//GUI_Game_ResetMotionState();
		//ImGui::Text("");
		//GUI_Game_StyleSwitcher();
		//ImGui::Text("");
		//GUI_Game_Training();
		//ImGui::Text("");
		GUI_Game_Vergil();
		//ImGui::Text("");
		//GUI_Game_WeaponSwitcher();
	}
	ImGui::End();
	ImGui::PopStyleVar(3);
}

#pragma endregion



















void GUI_Cosmetics_Color()
{
	auto ColorPalette = []
	(
		const char * label,
		const char ** items,
		float32(*var)[4],
		uint8 count
	)
	{
		bool update = false;
		for (uint8 index = 0; index < count; index++)
		{
			if (GUI_ColorEdit4(items[index], var[index]))
			{
				update = true;
				//Cosmetics_Color_UpdateColors(Config);
			}
			ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
		}
		ImGui::Text(label);
		return update;
	};
	//auto UpdateDoppelgangerColor = []()
	//{
	//	if (Config.Game.Multiplayer.enable)
	//	{
	//		return;
	//	}
	//	if (Config.Cosmetics.Doppelganger.noColor)
	//	{
	//		return;
	//	}
	//	if (!InGame())
	//	{
	//		return;
	//	}
	//	//auto & baseAddr = System_Actor_actorBaseAddr[ACTOR_TWO];
	//	//if (!baseAddr)
	//	//{
	//	//	return;
	//	//}
	//	//Cosmetics_Color_ApplyColor(baseAddr, 6, 0);
	//};




	
	//static uint8 slot[6] = {};
	//if (GUI_Button("DevilRebellion"))
	//{
	//	ApplyDevilRebellion(slot[0]);
	//}
	//if (GUI_Button("DevilCerberus"))
	//{
	//	ApplyDevilCerberus(slot[1]);
	//}
	//if (GUI_Button("DevilAgniRudra"))
	//{
	//	ApplyDevilAgniRudra(slot[2]);
	//}
	//if (GUI_Button("DevilNevan"))
	//{
	//	ApplyDevilNevan(slot[3]);
	//}
	//if (GUI_Button("DevilBeowulf"))
	//{
	//	ApplyDevilBeowulf(slot[4]);
	//}
	//if (GUI_Button("DevilSparda"))
	//{
	//	ApplyDevilSparda(slot[5]);
	//}
	//for (uint8 index = 0; index < countof(slot); index++)
	//{
	//	GUI_InputEx<uint8>("Slot", slot[index]);
	//}



















	ImGui::Text("");














	GUI_Hyperlink(Locale.Cosmetics.Color.header);
	ImGui::Text("");
	ImGui::Text(Locale.Cosmetics.Color.Aura.header);
	ColorPalette
	(
		Locale.Cosmetics.Color.Aura.Dante.label,
		Locale.Cosmetics.Color.Aura.Dante.items,
		Config.Cosmetics.Color.Aura.dante,
		countof(Config.Cosmetics.Color.Aura.dante)
	);
	ColorPalette
	(
		Locale.Cosmetics.Color.Aura.Vergil.label,
		Locale.Cosmetics.Color.Aura.Vergil.items,
		Config.Cosmetics.Color.Aura.vergil,
		countof(Config.Cosmetics.Color.Aura.vergil)
	);
	ColorPalette
	(
		Locale.Cosmetics.Color.Aura.NeroAngelo.label,
		Locale.Cosmetics.Color.Aura.NeroAngelo.items,
		Config.Cosmetics.Color.Aura.neroAngelo,
		countof(Config.Cosmetics.Color.Aura.neroAngelo)
	);
	ImGui::Text(Locale.Cosmetics.Color.Style.header);
	ColorPalette
	(
		Locale.Cosmetics.Color.Style.Trickster.label,
		Locale.Cosmetics.Color.Style.Trickster.items,
		Config.Cosmetics.Color.Style.trickster,
		countof(Config.Cosmetics.Color.Style.trickster)
	);
	ColorPalette
	(
		Locale.Cosmetics.Color.Style.Royalguard.label,
		Locale.Cosmetics.Color.Style.Royalguard.items,
		Config.Cosmetics.Color.Style.royalguard,
		countof(Config.Cosmetics.Color.Style.royalguard)
	);
	if (ColorPalette
	(
		Locale.Cosmetics.Color.Style.Doppelganger.label,
		Locale.Cosmetics.Color.Style.Doppelganger.items,
		Config.Cosmetics.Color.Style.doppelganger,
		countof(Config.Cosmetics.Color.Style.doppelganger)
	))
	{
		//UpdateDoppelgangerColor();
	}
	ImGui::Text(Locale.Cosmetics.Color.AirHike.header);
	ColorPalette
	(
		Locale.Cosmetics.Color.AirHike.Dante.label,
		Locale.Cosmetics.Color.AirHike.Dante.items,
		Config.Cosmetics.Color.AirHike.dante,
		countof(Config.Cosmetics.Color.AirHike.dante)
	);
	ImGui::Text("");
	if (GUI_Button(Locale.Cosmetics.Color.reset))
	{
		memcpy(&Config.Cosmetics.Color, &DefaultConfig.Cosmetics.Color, sizeof(Config.Cosmetics.Color));
		SaveConfig();
		//Cosmetics_Color_UpdateColors(DefaultConfig);
		//UpdateDoppelgangerColor();
	}
}

void GUI_Cosmetics_Dante()
{
	//auto UpdateModelAttributes = []()
	//{
	//	auto count = System_Actor_GetActorCount();
	//	for (uint8 actor = 0; actor < count; actor++)
	//	{
	//		//auto & baseAddr = System_Actor_actorBaseAddr[actor];
	//		//if (!baseAddr)
	//		//{
	//		//	continue;
	//		//}
	//		//auto & character      = *(uint8 *)(baseAddr + 0x78  );
	//		//auto & selectedWeapon = *(uint8 *)(baseAddr + 0x6490);
	//		//auto   equipment      =  (uint8 *)(baseAddr + 0x6498);
	//		//auto & weapon = equipment[selectedWeapon];
	//		//if (character != CHAR_DANTE)
	//		//{
	//		//	continue;
	//		//}
	//		//if ((weapon == WEAPON_DANTE_BEOWULF) && !Config.Cosmetics.Dante.Beowulf.hideModel)
	//		//{
	//		//	Cosmetics_Dante_ApplyBeowulfModelAttributes(baseAddr);
	//		//}
	//		//else
	//		//{
	//		//	Cosmetics_Dante_ApplyDefaultModelAttributes(baseAddr);
	//		//}
	//	}
	//};
	//GUI_Hyperlink(Locale.Cosmetics.Dante.header);
	//ImGui::Text("");
	//ImGui::Text(Locale.Cosmetics.Dante.Beowulf.header);
	//if (GUI_Checkbox
	//(
	//	Locale.Cosmetics.Dante.Beowulf.hideModel,
	//	Config.Cosmetics.Dante.Beowulf.hideModel
	//))
	//{
	//	Cosmetics_Dante_ToggleHideBeowulf(Config.Cosmetics.Dante.Beowulf.hideModel);
	//	UpdateModelAttributes();
	//}
}

void GUI_Cosmetics_Doppelganger()
{
	GUI_Hyperlink(Locale.Cosmetics.Doppelganger.header);
	ImGui::Text("");
	if (GUI_Checkbox
	(
		Locale.Cosmetics.Doppelganger.noColor,
		Config.Cosmetics.Doppelganger.noColor
	))
	{
		//// @Todo: Creater helper function.
		//{
		//	if (Config.Game.Multiplayer.enable)
		//	{
		//		goto sect0;
		//	}
		//	if (!InGame())
		//	{
		//		goto sect0;
		//	}
		//	auto & noColor = Config.Cosmetics.Doppelganger.noColor;
		//	auto & baseAddr1 = System_Actor_actorBaseAddr[ACTOR_ONE];
		//	auto & baseAddr2 = System_Actor_actorBaseAddr[ACTOR_TWO];
		//	if (!baseAddr1 || !baseAddr2)
		//	{
		//		goto sect0;
		//	}
		//	auto & shadow1 = *(uint32 *)(baseAddr1 + 0x3A18) = (noColor) ? 1 : 0;
		//	auto & shadow2 = *(uint32 *)(baseAddr2 + 0x3A18) = (noColor) ? 1 : 0;
		//	Cosmetics_Color_ApplyColor(baseAddr2, (Config.Cosmetics.Doppelganger.noColor) ? 7 : 6, 0);
		//}
		//sect0:;
	}
}

void GUI_Cosmetics_Object()
{
	GUI_Hyperlink(Locale.Cosmetics.Object.header);
	ImGui::Text("");
	//ImGui::PushItemWidth(200);
	//for (uint8 object = 0; object < Object_Count; object++)
	//{
	//	GUI_Combo<uint8>
	//	(
	//		Locale.Cosmetics.Object.label[object],
	//		Locale.Cosmetics.Object.items,
	//		countof(Locale.Cosmetics.Object.items),
	//		Config.Cosmetics.Object.index[object]
	//	);
	//}
	//ImGui::PopItemWidth();
	//ImGui::Text("");
	//if (GUI_Button(Locale.Cosmetics.Object.reset))
	//{
	//	memcpy(&Config.Cosmetics.Object, &DefaultConfig.Cosmetics.Object, sizeof(Config.Cosmetics.Object));
	//	SaveConfig();
	//}
}

void GUI_Cosmetics_Other()
{
	GUI_Hyperlink(Locale.Cosmetics.Other.header);
	ImGui::Text("");
	if (GUI_Checkbox(Locale.Cosmetics.Other.noDevilForm, Config.Cosmetics.Other.noDevilForm))
	{
		//Cosmetics_Other_ToggleNoDevilForm(Config.Cosmetics.Other.noDevilForm);
	}
}

void GUI_Cosmetics_Vergil()
{
	GUI_Hyperlink(Locale.Cosmetics.Vergil.header);
	ImGui::Text("");
	ImGui::Text(Locale.Cosmetics.Vergil.Beowulf.header);
	if (GUI_Checkbox
	(
		Locale.Cosmetics.Vergil.Beowulf.hideModel,
		Config.Cosmetics.Vergil.Beowulf.hideModel
	))
	{
		//Cosmetics_Vergil_ToggleHideBeowulf(Config.Cosmetics.Vergil.Beowulf.hideModel);
	}
}

void GUI_Cosmetics_Draw()
{
	static bool run = false;
	if (!run)
	{
		run = true;
		ImGui::SetNextWindowSize(ImVec2(GUI_Cosmetics_size.x + 16, GUI_Cosmetics_size.y + 16));
		ImGui::SetNextWindowPos(ImVec2(0, 25));
	}
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(1, 1));
	if (ImGui::Begin("GUI_Cosmetics", &pause, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
	{
		GUI_Cosmetics_Color();
		ImGui::Text("");
		GUI_Cosmetics_Dante();
		ImGui::Text("");
		GUI_Cosmetics_Doppelganger();
		ImGui::Text("");
		GUI_Cosmetics_Object();
		ImGui::Text("");
		GUI_Cosmetics_Other();
		ImGui::Text("");
		GUI_Cosmetics_Vergil();
	}
	ImGui::End();
	ImGui::PopStyleVar(3);
}

void GUI_Tools_Overlay()
{
	GUI_SECTION_HEADER(Tools.Overlay);
	ImGui::PushItemWidth(100);
	GUI_Combo<uint8>
	(
		"",
		Locale.Tools.Overlay.FontSize.items,
		countof(Locale.Tools.Overlay.FontSize.items),
		Config.Tools.Overlay.fontSizeIndex
	);
	ImGui::PopItemWidth();
	ImGui::SameLine();
	GUI_ColorEdit4("", Config.Tools.Overlay.color);
	GUI_Checkbox
	(
		Locale.Tools.Overlay.focus,
		Config.Tools.Overlay.focus
	);
	GUI_Checkbox
	(
		Locale.Tools.Overlay.memory,
		Config.Tools.Overlay.memory
	);
	GUI_SECTION_FOOTER_START(Tools.Overlay);
	GUI_Overlay_run = false;
	GUI_SECTION_FOOTER_END;
}

void GUI_Tools_Repair()
{
	GUI_Hyperlink(Locale.Tools.Repair.header);
	ImGui::Text("");
	auto ResetEquipment = []()
	{
		//if (!InGame())
		//{
		//	return;
		//}
		//auto count = System_Actor_GetActorCount();
		////for (uint8 actor = 0; actor < count; actor++)
		////{
		////	auto & baseAddr = System_Actor_actorBaseAddr[actor];
		////	if (!baseAddr)
		////	{
		////		continue;
		////	}
		////	auto & character = *(uint8 *)(baseAddr + 0x78);
		////	auto equipment = (uint8 *)(baseAddr + 0x6498);
		////	vp_memset(equipment, 0, 8);
		////	switch (character)
		////	{
		////	case CHAR_DANTE:
		////		equipment[0] = WEAPON_DANTE_REBELLION;
		////		equipment[1] = WEAPON_DANTE_CERBERUS;
		////		equipment[2] = WEAPON_EBONY_IVORY;
		////		equipment[3] = WEAPON_SHOTGUN;
		////		break;
		////	case CHAR_BOB:
		////		equipment[0] = WEAPON_YAMATO_BOB;
		////		break;
		////	case CHAR_LADY:
		////		equipment[2] = WEAPON_KALINA_ANN;
		////		equipment[4] = 11;
		////		break;
		////	case CHAR_VERGIL:
		////		equipment[0] = WEAPON_YAMATO;
		////		equipment[1] = WEAPON_BEOWULF_VERGIL;
		////		equipment[2] = WEAPON_FORCE_EDGE;
		////		break;
		////	}
		////}
	};
	auto ResetRangedWeaponLevels = []()
	{
		if (!InGame())
		{
			return;
		}
		//auto count = System_Actor_GetActorCount();
		//for (uint8 actor = 0; actor < count; actor++)
		//{
		//	auto & baseAddr = System_Actor_actorBaseAddr[actor];
		//	if (!baseAddr)
		//	{
		//		continue;
		//	}
		//	auto level = (uint32 *)(baseAddr + 0x64E4);
		//	level[0] = 0;
		//	level[1] = 0;
		//}
	};
	if (GUI_Button(Locale.Tools.Repair.resetEquipment))
	{
		ResetEquipment();
	}
	if (GUI_Button(Locale.Tools.Repair.resetRangedWeaponLevels))
	{
		ResetRangedWeaponLevels();
	}
}










void GUI_Tools_Camera()
{
	if (GUI_Hyperlink("Camera"))
	{
		GUI_Camera_show = true;
	}
}






void GUI_Tools_Speed()
{
	if (GUI_Hyperlink(Locale.Tools.Speed.header))
	{
		GUI_Speed_show = true;
	}
}

void GUI_Tools_Teleporter()
{
	if (GUI_Hyperlink(Locale.Tools.Teleporter.header))
	{
		GUI_Teleporter_show = true;
	}
}

void GUI_Tools_Draw()
{
	static bool run = false;
	if (!run)
	{
		run = true;
		ImGui::SetNextWindowSize(ImVec2(GUI_Tools_size.x + 16, GUI_Tools_size.y + 16));
		ImGui::SetNextWindowPos(ImVec2(0, 25));
	}
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(1, 1));
	if (ImGui::Begin("GUI_Tools", &pause, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
	{
		GUI_Tools_Camera();
		ImGui::Text("");
		GUI_Tools_Overlay();
		ImGui::Text("");
		GUI_Tools_Repair();
		ImGui::Text("");
		GUI_Tools_Speed();
		ImGui::Text("");
		GUI_Tools_Teleporter();
	}
	ImGui::End();
	ImGui::PopStyleVar(3);
}

void GUI_Main_Tab(const char * str, uint8 index)
{
	ImVec2 pos = ImGui::GetCursorPos();
	bool selected = activeTab == index ? true : false;
	ImVec2 size = ImVec2(100, 20);
	ImGui::PushID(GUI_id);
	GUI_id++;
	if (ImGui::Selectable("", &selected, 0, size))
	{
		activeTab = activeTab == index ? TAB_VOID : index;
	}
	ImGui::PopID();
	ImVec2 len = ImGui::CalcTextSize(str);
	if ((uint32)len.x % 2)
	{
		len.x += 1.0f;
	}
	if ((uint32)len.y % 2)
	{
		len.y += 1.0f;
	}
	float32 x = pos.x + ((size.x - len.x) / 2);
	float32 y = pos.y + ((size.y - len.y) / 2);
	ImGui::SetCursorPos(ImVec2(x, y));
	ImGui::RenderText(ImGui::GetCurrentWindow()->DC.CursorPos, str);
	ImGui::SetCursorPos(ImVec2(pos.x + size.x + 8.0f, pos.y));
}

void GUI_Main_Draw()
{
	static bool run = false;
	if (!run)
	{
		run = true;
		ImGui::SetNextWindowSize(ImVec2((float32)Window_width, 25));
		ImGui::SetNextWindowPos(ImVec2(0, 0));
		ImGui::GetStyle().ScrollbarRounding = 0;
	}
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(1, 1));
	if (ImGui::Begin("GUI_Main", &pause, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
	{
		ImGui::SetCursorPos(ImVec2(4, 2));
		for (uint8 i = 0; i < MAX_TAB; i++)
		{
			GUI_Main_Tab(Locale.Main.label[i], i);
		}
		ImGui::SetCursorPos(ImVec2(0, 24));
		ImGui::Separator();
		ImGui::End();
	}
	ImGui::PopStyleVar(4);
	switch (activeTab)
	{
	case TAB_GAME:
		GUI_Game_Draw();
		break;
	case TAB_COSMETICS:
		GUI_Cosmetics_Draw();
		break;
	case TAB_TOOLS:
		GUI_Tools_Draw();
		break;
	}
}






void GUI_Camera_Draw()
{
	static bool run = false;
	if (!run)
	{
		run = true;
		ImGui::SetNextWindowPos(ImVec2(900, 100));
	}
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(1, 1));
	if (ImGui::Begin("Camera", &GUI_Camera_show, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize))
	{
		{
			if (!InGame())
			{
				goto InvalidPointer;
			}
			// @Todo: Add to vars.
			auto addr = *(byte8 **)(appBaseAddr + 0xC8FBD0);
			if (!addr)
			{
				goto InvalidPointer;
			}
			addr = *(byte8 **)(addr + 0x498);
			if (!addr)
			{
				goto InvalidPointer;
			}
			auto & height     = *(float32 *)(addr + 0xD0 );
			auto & tilt       = *(float32 *)(addr + 0xD4 );
			auto & zoom       = *(float32 *)(addr + 0xD8 );
			auto & zoomLockOn = *(float32 *)(addr + 0xE0 );
			ImGui::Text(Locale.Camera.live);
			ImGui::PushItemWidth(200);
			GUI_InputEx<float32>(Locale.Camera.height    , height    , 10  );
			GUI_InputEx<float32>(Locale.Camera.tilt      , tilt      , 0.1f);
			GUI_InputEx<float32>(Locale.Camera.zoom      , zoom      , 50  );
			GUI_InputEx<float32>(Locale.Camera.zoomLockOn, zoomLockOn, 50  );
			ImGui::Text("");
			ImGui::Text(Locale.Camera.config);
			GUI_InputEx<float32>(Locale.Camera.height    , Config.Camera.height    , 10  );
			GUI_InputEx<float32>(Locale.Camera.tilt      , Config.Camera.tilt      , 0.1f);
			GUI_InputEx<float32>(Locale.Camera.zoom      , Config.Camera.zoom      , 50  );
			GUI_InputEx<float32>(Locale.Camera.zoomLockOn, Config.Camera.zoomLockOn, 50  );
			ImGui::PopItemWidth();
			ImGui::Text("");
			GUI_Checkbox
			(
				Locale.Camera.applyConfig,
				Config.Camera.applyConfig
			);
			GUI_PUSH_DISABLE(!Config.Camera.applyConfig);
			{
				ImGui::PushItemWidth(100);
				GUI_InputEx<uint32>
				(
					Locale.Camera.rate,
					Config.Camera.rate,
					100
				);
				ImGui::PopItemWidth();
			}
			GUI_POP_DISABLE(!Config.Camera.applyConfig);
			ImGui::Text("");
			if (GUI_Button(Locale.Camera.reset))
			{
				memcpy(&Config.Camera, &DefaultConfig.Camera, sizeof(Config.Camera));
				SaveConfig();
				Camera_Update(DefaultConfig);
			}
			goto End;
		}
		InvalidPointer:
		ImGui::Text("Invalid Pointer!");
	}
	End:
	ImGui::End();
	ImGui::PopStyleVar(3);
}







void GUI_Speed_Draw()
{
	static bool run = false;
	if (!run)
	{
		run = true;
		ImGui::SetNextWindowSize(ImVec2((GUI_Speed_size.x + 16), (GUI_Speed_size.y + 16)));
		ImGui::SetNextWindowPos(ImVec2(900, 100));
	}
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(1, 1));
	if (ImGui::Begin("Speed", &GUI_Speed_show, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse))
	{
		if constexpr (debug)
		{
			auto pos = ImGui::GetWindowPos();
			ImGui::Text("%f %f", pos.x, pos.y);
		}
		auto InputExSpeed = []
		(
			const char * label,
			float32    & var
		)
		{
			if (GUI_InputEx<float32>(label, var, 0.1f))
			{
				var = (ceilf(var * 10000) / 10000);
				Speed_Update(Config);
			}
		};
		//auto InputExSpeedMulti = [&]
		//(
		//	const char ** label,
		//	float32    *  var,
		//	uint8         count
		//)
		//{
		//	for (uint8 index = 0; index < count; index++)
		//	{
		//		InputExSpeed(label[index], var[index]);
		//	}
		//};
		ImGui::PushItemWidth(200);
		//ImGui::Text(Locale.Speed.FrameRate.header);
		//if (GUI_InputEx<uint32>
		//(
		//	Locale.Speed.FrameRate.target,
		//	Config.Speed.FrameRate.target
		//))
		//{
		//	Speed_Update(Config);
		//}
		//ImGui::SameLine();
		//GUI_Tooltip(Locale.Speed.FrameRate.hint, 300);
		//if constexpr (debug)
		//{
		//	ImGui::Text("Multiplier %.3f", Speed_FrameRate_multiplier);
		//}
		//ImGui::Text(Locale.Speed.Main.header);
		InputExSpeed
		(
			Locale.Speed.Main.base,
			Config.Speed.Main.base
		);
		//ImGui::SameLine(300);
		//ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0, 1, 0, 1));
		//ImGui::Text("%.3f", (DefaultConfig.Speed.Main.base * System_Graphics_frameRateMultiplier));
		//ImGui::PopStyleColor();
		InputExSpeed
		(
			Locale.Speed.Main.turbo,
			Config.Speed.Main.turbo
		);
		//ImGui::SameLine(300);
		//ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0, 1, 0, 1));
		//ImGui::Text("%.3f", (DefaultConfig.Speed.Main.turbo * System_Graphics_frameRateMultiplier));
		//ImGui::PopStyleColor();
		InputExSpeed
		(
			Locale.Speed.Main.actor,
			Config.Speed.Main.actor
		);
		InputExSpeed
		(
			Locale.Speed.Main.enemy,
			Config.Speed.Main.enemy
		);


/*

		ImGui::Text(Locale.Speed.Devil.header);
		ImGui::Text(Locale.Speed.Devil.Dante.header);
		InputExSpeedMulti
		(
			Locale.Speed.Devil.Dante.label,
			Config.Speed.Devil.dante,
			countof(Config.Speed.Devil.dante)
		);
		ImGui::Text(Locale.Speed.Devil.Vergil.header);
		InputExSpeedMulti
		(
			Locale.Speed.Devil.Vergil.label,
			Config.Speed.Devil.vergil,
			countof(Config.Speed.Devil.vergil)
		);
		ImGui::Text(Locale.Speed.Devil.NeroAngelo.header);
		InputExSpeedMulti
		(
			Locale.Speed.Devil.NeroAngelo.label,
			Config.Speed.Devil.neroAngelo,
			countof(Config.Speed.Devil.neroAngelo)
		);
		ImGui::Text(Locale.Speed.Quicksilver.header);
		InputExSpeed
		(
			Locale.Speed.Quicksilver.actor,
			Config.Speed.Quicksilver.actor
		);
		InputExSpeed
		(
			Locale.Speed.Quicksilver.enemy,
			Config.Speed.Quicksilver.enemy
		);*/



		//CONFIG DefaultConfig;


		ImGui::PopItemWidth();
		ImGui::Text("");
		if (GUI_Button(Locale.Speed.reset))
		{
			memcpy(&Config.Speed, &DefaultConfig.Speed, sizeof(Config.Speed));
			SaveConfig();
			Speed_Update(DefaultConfig);
		}
	}
	ImGui::End();
	ImGui::PopStyleVar(3);
}



























void GUI_Teleporter_Draw()
{
	static bool run = false;
	if (!run)
	{
		run = true;
		ImGui::SetNextWindowSize(ImVec2(GUI_Teleporter_size.x + 16, GUI_Teleporter_size.y + 16));
		ImGui::SetNextWindowPos(ImVec2(900, 300));
	}
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(1, 1));
	if (ImGui::Begin(Locale.Tools.Teleporter.header, &GUI_Teleporter_show, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize))
	{


		//{
		//	GUI_Input("Relative Tilt Direction", g_relativeTiltDirection);
		//}

		//DrawRelativeTilt();


		//{
		//	ImGui::Text("Counter");
		//	GUI_InputEx("g_mainCounter", g_mainCounter);
		//	GUI_InputEx("g_newCounter", g_newCounter);
		//}


		//{
		//	

		//	


		//	GUI_InputEx("group", g_motionGroup);
		//	GUI_InputEx("index", g_motionIndex);
		//	GUI_Checkbox("Log", g_logMotionData);
		//	ImGui::Text("");
		//}




		{
			static byte8 lowerBody[0x120] = {};
			static byte8 upperBody[0x120] = {};

			if (GUI_Button("Save Body State"))
			{
				auto baseAddr = Actor_actorBaseAddr[2];
				auto & actorData = *reinterpret_cast<ACTOR_DATA_DANTE *>(baseAddr);

				auto bottom = reinterpret_cast<byte8 *>(actorData + 0x6950);
				auto top = reinterpret_cast<byte8 *>(actorData + 0x6A70);

				memcpy(lowerBody, bottom, sizeof(lowerBody));
				memcpy(upperBody, top, sizeof(upperBody));
			}

			if (GUI_Button("Write Body State"))
			{
				auto baseAddr = Actor_actorBaseAddr[2];
				auto & actorData = *reinterpret_cast<ACTOR_DATA_DANTE *>(baseAddr);

				auto bottom = reinterpret_cast<byte8 *>(actorData + 0x6950);
				auto top = reinterpret_cast<byte8 *>(actorData + 0x6A70);

				//memcpy(lowerBody, bottom, sizeof(lowerBody));
				//memcpy(upperBody, top, sizeof(upperBody));


				memcpy(bottom, lowerBody, sizeof(lowerBody));
				memcpy(top, upperBody, sizeof(upperBody));


			}



		}



		ImGui::Text("");



		{
			static uint8 action = 0;
			GUI_InputEx("Action", action);
			if (GUI_Button("Trigger Action"))
			{
				auto baseAddr = Actor_actorBaseAddr[2];
				auto & actorData = *reinterpret_cast<ACTOR_DATA_DANTE *>(baseAddr);
				actorData.action = action;
				func_1E0800(actorData, 17, 0, 0xFFFFFFFF);
			}
			ImGui::SameLine();
			if (GUI_Button("Buffer Action"))
			{
				auto baseAddr = Actor_actorBaseAddr[2];
				auto & actorData = *reinterpret_cast<ACTOR_DATA_DANTE *>(baseAddr);
				actorData.bufferedAction = action;
			}
		}


		ImGui::Text("");

		{
			if (GUI_Button("Trigger Combo 1 Part 3"))
			{
				auto baseAddr = Actor_actorBaseAddr[2];
				auto & actorData = *reinterpret_cast<ACTOR_DATA_DANTE *>(baseAddr);


				func_211100(actorData);

			}
		}





		{

			static uint32 g_duration = 0;


			static uint32 vectorIndex = 0;
			static uint16 cacheFileId = pl000_00_0;
			static uint8 index = 0;



			GUI_InputEx("vectorIndex", vectorIndex);
			GUI_InputEx("cacheFileId", cacheFileId);
			GUI_InputEx("index", index);
			
			GUI_InputEx("duration", g_duration);

			ImGui::Text("");

			ImGui::SameLine(180);

			



			if (GUI_Button("Play Motion"))
			{
				auto file = File_staticFiles[cacheFileId][index];
				if (file)
				{
					auto & duration = *reinterpret_cast<float32 *>(file + 0xC);
					g_duration = static_cast<uint32>(duration);
					Log("file %llX", file);
				}
				auto baseAddr = Actor_actorBaseAddr[vectorIndex];
				auto & actorData = *reinterpret_cast<ACTOR_DATA_DANTE *>(baseAddr);
				func_8AC80(actorData.modelData[actorData.activeModelIndex], BODY_PART_LOWER, File_staticFiles[cacheFileId][index], 0, false);
				func_8AC80(actorData.modelData[actorData.activeModelIndex], BODY_PART_UPPER, File_staticFiles[cacheFileId][index], 0, false);
			}
			

		}








		//{
		//	static uint32 index = 0;
		//	GUI_InputEx<uint32>("Index", index);
		//	if (GUI_Button("Summon Swords"))
		//	{
		//		func_223F50(Actor_actorBaseAddr[0], index);
		//	}
		//	if (GUI_Button("Create Swords"))
		//	{
		//		func_223AC0(Actor_actorBaseAddr[0]);
		//	}
		//	if (GUI_Button("Shoot Sword"))
		//	{
		//		func_223BE0(Actor_actorBaseAddr[0], index);
		//	}
		//}











		//{
		//	static uint8 style = 0;
		//	GUI_InputEx<uint8>("Style", style);
		//	if (GUI_Button("Update Style Icon"))
		//	{
		//		//UpdateStyleIcon(style, styleIconDante[style].model, styleIconDante[style].texture);
		//	}
		//}


		//{
		//	static uint8 index = 0;
		//	static uint8 weapon = 0;
		//	GUI_InputEx<uint8>("Index", index);
		//	GUI_InputEx<uint8>("Weapon", weapon);
		//	if (GUI_Button("Update Weapon Icon"))
		//	{
		//		//UpdateWeaponIcon(index, weaponIcon[weapon].model, weaponIcon[weapon].texture);
		//	}
		//}












		//{
		//	static uint32 off = 0;
		//	if (GUI_Button("Hide"))
		//	{
		//		auto g_pool = *reinterpret_cast<byte8 ***>(appBaseAddr + 0xC90E28);
		//		auto hud = *reinterpret_cast<byte8 **>(g_pool[11]);
		//		auto dest = (hud + off);
		//		auto & visible = *reinterpret_cast<bool *>(dest + 0x18) = false;
		//	}
		//	ImGui::SameLine();
		//	if (GUI_Button("Show"))
		//	{
		//		auto g_pool = *reinterpret_cast<byte8 ***>(appBaseAddr + 0xC90E28);
		//		auto hud = *reinterpret_cast<byte8 **>(g_pool[11]);
		//		auto dest = (hud + off);
		//		auto & visible = *reinterpret_cast<bool *>(dest + 0x18) = true;
		//	}
		//	ImGui::SameLine();
		//	GUI_InputEx<uint32>("Offset", off, 1, true, false);
		//}









		if constexpr (debug)
		{
			auto pos = ImGui::GetWindowPos();
			ImGui::Text("%f %f", pos.x, pos.y);
		}
		{
			if (!InGame())
			{
				goto InvalidPointer;
			}
			VARS vars;
			if (!vars.init)
			{
				goto InvalidPointer;
			}
			uint32 & room         = *vars.room;
			uint32 & position     = *vars.position;
			uint32 & event        = *vars.event;
			uint16 & nextRoom     = *vars.nextRoom;
			uint16 & nextPosition = *vars.nextPosition;
			ImGui::PushItemWidth(100);
			ImGui::Text(Locale.Teleporter.current);
			GUI_Input("", room, false, ImGuiInputTextFlags_ReadOnly);
			GUI_Input("", position, false, ImGuiInputTextFlags_ReadOnly);
			ImGui::Text(Locale.Teleporter.next);
			GUI_InputEx<uint16>("", nextRoom);
			GUI_InputEx<uint16>("", nextPosition);
			if (GUI_Button(Locale.Teleporter.teleport))
			{
				event = EVENT_TELEPORT;
			}
			ImGui::PopItemWidth();
			goto TeleporterEnd;
		}
		InvalidPointer:
		ImGui::Text(Locale.Teleporter.invalidPointer);
		TeleporterEnd:;
	}
	ImGui::End();
	ImGui::PopStyleVar(3);
}







void GUI_Overlay_Draw()
{
	if (!GUI_Overlay_run)
	{
		GUI_Overlay_run = true;
		ImGui::SetNextWindowSize(ImVec2(GUI_Overlay_size.x + 16, GUI_Overlay_size.y + 16));
		ImGui::SetNextWindowPos(ImVec2(Config.Tools.Overlay.x, Config.Tools.Overlay.y));
	}
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(1, 1));
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
	if (ImGui::Begin("GUI_Overlay", &Config.Tools.Overlay.enable, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize))
	{
		{
			ImVec2 pos = ImGui::GetWindowPos();
			if ((Config.Tools.Overlay.x != pos.x) || (Config.Tools.Overlay.y != pos.y))
			{
				Config.Tools.Overlay.x = pos.x;
				Config.Tools.Overlay.y = pos.y;
				SaveConfig();
			}
		}
		ImGuiIO & io = ImGui::GetIO();
		ImGui::PushFont(io.Fonts->Fonts[FONT_OVERLAY_8 + Config.Tools.Overlay.fontSizeIndex]);
		ImGui::PushStyleColor(ImGuiCol_Text, *(ImVec4 *)Config.Tools.Overlay.color);
		//if (Config.Tools.Overlay.heapFrame)
		//{
		//	auto & value = *(uint32 *)(appBaseAddr + 0xCA8958);
		//	ImGui::Text("%s %u", Locale.Tools.Overlay.heapFrame, value);
		//}
		if (Config.Tools.Overlay.focus)
		{
			ImVec4 color = ImVec4(0, 1, 0, 1);
			if (GetForegroundWindow() != appWindow)
			{
				color = ImVec4(1, 0, 0, 1);
			}
			ImGui::PushStyleColor(ImGuiCol_Text, color);
			ImGui::Text(Locale.Tools.Overlay.focus);
			ImGui::PopStyleColor();
		}
		//ImGui::Text("%llu", Game_StyleSwitcher_counter);


		ImGui::Text("%.3f FPS", (ImGui::GetIO().Framerate));


		if (Config.Tools.Overlay.memory)
		{
			uint32 off[] =
			{
				0xCA8910,
				0xCA8938,
				0xCA8960,
			};
			for (uint8 index = 0; index < countof(off); index++)
			{
				MEMORY_OBJECT & object = *(MEMORY_OBJECT *)(appBaseAddr + off[index]);
				ImGui::Text("__%.4u__", index);
				ImGui::Text("addr     %llX", object.addr);
				ImGui::Text("end      %llX", object.end);
				ImGui::Text("last     %X", object.last);
				ImGui::Text("boundary %X", object.boundary);
				ImGui::Text("size     %X", object.size);
				ImGui::Text("pipe     %u", object.pipe);
				ImGui::Text("count    %u", object.count);
			}
		}


		//ImGui::Text("devilCounter %u", devilCounter);


		//ImGui::Text("Delta %f", Update_delta);




		

		//ImGui::Text("%f value", GUI_value);
		//ImGui::Text("%f valueRounded", GUI_valueRounded);





		/*
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		*/


		ImGui::PopStyleColor();
		ImGui::PopFont();
	}
	ImGui::End();
	ImGui::PopStyleColor();
	ImGui::PopStyleVar(3);
}

// void DrawRestartOverlay()
// {
// 	//static ImVec2 size = {};
// 	//ImVec2 position = {};
// 	//position.x = (ImGui::GetIO().DisplaySize.x - size.x) / 2;
// 	//position.y = (ImGui::GetIO().DisplaySize.y - size.y) / 2;
// 	//ImGui::SetNextWindowPos(position);
// 	//ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
// 	//ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
// 	//ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(1, 1));
// 	//ImGui::PushStyleColor(ImGuiCol_WindowBg, ImGui::GetStyle().Colors[ImGuiCol_WindowBg]);
// 	//if (ImGui::Begin("RestartOverlay", &restart, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_AlwaysAutoResize))
// 	//{
// 	//	size = ImGui::GetWindowSize();
// 	//	ImGuiIO & io = ImGui::GetIO();
// 	//	ImGui::PushFont(io.Fonts->Fonts[1]);
// 	//	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1, 0, 0, 1));
// 	//	//ImGui::Text(Locale.restartRequired);
// 	//	ImGui::PopStyleColor();
// 	//	ImGui::PopFont();
// 	//}
// 	//ImGui::End();
// 	//ImGui::PopStyleColor();
// 	//ImGui::PopStyleVar(3);
// }



















// $NewGuiStart

inline void NEW_GUI_PushId()
{
	ImGui::PushID(GUI_id);
	GUI_id++;
}

inline void NEW_GUI_PopId()
{
	ImGui::PopID();
}

bool NEW_GUI_Button
(
	const char * label,
	const ImVec2 & size = ImVec2(0, 0)
)
{
	NEW_GUI_PushId();
	auto update = ImGui::Button(label, size);
	NEW_GUI_PopId();
	return update;
}

bool NEW_GUI_Checkbox
(
	const char * label,
	bool & var,
	bool save = true
)
{
	NEW_GUI_PushId();
	auto update = ImGui::Checkbox(label, &var);
	NEW_GUI_PopId();

	if (update && save)
	{
		SaveConfig();
	}

	return update;
}

template <typename T>
bool NEW_GUI_Input
(
	const char * label,
	T & var,
	T step = 1,
	const char * format = 0,
	ImGuiInputTextFlags flags = 0,
	bool save = true
)
{
	NEW_GUI_PushId();
	auto update = ImGui::InputScalar
	(
		label,
		(TypeMatch<T, uint8  >::value) ? ImGuiDataType_U8    :
		(TypeMatch<T, uint16 >::value) ? ImGuiDataType_U16   :
		(TypeMatch<T, uint32 >::value) ? ImGuiDataType_U32   :
		(TypeMatch<T, uint64 >::value) ? ImGuiDataType_U64   :
		(TypeMatch<T, float32>::value) ? ImGuiDataType_Float :
		0,
		&var,
		(step == 0) ? 0 : &step,
		(step == 0) ? 0 : &step,
		format,
		flags
	);
	NEW_GUI_PopId();

	if (update && save)
	{
		SaveConfig();
	}

	return update;
}

template <typename T>
bool NEW_GUI_InputDefault
(
	const char * label,
	T & var,
	T & defaultVar,
	T step = 1,
	const char * format = 0,
	ImGuiInputTextFlags flags = 0,
	bool save = true
)
{
	auto & window = *ImGui::GetCurrentWindow();
	auto & style = ImGui::GetStyle();

	auto buttonSize = ImVec2(ImGui::GetFrameHeight(), ImGui::GetFrameHeight());

	auto itemWidth = window.DC.ItemWidth;

	if (window.DC.ItemWidthStack.Size > 0)
	{
		window.DC.ItemWidth -= (buttonSize.x + style.ItemInnerSpacing.x);
		window.DC.ItemWidthStack.back() = window.DC.ItemWidth;
	}

	NEW_GUI_PushId();
	auto update = ImGui::InputScalar
	(
		"",
		(TypeMatch<T, uint8  >::value) ? ImGuiDataType_U8    :
		(TypeMatch<T, uint16 >::value) ? ImGuiDataType_U16   :
		(TypeMatch<T, uint32 >::value) ? ImGuiDataType_U32   :
		(TypeMatch<T, uint64 >::value) ? ImGuiDataType_U64   :
		(TypeMatch<T, float32>::value) ? ImGuiDataType_Float :
		0,
		&var,
		(step == 0) ? 0 : &step,
		(step == 0) ? 0 : &step,
		format,
		flags
	);
	NEW_GUI_PopId();

	ImGui::SameLine(0, style.ItemInnerSpacing.x);
	if (NEW_GUI_Button("D", buttonSize))
	{
		update = true;
		var = defaultVar;
	}

	ImGui::SameLine(0, style.ItemInnerSpacing.x);
	ImGui::Text(label);

	if (window.DC.ItemWidthStack.Size > 0)
	{
		window.DC.ItemWidth = itemWidth;
		window.DC.ItemWidthStack.back() = window.DC.ItemWidth;
	}

	if (update && save)
	{
		SaveConfig();
	}

	return update;
}

template <typename T>
bool NEW_GUI_Slider
(
	const char * label,
	T & var,
	const T min,
	const T max,
	bool save = true
)
{
	ImGuiWindow * window = ImGui::GetCurrentWindow();
	ImGuiIO & io = ImGui::GetIO();

	NEW_GUI_PushId();
	auto update = ImGui::SliderScalar
	(
		label,
		(TypeMatch<T, uint8  >::value) ? ImGuiDataType_U8    :
		(TypeMatch<T, uint16 >::value) ? ImGuiDataType_U16   :
		(TypeMatch<T, uint32 >::value) ? ImGuiDataType_U32   :
		(TypeMatch<T, uint64 >::value) ? ImGuiDataType_U64   :
		(TypeMatch<T, float32>::value) ? ImGuiDataType_Float :
		0,
		&var,
		&min,
		&max,
		"%u"
	);
	if (ImGui::IsItemHovered())
	{
		window->Flags |= ImGuiWindowFlags_NoScrollbar;
		window->Flags |= ImGuiWindowFlags_NoScrollWithMouse;
		if (io.MouseWheel < 0)
		{
			if (var > min)
			{
				var--;
				update = true;
			}
		}
		else if (io.MouseWheel > 0)
		{
			if (var < max)
			{
				var++;
				update = true;
			}
		}
	}
	NEW_GUI_PopId();

	if (update && save)
	{
		SaveConfig();
	}

	return update;
}

bool NEW_GUI_Selectable
(
	const char * label,
	bool * selected,
	ImGuiSelectableFlags flags = 0
)
{
	NEW_GUI_PushId();
	auto update = ImGui::Selectable(label, selected, flags);
	NEW_GUI_PopId();
	return update;
}


















template
<
	typename T,
	uint8 count
>
bool NEW_GUI_ComboMap
(
	const char * label,
	const char *(&names)[count],
	T(&map)[count],
	uint8 & index,
	T & var,
	bool save = true
)
{
	bool update = false;
	NEW_GUI_PushId();
	if (ImGui::BeginCombo(label, names[index]))
	{
		for_all(uint8, mapIndex, count)
		{
			auto & mapItem = map[mapIndex];
			bool selected = (mapItem == var) ? true : false;
			NEW_GUI_PushId();
			if (NEW_GUI_Selectable(names[mapIndex], &selected))
			{
				update = true;
				index = mapIndex;
				var = mapItem;
			}
			NEW_GUI_PopId();
		}
		ImGui::EndCombo();
	}
	NEW_GUI_PopId();

	if (update && save)
	{
		SaveConfig();
	}

	return update;
}

template
<
	typename T,
	uint8 count
>
bool NEW_GUI_Combo
(
	const char * label,
	const char *(&names)[count],
	T & var,
	bool save = true
)
{
	bool update = false;
	NEW_GUI_PushId();
	if (ImGui::BeginCombo(label, names[var]))
	{
		for_all(uint8, index, count)
		{
			bool selected = (index == var) ? true : false;
			NEW_GUI_PushId();
			if (NEW_GUI_Selectable(names[index], &selected))
			{
				update = true;
				var = static_cast<T>(index);
			}
			NEW_GUI_PopId();
		}
		ImGui::EndCombo();
	}
	NEW_GUI_PopId();

	if (update && save)
	{
		SaveConfig();
	}

	return update;
}



















































inline void NEW_GUI_SectionStart()
{
	ImGui::Text("");
}

inline void NEW_GUI_SectionStart(const char * label)
{
	ImGui::Text(label);
	ImGui::Text("");
}

inline void NEW_GUI_SectionEnd()
{
	ImGui::Text("");
	ImGui::Separator();
	ImGui::Text("");
}

const char * characterName[] =
{
	"Dante",
	"Bob",
	"Lady",
	"Vergil",
};

inline void CharacterCostumeSelect
(
	uint8 player,
	uint8 entity
)
{
	auto & character = Config.Actor.character[player][entity];
	if (character >= MAX_CHAR)
	{
		character = CHAR_DANTE;
	}
	auto & costume = Config.Actor.costume[player][entity][character];
	ImGui::PushItemWidth(150);
	NEW_GUI_Combo("Character", characterName, character);
	NEW_GUI_Input("Costume", costume);
	ImGui::PopItemWidth();
}







// $MeleeWeaponSelectMapStart






const char * meleeWeaponSelectNamesDante[] =
{
	"Rebellion",
	"Cerberus",
	"Agni & Rudra",
	"Nevan",
	"Beowulf",
	"Vergil Yamato",
	"Vergil Beowulf",
	"Vergil Force Edge",
};

const char * meleeWeaponSelectNamesVergil[] =
{
	"Yamato",
	"Beowulf",
	"Force Edge",
	"Dante Rebellion",
	"Dante Cerberus",
	"Dante Agni & Rudra",
	"Dante Nevan",
	"Dante Beowulf",
};

uint8 meleeWeaponSelectMapDante[] =
{
	WEAPON_DANTE_REBELLION,
	WEAPON_DANTE_CERBERUS,
	WEAPON_DANTE_AGNI_RUDRA,
	WEAPON_DANTE_NEVAN,
	WEAPON_DANTE_BEOWULF,
	WEAPON_VERGIL_YAMATO,
	WEAPON_VERGIL_BEOWULF,
	WEAPON_VERGIL_FORCE_EDGE,
};

uint8 meleeWeaponSelectMapVergil[] =
{
	WEAPON_VERGIL_YAMATO,
	WEAPON_VERGIL_BEOWULF,
	WEAPON_VERGIL_FORCE_EDGE,
	WEAPON_DANTE_REBELLION,
	WEAPON_DANTE_CERBERUS,
	WEAPON_DANTE_AGNI_RUDRA,
	WEAPON_DANTE_NEVAN,
	WEAPON_DANTE_BEOWULF,
};






const char * rangedWeaponSelectNamesDante[] =
{
	"Ebony & Ivory",
	"Shotgun",
	"Artemis",
	"Spiral",
	"Kalina Ann",
};


uint8 rangedWeaponSelectMapDante[] =
{
	WEAPON_DANTE_EBONY_IVORY,
	WEAPON_DANTE_SHOTGUN,
	WEAPON_DANTE_ARTEMIS,
	WEAPON_DANTE_SPIRAL,
	WEAPON_DANTE_KALINA_ANN,
};



















uint8 meleeWeaponSelectIndex [MAX_PLAYER][MAX_ENTITY][MAX_CHAR][MAX_MELEE_WEAPON ] = {};
uint8 rangedWeaponSelectIndex[MAX_PLAYER][MAX_ENTITY][MAX_CHAR][MAX_RANGED_WEAPON] = {};



//
//
//inline void WeaponSelect
//(
//	const char *  label,
//	uint8      *  configMap,
//	uint8         configMapCount,
//	uint8      *  selectMap,
//	uint8         selectMapCount,
//	const char ** selectName,
//	uint8      *  selectIndex,
//	uint8      &  weaponCount
//)
//{
//	if (!selectMap)
//	{
//		return;
//	}
//
//	ImGui::Text(label);
//	ImGui::Text("");
//
//	ImGui::PushItemWidth(250);
//
//	NEW_GUI_Slider<uint8>("", weaponCount, 1, configMapCount);
//
//	for_all(uint8, configMapIndex, configMapCount)
//	{
//		bool skip = (configMapIndex >= weaponCount) ? true : false;
//		GUI_PUSH_DISABLE(skip);
//		auto & configMapItem   = configMap  [configMapIndex];
//		auto & selectIndexItem = selectIndex[configMapIndex];
//
//		NEW_GUI_ComboMap("", selectName)
//
//
//
//			NEW_GUI_ComboMap
//			(
//				"",
//				selectName,
//				selectMapCount,
//				selectMap,
//				selectIndexItem,
//				configMapItem
//			);
//		GUI_POP_DISABLE(skip);
//	}
//
//	ImGui::PopItemWidth();
//
//	ImGui::Text("");
//}
//
//inline void MeleeWeaponSelect
//(
//	uint8 player,
//	uint8 entity,
//	uint8 character
//)
//{
//	WeaponSelect
//	(
//		"Melee Weapons",
//		Config.Actor.meleeWeapon[player][entity][character],
//		MAX_MELEE_WEAPON,
//		meleeWeaponSelectMap     [character],
//		meleeWeaponSelectMapCount[character],
//		meleeWeaponSelectName    [character],
//		meleeWeaponSelectIndex[player][entity][character],
//		Config.Actor.meleeWeaponCount[player][entity][character]
//	);
//}












//uint8 * meleeWeaponSelectMap[MAX_CHAR] =
//{
//	meleeWeaponSelectMapDante,
//	0,
//	0,
//	meleeWeaponSelectMapVergil
//};
//
//uint8 meleeWeaponSelectMapCount[MAX_CHAR] =
//{
//	countof(meleeWeaponSelectMapDante),
//	0,
//	0,
//	countof(meleeWeaponSelectMapVergil),
//};

// $MeleeWeaponSelectMapEnd

// $MeleeWeaponSelectNameStart

//const char * meleeWeaponSelectNameDante[] =
//{
//	"Rebellion",
//	"Cerberus",
//	"Agni & Rudra",
//	"Nevan",
//	"Beowulf",
//	"Vergil Yamato",
//	"Vergil Beowulf",
//	"Vergil Force Edge",
//};
//
//const char * meleeWeaponSelectNameVergil[] =
//{
//	"Yamato",
//	"Beowulf",
//	"Force Edge",
//	"Dante Rebellion",
//	"Dante Cerberus",
//	"Dante Agni & Rudra",
//	"Dante Nevan",
//	"Dante Beowulf",
//};

//const char ** meleeWeaponSelectName[MAX_CHAR] =
//{
//	meleeWeaponSelectNameDante,
//	0,
//	0,
//	meleeWeaponSelectNameVergil,
//};
//
//uint8 meleeWeaponSelectNameCount[MAX_CHAR] =
//{
//	countof(meleeWeaponSelectNameDante),
//	0,
//	0,
//	countof(meleeWeaponSelectNameVergil),
//};

// $MeleeWeaponSelectNameEnd

// $RangedWeaponSelectMapStart


//
//uint8 * rangedWeaponSelectMap[MAX_CHAR] =
//{
//	rangedWeaponSelectMapDante,
//	0,
//	0,
//	0,
//};
//
//uint8 rangedWeaponSelectMapCount[MAX_CHAR] =
//{
//	countof(rangedWeaponSelectMapDante),
//	0,
//	0,
//	0,
//};

// $RangedWeaponSelectMapEnd

// $RangedWeaponSelectNameStart


//
//const char ** rangedWeaponSelectName[MAX_CHAR] =
//{
//	rangedWeaponSelectNameDante,
//	0,
//	0,
//	0,
//};
//
//uint8 rangedWeaponSelectNameCount[MAX_CHAR] =
//{
//	countof(rangedWeaponSelectNameDante),
//	0,
//	0,
//	0,
//};

// $RangedWeaponSelectNameEnd

//uint8 meleeWeaponSelectIndex [MAX_PLAYER][MAX_ENTITY][MAX_CHAR][MAX_MELEE_WEAPON ] = {};








template
<
	uint64 configMapItemCount,
	uint64 selectMapItemCount
>
void WeaponSelectFunction
(
	const char * label,
	uint8(&configMap)[configMapItemCount],
	uint8 & weaponCount,
	const char *(&selectNames)[selectMapItemCount],
	uint8(&selectMap)[selectMapItemCount],
	uint8(&selectIndex)[configMapItemCount]
)
{
	ImGui::Text(label);
	ImGui::Text("");

	ImGui::PushItemWidth(250);

	NEW_GUI_Slider<uint8>("", weaponCount, 1, configMapItemCount);

	for_all(uint8, configMapIndex, configMapItemCount)
	{
		auto & configMapItem   = configMap  [configMapIndex];
		auto & selectIndexItem = selectIndex[configMapIndex];

		bool skip = (configMapIndex >= weaponCount) ? true : false;
		GUI_PUSH_DISABLE(skip);

		NEW_GUI_ComboMap
		(
			"",
			selectNames,
			selectMap,
			selectIndexItem,
			configMapItem
		);

		GUI_POP_DISABLE(skip);
	}

	ImGui::PopItemWidth();
}

template <uint64 character>
void WeaponSelect
(
	uint8 player,
	uint8 entity
)
{
	WeaponSelectFunction
	(
		"Melee Weapons",
		Config.Actor.meleeWeapon     [player][entity][character],
		Config.Actor.meleeWeaponCount[player][entity][character],
		(character == CHAR_DANTE) ? meleeWeaponSelectNamesDante : meleeWeaponSelectNamesVergil,
		(character == CHAR_DANTE) ? meleeWeaponSelectMapDante   : meleeWeaponSelectMapVergil,
		meleeWeaponSelectIndex[player][entity][character]
	);

	if constexpr (character == CHAR_DANTE)
	{
		ImGui::Text("");
		WeaponSelectFunction
		(
			"Ranged Weapons",
			Config.Actor.rangedWeapon     [player][entity][character],
			Config.Actor.rangedWeaponCount[player][entity][character],
			rangedWeaponSelectNamesDante,
			rangedWeaponSelectMapDante,
			rangedWeaponSelectIndex[player][entity][character]
		);
	}
}








































//inline void WeaponSelect
//(
//	const char *  label,
//	uint8      *  configMap,
//	uint8         configMapCount,
//	uint8      *  selectMap,
//	uint8         selectMapCount,
//	const char ** selectName,
//	uint8      *  selectIndex,
//	uint8      &  weaponCount
//)
//{
//	if (!selectMap)
//	{
//		return;
//	}
//
//	ImGui::Text(label);
//	ImGui::Text("");
//
//	ImGui::PushItemWidth(250);
//
//	NEW_GUI_Slider<uint8>("", weaponCount, 1, configMapCount);
//
//	for_all(uint8, configMapIndex, configMapCount)
//	{
//		bool skip = (configMapIndex >= weaponCount) ? true : false;
//		GUI_PUSH_DISABLE(skip);
//		auto & configMapItem   = configMap  [configMapIndex];
//		auto & selectIndexItem = selectIndex[configMapIndex];
//
//		NEW_GUI_ComboMap("", selectName)
//
//
//
//		NEW_GUI_ComboMap
//		(
//			"",
//			selectName,
//			selectMapCount,
//			selectMap,
//			selectIndexItem,
//			configMapItem
//		);
//		GUI_POP_DISABLE(skip);
//	}
//
//	ImGui::PopItemWidth();
//
//	ImGui::Text("");
//}
//
//inline void MeleeWeaponSelect
//(
//	uint8 player,
//	uint8 entity,
//	uint8 character
//)
//{
//	WeaponSelect
//	(
//		"Melee Weapons",
//		Config.Actor.meleeWeapon[player][entity][character],
//		MAX_MELEE_WEAPON,
//		meleeWeaponSelectMap     [character],
//		meleeWeaponSelectMapCount[character],
//		meleeWeaponSelectName    [character],
//		meleeWeaponSelectIndex[player][entity][character],
//		Config.Actor.meleeWeaponCount[player][entity][character]
//	);
//}

//inline void RangedWeaponSelect
//(
//	uint8 player,
//	uint8 entity,
//	uint8 character
//)
//{
//	WeaponSelect
//	(
//		"Ranged Weapons",
//		Config.Actor.rangedWeapon[player][entity][character],
//		MAX_RANGED_WEAPON,
//		rangedWeaponSelectMap     [character],
//		rangedWeaponSelectMapCount[character],
//		rangedWeaponSelectName    [character],
//		rangedWeaponSelectIndex[player][entity][character],
//		Config.Actor.rangedWeaponCount[player][entity][character]
//	);
//}






















//inline void UpdateWeaponSelectIndex
//(
//	uint8 * configMap,
//	uint8   configMapCount,
//	uint8 * selectMap,
//	uint8   selectMapCount,
//	uint8 * selectIndex
//)
//{
//	if (!selectMap)
//	{
//		return;
//	}
//	for_all(uint8, configMapIndex, configMapCount)
//	{
//		auto & configMapItem   = configMap  [configMapIndex];
//		auto & selectIndexItem = selectIndex[configMapIndex];
//		for_all(uint8, selectMapIndex, selectMapCount)
//		{
//			auto & selectMapItem = selectMap[selectMapIndex];
//			if (selectMapItem == configMapItem)
//			{
//				selectIndexItem = selectMapIndex;
//				break;
//			}
//		}
//	}
//}
//
//inline void UpdateMeleeWeaponSelectIndex
//(
//	uint8 player,
//	uint8 entity,
//	uint8 character
//)
//{
//	UpdateWeaponSelectIndex
//	(
//		Config.Actor.meleeWeapon[player][entity][character],
//		MAX_MELEE_WEAPON,
//		meleeWeaponSelectMap     [character],
//		meleeWeaponSelectMapCount[character],
//		meleeWeaponSelectIndex[player][entity][character]
//	);
//}
//
//inline void UpdateRangedWeaponSelectIndex
//(
//	uint8 player,
//	uint8 entity,
//	uint8 character
//)
//{
//	UpdateWeaponSelectIndex
//	(
//		Config.Actor.rangedWeapon[player][entity][character],
//		MAX_RANGED_WEAPON,
//		rangedWeaponSelectMap     [character],
//		rangedWeaponSelectMapCount[character],
//		rangedWeaponSelectIndex[player][entity][character]
//	);
//}
//
//inline void UpdateWeaponSelectIndices()
//{
//	for_all(uint8, player   , MAX_PLAYER){
//	for_all(uint8, entity   , MAX_ENTITY){
//	for_all(uint8, character, MAX_CHAR  )
//	{
//		UpdateMeleeWeaponSelectIndex (player, entity, character);
//		UpdateRangedWeaponSelectIndex(player, entity, character);
//	}}}
//}
//




























inline void ResetActorConfig
(
	uint8 player,
	uint8 entity
)
{
	Config.Actor.character[player][entity] = DefaultConfig.Actor.character[player][entity];

	memcpy(Config.Actor.costume[player][entity], DefaultConfig.Actor.costume[player][entity], sizeof(Config.Actor.costume[player][entity]));

	memcpy(Config.Actor.meleeWeapon [player][entity], DefaultConfig.Actor.meleeWeapon [player][entity], sizeof(Config.Actor.meleeWeapon [player][entity]));
	memcpy(Config.Actor.rangedWeapon[player][entity], DefaultConfig.Actor.rangedWeapon[player][entity], sizeof(Config.Actor.rangedWeapon[player][entity]));

	memcpy(Config.Actor.meleeWeaponCount [player][entity], DefaultConfig.Actor.meleeWeaponCount [player][entity], sizeof(Config.Actor.meleeWeaponCount [player][entity]));
	memcpy(Config.Actor.rangedWeaponCount[player][entity], DefaultConfig.Actor.rangedWeaponCount[player][entity], sizeof(Config.Actor.rangedWeaponCount[player][entity]));

	//for_all(uint8, character, MAX_CHAR)
	//{
	//	UpdateMeleeWeaponSelectIndex (player, entity, character);
	//	UpdateRangedWeaponSelectIndex(player, entity, character);
	//}
}

inline void ActorTabContent
(
	uint8 player,
	uint8 entity
)
{
	ImGui::Text("");
	CharacterCostumeSelect(player, entity);
	ImGui::Text("");

	auto & character = Config.Actor.character[player][entity];

	switch (character)
	{
	case CHAR_DANTE:
	{
		WeaponSelect<CHAR_DANTE>(player, entity);
		break;
	}
	case CHAR_VERGIL:
	{
		WeaponSelect<CHAR_VERGIL>(player, entity);
		break;
	}
	}




	//if (character >= MAX_CHAR)
	//{
	//	character = CHAR_DANTE;
	//}

	//MeleeWeaponSelect (player, entity, character);
	//RangedWeaponSelect(player, entity, character);

	if (NEW_GUI_Button("Reset"))
	{
		ResetActorConfig(player, entity);
	}
}

inline void ActorTab
(
	const char * label,
	uint8 player
)
{
	GUI_PUSH_DISABLE(Config.Actor.playerCount < (player + 1));
	if (ImGui::BeginTabItem(label))
	{
		if (ImGui::BeginTabBar("EntityTabs"))
		{
			if (ImGui::BeginTabItem("Main"))
			{
				ActorTabContent(player, ENTITY_MAIN);
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Clone"))
			{
				ActorTabContent(player, ENTITY_CLONE);
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
		ImGui::EndTabItem();
	}
	GUI_POP_DISABLE(Config.Actor.playerCount < (player + 1));
}

template <typename T>
void ActionData
(
	const char * label,
	T(&vars)[2],
	T(&defaultVars)[2],
	T step = 1,
	const char * format = 0,
	ImGuiInputTextFlags flags = 0,
	bool save = true
)
{
	auto & style = ImGui::GetStyle();

	ImGui::PushItemWidth(150);
	NEW_GUI_InputDefault(""   , vars[0], defaultVars[0], step, format, flags, save);
	ImGui::SameLine(0, style.ItemInnerSpacing.x);
	NEW_GUI_InputDefault(label, vars[1], defaultVars[1], step, format, flags, save);
	ImGui::PopItemWidth();
}




template
<
	typename T1,
	uint64 itemCount,
	typename T2
>
void NEW_GUI_UpdateIndex
(
	T1(&map)[itemCount],
	uint8 & index,
	T2 & var
)
{
	for_all(uint8, mapIndex, itemCount)
	{
		auto & mapItem = map[mapIndex];
		if (mapItem == var)
		{
			index = var;
			break;
		}
	}
}



















const char * modeNames[] =
{
	"Easy",
	"Normal",
	"Hard",
	"Very Hard",
	"Dante Must Die",
	"Heaven or Hell",
};

uint32 modeMap[] =
{
	MODE_EASY,
	MODE_NORMAL,
	MODE_HARD,
	MODE_VERY_HARD,
	MODE_DANTE_MUST_DIE,
	MODE_HARD,
};

uint8 modeIndex = 0;









void NEW_GUI_Main()
{
	static bool run = false;
	if (!run)
	{
		run = true;
		ImGui::SetNextWindowSize(ImVec2(600, 650));
		ImGui::SetNextWindowPos(ImVec2(650, 50));

		//ImGuiIO & io = ImGui::GetIO();
		//io.FontDefault = io.Fonts->Fonts[FONT_MAIN];
		//ImGui::PushFont(io.Fonts->Fonts[FONT_OVERLAY_8 + Config.Tools.Overlay.fontSizeIndex]);

		//ImGui::SetCurrentFont(io.Fonts->Fonts[FONT_OVERLAY_8]);
	}

	if (ImGui::Begin("DDMK 2.7", &pause))
	{
		auto size = ImGui::GetWindowSize();
		ImGui::Text("width  %f", size.x);
		ImGui::Text("height %f", size.y);
		//ImGuiIO & io = ImGui::GetIO();
		//ImGui::SetCurrentFont(io.Fonts->Fonts[FONT_OVERLAY_8]);
		ImGui::Text("actorCount %u", Actor_actorBaseAddr.count);
		ImGui::Text("");


		/*
		dmc3.exe+204C53 - F3 0F10 05 A1B52D00   - movss xmm0,[dmc3.exe+4E01FC] { (-1.50) }

		*/

		auto & actorData = *reinterpret_cast<ACTOR_DATA_DANTE *>(Actor_actorBaseAddr[2]);



		{
			static uint32  arg2           = 8;
			static uint8   arg3           = 14;
			static float32 pull           = -70.0f;
			static float32 pullMultiplier = -1.5f;
			static uint8   arg6           = 0;
			NEW_GUI_Input<uint32 >("arg2"          , arg2          );
			NEW_GUI_Input<uint8  >("arg3"          , arg3          );
			NEW_GUI_Input<float32>("pull"          , pull          );
			NEW_GUI_Input<float32>("pullMultiplier", pullMultiplier);
			NEW_GUI_Input<uint8  >("arg6"          , arg6          );
			if (NEW_GUI_Button("Drop1"))
			{
				func_1DFDA0(actorData, arg2, arg3, pull, pullMultiplier, arg6);
			}
			if (NEW_GUI_Button("Set Y"))
			{
				actorData.position.y = 500;
			}
		}

		{
			//static uint32  arg2 = 50000;
			static float32 arg3 = 1;
			//NEW_GUI_Input<uint32 >("arg2", arg2);
			NEW_GUI_Input<float32>("arg3", arg3);
			if (NEW_GUI_Button("Drop2"))
			{
				func_1FB300(actorData, actorData.rotation, arg3);
			}
		}







		if (ImGui::CollapsingHeader("Actor"))
		{
			ImGui::Text("");
			if (NEW_GUI_Checkbox("Enable", Config.Actor.enable))
			{
				//ToggleUpdateWeapon(Config.Actor.enable);
			}
			ImGui::Text("");
			if (NEW_GUI_Button("Reset"))
			{
				memcpy(&Config.Actor, &DefaultConfig.Actor, sizeof(Config.Actor));
			}
			ImGui::Text("");




			ImGui::PushItemWidth(200);
			NEW_GUI_Slider<uint8>("Player Count", Config.Actor.playerCount, 1, MAX_ACTOR);
			ImGui::PopItemWidth();
			ImGui::Text("");




			if (ImGui::BeginTabBar("PlayerTabs"))
			{
				ActorTab("Player 1", 0);
				ActorTab("Player 2", 1);
				ActorTab("Player 3", 2);
				ActorTab("Player 4", 3);
				ImGui::EndTabBar();
			}
			ImGui::Text("");
		}





		if (ImGui::CollapsingHeader("Dante"))
		{
			NEW_GUI_SectionStart();
			NEW_GUI_Checkbox("Enable", Config.Dante.enable);
			ImGui::Text("");
			if (NEW_GUI_Button("Reset"))
			{
				memcpy(&Config.Dante, &DefaultConfig.Dante, sizeof(Config.Dante));
			}
			NEW_GUI_SectionEnd();








			




			NEW_GUI_SectionStart("Air Hike");
			
			ActionData<uint8>("Count", Config.Dante.AirHike.count, DefaultConfig.Dante.AirHike.count);
			
			ImGui::Text("");
			NEW_GUI_Checkbox("Core Ability", Config.Dante.AirHike.coreAbility);
			NEW_GUI_SectionEnd();

			NEW_GUI_SectionStart("Trickster");
			
			ActionData<uint8>("Dash Count"     , Config.Dante.Trickster.dashCount    , DefaultConfig.Dante.Trickster.dashCount    );
			ActionData<uint8>("Sky Star Count" , Config.Dante.Trickster.skyStarCount , DefaultConfig.Dante.Trickster.skyStarCount );
			ActionData<uint8>("Air Trick Count", Config.Dante.Trickster.airTrickCount, DefaultConfig.Dante.Trickster.airTrickCount);
			
			NEW_GUI_SectionEnd();

			NEW_GUI_SectionStart("Rebellion");
			
			ActionData<float32>("Stinger Duration"    , Config.Dante.Rebellion.stingerDuration   , DefaultConfig.Dante.Rebellion.stingerDuration   , 1 , "%.0f");
			ActionData<float32>("Stinger Range"       , Config.Dante.Rebellion.stingerRange      , DefaultConfig.Dante.Rebellion.stingerRange      , 10, "%.0f");
			ActionData<float32>("Air Stinger Duration", Config.Dante.Rebellion.airStingerDuration, DefaultConfig.Dante.Rebellion.airStingerDuration, 1 , "%.0f");
			ActionData<float32>("Air Stinger Range"   , Config.Dante.Rebellion.airStingerRange   , DefaultConfig.Dante.Rebellion.airStingerRange   , 10, "%.0f");
			
			ImGui::Text("");
			NEW_GUI_Checkbox("Infinite Sword Pierce", Config.Dante.Rebellion.infiniteSwordPierce);
			NEW_GUI_SectionEnd();

			NEW_GUI_SectionStart("Cerberus");
			
			ActionData<float32>("Revolver Height", Config.Dante.Cerberus.revolverHeight, DefaultConfig.Dante.Cerberus.revolverHeight, 0.5f, "%.1f");
			
			NEW_GUI_SectionEnd();

			NEW_GUI_SectionStart("Agni & Rudra");
			
			ActionData<float32>("Jet-Stream Duration", Config.Dante.AgniAndRudra.jetStreamDuration, DefaultConfig.Dante.AgniAndRudra.jetStreamDuration, 1 , "%.0f");
			ActionData<float32>("Jet-Stream Range"   , Config.Dante.AgniAndRudra.jetStreamRange   , DefaultConfig.Dante.AgniAndRudra.jetStreamRange   , 10, "%.0f");
			
			NEW_GUI_SectionEnd();





			NEW_GUI_SectionStart("Nevan");
			
			ActionData<float32>("Reverb Shock Duration", Config.Dante.Nevan.reverbShockDuration, DefaultConfig.Dante.Nevan.reverbShockDuration, 1 , "%.0f");
			ActionData<float32>("Reverb Shock Range"   , Config.Dante.Nevan.reverbShockRange   , DefaultConfig.Dante.Nevan.reverbShockRange   , 10, "%.0f");
			
			NEW_GUI_SectionEnd();




			NEW_GUI_SectionStart("Beowulf");
			

			ActionData<float32>("Straight Duration"    , Config.Dante.Beowulf.straightDuration   , DefaultConfig.Dante.Beowulf.straightDuration   , 1 , "%.0f");
			ActionData<float32>("Straight Range"       , Config.Dante.Beowulf.straightRange      , DefaultConfig.Dante.Beowulf.straightRange      , 10, "%.0f");
			ActionData<float32>("Air Straight Duration", Config.Dante.Beowulf.airStraightDuration, DefaultConfig.Dante.Beowulf.airStraightDuration, 1 , "%.0f");
			ActionData<float32>("Air Straight Range"   , Config.Dante.Beowulf.airStraightRange   , DefaultConfig.Dante.Beowulf.airStraightRange   , 10, "%.0f");
			ActionData<float32>("Rising Dragon Height" , Config.Dante.Beowulf.risingDragonHeight , DefaultConfig.Dante.Beowulf.risingDragonHeight , 10, "%.1f");
			

			ImGui::Text("");
			NEW_GUI_Checkbox("Hide", Config.Dante.Beowulf.hide);
			NEW_GUI_SectionEnd();





			NEW_GUI_SectionStart("Ebony & Ivory");
			NEW_GUI_Checkbox("Foursome Time", Config.Dante.EbonyIvory.foursomeTime);
			NEW_GUI_Checkbox("Infinite Rain Storm", Config.Dante.EbonyIvory.infiniteRainStorm);
			NEW_GUI_SectionEnd();



			NEW_GUI_SectionStart("Shotgun");
			

			ActionData<float32>("Gun Stinger Duration"    , Config.Dante.Shotgun.gunStingerDuration   , DefaultConfig.Dante.Shotgun.gunStingerDuration   , 1 , "%.0f");
			ActionData<float32>("Gun Stinger Range"       , Config.Dante.Shotgun.gunStingerRange      , DefaultConfig.Dante.Shotgun.gunStingerRange      , 10, "%.0f");
			ActionData<float32>("Air Gun Stinger Duration", Config.Dante.Shotgun.airGunStingerDuration, DefaultConfig.Dante.Shotgun.airGunStingerDuration, 1 , "%.0f");
			ActionData<float32>("Air Gun Stinger Range"   , Config.Dante.Shotgun.airGunStingerRange   , DefaultConfig.Dante.Shotgun.airGunStingerRange   , 10, "%.0f");
			
			NEW_GUI_SectionEnd();





			NEW_GUI_SectionStart("Artemis");
			NEW_GUI_Checkbox("Swap Normal Shot and Multi Lock", Config.Dante.Artemis.swapNormalShotAndMultiLock);
			NEW_GUI_Checkbox("Instant Full Charge", Config.Dante.Artemis.instantFullCharge);
			NEW_GUI_SectionEnd();


			ImGui::PushItemWidth(150);


			//NEW_GUI_SectionStart();
			NEW_GUI_InputDefault<uint8>("Crazy Combo Level Multiplier", Config.Dante.crazyComboLevelMultiplier, DefaultConfig.Dante.crazyComboLevelMultiplier);
			NEW_GUI_InputDefault<float32>("Weapon Switch Timeout", Config.Dante.weaponSwitchTimeout, DefaultConfig.Dante.weaponSwitchTimeout, 1, "%.0f");
			NEW_GUI_Checkbox("Summoned Swords", Config.Dante.summonedSwords);

			ImGui::PopItemWidth();


			//NEW_GUI_SectionEnd();

			ImGui::Text("");

			






		}




		if (ImGui::CollapsingHeader("Training"))
		{
			ImGui::Text("");
			NEW_GUI_Checkbox("Enable", Config.Training.enable);
			ImGui::Text("");
			NEW_GUI_Button("Reset");
			ImGui::Text("");
			if (NEW_GUI_Checkbox("Infinite Hit Points", Config.Training.infiniteHitPoints))
			{
				Training_ToggleInfiniteHitPoints(Config.Training.infiniteHitPoints);

			}
			if (NEW_GUI_Checkbox("Infinite Magic Points", Config.Training.infiniteMagicPoints))
			{

			}
			if (NEW_GUI_Checkbox("Disable Timer", Config.Training.disableTimer))
			{

			}
			ImGui::Text("");
		}


		if (ImGui::CollapsingHeader("System"))
		{
			ImGui::Text("");
			NEW_GUI_SectionStart("Event");
			NEW_GUI_Checkbox("Skip Intro"    , Config.Event.skipIntro    );
			NEW_GUI_Checkbox("Skip Cutscenes", Config.Event.skipCutscenes);
			NEW_GUI_SectionEnd();

			NEW_GUI_SectionStart("File");
			NEW_GUI_Checkbox("Prefer Local Files", Config.File.preferLocalFiles);
			NEW_GUI_SectionEnd();

			NEW_GUI_SectionStart("Graphics");
			NEW_GUI_InputDefault("Frame Rate", Config.Graphics.frameRate, DefaultConfig.Graphics.frameRate);

			const char * items[] =
			{
				"Auto",
				"Force Off",
				"Force On",
			};
			//NEW_GUI_Combo<uint8>("V-Sync", items, countof<uint8>(items), Config.Graphics.vSync);
			//NEW_GUI_SectionEnd();

			NEW_GUI_SectionStart("Input");
			NEW_GUI_Checkbox("Hide Mouse Cursor", Config.Input.hideMouseCursor);
			NEW_GUI_SectionEnd();

			NEW_GUI_SectionStart("Window");
			NEW_GUI_Checkbox("Force Focus", Config.Window.forceFocus);
			NEW_GUI_SectionEnd();






		}


		if (ImGui::CollapsingHeader("Teleporter"))
		{
			auto Draw = []()
			{
				if (!InGame())
				{
					return false;
				}
				auto pool = *reinterpret_cast<byte8 ***>(appBaseAddr + 0xC90E10);
				if (!pool)
				{
					return false;
				}
				if (!pool[8])
				{
					return false;
				}
				if (!pool[12])
				{
					return false;
				}
				auto & eventData = *reinterpret_cast<EVENT_DATA *>(pool[8]);
				auto & nextEventData = *reinterpret_cast<NEXT_EVENT_DATA *>(pool[12]);
				float32 width = 150;

				ImGui::PushItemWidth(width);
				ImGui::Text("Current");
				NEW_GUI_Input<uint32>("", eventData.room    , 0, "%u", ImGuiInputTextFlags_ReadOnly, false);
				NEW_GUI_Input<uint32>("", eventData.position, 0, "%u", ImGuiInputTextFlags_ReadOnly, false);
				ImGui::Text("Next");
				NEW_GUI_Input<uint16>("", nextEventData.room    , 1, "%u", 0, false);
				NEW_GUI_Input<uint16>("", nextEventData.position, 1, "%u", 0, false);
				if (NEW_GUI_Button("Teleport", ImVec2(width, ImGui::GetFrameHeight())))
				{
					eventData.index = EVENT_TELEPORT;
				}
				ImGui::PopItemWidth();

				return true;
			};

			ImGui::Text("");
			if (!Draw())
			{
				ImGui::Text("Invalid Pointer");
			}
		}


		if (ImGui::CollapsingHeader("Arcade"))
		{
			ImGui::Text("");
			NEW_GUI_Checkbox("Enable", Config.Arcade.enable);
			ImGui::Text("");
			NEW_GUI_Button("Reset");
			ImGui::Text("");



			const char * missionNames[] =
			{
				"Movie",
				"Mission 1",
				"Mission 2",
				"Mission 3",
				"Mission 4",
				"Mission 5",
				"Mission 6",
				"Mission 7",
				"Mission 8",
				"Mission 9",
				"Mission 10",
				"Mission 11",
				"Mission 12",
				"Mission 13",
				"Mission 14",
				"Mission 15",
				"Mission 16",
				"Mission 17",
				"Mission 18",
				"Mission 19",
				"Mission 20",
				"Bloody Palace",
			};
			//NEW_GUI_Combo<uint32>("Mission", missionNames, countof<uint32>(missionNames), Config.Arcade.mission);
			NEW_GUI_Combo("Mission", missionNames, Config.Arcade.mission);







			NEW_GUI_ComboMap("Mode", modeNames, modeMap, modeIndex, Config.Arcade.mode);


















		}



		




	}
	ImGui::End();
}















export void GUI_Render()
{
	if (GUI_hide)
	{
		return;
	}
	GUI_id = 0;
	if (pause)
	{
		GUI_Main_Draw();
	}
	if (Config.Tools.Overlay.enable)
	{
		GUI_Overlay_Draw();
	}
	if (GUI_Camera_show)
	{
		GUI_Camera_Draw();
	}
	if (GUI_Speed_show)
	{
		GUI_Speed_Draw();
	}
	if (GUI_Teleporter_show)
	{
		GUI_Teleporter_Draw();
	}
	//if (restart)
	//{
	//	DrawRestartOverlay();
	//}

	//ImGui::ShowDemoWindow();

	if (pause)
	{
		NEW_GUI_Main();
	}

	



}

export void GUI_Init()
{
	BuildFonts();

	//for_all(uint8, player   , MAX_PLAYER){
	//for_all(uint8, entity   , MAX_ENTITY){
	//for_all(uint8, character, MAX_CHAR  )
	//{
	//	UpdateMeleeWeaponSelectIndex (player, entity, character);
	//	UpdateRangedWeaponSelectIndex(player, entity, character);
	//}}}

	
	//NEW_GUI_UpdateIndex(modeMap, modeIndex, Config.Arcade.mode);






}

#ifdef __GARBAGE__
#endif

#endif
