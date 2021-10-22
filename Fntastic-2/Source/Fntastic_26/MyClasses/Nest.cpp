// Fill out your copyright notice in the Description page of Project Settings.


#include "../MyClasses/Nest.h"
#include "TimerManager.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ANest::ANest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Plane
	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plane"));
	Plane->SetupAttachment(RootComponent);

	// Create Particle component
	Sparks = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Sparks"));
	Sparks->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ANest::BeginPlay()
{
	Super::BeginPlay();
	
	StopSpawnVisual();
}

// Called every frame
void ANest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Не выдаёт контроллер - перенёс в блупринты
//ATurtleController* ANest::SpawnTurtle() {
//	if (TurtleClass) {
//		FTransform Transform;
//		Transform.SetLocation(GetActorLocation());
//		Transform.SetRotation(GetActorTransform().GetRotation());
//		ATurtle* turtle = GetWorld()->SpawnActorDeferred<ATurtle>(TurtleClass, Transform);
//		// turtle = (ATurtle*)UGameplayStatics::FinishSpawningActor(turtle, Transform);
//		Sparks->BeginTrails(FName(), FName(), ETrailWidthMode::ETrailWidthMode_FromCentre, 0.0f);
//		FTimerHandle h;
//		GetWorld()->GetTimerManager().SetTimer(h, this, &ANest::StopSpawnVisual, 4.0f, false);
//		ATurtleController* castedController = Cast<ATurtleController>(turtle->GetController());
//		FinishLine->OnTurtleSpawned(castedController);
//		turtle->SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), FinishLine->GetActorLocation()));
//		return castedController;
//	}
//
//	return NULL;
//}

void ANest::StopSpawnVisual() {
	Sparks->EndTrails();
}
