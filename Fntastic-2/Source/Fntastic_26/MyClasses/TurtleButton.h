// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

#include "Nest.h"
#include "TurtleController.h"
#include "Interaction.h"
#include "Turtle.h"

#include "TurtleButton.generated.h"

UCLASS()
class FNTASTIC_26_API ATurtleButton : public AActor, public IInteraction
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurtleButton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		// ������� ��������� � ������ � ������������� � ������� ������
		void SpawnTurtleAndRace(bool Race);

	UFUNCTION(BlueprintCallable)
		// ����������� ��� ������������ ������� ������
		void TurtleFinished();

	UFUNCTION(BlueprintCallable)
		// ������ �������� ��������� �� ������� (����� ������������ ��������)
		void RaceStart();

	// IInteraction

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		/** Called when player interacts object, that extended with this interface */
		bool Interact(AFntastic_26Character* Character);
	virtual bool Interact_Implementation(AFntastic_26Character* Character) override;


	// Properties

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		// ������ ������, ��� ���� �������� ��������
		ANest* Nest;

	UPROPERTY(BlueprintReadWrite)
		// ���� ������ �� ������, ����� ������������� ��������� �������
		bool bButtonPressed;

	UPROPERTY(BlueprintReadWrite)
		// ���������� ���������, ����� ��������� � ��������
		ATurtleController* TurtleController;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		// ������ ������ (�����)
		UStaticMeshComponent* Sphere;

	// ����� ��� ������ � ��������
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Effects|Sound")
		USoundWave* SpawnSound;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects|Sound")
		USoundWave* RaceSound;

	// �������� �������� �� ������
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float RunDelay;



};
