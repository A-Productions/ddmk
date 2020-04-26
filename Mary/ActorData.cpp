#include "ActorData.h"

static_assert(offsetof(ACTOR_DATA, init) == 0x8);
static_assert(offsetof(ACTOR_DATA, character) == 0x78);
static_assert(offsetof(ACTOR_DATA, position) == 0x80);
static_assert(offsetof(ACTOR_DATA, direction) == 0xC0);
static_assert(offsetof(ACTOR_DATA, id) == 0x118);
static_assert(offsetof(ACTOR_DATA, isClone) == 0x11C);
static_assert(offsetof(ACTOR_DATA, visible) == 0x120);
static_assert(offsetof(ACTOR_DATA, modelData) == 0x200);
static_assert(offsetof(ACTOR_DATA, motionArchive) == 0x38A0);
static_assert(offsetof(ACTOR_DATA, motionData) == 0x39B0);
static_assert(offsetof(ACTOR_DATA, motionDataMirror) == 0x39B4);
static_assert(offsetof(ACTOR_DATA, motionState1) == 0x39D0);
static_assert(offsetof(ACTOR_DATA, shadow) == 0x3A18);
static_assert(offsetof(ACTOR_DATA, color) == 0x3A28);
static_assert(offsetof(ACTOR_DATA, actionData) == 0x3DD0);
static_assert(offsetof(ACTOR_DATA, motionState2) == 0x3E00);
static_assert(offsetof(ACTOR_DATA, motionTimer) == 0x3E34);
static_assert(offsetof(ACTOR_DATA, idleTimer) == 0x3E38);
static_assert(offsetof(ACTOR_DATA, motionState3) == 0x3E60);
static_assert(offsetof(ACTOR_DATA, activeModelIndex) == 0x3E6C);
static_assert(offsetof(ACTOR_DATA, queuedModelIndex) == 0x3E70);
static_assert(offsetof(ACTOR_DATA, modelMap) == 0x3E74);
static_assert(offsetof(ACTOR_DATA, modelState) == 0x3E80);
static_assert(offsetof(ACTOR_DATA, lockOn) == 0x3E84);
static_assert(offsetof(ACTOR_DATA, activeModelIndexMirror) == 0x3E88);
static_assert(offsetof(ACTOR_DATA, activeDevilModel) == 0x3E8C);
static_assert(offsetof(ACTOR_DATA, airRaid) == 0x3E90);
static_assert(offsetof(ACTOR_DATA, devilState) == 0x3E94);
static_assert(offsetof(ACTOR_DATA, devil) == 0x3E9B);
static_assert(offsetof(ACTOR_DATA, costume) == 0x3E9E);
static_assert(offsetof(ACTOR_DATA, sparda) == 0x3E9F);
static_assert(offsetof(ACTOR_DATA, useHolyWater) == 0x3EA4);
static_assert(offsetof(ACTOR_DATA, magicPoints) == 0x3EB8);
static_assert(offsetof(ACTOR_DATA, maxMagicPoints) == 0x3EBC);
static_assert(offsetof(ACTOR_DATA, cameraDirection) == 0x3ED8);
static_assert(offsetof(ACTOR_DATA, moveOnly) == 0x3F19);
static_assert(offsetof(ACTOR_DATA, move) == 0x3FA4);
static_assert(offsetof(ACTOR_DATA, lastMove) == 0x3FA5);
static_assert(offsetof(ACTOR_DATA, chainCount) == 0x3FAC);
static_assert(offsetof(ACTOR_DATA, expertise) == 0x3FEC);
static_assert(offsetof(ACTOR_DATA, maxHitPoints) == 0x40EC);
static_assert(offsetof(ACTOR_DATA, hitPoints) == 0x411C);
static_assert(offsetof(ACTOR_DATA, targetBaseAddr) == 0x6328);
static_assert(offsetof(ACTOR_DATA, style) == 0x6338);
static_assert(offsetof(ACTOR_DATA, styleLevel) == 0x6358);
static_assert(offsetof(ACTOR_DATA, styleExperience) == 0x6364);
static_assert(offsetof(ACTOR_DATA, styleRank) == 0x6510);
static_assert(offsetof(ACTOR_DATA, styleMeter) == 0x6514);
static_assert(offsetof(ACTOR_DATA, inputData) == 0x6674);
static_assert(offsetof(ACTOR_DATA, collisionIndex) == 0x7254);
static_assert(offsetof(ACTOR_DATA, interactionData) == 0x7460);
static_assert(offsetof(ACTOR_DATA, buttons) == 0x74E0);
static_assert(offsetof(ACTOR_DATA, rightStick) == 0x74F8);
static_assert(offsetof(ACTOR_DATA, leftStickPosition) == 0x7508);
static_assert(offsetof(ACTOR_DATA, leftStickRadius) == 0x750A);
static_assert(offsetof(ACTOR_DATA, actorCameraDirection) == 0x750C);
static_assert(offsetof(ACTOR_DATA, leftStickDirection) == 0x751C);
static_assert(offsetof(ACTOR_DATA, newCharacterModel) == 0xB8C0);
static_assert(offsetof(ACTOR_DATA, newParentBaseAddr) == 0xB8C8);
static_assert(offsetof(ACTOR_DATA, newChildBaseAddr) == 0xB8D0);
static_assert(offsetof(ACTOR_DATA, newGamepad) == 0xB8F0);
static_assert(offsetof(ACTOR_DATA, newButtonMask) == 0xB8F1);
static_assert(offsetof(ACTOR_DATA, newCopyPosition) == 0xB8F3);
static_assert(offsetof(ACTOR_DATA, newStyle) == 0xB8F4);
static_assert(offsetof(ACTOR_DATA, newStyleMap) == 0xB8F8);
static_assert(offsetof(ACTOR_DATA, newMeleeWeaponMap) == 0xB904);
static_assert(offsetof(ACTOR_DATA, newMeleeWeaponData) == 0xB910);
static_assert(offsetof(ACTOR_DATA, newMeleeWeaponCount) == 0xB938);
static_assert(offsetof(ACTOR_DATA, newMeleeWeaponIndex) == 0xB939);
static_assert(offsetof(ACTOR_DATA, newRangedWeaponMap) == 0xB93C);
static_assert(offsetof(ACTOR_DATA, newRangedWeaponData) == 0xB948);
static_assert(offsetof(ACTOR_DATA, newRangedWeaponCount) == 0xB970);
static_assert(offsetof(ACTOR_DATA, newRangedWeaponIndex) == 0xB971);

