// Fill out your copyright notice in the Description page of Project Settings.


#include "PyhisicsTurretActor.h"
#include "PhysicsProjectile.h"
#include <Runtime/Engine/Classes/Kismet/KismetMathLibrary.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

void APyhisicsTurretActor::Shoot() 
{
	FHitResult OutHit;
	FVector Start = TurretMesh->GetSocketLocation("TurretMesh");
	FVector End = TurretMesh->GetSocketLocation("TurretMesh") + (TurretMesh->GetRightVector() * TurretRange);

	FCollisionQueryParams CollQueryParams;
	CollQueryParams.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(OUT OutHit, Start, End, ECollisionChannel::ECC_Camera, CollQueryParams))
	{
		if (OutHit.Actor->GetActorLabel() == "MainCharacter")
		{
			if (ProjectileClass != nullptr)
			{
				FRotator SpawnRotation = UKismetMathLibrary::ComposeRotators(FRotator(0.f, 90.f, 0.f), TurretMesh->GetSocketRotation("TurretMesh"));
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				FVector SpawnLocation = TurretMesh->GetSocketLocation("TurretMesh");
				UGameplayStatics::PlaySoundAtLocation(this, ShootSound, SpawnLocation);

				//Set Spawn Collision Handling Override
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				// spawn the projectile 
				APhysicsProjectile* Bullet = GetWorld()->SpawnActor<APhysicsProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);

				Bullet->SetProjectileDamage(TurretDamage);
			}
		}
	}
}
