// Copyright Epic Games, Inc. All Rights Reserved.


#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Clouds3D_ProjectGameMode.h"
#include "Clouds3D_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"


void AClouds3D_ProjectGameMode::BeginPlay()
{
	Super::BeginPlay();

	AClouds3D_ProjectCharacter* MyCharacter = Cast<AClouds3D_ProjectCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (PlayerHUDClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDClass);

		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
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
	}/* else
	{
		APlayerController* const MyPlayer = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
		if (MyPlayer != NULL)
		{
			MyPlayer->SetPause(Pause);
			CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDClass);

			if (CurrentWidget != nullptr)
			{
				CurrentWidget->AddToViewport();
			}
		}
	}*/
}
