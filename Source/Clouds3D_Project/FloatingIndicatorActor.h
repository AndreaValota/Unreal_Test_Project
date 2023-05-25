// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingIndicatorActor.generated.h"

UCLASS()
class CLOUDS3D_PROJECT_API AFloatingIndicatorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingIndicatorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* IndicatorMesh;

	UPROPERTY()
	FTimerHandle TimerHandle;

	UPROPERTY()
	int FloatDelay = 0;

	UPROPERTY()
	int Direction = 1;

	UFUNCTION()
	void Float();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
