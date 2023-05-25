// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretActor.h"
#include "Kismet/GameplayStatics.h"
#include "Clouds3D_ProjectCharacter.h"
#include <Runtime/Engine/Classes/Kismet/KismetMathLibrary.h>

// Sets default values
ATurretActor::ATurretActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	TurretMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TurretMesh"));
	TurretMesh -> SetupAttachment(Root);

	PedestalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PedestalMesh"));
	PedestalMesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void ATurretActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ATurretActor::Shoot, ShootDelay, true, 1.f);
	
}

// Called every frame
void ATurretActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateLookAtDirection();
}

void ATurretActor::UpdateLookAtDirection() 
{
	FVector Start = TurretMesh->GetSocketLocation("TurretMesh");
	//UE_LOG(LogTemp, Error, TEXT("Posizione %s"), *Start.ToString());
	TArray<AActor*> ActorsToFind;
	FVector End;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AClouds3D_ProjectCharacter::StaticClass(), ActorsToFind);

	for (AActor* Character : ActorsToFind)
	{
		if (Character->GetActorLabel() == "MainCharacter") {
			End = Character->GetActorLocation();
			//UE_LOG(LogTemp, Error, TEXT("END %s"), *End.ToString());
		}
	}

	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Start, End);
	//UE_LOG(LogTemp, Error, TEXT("END %s"), *LookAtRotation.ToString());
	TurretMesh->SetRelativeRotation(UKismetMathLibrary::ComposeRotators(FRotator(0.f, -90.f, 0.f),LookAtRotation));

}


void ATurretActor::Shoot()
{
	FHitResult OutHit;
	FVector Start = TurretMesh->GetSocketLocation("TurretMesh");
	FVector End = TurretMesh->GetSocketLocation("TurretMesh")+ (TurretMesh->GetRightVector() * TurretRange);

	FCollisionQueryParams CollQueryParams;
	CollQueryParams.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(OUT OutHit, Start, End, ECollisionChannel::ECC_Camera, CollQueryParams))
	{
		if (OutHit.Actor->GetActorLabel() == "MainCharacter")
		{
			UGameplayStatics::PlaySoundAtLocation(this, ShootSound, TurretMesh->GetComponentLocation());
			FPointDamageEvent DamageEvent(TurretDamage, OutHit,  TurretMesh->GetRightVector(),nullptr);
			OutHit.GetActor()->TakeDamage(TurretDamage, DamageEvent, GetInstigatorController(), this);
		}
	}
}

