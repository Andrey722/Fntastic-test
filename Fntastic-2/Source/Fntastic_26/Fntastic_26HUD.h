// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Fntastic_26HUD.generated.h"

UCLASS()
class AFntastic_26HUD : public AHUD
{
	GENERATED_BODY()

public:
	AFntastic_26HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

