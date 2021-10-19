// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

#include "TurtleButton.h"

#include "RaceButton.generated.h"

// ����� ������ �� ���� � �������, ������ ������ ����� �������� ����� ���������

UCLASS()
class FNTASTIC_26_API ARaceButton : public AActor, public IInteraction
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARaceButton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		// ������ �������� ��������� � ������������ �������� (�� �������)
		void RaceStart();

	// IInteraction - ������� ���������� ��� �������������� � ����������

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		bool Interact(AFntastic_26Character* Character);
	virtual bool Interact_Implementation(AFntastic_26Character* Character) override;

	// PROPERTIES

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		// ������ ������ (�����)
		UStaticMeshComponent* Sphere;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		// ������ ������, ������� ��������� ��� ������
		TArray<ATurtleButton*> Buttons;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		// �������� �������� (��� ������������ ��������)
		float RunDelay;

	// ����� ������ � �������� ���������
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects|Sound")
		USoundWave* SpawnSound;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects|Sound")
		USoundWave* RaceSound;

};
