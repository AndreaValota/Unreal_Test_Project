// Copyright Epic Games, Inc. All Rights Reserved.

#include "Clouds3D_ProjectGameMode.h"
#include "Clouds3D_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AClouds3D_ProjectGameMode::AClouds3D_ProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
