#pragma once
#include "../../Core/Core.h"

#include "../System/Actor.h"

void Game_Vergil_Init();
void Game_Vergil_ForceEdge_ToggleInfiniteRoundTrip(bool enable);
void Game_Vergil_SummonedSwords_ToggleChronoSwords(bool enable);
// @Todo: Should be part of Init.
void Game_Vergil_WeaponSwitchTimeout_MeleeToggle(float32 var);
