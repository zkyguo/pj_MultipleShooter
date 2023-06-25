// Copyright Epic Games, Inc. All Rights Reserved.

#include "pj_MultipleShooterGameMode.h"
#include "pj_MultipleShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

Apj_MultipleShooterGameMode::Apj_MultipleShooterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
