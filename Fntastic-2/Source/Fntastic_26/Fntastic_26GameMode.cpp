// Copyright Epic Games, Inc. All Rights Reserved.

#include "Fntastic_26GameMode.h"
#include "Fntastic_26HUD.h"
#include "Fntastic_26Character.h"
#include "UObject/ConstructorHelpers.h"

AFntastic_26GameMode::AFntastic_26GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFntastic_26HUD::StaticClass();
}
