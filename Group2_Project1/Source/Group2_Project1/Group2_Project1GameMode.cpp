// Copyright Epic Games, Inc. All Rights Reserved.

#include "Group2_Project1GameMode.h"
#include "Group2_Project1PlayerController.h"
#include "Group2_Project1Character.h"
#include "UObject/ConstructorHelpers.h"

AGroup2_Project1GameMode::AGroup2_Project1GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGroup2_Project1PlayerController::StaticClass();

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