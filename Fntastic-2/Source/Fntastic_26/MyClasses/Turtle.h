// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"

#include "Turtle.generated.h"

UCLASS()
class FNTASTIC_26_API ATurtle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATurtle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// PORPERTIES

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		// Моделька черепашки
		UStaticMeshComponent* Mesh;

};
