// Fill out your copyright notice in the Description page of Project Settings.


#include "TurtleControllerWaiting.h"

ATurtleControllerWaiting::ATurtleControllerWaiting() : Super() {

}

void ATurtleControllerWaiting::Tick(float DeltaTime) {
	if (bRaceStarted) {
		if (bMoving) {
			MoveForward(DeltaTime);
			CalcTimer(DeltaTime, 1.0f);
		}
		else {
			CalcTimer(DeltaTime, 0.5f);
		}
	}
}

void ATurtleControllerWaiting::CalcTimer(float DeltaTime, float TargetTime)
{
	Timer += DeltaTime;
	if (Timer >= TargetTime) {
		bMoving = !bMoving;
		Timer = 0.0f;
	}
}

