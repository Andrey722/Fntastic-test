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
		// ������� ��������� � ����������� ������� ��� � ���������
		ATurtleController* SpawnTurtle();

	UFUNCTION(BlueprintCallable)
		// ����������� ������ �������� (����� ��������� �������� ���������)
		void StopSpawnVisual();

	// PROPERTIES

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		// ����� ���������, ������� ����� ���������� � ���� ������
		TSubclassOf<ATurtle> TurtleClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		// ������ ������, � �������� ������ ���� ���������
		AFinishTrigger* FinishLine;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		// �������� ������ (������ �����)
		UStaticMeshComponent* Plane;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		// ������� ������, ������� ���������� ��� ��������� ���������
		UParticleSystemComponent* Sparks;

};
