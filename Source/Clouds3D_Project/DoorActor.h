// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorActor.generated.h"

UCLASS()
class CLOUDS3D_PROJECT_API ADoorActor : public AActor
{
	GENERATED_BODY()
	
public:		
	// Sets default values for this actor's properties
	ADoorActor();

protected:

	bool bDoorOpen;

	UPROPERTY(EditAnywhere, Category = "Speed")
	int Speed;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ToggleDoor();


private:

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* DoorMesh;

};