static_assert(offsetof(ACTOR_DATA_DANTE, init) == 0x8);
static_assert(offsetof(ACTOR_DATA_DANTE, character) == 0x78);
static_assert(offsetof(ACTOR_DATA_DANTE, position) == 0x80);
static_assert(offsetof(ACTOR_DATA_DANTE, direction) == 0xC0);
static_assert(offsetof(ACTOR_DATA_DANTE, id) == 0x118);
static_assert(offsetof(ACTOR_DATA_DANTE, isClone) == 0x11C);
static_assert(offsetof(ACTOR_DATA_DANTE, visible) == 0x120);
static_assert(offsetof(ACTOR_DATA_DANTE, modelData) == 0x200);
static_assert(offsetof(ACTOR_DATA_DANTE, motionArchive) == 0x38A0);
static_assert(offsetof(ACTOR_DATA_DANTE, motionData) == 0x39B0);
static_assert(offsetof(ACTOR_DATA_DANTE, motionDataMirror) == 0x39B4);
static_assert(offsetof(ACTOR_DATA_DANTE, motionState1) == 0x39D0);
static_assert(offsetof(ACTOR_DATA_DANTE, shadow) == 0x3A18);
static_assert(offsetof(ACTOR_DATA_DANTE, color) == 0x3A28);
static_assert(offsetof(ACTOR_DATA_DANTE, actionData) == 0x3DD0);
static_assert(offsetof(ACTOR_DATA_DANTE, motionState2) == 0x3E00);
static_assert(offsetof(ACTOR_DATA_DANTE, chargedShotAir) == 0x3E1A);
static_assert(offsetof(ACTOR_DATA_DANTE, chargedShot) == 0x3E22);
static_assert(offsetof(ACTOR_DATA_DANTE, motionTimer) == 0x3E34);
static_assert(offsetof(ACTOR_DATA_DANTE, idleTimer) == 0x3E38);
static_assert(offsetof(ACTOR_DATA_DANTE, motionState3) == 0x3E60);
static_assert(offsetof(ACTOR_DATA_DANTE, activeModelIndex) == 0x3E6C);
static_assert(offsetof(ACTOR_DATA_DANTE, queuedModelIndex) == 0x3E70);
static_assert(offsetof(ACTOR_DATA_DANTE, modelMap) == 0x3E74);
static_assert(offsetof(ACTOR_DATA_DANTE, modelState) == 0x3E80);
static_assert(offsetof(ACTOR_DATA_DANTE, lockOn) == 0x3E84);
static_assert(offsetof(ACTOR_DATA_DANTE, activeModelIndexMirror) == 0x3E88);
static_assert(offsetof(ACTOR_DATA_DANTE, activeDevilModel) == 0x3E8C);
static_assert(offsetof(ACTOR_DATA_DANTE, airRaid) == 0x3E90);
static_assert(offsetof(ACTOR_DATA_DANTE, devilState) == 0x3E94);
static_assert(offsetof(ACTOR_DATA_DANTE, devil) == 0x3E9B);
static_assert(offsetof(ACTOR_DATA_DANTE, costume) == 0x3E9E);
static_assert(offsetof(ACTOR_DATA_DANTE, sparda) == 0x3E9F);
static_assert(offsetof(ACTOR_DATA_DANTE, useHolyWater) == 0x3EA4);
static_assert(offsetof(ACTOR_DATA_DANTE, magicPoints) == 0x3EB8);
static_assert(offsetof(ACTOR_DATA_DANTE, maxMagicPoints) == 0x3EBC);
static_assert(offsetof(ACTOR_DATA_DANTE, cameraDirection) == 0x3ED8);
static_assert(offsetof(ACTOR_DATA_DANTE, moveOnly) == 0x3F19);
static_assert(offsetof(ACTOR_DATA_DANTE, move) == 0x3FA4);
static_assert(offsetof(ACTOR_DATA_DANTE, lastMove) == 0x3FA5);
static_assert(offsetof(ACTOR_DATA_DANTE, chainCount) == 0x3FAC);
static_assert(offsetof(ACTOR_DATA_DANTE, expertise) == 0x3FEC);
static_assert(offsetof(ACTOR_DATA_DANTE, maxHitPoints) == 0x40EC);
static_assert(offsetof(ACTOR_DATA_DANTE, hitPoints) == 0x411C);
static_assert(offsetof(ACTOR_DATA_DANTE, targetBaseAddr) == 0x6328);
static_assert(offsetof(ACTOR_DATA_DANTE, style) == 0x6338);
static_assert(offsetof(ACTOR_DATA_DANTE, styleLevel) == 0x6358);
static_assert(offsetof(ACTOR_DATA_DANTE, dashCount) == 0x635C);
static_assert(offsetof(ACTOR_DATA_DANTE, skyStarCount) == 0x635D);
static_assert(offsetof(ACTOR_DATA_DANTE, airTrickCount) == 0x635E);
static_assert(offsetof(ACTOR_DATA_DANTE, quicksilver) == 0x6361);
static_assert(offsetof(ACTOR_DATA_DANTE, doppelganger) == 0x6362);
static_assert(offsetof(ACTOR_DATA_DANTE, styleExperience) == 0x6364);
static_assert(offsetof(ACTOR_DATA_DANTE, cloneIsActive) == 0x6454);
static_assert(offsetof(ACTOR_DATA_DANTE, cloneBaseAddr) == 0x6478);
static_assert(offsetof(ACTOR_DATA_DANTE, cloneIsControlledByPlayer) == 0x6480);
static_assert(offsetof(ACTOR_DATA_DANTE, activeWeapon) == 0x648D);
static_assert(offsetof(ACTOR_DATA_DANTE, meleeWeaponIndex) == 0x6490);
static_assert(offsetof(ACTOR_DATA_DANTE, rangedWeaponIndex) == 0x6494);
static_assert(offsetof(ACTOR_DATA_DANTE, meleeWeaponMap) == 0x6498);
static_assert(offsetof(ACTOR_DATA_DANTE, rangedWeaponMap) == 0x649A);
static_assert(offsetof(ACTOR_DATA_DANTE, meleeWeaponData) == 0x64A0);
static_assert(offsetof(ACTOR_DATA_DANTE, rangedWeaponData) == 0x64B0);
static_assert(offsetof(ACTOR_DATA_DANTE, meleeWeaponFlags) == 0x64C8);
static_assert(offsetof(ACTOR_DATA_DANTE, rangedWeaponFlags) == 0x64D0);
static_assert(offsetof(ACTOR_DATA_DANTE, meleeWeaponLevel) == 0x64DC);
static_assert(offsetof(ACTOR_DATA_DANTE, rangedWeaponLevel) == 0x64E4);
static_assert(offsetof(ACTOR_DATA_DANTE, activeMeleeWeapon) == 0x64F0);
static_assert(offsetof(ACTOR_DATA_DANTE, activeRangedWeapon) == 0x64F1);
static_assert(offsetof(ACTOR_DATA_DANTE, meleeWeaponTimer) == 0x64F4);
static_assert(offsetof(ACTOR_DATA_DANTE, rangedWeaponTimer) == 0x64FC);
static_assert(offsetof(ACTOR_DATA_DANTE, meleeWeaponSwitchTimeout) == 0x6508);
static_assert(offsetof(ACTOR_DATA_DANTE, rangedWeaponSwitchTimeout) == 0x650C);
static_assert(offsetof(ACTOR_DATA_DANTE, styleRank) == 0x6510);
static_assert(offsetof(ACTOR_DATA_DANTE, styleMeter) == 0x6514);
static_assert(offsetof(ACTOR_DATA_DANTE, inputData) == 0x6674);
static_assert(offsetof(ACTOR_DATA_DANTE, collisionIndex) == 0x7254);
static_assert(offsetof(ACTOR_DATA_DANTE, interactionData) == 0x7460);
static_assert(offsetof(ACTOR_DATA_DANTE, buttons) == 0x74E0);
static_assert(offsetof(ACTOR_DATA_DANTE, rightStick) == 0x74F8);
static_assert(offsetof(ACTOR_DATA_DANTE, leftStickPosition) == 0x7508);
static_assert(offsetof(ACTOR_DATA_DANTE, leftStickRadius) == 0x750A);
static_assert(offsetof(ACTOR_DATA_DANTE, actorCameraDirection) == 0x750C);
static_assert(offsetof(ACTOR_DATA_DANTE, leftStickDirection) == 0x751C);
static_assert(offsetof(ACTOR_DATA_DANTE, devilModelMetadata) == 0xB600);
static_assert(offsetof(ACTOR_DATA_DANTE, modelMetadata) == 0xB630);
static_assert(offsetof(ACTOR_DATA_DANTE, artemisChargeValue) == 0xB868);
static_assert(offsetof(ACTOR_DATA_DANTE, artemisChargeFlags) == 0xB87C);
static_assert(offsetof(ACTOR_DATA_DANTE, newCharacterModel) == 0xB8C0);
static_assert(offsetof(ACTOR_DATA_DANTE, newParentBaseAddr) == 0xB8C8);
static_assert(offsetof(ACTOR_DATA_DANTE, newChildBaseAddr) == 0xB8D0);
static_assert(offsetof(ACTOR_DATA_DANTE, newGamepad) == 0xB8F0);
static_assert(offsetof(ACTOR_DATA_DANTE, newButtonMask) == 0xB8F1);
static_assert(offsetof(ACTOR_DATA_DANTE, newCopyPosition) == 0xB8F3);
static_assert(offsetof(ACTOR_DATA_DANTE, newStyle) == 0xB8F4);
static_assert(offsetof(ACTOR_DATA_DANTE, newStyleMap) == 0xB8F8);
static_assert(offsetof(ACTOR_DATA_DANTE, newMeleeWeaponMap) == 0xB904);
static_assert(offsetof(ACTOR_DATA_DANTE, newMeleeWeaponData) == 0xB910);
static_assert(offsetof(ACTOR_DATA_DANTE, newMeleeWeaponCount) == 0xB938);
static_assert(offsetof(ACTOR_DATA_DANTE, newMeleeWeaponIndex) == 0xB939);
static_assert(offsetof(ACTOR_DATA_DANTE, newRangedWeaponMap) == 0xB93C);
static_assert(offsetof(ACTOR_DATA_DANTE, newRangedWeaponData) == 0xB948);
static_assert(offsetof(ACTOR_DATA_DANTE, newRangedWeaponCount) == 0xB970);
static_assert(offsetof(ACTOR_DATA_DANTE, newRangedWeaponIndex) == 0xB971);

