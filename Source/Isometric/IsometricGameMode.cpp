// Copyright Epic Games, Inc. All Rights Reserved.

#include "IsometricGameMode.h"
#include "IsometricPlayerController.h"
#include "IsometricCharacter.h"
#include "UObject/ConstructorHelpers.h"

AIsometricGameMode::AIsometricGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AIsometricPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}