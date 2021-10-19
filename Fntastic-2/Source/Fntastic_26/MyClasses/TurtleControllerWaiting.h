// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurtleController.h"
#include "TurtleControllerWaiting.generated.h"

/**
 * 
 */
UCLASS()
class FNTASTIC_26_API ATurtleControllerWaiting : public ATurtleController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATurtleControllerWaiting();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		// Функция для инкрементирования и проверки таймера
		void CalcTimer(float DeltaTime, float TargetTime);

	// PROPERTIES

	UPROPERTY(BlueprintReadWrite)
		// Флаг двигается ли черепашка или ждёт
		bool bMoving = true;

	UPROPERTY(BlueprintReadWrite)
		float Timer;
	
};