static_assert(offsetof(ACTOR_DATA_BOB, init) == 0x8);
static_assert(offsetof(ACTOR_DATA_BOB, character) == 0x78);
static_assert(offsetof(ACTOR_DATA_BOB, position) == 0x80);
static_assert(offsetof(ACTOR_DATA_BOB, direction) == 0xC0);
static_assert(offsetof(ACTOR_DATA_BOB, id) == 0x118);
static_assert(offsetof(ACTOR_DATA_BOB, isClone) == 0x11C);
static_assert(offsetof(ACTOR_DATA_BOB, visible) == 0x120);
static_assert(offsetof(ACTOR_DATA_BOB, modelData) == 0x200);
static_assert(offsetof(ACTOR_DATA_BOB, motionArchive) == 0x38A0);
static_assert(offsetof(ACTOR_DATA_BOB, motionData) == 0x39B0);
static_assert(offsetof(ACTOR_DATA_BOB, motionDataMirror) == 0x39B4);
static_assert(offsetof(ACTOR_DATA_BOB, motionState1) == 0x39D0);
static_assert(offsetof(ACTOR_DATA_BOB, shadow) == 0x3A18);
static_assert(offsetof(ACTOR_DATA_BOB, color) == 0x3A28);
static_assert(offsetof(ACTOR_DATA_BOB, actionData) == 0x3DD0);
static_assert(offsetof(ACTOR_DATA_BOB, motionState2) == 0x3E00);
static_assert(offsetof(ACTOR_DATA_BOB, motionTimer) == 0x3E34);
static_assert(offsetof(ACTOR_DATA_BOB, idleTimer) == 0x3E38);
static_assert(offsetof(ACTOR_DATA_BOB, motionState3) == 0x3E60);
static_assert(offsetof(ACTOR_DATA_BOB, activeModelIndex) == 0x3E6C);
static_assert(offsetof(ACTOR_DATA_BOB, queuedModelIndex) == 0x3E70);
static_assert(offsetof(ACTOR_DATA_BOB, modelMap) == 0x3E74);
static_assert(offsetof(ACTOR_DATA_BOB, modelState) == 0x3E80);
static_assert(offsetof(ACTOR_DATA_BOB, lockOn) == 0x3E84);
static_assert(offsetof(ACTOR_DATA_BOB, activeModelIndexMirror) == 0x3E88);
static_assert(offsetof(ACTOR_DATA_BOB, activeDevilModel) == 0x3E8C);
static_assert(offsetof(ACTOR_DATA_BOB, airRaid) == 0x3E90);
static_assert(offsetof(ACTOR_DATA_BOB, devilState) == 0x3E94);
static_assert(offsetof(ACTOR_DATA_BOB, devil) == 0x3E9B);
static_assert(offsetof(ACTOR_DATA_BOB, costume) == 0x3E9E);
static_assert(offsetof(ACTOR_DATA_BOB, sparda) == 0x3E9F);
static_assert(offsetof(ACTOR_DATA_BOB, useHolyWater) == 0x3EA4);
static_assert(offsetof(ACTOR_DATA_BOB, magicPoints) == 0x3EB8);
static_assert(offsetof(ACTOR_DATA_BOB, maxMagicPoints) == 0x3EBC);
static_assert(offsetof(ACTOR_DATA_BOB, cameraDirection) == 0x3ED8);
static_assert(offsetof(ACTOR_DATA_BOB, moveOnly) == 0x3F19);
static_assert(offsetof(ACTOR_DATA_BOB, move) == 0x3FA4);
static_assert(offsetof(ACTOR_DATA_BOB, lastMove) == 0x3FA5);
static_assert(offsetof(ACTOR_DATA_BOB, chainCount) == 0x3FAC);
static_assert(offsetof(ACTOR_DATA_BOB, expertise) == 0x3FEC);
static_assert(offsetof(ACTOR_DATA_BOB, maxHitPoints) == 0x40EC);
static_assert(offsetof(ACTOR_DATA_BOB, hitPoints) == 0x411C);
static_assert(offsetof(ACTOR_DATA_BOB, targetBaseAddr) == 0x6328);
static_assert(offsetof(ACTOR_DATA_BOB, style) == 0x6338);
static_assert(offsetof(ACTOR_DATA_BOB, styleLevel) == 0x6358);
static_assert(offsetof(ACTOR_DATA_BOB, styleExperience) == 0x6364);
static_assert(offsetof(ACTOR_DATA_BOB, styleRank) == 0x6510);
static_assert(offsetof(ACTOR_DATA_BOB, styleMeter) == 0x6514);
static_assert(offsetof(ACTOR_DATA_BOB, inputData) == 0x6674);
static_assert(offsetof(ACTOR_DATA_BOB, collisionIndex) == 0x7254);
static_assert(offsetof(ACTOR_DATA_BOB, interactionData) == 0x7460);
static_assert(offsetof(ACTOR_DATA_BOB, buttons) == 0x74E0);
static_assert(offsetof(ACTOR_DATA_BOB, rightStick) == 0x74F8);
static_assert(offsetof(ACTOR_DATA_BOB, leftStickPosition) == 0x7508);
static_assert(offsetof(ACTOR_DATA_BOB, leftStickRadius) == 0x750A);
static_assert(offsetof(ACTOR_DATA_BOB, actorCameraDirection) == 0x750C);
static_assert(offsetof(ACTOR_DATA_BOB, leftStickDirection) == 0x751C);
static_assert(offsetof(ACTOR_DATA_BOB, newCharacterModel) == 0xB8C0);
static_assert(offsetof(ACTOR_DATA_BOB, newParentBaseAddr) == 0xB8C8);
static_assert(offsetof(ACTOR_DATA_BOB, newChildBaseAddr) == 0xB8D0);
static_assert(offsetof(ACTOR_DATA_BOB, newGamepad) == 0xB8F0);
static_assert(offsetof(ACTOR_DATA_BOB, newButtonMask) == 0xB8F1);
static_assert(offsetof(ACTOR_DATA_BOB, newCopyPosition) == 0xB8F3);
static_assert(offsetof(ACTOR_DATA_BOB, newStyle) == 0xB8F4);
static_assert(offsetof(ACTOR_DATA_BOB, newStyleMap) == 0xB8F8);
static_assert(offsetof(ACTOR_DATA_BOB, newMeleeWeaponMap) == 0xB904);
static_assert(offsetof(ACTOR_DATA_BOB, newMeleeWeaponData) == 0xB910);
static_assert(offsetof(ACTOR_DATA_BOB, newMeleeWeaponCount) == 0xB938);
static_assert(offsetof(ACTOR_DATA_BOB, newMeleeWeaponIndex) == 0xB939);
static_assert(offsetof(ACTOR_DATA_BOB, newRangedWeaponMap) == 0xB93C);
static_assert(offsetof(ACTOR_DATA_BOB, newRangedWeaponData) == 0xB948);
static_assert(offsetof(ACTOR_DATA_BOB, newRangedWeaponCount) == 0xB970);
static_assert(offsetof(ACTOR_DATA_BOB, newRangedWeaponIndex) == 0xB971);

