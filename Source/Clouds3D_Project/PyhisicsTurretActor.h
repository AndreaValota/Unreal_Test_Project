// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurretActor.h"
#include "PyhisicsTurretActor.generated.h"

/**
 * 
 */
UCLASS()
class CLOUDS3D_PROJECT_API APyhisicsTurretActor : public ATurretActor
{
	GENERATED_BODY()

public:

	virtual void Shoot() override;

private:

	UPROPERTY(EditAnywhere, Category = Projectile)
		TSubclassOf<class APhysicsProjectile> ProjectileClass;
	
};
