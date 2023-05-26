// Fill out your copyright notice in the Description page of Project Settings.

#include "Blueprint/UserWidget.h"
#include "MainMenuGameMode.h"

void AMainMenuGameMode::BeginPlay()
{
	Super::BeginPlay();

	ShowMainMenu();
}

void AMainMenuGameMode::ShowMainMenu()
{
	if (MainMenuClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), MainMenuClass);

		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
			APlayerController* const MyPlayer = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
			MyPlayer->SetShowMouseCursor(true);
		}
	}
}