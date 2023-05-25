// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingIndicatorActor.h"

// Sets default values
AFloatingIndicatorActor::AFloatingIndicatorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	IndicatorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IndicatorMesh"));
	IndicatorMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AFloatingIndicatorActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AFloatingIndicatorActor::Float, 1.f, true, 0.f);
	
}

void AFloatingIndicatorActor::Float()
{
	FloatDelay++;

	if (FloatDelay % 2 == 0)
	{
		Direction = Direction * -1;
	}
}

// Called every frame
void AFloatingIndicatorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->SetActorLocation(GetActorLocation() + FVector(0.f, 0.f, 50.f * DeltaTime * Direction));

}

