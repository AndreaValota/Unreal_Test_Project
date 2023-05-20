// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonActor.h"
#include "Components/BoxComponent.h"

// Sets default values
AButtonActor::AButtonActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ButtonMesh"));
	ButtonMesh->SetupAttachment(RootComponent);

	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionMesh"));
	CollisionMesh -> SetupAttachment(ButtonMesh);
	CollisionMesh->SetGenerateOverlapEvents(true);
	CollisionMesh->SetBoxExtent(FVector(200.f, 200.f, 200.f), false);
	CollisionMesh->SetCollisionProfileName(TEXT("Trigger"), false);

	CollisionMesh->OnComponentBeginOverlap.AddDynamic(this, &AButtonActor::OnComponentOverlap);
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

	if (Door)
	{
		Door->ToggleDoor();

		for (ATurretActor* Turret : LinkedTurrets)
		{
			Turret->SetActorTickEnabled(false);
			GetWorldTimerManager().ClearAllTimersForObject(Turret);
		}
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("No Linked Door"));
	}
}

void AButtonActor::OnComponentOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning ,TEXT("On Component Overlap Begin!"));
}

