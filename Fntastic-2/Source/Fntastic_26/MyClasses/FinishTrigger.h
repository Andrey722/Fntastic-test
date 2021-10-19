// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "Engine/TextRenderActor.h"
#include "Kismet/GameplayStatics.h"

#include "Turtle.h"
#include "TurtleController.h"

#include "FinishTrigger.generated.h"

UCLASS()
class FNTASTIC_26_API AFinishTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFinishTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	// �������� �� ������� ����������� �������� ������
		void BoxTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// PROPERTIES

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		// ����� ������
		UStaticMeshComponent* Plane;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		// �������� ������
		UBoxComponent* BoxCollision;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		// ����� �� �����
		ATextRenderActor* FinishText;

	// ����� � ������� ������
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects|Sound")
		USoundWave* FinishSound;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects|Particle")
		UParticleSystem* FinishParticle;

};
