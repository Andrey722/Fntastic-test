// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "TimerManager.h"

#include "TurtleController.h"
#include "Turtle.h"
#include "FinishTrigger.h"

#include "Nest.generated.h"

UCLASS()
class FNTASTIC_26_API ANest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		// Спавним черепашку и проигрываем эффекты при её появлении
		ATurtleController* SpawnTurtle();

	UFUNCTION(BlueprintCallable)
		// Заканчиваем работу эффектов (когда черепашка начинает двигаться)
		void StopSpawnVisual();

	// PROPERTIES

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		// Класс черепашки, которую нужно заспавнить в этом гнезде
		TSubclassOf<ATurtle> TurtleClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		// Объект финиша, к которому должна идти черепашка
		AFinishTrigger* FinishLine;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		// Моделька гнезда (просто плейн)
		UStaticMeshComponent* Plane;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		// Система частиц, которая включается при появлении черепашки
		UParticleSystemComponent* Sparks;

};
