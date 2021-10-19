// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurtleController.h"
#include "TurtleControllerBacking.generated.h"

/**
 * 
 */
UCLASS()
class FNTASTIC_26_API ATurtleControllerBacking : public ATurtleController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATurtleControllerBacking();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		// ������� ��� ����������������� � �������� �������
		void CalcTimer(float DeltaTime, float TargetTime);

	// PROPERTIES

	UPROPERTY(BlueprintReadWrite)
		// ���� ��������� �� ��������� ����� ��� �����
		bool bMovingForward = true;

	UPROPERTY(BlueprintReadWrite)
		float Timer;
	
};
