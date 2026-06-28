// Copyright Epic Games, Inc. All Rights Reserved.

#include "GES_2GameMode.h"
#include "GES_2Character.h"
#include "UObject/ConstructorHelpers.h"

AGES_2GameMode::AGES_2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
