module;
#include "../Core/Core.h"

#include "Vars.h"
export module Event;

import Actor;
import Arcade;
import BossRush;

import Config;


import File;
import Model;

#define debug false


//bool MainLoop_run = false;










// void SetPool()
// {
// 	LogFunction();
// }

// void ClearPool()
// {
// 	LogFunction();
// }
































//bool Main_run = false;
//bool Teleport_run = false;
//bool Customize_run = false;
//bool Delete_run = false;


bool Event_run[MAX_EVENT] = {};

bool MainLoopOnce_run = false;
bool MainLoopOnceSync_run = false;










void InitSession()
{
	LogFunction();
	Arcade_InitSession();
}

void SetCharacter(byte8 * dest)
{
	LogFunction();
	Arcade_SetCharacter(dest);
}

void SetRoom()
{
	LogFunction();
	Arcade_SetRoom();
	BossRush_SetRoom();
}

void SetNextRoom()
{
	LogFunction();
	Actor_SetNextRoom();
	BossRush_SetNextRoom();
}

void SetContinueRoom()
{
	LogFunction();
	BossRush_SetContinueRoom();
}

bool SetTrack
(
	byte8 * dest,
	const char * filename,
	uint32 arg3,
	uint32 arg4
)
{
	Log("%s %llX %s %u %u", FUNC_NAME, dest, filename, arg3, arg4);

	return BossRush_SetTrack(filename);
}




// export void LockActor(byte8 * baseAddr)
// {
// 	auto & actorData = *reinterpret_cast<ActorData *>(baseAddr);
// 	actorData.newButtonMask = 0;
// 	actorData.newEnableRightStick = false;
// 	actorData.newEnableLeftStick = false;
// }


// export void UnlockActor(byte8 * baseAddr)
// {
// 	auto & actorData = *reinterpret_cast<ActorData *>(baseAddr);
// 	actorData.newButtonMask = 0xFFFF;
// 	actorData.newEnableRightStick = true;
// 	actorData.newEnableLeftStick = true;
// }





void CreateMainActor(byte8 * baseAddr)
{
	memset(Event_run, 0, MAX_EVENT);
	MainLoopOnce_run = false;
	MainLoopOnceSync_run = false;

	Actor_CreateMainActor(baseAddr);

	Arcade_CreateMainActor(baseAddr);
}

void Main_CreateMainActor(byte8 * baseAddr)
{
	LogFunction();

	return CreateMainActor(baseAddr);
}

void Customize_CreateMainActor(byte8 * baseAddr)
{
	LogFunction();

	return CreateMainActor(baseAddr);
}



void CreateCloneActor(byte8 * baseAddr)
{
	Actor_CreateCloneActor(baseAddr);
}

void Main_CreateCloneActor(byte8 * baseAddr)
{
	LogFunction();

	return CreateCloneActor(baseAddr);
}

void UpdateActorDante_CreateCloneActor(byte8 * baseAddr)
{
	LogFunction();

	return CreateCloneActor(baseAddr);
}







// @Todo: Update names.

bool EventOnce(EventData & eventData)
{
	auto event = eventData.event;
	if (event >= MAX_EVENT)
	{
		return false;
	}

	auto & run = Event_run[event];
	if (run)
	{
		return false;
	}

	run = true;

	switch (eventData.event)
	{
	case EVENT_MAIN:
	{
		Log("Main");
		Actor_Main();
		BossRush_Main();
		break;
	}
	case EVENT_TELEPORT:
	{
		Log("Teleport");
		break;
	}
	case EVENT_DEATH:
	{
		Log("Death");
		break;
	}
	case EVENT_CUSTOMIZE:
	{
		Log("Customize");
		Actor_Customize();
		break;
	}
	case EVENT_DELETE:
	{
		Log("Delete %u", eventData.subevent);
		Actor_Delete();
		break;
	}
	}

	return false;
}

void EventLoop(EventData & eventData)
{
	return;
}

void EventHandler(EventData & eventData)
{
	if (EventOnce(eventData))
	{
		return;
	}
	EventLoop(eventData);
}

void MainLoopOnce()
{
	if (!MainLoopOnce_run)
	{
		MainLoopOnce_run = true;

		LogFunction();

		Actor_MainLoopOnce();
	}
}

