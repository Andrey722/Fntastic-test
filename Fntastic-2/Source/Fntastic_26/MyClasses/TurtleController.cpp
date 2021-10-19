// Fill out your copyright notice in the Description page of Project Settings.


#include "../MyClasses/TurtleController.h"

ATurtleController::ATurtleController() : Super() {
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ATurtleController::BeginPlay() {
	Super::BeginPlay();
}

void ATurtleController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (bRaceStarted) {
		MoveForward(DeltaTime);
	}
}

void ATurtleController::MoveForward(float DeltaTime) {
	GetPawn()->SetActorLocation(GetPawn()->GetActorLocation() + GetPawn()->GetActorForwardVector() * DeltaTime * Speed);
}

void ATurtleController::OnFinish() {
	OnTurtleFinished.Broadcast();
}