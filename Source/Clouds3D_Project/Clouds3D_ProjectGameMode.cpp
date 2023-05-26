// Copyright Epic Games, Inc. All Rights Reserved.


#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Clouds3D_ProjectGameMode.h"
#include "Clouds3D_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"


void AClouds3D_ProjectGameMode::BeginPlay()
{
	Super::BeginPlay();

	ShowPlayerHUD();
}

AClouds3D_ProjectGameMode::AClouds3D_ProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AClouds3D_ProjectGameMode::SetGamePaused(bool Pause)
{
	if (Pause) {
		APlayerController* const MyPlayer = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
		if (MyPlayer != NULL)
		{
			MyPlayer->SetPause(Pause);
			MyPlayer->SetShowMouseCursor(true);
			CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), PauseMenuClass);

			if (CurrentWidget != nullptr)
			{
				CurrentWidget->AddToViewport();
			}
		}
	}
}

/*void AClouds3D_ProjectGameMode::ShowMainMenu()
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
}*/

void AClouds3D_ProjectGameMode::ShowPlayerHUD()
{
	if (PlayerHUDClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDClass);

		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}
