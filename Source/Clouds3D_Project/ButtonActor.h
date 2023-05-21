// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DoorActor.h"
#include "TurretActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ButtonActor.generated.h"

UCLASS()
class CLOUDS3D_PROJECT_API AButtonActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AButtonActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "LinkedDoor")
		ADoorActor* Door;

	UPROPERTY(EditAnywhere, Category = "LinkedTurrets")
		TArray<ATurretActor*> LinkedTurrets;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
		class UStaticMeshComponent* ButtonMesh;

	UPROPERTY(VisibleAnywhere, Category = "CollisionMesh")
		class UBoxComponent* CollisionMesh = nullptr;

	UPROPERTY(EditAnywhere, Category = "ActivetedMaterial")
		class UMaterial* ActivatedMaterial = nullptr;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Pressed();

};
