// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "JumpMotigaGameMode.h"
#include "JumpMotigaCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJumpMotigaGameMode::AJumpMotigaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
