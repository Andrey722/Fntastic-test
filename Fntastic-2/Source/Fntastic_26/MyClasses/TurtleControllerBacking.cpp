// Fill out your copyright notice in the Description page of Project Settings.


#include "TurtleControllerBacking.h"

ATurtleControllerBacking::ATurtleControllerBacking() : Super() {

}

void ATurtleControllerBacking::Tick(float DeltaTime) {
	if (bRaceStarted) {
		MoveForward(DeltaTime);
		if (bMovingForward) {
			CalcTimer(DeltaTime, 1.0f);
		}
		else {
			CalcTimer(DeltaTime, 0.5f);
		}
	}
}

void ATurtleControllerBacking::CalcTimer(float DeltaTime, float TargetTime)
{
	Timer += DeltaTime;
	if (Timer >= TargetTime) {
		bMovingForward = !bMovingForward;
		Timer = 0.0f;
		GetPawn()->AddActorWorldRotation(FRotator(0.0f, 180.0f, 0.0f));
	}
}