void MainLoopOnceSync()
{
	auto & cutsceneBar = *reinterpret_cast<bool *>(appBaseAddr + 0x5D113D);
	if (cutsceneBar)
	{
		return;
	}

	if (!MainLoopOnceSync_run)
	{
		MainLoopOnceSync_run = true;

		LogFunction();

		Actor_MainLoopOnceSync();
	}
}






/*
void Camera_Update(CONFIG & config)
{
	// @Todo: Add to vars.
	auto addr = *(byte8 **)(appBaseAddr + 0xC8FBD0);
	if (!addr)
	{
		return;
	}
	addr = *(byte8 **)(addr + 0x498);
	if (!addr)
	{
		return;
	}
	auto & height     = *(float32 *)(addr + 0xD0) = config.Camera.height;
	auto & tilt       = *(float32 *)(addr + 0xD4) = config.Camera.tilt;
	auto & zoom       = *(float32 *)(addr + 0xD8) = config.Camera.zoom;
	auto & zoomLockOn = *(float32 *)(addr + 0xE0) = config.Camera.zoomLockOn;
}
*/



float cameraTimeout = 0;


void UpdateCamera()
{

	if (cameraTimeout > 0)
	{
		cameraTimeout -= 10.0f;
	}
	else if (cameraTimeout < 0)
	{
		cameraTimeout = 0;
	}



	if (cameraTimeout > 0)
	{
		return;
	}



	if (!activeConfig.Camera.applyConfig)
	{
		return;
	}







	IntroduceCameraData(return);

	cameraData.height     = activeConfig.Camera.height;
	cameraData.tilt       = activeConfig.Camera.tilt;
	cameraData.zoom       = activeConfig.Camera.zoom;
	cameraData.zoomLockOn = activeConfig.Camera.zoomLockOn;

	cameraTimeout = activeConfig.Camera.timeout;








}









void MainLoop()
{
	MainLoopOnce();
	MainLoopOnceSync();


	UpdateCamera();


	CharacterSwitchController();




}

void ActorLoop(byte8 * baseAddr)
{
	static bool run = false;
	if (!run)
	{
		run = true;
		LogFunction();
	}
	Actor_ActorLoop(baseAddr);
}

// void SkyStarReset(byte8 * baseAddr)
// {
// 	Mobility::SkyStarReset(baseAddr);
// }



// void DeactivateDevilForm(byte8 * baseAddr)
// {
// 	if (!baseAddr)
// 	{
// 		return;
// 	}

// 	Actor_DeactivateDevilForm(baseAddr);
// }

void InGameCutsceneStart()
{
	LogFunction();

	Actor_InGameCutsceneStart();
}

void InGameCutsceneEnd()
{
	LogFunction();

	Actor_InGameCutsceneEnd();
}




