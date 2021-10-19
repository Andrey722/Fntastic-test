// Fill out your copyright notice in the Description page of Project Settings.


#include "../MyClasses/TurtleButton.h"

// Sets default values
ATurtleButton::ATurtleButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Sphere
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ATurtleButton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurtleButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATurtleButton::SpawnTurtleAndRace(bool Race) {
	if (!bButtonPressed) {
		TurtleController = Nest->SpawnTurtle();
		TurtleController->OnTurtleFinished.AddDynamic(this, &ATurtleButton::TurtleFinished);
		bButtonPressed = true;
		Sphere->AddLocalOffset(FVector(0.0f, 0.0f, -5.0f));
		if (!Race) {
			if (SpawnSound) {
				UGameplayStatics::PlaySound2D(GetWorld(), SpawnSound);
			}
			FTimerHandle h;
			GetWorld()->GetTimerManager().SetTimer(h, this, &ATurtleButton::RaceStart, RunDelay, false);
		}
	}
}

void ATurtleButton::TurtleFinished() {
	TurtleController->OnTurtleFinished.RemoveDynamic(this, &ATurtleButton::TurtleFinished);
	TurtleController = NULL;
	bButtonPressed = false;
	Sphere->AddLocalOffset(FVector(0.0f, 0.0f, 5.0f));
}

void ATurtleButton::RaceStart() {
	TurtleController->bRaceStarted = true;
	ATurtle* castedTurtle = Cast<ATurtle>(TurtleController->GetPawn());
	if (castedTurtle) {
		if (RaceSound) {
			UGameplayStatics::SpawnSoundAttached(RaceSound, castedTurtle->Mesh, FName(), ((FVector)(ForceInit)), EAttachLocation::KeepRelativeOffset, true);
		}
	}
}

bool ATurtleButton::Interact_Implementation(AFntastic_26Character* Character)
{
	SpawnTurtleAndRace(false);
	return true;
}

