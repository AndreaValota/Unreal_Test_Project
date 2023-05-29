// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckpointBoxActor.h"
#include "Components/BoxComponent.h"
#include <Clouds3D_Project/Clouds3D_ProjectCharacter.h>

// Sets default values
ACheckpointBoxActor::ACheckpointBoxActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(100.f, 100.f, 100.f));
	CollisionBox->SetCollisionProfileName("Trigger");
	RootComponent = CollisionBox;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ACheckpointBoxActor::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ACheckpointBoxActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACheckpointBoxActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACheckpointBoxActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FVector CheckpointLocation = this->GetActorLocation();

	if (OtherActor->IsA(AClouds3D_ProjectCharacter::StaticClass()))
	{
		Cast<AClouds3D_ProjectCharacter>(OtherActor)->SetRespawn(this->GetActorLocation());
	}
}

