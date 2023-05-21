// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonActor.h"
#include "Components/BoxComponent.h"

// Sets default values
AButtonActor::AButtonActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ButtonMesh"));
	ButtonMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AButtonActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AButtonActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AButtonActor::Pressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Interacted with Button"));

	ButtonMesh->SetMaterial(0,ActivatedMaterial);

	if (Door)
	{
		Door->ToggleDoor();
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("No Linked Door"));
	}

	if (LinkedTurrets.Num() != 0)
	{
		for (ATurretActor* Turret : LinkedTurrets)
		{
			Turret->SetActorTickEnabled(false);
			GetWorldTimerManager().ClearAllTimersForObject(Turret);
		}
	}
}


