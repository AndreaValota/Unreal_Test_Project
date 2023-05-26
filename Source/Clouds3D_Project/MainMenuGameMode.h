// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CLOUDS3D_PROJECT_API AMainMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "MainMenu", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> MainMenuClass;

	UFUNCTION(BlueprintCallable, Category = "MainMenu")
	void ShowMainMenu();

	UPROPERTY()
	class UUserWidget* CurrentWidget;

};
