#pragma once
#include "../../Core/Core.h"

#include "../Config.h"
#include "../Vars.h"

#include "Cache.h"

extern bool System_Actor_enableArrayExtension;
extern bool System_Actor_enableCreateActor;
extern bool System_Actor_enableUpdateActor;
extern bool System_Actor_enableDoppelgangerFixes;

extern byte * actorBaseAddr[MAX_ACTOR];
extern bool updateModelAttributes[MAX_ACTOR];

typedef void(* UpdateDevilForm_t)(byte *       );
typedef void(* UpdateFlux_t     )(byte *, uint8);
typedef void(* Relax_t          )(byte *       );

extern UpdateDevilForm_t UpdateDevilForm;
extern UpdateFlux_t      UpdateFlux;
extern Relax_t           Relax;

uint8 GetActorId(byte * baseAddr);
uint8 GetActorCount();
void ResetDevilModel();
void UpdateDevilModel(uint8 model);
void System_Actor_Init();
void System_Actor_ToggleArrayExtension(bool enable);
void System_Actor_ToggleCreateActor(bool enable);
void System_Actor_ToggleUpdateActor(bool enable);
void System_Actor_ToggleDoppelgangerFixes(bool enable);