static_assert(offsetof(ACTOR_DATA_LADY, init) == 0x8);
static_assert(offsetof(ACTOR_DATA_LADY, character) == 0x78);
static_assert(offsetof(ACTOR_DATA_LADY, position) == 0x80);
static_assert(offsetof(ACTOR_DATA_LADY, direction) == 0xC0);
static_assert(offsetof(ACTOR_DATA_LADY, id) == 0x118);
static_assert(offsetof(ACTOR_DATA_LADY, isClone) == 0x11C);
static_assert(offsetof(ACTOR_DATA_LADY, visible) == 0x120);
static_assert(offsetof(ACTOR_DATA_LADY, modelData) == 0x200);
static_assert(offsetof(ACTOR_DATA_LADY, motionArchive) == 0x38A0);
static_assert(offsetof(ACTOR_DATA_LADY, motionData) == 0x39B0);
static_assert(offsetof(ACTOR_DATA_LADY, motionDataMirror) == 0x39B4);
static_assert(offsetof(ACTOR_DATA_LADY, motionState1) == 0x39D0);
static_assert(offsetof(ACTOR_DATA_LADY, shadow) == 0x3A18);
static_assert(offsetof(ACTOR_DATA_LADY, color) == 0x3A28);
static_assert(offsetof(ACTOR_DATA_LADY, actionData) == 0x3DD0);
static_assert(offsetof(ACTOR_DATA_LADY, motionState2) == 0x3E00);
static_assert(offsetof(ACTOR_DATA_LADY, motionTimer) == 0x3E34);
static_assert(offsetof(ACTOR_DATA_LADY, idleTimer) == 0x3E38);
static_assert(offsetof(ACTOR_DATA_LADY, motionState3) == 0x3E60);
static_assert(offsetof(ACTOR_DATA_LADY, activeModelIndex) == 0x3E6C);
static_assert(offsetof(ACTOR_DATA_LADY, queuedModelIndex) == 0x3E70);
static_assert(offsetof(ACTOR_DATA_LADY, modelMap) == 0x3E74);
static_assert(offsetof(ACTOR_DATA_LADY, modelState) == 0x3E80);
static_assert(offsetof(ACTOR_DATA_LADY, lockOn) == 0x3E84);
static_assert(offsetof(ACTOR_DATA_LADY, activeModelIndexMirror) == 0x3E88);
static_assert(offsetof(ACTOR_DATA_LADY, activeDevilModel) == 0x3E8C);
static_assert(offsetof(ACTOR_DATA_LADY, airRaid) == 0x3E90);
static_assert(offsetof(ACTOR_DATA_LADY, devilState) == 0x3E94);
static_assert(offsetof(ACTOR_DATA_LADY, devil) == 0x3E9B);
static_assert(offsetof(ACTOR_DATA_LADY, costume) == 0x3E9E);
static_assert(offsetof(ACTOR_DATA_LADY, sparda) == 0x3E9F);
static_assert(offsetof(ACTOR_DATA_LADY, useHolyWater) == 0x3EA4);
static_assert(offsetof(ACTOR_DATA_LADY, magicPoints) == 0x3EB8);
static_assert(offsetof(ACTOR_DATA_LADY, maxMagicPoints) == 0x3EBC);
static_assert(offsetof(ACTOR_DATA_LADY, cameraDirection) == 0x3ED8);
static_assert(offsetof(ACTOR_DATA_LADY, moveOnly) == 0x3F19);
static_assert(offsetof(ACTOR_DATA_LADY, move) == 0x3FA4);
static_assert(offsetof(ACTOR_DATA_LADY, lastMove) == 0x3FA5);
static_assert(offsetof(ACTOR_DATA_LADY, chainCount) == 0x3FAC);
static_assert(offsetof(ACTOR_DATA_LADY, expertise) == 0x3FEC);
static_assert(offsetof(ACTOR_DATA_LADY, maxHitPoints) == 0x40EC);
static_assert(offsetof(ACTOR_DATA_LADY, hitPoints) == 0x411C);
static_assert(offsetof(ACTOR_DATA_LADY, targetBaseAddr) == 0x6328);
static_assert(offsetof(ACTOR_DATA_LADY, style) == 0x6338);
static_assert(offsetof(ACTOR_DATA_LADY, styleLevel) == 0x6358);
static_assert(offsetof(ACTOR_DATA_LADY, styleExperience) == 0x6364);
static_assert(offsetof(ACTOR_DATA_LADY, styleRank) == 0x6510);
static_assert(offsetof(ACTOR_DATA_LADY, styleMeter) == 0x6514);
static_assert(offsetof(ACTOR_DATA_LADY, inputData) == 0x6674);
static_assert(offsetof(ACTOR_DATA_LADY, collisionIndex) == 0x7254);
static_assert(offsetof(ACTOR_DATA_LADY, interactionData) == 0x7460);
static_assert(offsetof(ACTOR_DATA_LADY, buttons) == 0x74E0);
static_assert(offsetof(ACTOR_DATA_LADY, rightStick) == 0x74F8);
static_assert(offsetof(ACTOR_DATA_LADY, leftStickPosition) == 0x7508);
static_assert(offsetof(ACTOR_DATA_LADY, leftStickRadius) == 0x750A);
static_assert(offsetof(ACTOR_DATA_LADY, actorCameraDirection) == 0x750C);
static_assert(offsetof(ACTOR_DATA_LADY, leftStickDirection) == 0x751C);
static_assert(offsetof(ACTOR_DATA_LADY, newCharacterModel) == 0xB8C0);
static_assert(offsetof(ACTOR_DATA_LADY, newParentBaseAddr) == 0xB8C8);
static_assert(offsetof(ACTOR_DATA_LADY, newChildBaseAddr) == 0xB8D0);
static_assert(offsetof(ACTOR_DATA_LADY, newGamepad) == 0xB8F0);
static_assert(offsetof(ACTOR_DATA_LADY, newButtonMask) == 0xB8F1);
static_assert(offsetof(ACTOR_DATA_LADY, newCopyPosition) == 0xB8F3);
static_assert(offsetof(ACTOR_DATA_LADY, newStyle) == 0xB8F4);
static_assert(offsetof(ACTOR_DATA_LADY, newStyleMap) == 0xB8F8);
static_assert(offsetof(ACTOR_DATA_LADY, newMeleeWeaponMap) == 0xB904);
static_assert(offsetof(ACTOR_DATA_LADY, newMeleeWeaponData) == 0xB910);
static_assert(offsetof(ACTOR_DATA_LADY, newMeleeWeaponCount) == 0xB938);
static_assert(offsetof(ACTOR_DATA_LADY, newMeleeWeaponIndex) == 0xB939);
static_assert(offsetof(ACTOR_DATA_LADY, newRangedWeaponMap) == 0xB93C);
static_assert(offsetof(ACTOR_DATA_LADY, newRangedWeaponData) == 0xB948);
static_assert(offsetof(ACTOR_DATA_LADY, newRangedWeaponCount) == 0xB970);
static_assert(offsetof(ACTOR_DATA_LADY, newRangedWeaponIndex) == 0xB971);

