// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/EngineTypes.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurretActor.generated.h"

UCLASS()
class CLOUDS3D_PROJECT_API ATurretActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurretActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
	//	float BeamLength = 1000.f;

	UPROPERTY(EditAnywhere)
		float ShootDelay = 1.f;

	UPROPERTY(EditAnywhere)
		float TurretRange = 1000.f;

	UPROPERTY(EditAnywhere)
		float TurretDamage = 10.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private: 
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly)
		USkeletalMeshComponent* TurretMesh;

	UPROPERTY(EditDefaultsOnly)
		class UStaticMeshComponent* PedestalMesh;

	UPROPERTY(EditDefaultsOnly)
		USoundBase* ShootSound;

	//UPROPERTY(EditDefaultsOnly)
	//	class UStaticMeshComponent* Beam;

	UFUNCTION()
		void UpdateLookAtDirection();

	UPROPERTY()
		FTimerHandle TimerHandle;

	//UFUNCTION(BlueprintCallable)
	//	void SetBeamLength(float Length);

	UFUNCTION()
		void Shoot();

};
