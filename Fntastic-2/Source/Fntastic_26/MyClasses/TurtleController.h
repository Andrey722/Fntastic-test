// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TurtleController.generated.h"

// Dynamic delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTurtleFinishedEvent);

UCLASS()
class FNTASTIC_26_API ATurtleController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATurtleController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		// ������� ��� �������� ��������� � ������� � ��������
		virtual void MoveForward(float DeltaTime);

	UFUNCTION(BlueprintCallable)
		// ����� ������� ������
		void OnFinish();

	// PROPERTIES

	UPROPERTY(BlueprintReadWrite)
		// ���� ����, ��� ��������� ����� ���������
		bool bRaceStarted;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		// �������� �������� ���������
		float Speed;

	// ASSIGNABLE

	UPROPERTY(BlueprintAssignable)
		// ������� ����, ��� ��������� ������������
		FTurtleFinishedEvent OnTurtleFinished;
	
};