static_assert(offsetof(ACTOR_DATA_VERGIL, init) == 0x8);
static_assert(offsetof(ACTOR_DATA_VERGIL, character) == 0x78);
static_assert(offsetof(ACTOR_DATA_VERGIL, position) == 0x80);
static_assert(offsetof(ACTOR_DATA_VERGIL, direction) == 0xC0);
static_assert(offsetof(ACTOR_DATA_VERGIL, id) == 0x118);
static_assert(offsetof(ACTOR_DATA_VERGIL, isClone) == 0x11C);
static_assert(offsetof(ACTOR_DATA_VERGIL, visible) == 0x120);
static_assert(offsetof(ACTOR_DATA_VERGIL, modelData) == 0x200);
static_assert(offsetof(ACTOR_DATA_VERGIL, motionArchive) == 0x38A0);
static_assert(offsetof(ACTOR_DATA_VERGIL, motionData) == 0x39B0);
static_assert(offsetof(ACTOR_DATA_VERGIL, motionDataMirror) == 0x39B4);
static_assert(offsetof(ACTOR_DATA_VERGIL, motionState1) == 0x39D0);
static_assert(offsetof(ACTOR_DATA_VERGIL, shadow) == 0x3A18);
static_assert(offsetof(ACTOR_DATA_VERGIL, color) == 0x3A28);
static_assert(offsetof(ACTOR_DATA_VERGIL, actionData) == 0x3DD0);
static_assert(offsetof(ACTOR_DATA_VERGIL, motionState2) == 0x3E00);
static_assert(offsetof(ACTOR_DATA_VERGIL, motionTimer) == 0x3E34);
static_assert(offsetof(ACTOR_DATA_VERGIL, idleTimer) == 0x3E38);
static_assert(offsetof(ACTOR_DATA_VERGIL, motionState3) == 0x3E60);
static_assert(offsetof(ACTOR_DATA_VERGIL, activeModelIndex) == 0x3E6C);
static_assert(offsetof(ACTOR_DATA_VERGIL, queuedModelIndex) == 0x3E70);
static_assert(offsetof(ACTOR_DATA_VERGIL, modelMap) == 0x3E74);
static_assert(offsetof(ACTOR_DATA_VERGIL, modelState) == 0x3E80);
static_assert(offsetof(ACTOR_DATA_VERGIL, lockOn) == 0x3E84);
static_assert(offsetof(ACTOR_DATA_VERGIL, activeModelIndexMirror) == 0x3E88);
static_assert(offsetof(ACTOR_DATA_VERGIL, activeDevilModel) == 0x3E8C);
static_assert(offsetof(ACTOR_DATA_VERGIL, airRaid) == 0x3E90);
static_assert(offsetof(ACTOR_DATA_VERGIL, devilState) == 0x3E94);
static_assert(offsetof(ACTOR_DATA_VERGIL, devil) == 0x3E9B);
static_assert(offsetof(ACTOR_DATA_VERGIL, costume) == 0x3E9E);
static_assert(offsetof(ACTOR_DATA_VERGIL, sparda) == 0x3E9F);
static_assert(offsetof(ACTOR_DATA_VERGIL, useHolyWater) == 0x3EA4);
static_assert(offsetof(ACTOR_DATA_VERGIL, magicPoints) == 0x3EB8);
static_assert(offsetof(ACTOR_DATA_VERGIL, maxMagicPoints) == 0x3EBC);
static_assert(offsetof(ACTOR_DATA_VERGIL, cameraDirection) == 0x3ED8);
static_assert(offsetof(ACTOR_DATA_VERGIL, moveOnly) == 0x3F19);
static_assert(offsetof(ACTOR_DATA_VERGIL, move) == 0x3FA4);
static_assert(offsetof(ACTOR_DATA_VERGIL, lastMove) == 0x3FA5);
static_assert(offsetof(ACTOR_DATA_VERGIL, chainCount) == 0x3FAC);
static_assert(offsetof(ACTOR_DATA_VERGIL, expertise) == 0x3FEC);
static_assert(offsetof(ACTOR_DATA_VERGIL, maxHitPoints) == 0x40EC);
static_assert(offsetof(ACTOR_DATA_VERGIL, hitPoints) == 0x411C);
static_assert(offsetof(ACTOR_DATA_VERGIL, targetBaseAddr) == 0x6328);
static_assert(offsetof(ACTOR_DATA_VERGIL, style) == 0x6338);
static_assert(offsetof(ACTOR_DATA_VERGIL, styleLevel) == 0x6358);
static_assert(offsetof(ACTOR_DATA_VERGIL, airTrickCount) == 0x635E);
static_assert(offsetof(ACTOR_DATA_VERGIL, trickUpCount) == 0x635F);
static_assert(offsetof(ACTOR_DATA_VERGIL, trickDownCount) == 0x6360);
static_assert(offsetof(ACTOR_DATA_VERGIL, styleExperience) == 0x6364);
static_assert(offsetof(ACTOR_DATA_VERGIL, activeMeleeWeaponIndex) == 0x6484);
static_assert(offsetof(ACTOR_DATA_VERGIL, queuedMeleeWeaponIndex) == 0x6488);
static_assert(offsetof(ACTOR_DATA_VERGIL, meleeWeaponMap) == 0x6498);
static_assert(offsetof(ACTOR_DATA_VERGIL, meleeWeaponData) == 0x64A0);
static_assert(offsetof(ACTOR_DATA_VERGIL, meleeWeaponFlags) == 0x64C8);
static_assert(offsetof(ACTOR_DATA_VERGIL, meleeWeaponLevel) == 0x64DC);
static_assert(offsetof(ACTOR_DATA_VERGIL, meleeWeaponTimer) == 0x64F4);
static_assert(offsetof(ACTOR_DATA_VERGIL, meleeWeaponSwitchForwardTimeout) == 0x6508);
static_assert(offsetof(ACTOR_DATA_VERGIL, meleeWeaponSwitchBackwardTimeout) == 0x650C);
static_assert(offsetof(ACTOR_DATA_VERGIL, styleRank) == 0x6510);
static_assert(offsetof(ACTOR_DATA_VERGIL, styleMeter) == 0x6514);
static_assert(offsetof(ACTOR_DATA_VERGIL, inputData) == 0x6674);
static_assert(offsetof(ACTOR_DATA_VERGIL, collisionIndex) == 0x7254);
static_assert(offsetof(ACTOR_DATA_VERGIL, interactionData) == 0x7460);
static_assert(offsetof(ACTOR_DATA_VERGIL, buttons) == 0x74E0);
static_assert(offsetof(ACTOR_DATA_VERGIL, rightStick) == 0x74F8);
static_assert(offsetof(ACTOR_DATA_VERGIL, leftStickPosition) == 0x7508);
static_assert(offsetof(ACTOR_DATA_VERGIL, leftStickRadius) == 0x750A);
static_assert(offsetof(ACTOR_DATA_VERGIL, actorCameraDirection) == 0x750C);
static_assert(offsetof(ACTOR_DATA_VERGIL, leftStickDirection) == 0x751C);
static_assert(offsetof(ACTOR_DATA_VERGIL, modelMetadata) == 0xB640);
static_assert(offsetof(ACTOR_DATA_VERGIL, newCharacterModel) == 0xB8C0);
static_assert(offsetof(ACTOR_DATA_VERGIL, newParentBaseAddr) == 0xB8C8);
static_assert(offsetof(ACTOR_DATA_VERGIL, newChildBaseAddr) == 0xB8D0);
static_assert(offsetof(ACTOR_DATA_VERGIL, newGamepad) == 0xB8F0);
static_assert(offsetof(ACTOR_DATA_VERGIL, newButtonMask) == 0xB8F1);
static_assert(offsetof(ACTOR_DATA_VERGIL, newCopyPosition) == 0xB8F3);
static_assert(offsetof(ACTOR_DATA_VERGIL, newStyle) == 0xB8F4);
static_assert(offsetof(ACTOR_DATA_VERGIL, newStyleMap) == 0xB8F8);
static_assert(offsetof(ACTOR_DATA_VERGIL, newMeleeWeaponMap) == 0xB904);
static_assert(offsetof(ACTOR_DATA_VERGIL, newMeleeWeaponData) == 0xB910);
static_assert(offsetof(ACTOR_DATA_VERGIL, newMeleeWeaponCount) == 0xB938);
static_assert(offsetof(ACTOR_DATA_VERGIL, newMeleeWeaponIndex) == 0xB939);
static_assert(offsetof(ACTOR_DATA_VERGIL, newRangedWeaponMap) == 0xB93C);
static_assert(offsetof(ACTOR_DATA_VERGIL, newRangedWeaponData) == 0xB948);
static_assert(offsetof(ACTOR_DATA_VERGIL, newRangedWeaponCount) == 0xB970);
static_assert(offsetof(ACTOR_DATA_VERGIL, newRangedWeaponIndex) == 0xB971);
