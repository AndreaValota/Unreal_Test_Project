// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GodModeButtonActor.generated.h"

UCLASS()
class CLOUDS3D_PROJECT_API AGodModeButtonActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGodModeButtonActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
		class UStaticMeshComponent* ButtonMesh;

	UPROPERTY(EditAnywhere, Category = "UsedMaterial")
		class UMaterial* UsedMaterial = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Pressed();

};
