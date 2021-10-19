// Fill out your copyright notice in the Description page of Project Settings.


#include "../MyClasses/FinishTrigger.h"

// Sets default values
AFinishTrigger::AFinishTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Plane
	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plane"));
	Plane->SetupAttachment(RootComponent);

	// Create Box Collision
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	BoxCollision->SetupAttachment(RootComponent);
	BoxCollision->SetGenerateOverlapEvents(true);
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AFinishTrigger::BoxTriggerBeginOverlap);

}

// Called when the game starts or when spawned
void AFinishTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFinishTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFinishTrigger::BoxTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ATurtle* castedTurtle = Cast<ATurtle>(OtherActor);
	if (castedTurtle) {
		ATurtleController* castedTurtleController = Cast<ATurtleController>(castedTurtle->GetController());
		if (castedTurtleController) {
			castedTurtleController->OnFinish();
			FFormatNamedArguments Args;
			Args.Add("s", FText::FromName(castedTurtle->GetFName()));
			FinishText->GetTextRender()->SetText(FText::Format(NSLOCTEXT("TurtleRace", "FinishText", "Turtle {s} has finished!"), Args));
			if (FinishParticle) {
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), FinishParticle, castedTurtle->GetActorLocation(), FRotator::ZeroRotator, FVector(2.0f, 2.0f, 2.0f));
			}
			GetWorld()->DestroyActor(castedTurtle);
			if (FinishSound) {
				UGameplayStatics::PlaySound2D(GetWorld(), FinishSound);
			}
		}
	}
}

