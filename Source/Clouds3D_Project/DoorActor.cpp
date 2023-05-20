// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorActor.h"

// Sets default values
ADoorActor::ADoorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(RootComponent);

	bDoorOpen = false; 

}

// Called when the game starts or when spawned
void ADoorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDoorOpen)
	{	
		FVector Location = GetActorLocation();
		if ((Location.Z + 330.f) < 1) {
			bDoorOpen = false;
		}
		FVector Down = FVector(0.f,0.f,-1.f);
		Location += Down * Speed * DeltaTime;
		SetActorLocation(Location);
	}

}

void ADoorActor::ToggleDoor()
{
	UE_LOG(LogTemp, Error, TEXT("Interacted with door"));

	if (!bDoorOpen) 
	{
		bDoorOpen = true;
	}
}