export void Event_Init()
{
	LogFunction();



	// {
	// 	constexpr byte8 sect0[] =
	// 	{
	// 		0x40, 0x88, 0xB7, 0x9B, 0x3E, 0x00, 0x00, // mov [rdi+00003E9B],sil
	// 	};
	// 	constexpr byte8 sect1[] =
	// 	{
	// 		mov_rcx_rdi,
	// 	};
	// 	auto func = CreateFunction(DeactivateDevilForm, (appBaseAddr + 0x1E78C6), true, true, sizeof(sect0), sizeof(sect1));
	// 	memcpy(func.sect0, sect0, sizeof(sect0));
	// 	memcpy(func.sect1, sect1, sizeof(sect1));
	// 	WriteJump((appBaseAddr + 0x1E78BF), func.addr, 2);
	// 	/*
	// 	dmc3.exe+1E78BF - 40 88 B7 9B3E0000 - mov [rdi+00003E9B],sil
	// 	dmc3.exe+1E78C6 - 48 8B CF          - mov rcx,rdi
	// 	*/
	// }










	// Main
	{
		constexpr byte8 sect0[] =
		{
			0xE8, 0x00, 0x00, 0x00, 0x00, // call dmc3.exe+212760
		};
		auto func = CreateFunction(InitSession, (appBaseAddr + 0x2432CB), true, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		WriteCall(func.sect0, (appBaseAddr + 0x212760));
		WriteJump((appBaseAddr + 0x2432C6), func.addr);
		/*
		dmc3.exe+2432C6 - E8 95F4FCFF - call dmc3.exe+212760
		dmc3.exe+2432CB - 33 FF       - xor edi,edi
		*/
	}
	{
		constexpr byte8 sect1[] =
		{
			0x48, 0x8B, 0xC8, //mov rcx,rax
		};
		constexpr byte8 sect2[] =
		{
			0x0F, 0xB6, 0x88, 0x65, 0x45, 0x00, 0x00, // movzx ecx,byte ptr [rax+00004565]
		};
		auto func = CreateFunction(SetCharacter, (appBaseAddr + 0x24350B), true, true, 0, sizeof(sect1), sizeof(sect2));
		memcpy(func.sect1, sect1, sizeof(sect1));
		memcpy(func.sect2, sect2, sizeof(sect2));
		WriteJump((appBaseAddr + 0x243504), func.addr, 2);
		/*
		dmc3.exe+243504 - 0FB6 88 65450000 - movzx ecx,byte ptr [rax+00004565]
		dmc3.exe+24350B - 88 0D 53BDA400   - mov [dmc3.exe+C8F264],cl
		*/
	}
	{
		constexpr byte8 sect0[] =
		{
			0x66, 0x89, 0x82, 0x64, 0x01, 0x00, 0x00, // mov [rdx+00000164],ax
		};
		constexpr byte8 sect1[] =
		{
			0x48, 0x8B, 0xCA, //mov rcx,rdx
		};
		auto func = CreateFunction(SetRoom, (appBaseAddr + 0x1AA8CC), true, true, sizeof(sect0), sizeof(sect1));
		memcpy(func.sect0, sect0, sizeof(sect0));
		memcpy(func.sect1, sect1, sizeof(sect1));
		WriteJump((appBaseAddr + 0x1AA8C5), func.addr, 2);
		/*
		dmc3.exe+1AA8C5 - 66 89 82 64010000 - mov [rdx+00000164],ax
		dmc3.exe+1AA8CC - C3                - ret
		*/
	}












	// Set Next Room
	{
		constexpr byte8 sect0[] =
		{
			0x66, 0x89, 0x90, 0x66, 0x01, 0x00, 0x00, // mov [rax+00000166],dx
		};
		constexpr byte8 sect1[] =
		{
			0x48, 0x8B, 0xC8, //mov rcx,rax
		};
		auto func = CreateFunction(SetNextRoom, (appBaseAddr + 0x1A6002), true, true, sizeof(sect0), sizeof(sect1));
		memcpy(func.sect0, sect0, sizeof(sect0));
		memcpy(func.sect1, sect1, sizeof(sect1));
		WriteJump((appBaseAddr + 0x1A5FFB), func.addr, 2);
		/*
		dmc3.exe+1A5FFB - 66 89 90 66010000 - mov [rax+00000166],dx
		dmc3.exe+1A6002 - EB 23             - jmp dmc3.exe+1A6027
		*/
	}
	{
		constexpr byte8 sect0[] =
		{
			0x66, 0x89, 0x81, 0x66, 0x01, 0x00, 0x00, // mov [rcx+00000166],ax
		};
		auto func = CreateFunction(SetNextRoom, (appBaseAddr + 0x1A6114), true, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		WriteJump((appBaseAddr + 0x1A610D), func.addr, 2);
		/*
		dmc3.exe+1A610D - 66 89 81 66010000 - mov [rcx+00000166],ax
		dmc3.exe+1A6114 - 89 A9 60010000    - mov [rcx+00000160],ebp
		*/
	}
	{
		constexpr byte8 sect0[] =
		{
			0x66, 0x89, 0x8E, 0x66, 0x01, 0x00, 0x00, // mov [rsi+00000166],cx
		};
		constexpr byte8 sect1[] =
		{
			mov_rcx_rsi,
		};
		auto func = CreateFunction(SetNextRoom, (appBaseAddr + 0x1A6687), true, true, sizeof(sect0), sizeof(sect1));
		memcpy(func.sect0, sect0, sizeof(sect0));
		memcpy(func.sect1, sect1, sizeof(sect1));
		WriteJump((appBaseAddr + 0x1A6680), func.addr, 2);
		/*
		dmc3.exe+1A6680 - 66 89 8E 66010000 - mov [rsi+00000166],cx
		dmc3.exe+1A6687 - 40 38 BE C6000000 - cmp [rsi+000000C6],dil
		*/
	}
















	{
		constexpr byte8 sect0[] =
		{
			0x66, 0x89, 0x81, 0x66, 0x01, 0x00, 0x00, // mov [rcx+00000166],ax
		};
		auto func = CreateFunction(SetContinueRoom, (appBaseAddr + 0x1AA3CC), true, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		WriteJump((appBaseAddr + 0x1AA3C5), func.addr, 2);
		/*
		dmc3.exe+1AA3C5 - 66 89 81 66010000       - mov [rcx+00000166],ax
		dmc3.exe+1AA3CC - C7 81 60010000 00000000 - mov [rcx+00000160],00000000
		*/
	}
	{
		constexpr byte8 sect0[] =
		{
			0x48, 0x89, 0x5C, 0x24, 0x08, // mov [rsp+08],rbx
		};
		constexpr byte8 sect2[] =
		{
			0x84, 0xC0, // test al,al
			0x75, 0x01, // jne short
			0xC3,       // ret
		};
		auto func = CreateFunction(SetTrack, (appBaseAddr + 0x32BA95), true, false, sizeof(sect0), 0, sizeof(sect2));
		memcpy(func.sect0, sect0, sizeof(sect0));
		memcpy(func.sect2, sect2, sizeof(sect2));
		WriteJump((appBaseAddr + 0x32BA90), func.addr);
		/*
		dmc3.exe+32BA90 - 48 89 5C 24 08 - mov [rsp+08],rbx
		dmc3.exe+32BA95 - 48 89 6C 24 10 - mov [rsp+10],rbp
		*/
	}

	// Create Main Actor
	{
		constexpr byte8 sect0[] =
		{
			0xE8, 0x00, 0x00, 0x00, 0x00, //call dmc3.exe+1DE820
		};
		constexpr byte8 sect1[] =
		{
			mov_rcx_rax,
		};
		auto func = CreateFunction(Main_CreateMainActor, (appBaseAddr + 0x23C77E), true, true, sizeof(sect0), sizeof(sect1));
		memcpy(func.sect0, sect0, sizeof(sect0));
		memcpy(func.sect1, sect1, sizeof(sect1));
		WriteCall(func.sect0, (appBaseAddr + 0x1DE820));
		WriteJump((appBaseAddr + 0x23C779), func.addr);
		/*
		dmc3.exe+23C779 - E8 A220FAFF       - call dmc3.exe+1DE820
		dmc3.exe+23C77E - 48 89 87 B82C0000 - mov [rdi+00002CB8],rax
		*/
	}
	{
		constexpr byte8 sect0[] =
		{
			0xE8, 0x00, 0x00, 0x00, 0x00, // call dmc3.exe+1DE820
		};
		constexpr byte8 sect1[] =
		{
			mov_rcx_rax,
		};
		auto func = CreateFunction(Customize_CreateMainActor, (appBaseAddr + 0x23B7B8), true, true, sizeof(sect0), sizeof(sect1));
		memcpy(func.sect0, sect0, sizeof(sect0));
		memcpy(func.sect1, sect1, sizeof(sect1));
		WriteCall(func.sect0, (appBaseAddr + 0x1DE820));
		WriteJump((appBaseAddr + 0x23B7B3), func.addr);
		/*
		dmc3.exe+23B7B3 - E8 6830FAFF       - call dmc3.exe+1DE820
		dmc3.exe+23B7B8 - 48 89 87 B82C0000 - mov [rdi+00002CB8],rax
		*/
	}

	// Create Clone Actor
	{
		constexpr byte8 sect0[] =
		{
			0xE8, 0x00, 0x00, 0x00, 0x00, // call dmc3.exe+1DE820
		};
		constexpr byte8 sect1[] =
		{
			mov_rcx_rax,
		};
		auto func = CreateFunction(Main_CreateCloneActor, (appBaseAddr + 0x211E88), true, true, sizeof(sect0), sizeof(sect1));
		memcpy(func.sect0, sect0, sizeof(sect0));
		memcpy(func.sect1, sect1, sizeof(sect1));
		WriteCall(func.sect0, (appBaseAddr + 0x1DE820));
		WriteJump((appBaseAddr + 0x211E83), func.addr);
		/*
		dmc3.exe+211E83 - E8 98C9FCFF       - call dmc3.exe+1DE820
		dmc3.exe+211E88 - 48 89 83 78640000 - mov [rbx+00006478],rax
		*/
	}
	{
		constexpr byte8 sect0[] =
		{
			0xE8, 0x00, 0x00, 0x00, 0x00, // call dmc3.exe+1DE820
		};
		constexpr byte8 sect1[] =
		{
			mov_rcx_rax,
		};
		auto func = CreateFunction(UpdateActorDante_CreateCloneActor, (appBaseAddr + 0x2134E3), true, true, sizeof(sect0), sizeof(sect1));
		memcpy(func.sect0, sect0, sizeof(sect0));
		memcpy(func.sect1, sect1, sizeof(sect1));
		WriteCall(func.sect0, (appBaseAddr + 0x1DE820));
		WriteJump((appBaseAddr + 0x2134DE), func.addr);
		/*
		dmc3.exe+2134DE - E8 3DB3FCFF       - call dmc3.exe+1DE820
		dmc3.exe+2134E3 - 48 89 86 78640000 - mov [rsi+00006478],rax
		*/
	}






















	// Event Handler
	{
		constexpr byte8 sect1[] =
		{
			mov_rcx_rbx,
		};
		constexpr byte8 sect2[] =
		{
			0x48, 0x03, 0xCA, // add rcx,rdx
			0xFF, 0xE1,       // jmp rcx
		};
		auto func = CreateFunction(EventHandler, 0, true, true, 0, sizeof(sect1), sizeof(sect2));
		memcpy(func.sect1, sect1, sizeof(sect1));
		memcpy(func.sect2, sect2, sizeof(sect2));
		WriteJump((appBaseAddr + 0x23B41F), func.addr);
		/*
		dmc3.exe+23B41F - 48 03 CA - add rcx,rdx
		dmc3.exe+23B422 - FF E1    - jmp rcx
		*/
	}

	// Loops
	{
		constexpr byte8 sect0[] =
		{
			0xE8, 0x00, 0x00, 0x00, 0x00, // call dmc3.exe+23B060
		};
		auto func = CreateFunction(MainLoop, (appBaseAddr + 0x23D4B7), true, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		WriteCall(func.sect0, (appBaseAddr + 0x23B060));
		WriteJump((appBaseAddr + 0x23D4B2), func.addr);
		/*
		dmc3.exe+23D4B2 - E8 A9DBFFFF - call dmc3.exe+23B060
		dmc3.exe+23D4B7 - 84 C0       - test al,al
		*/
	}
	{
		/*
		dmc3.exe+1E25EB - E8 F0820000 - call dmc3.exe+1EA8E0 - Weapon Switch Controller Dante
		dmc3.exe+1F900E - E8 5D94FEFF - call dmc3.exe+1E2470 - Actor Input Handler
		dmc3.exe+1DFA96 - E8 05890100 - call dmc3.exe+1F83A0 - Actor Main Update
		*/
		constexpr byte8 sect0[] =
		{
			0xE8, 0x00, 0x00, 0x00, 0x00, // call dmc3.exe+1F83A0
		};
		constexpr byte8 sect1[] =
		{
			mov_rcx_rbx,
		};
		auto func = CreateFunction(ActorLoop, (appBaseAddr + 0x1DFA9B), true, true, sizeof(sect0), sizeof(sect1));
		memcpy(func.sect0, sect0, sizeof(sect0));
		memcpy(func.sect1, sect1, sizeof(sect1));
		WriteCall(func.sect0, (appBaseAddr + 0x1F83A0));
		WriteJump((appBaseAddr + 0x1DFA96), func.addr);
		/*
		dmc3.exe+1DFA96 - E8 05890100 - call dmc3.exe+1F83A0
		dmc3.exe+1DFA9B - EB 08       - jmp dmc3.exe+1DFAA5
		*/
	}

	// In-Game Cutscenes
	{
		constexpr byte8 sect0[] =
		{
			0xC6, 0x05, 0x00, 0x00, 0x00, 0x00, 0x01, // mov byte ptr [dmc3.exe+5D113D],01
		};
		auto func = CreateFunction(InGameCutsceneStart, (appBaseAddr + 0x23DD73), true, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		WriteAddress(func.sect0, (appBaseAddr + 0x5D113D), 7, 0, 0, 0, 1);
		WriteJump((appBaseAddr + 0x23DD6C), func.addr, 2);
		/*
		dmc3.exe+23DD6C - C6 05 CA333900 01 - mov byte ptr [dmc3.exe+5D113D],01
		dmc3.exe+23DD73 - E8 988B0E00       - call dmc3.exe+326910
		*/
	}
	{
		constexpr byte8 sect0[] =
		{
			0xC6, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, // mov byte ptr [dmc3.exe+5D113D],00
		};
		auto func = CreateFunction(InGameCutsceneEnd, (appBaseAddr + 0x23DEAA), true, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		WriteAddress(func.sect0, (appBaseAddr + 0x5D113D), 7, 0, 0, 0, 1);
		WriteJump((appBaseAddr + 0x23DEA3), func.addr, 2);
		/*
		dmc3.exe+23DEA3 - C6 05 93323900 00       - mov byte ptr [dmc3.exe+5D113D],00
		dmc3.exe+23DEAA - C7 05 ECAAA700 00000000 - mov [dmc3.exe+CB89A0],00000000
		*/
	}










	// {
	// 	constexpr byte8 sect0[] =
	// 	{
	// 		0x48, 0x89, 0x15, 0x00, 0x00, 0x00, 0x00, //mov [dmc3.exe+C90E28],rdx
	// 	};
	// 	auto func = CreateFunction(SetPool, (appBaseAddr + 0x23E69F), true, true, sizeof(sect0));
	// 	memcpy(func.sect0, sect0, sizeof(sect0));
	// 	WriteAddress(func.sect0, (appBaseAddr + 0xC90E28), 7);
	// 	WriteJump((appBaseAddr + 0x23E698), func.addr, 2);
	// 	/*
	// 	dmc3.exe+23E698 - 48 89 15 8927A500 - mov [dmc3.exe+C90E28],rdx
	// 	dmc3.exe+23E69F - 48 8D 83 D06A0000 - lea rax,[rbx+00006AD0]
	// 	*/
	// }
	// {
	// 	constexpr byte8 sect0[] =
	// 	{
	// 		0x48, 0x89, 0x0D, 0x00, 0x00, 0x00, 0x00, //mov [dmc3.exe+C90E28],rcx
	// 	};
	// 	auto func = CreateFunction(ClearPool, (appBaseAddr + 0x23B39A), true, true, sizeof(sect0));
	// 	memcpy(func.sect0, sect0, sizeof(sect0));
	// 	WriteAddress(func.sect0, (appBaseAddr + 0xC90E28), 7);
	// 	WriteJump((appBaseAddr + 0x23B393), func.addr, 2);
	// 	/*
	// 	dmc3.exe+23B393 - 48 89 0D 8E5AA500 - mov [dmc3.exe+C90E28],rcx
	// 	dmc3.exe+23B39A - 48 89 0D 975AA500 - mov [dmc3.exe+C90E38],rcx
	// 	*/
	// }
}

export void Event_ToggleSkipIntro(bool enable)
{
	LogFunction(enable);
	WriteAddress((appBaseAddr + 0x2383F2), (enable) ? (appBaseAddr + 0x2383F8) : (appBaseAddr + 0x238527), 6); // Skip Message
	WriteAddress((appBaseAddr + 0x241789), (enable) ? (appBaseAddr + 0x24178B) : (appBaseAddr + 0x2417A6), 2); // Skip Video
	Write<uint8>((appBaseAddr + 0x238704), (enable) ? 0 : 1); // Hide Rebellion
	// Disable Video Timer
	{
		auto dest = (appBaseAddr + 0x243531);
		if (enable)
		{
			vp_memset(dest, 0x90, 2);
		}
		else
		{
			constexpr byte8 buffer[] =
			{
				0xFF, 0xC8, //dec eax
			};
			vp_memcpy(dest, buffer, sizeof(buffer));
		}
	}
}

export void Event_ToggleSkipCutscenes(bool enable)
{
	LogFunction(enable);

	WriteAddress((appBaseAddr + 0x238CCA), (enable) ? (appBaseAddr + 0x238CD0) : (appBaseAddr + 0x238E62), 6);
	/*
	dmc3.exe+238CCA - 0F85 92010000 - jne dmc3.exe+238E62
	dmc3.exe+238CD0 - 8B 43 1C      - mov eax,[rbx+1C]
	*/

	WriteAddress((appBaseAddr + 0x23918A), (enable) ? (appBaseAddr + 0x23918C) : (appBaseAddr + 0x2391A4), 2);
	/*
	dmc3.exe+23918A - 75 18    - jne dmc3.exe+2391A4
	dmc3.exe+23918C - 8B 43 1C - mov eax,[rbx+1C]
	*/
}

#ifdef __GARBAGE__
#endif
