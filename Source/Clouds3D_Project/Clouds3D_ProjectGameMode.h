// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Clouds3D_ProjectGameMode.generated.h"

UCLASS(minimalapi)
class AClouds3D_ProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	AClouds3D_ProjectGameMode();

	void SetGamePaused(bool Pause);

	//UFUNCTION(BlueprintCallable, Category = "MainMenu")
	//void ShowMainMenu();

	UFUNCTION(BlueprintCallable, Category = "HUD")
	void ShowPlayerHUD();

protected:

	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "MainMenu", Meta = (BlueprintProtected = "true"))
	//TSubclassOf<class UUserWidget> MainMenuClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUD", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> PlayerHUDClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "PauseMenu", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> PauseMenuClass;

	UPROPERTY()
	class UUserWidget* CurrentWidget;

};



