// Fill out your copyright notice in the Description page of Project Settings.


#include "GodModeButtonActor.h"

// Sets default values
AGodModeButtonActor::AGodModeButtonActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ButtonMesh"));
	ButtonMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGodModeButtonActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGodModeButtonActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGodModeButtonActor::Pressed()
{
	ButtonMesh->SetMaterial(0, UsedMaterial);
}

