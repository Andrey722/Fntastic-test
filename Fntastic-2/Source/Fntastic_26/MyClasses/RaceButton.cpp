// Fill out your copyright notice in the Description page of Project Settings.


#include "../MyClasses/RaceButton.h"

// Sets default values
ARaceButton::ARaceButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Sphere
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ARaceButton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARaceButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARaceButton::RaceStart() {
	for(ATurtleButton* Button : Buttons) {
		Button->TurtleController->bRaceStarted = true;
	}
	if (RaceSound) {
		UGameplayStatics::PlaySound2D(GetWorld(), RaceSound);
	}
}

bool ARaceButton::Interact_Implementation(AFntastic_26Character* Character)
{
	if (Buttons.Num() > 0) {
		for (ATurtleButton* Button : Buttons) {
			Button->SpawnTurtleAndRace(true);
		}
		if (SpawnSound) {
			UGameplayStatics::PlaySound2D(GetWorld(), SpawnSound);
		}
		FTimerHandle h;
		GetWorld()->GetTimerManager().SetTimer(h, this, &ARaceButton::RaceStart, RunDelay, false);
		return true;
	}
	return false;
}
