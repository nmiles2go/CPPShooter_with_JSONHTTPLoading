// Copyright Epic Games, Inc. All Rights Reserved.


#include "CPP_JSON_SHOOTERPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "CPP_JSON_SHOOTERCameraManager.h"
#include "Blueprint/UserWidget.h"
#include "CPP_JSON_SHOOTER.h"
#include "Widgets/Input/SVirtualJoystick.h"

ACPP_JSON_SHOOTERPlayerController::ACPP_JSON_SHOOTERPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = ACPP_JSON_SHOOTERCameraManager::StaticClass();
}

void ACPP_JSON_SHOOTERPlayerController::BeginPlay()
{
	Super::BeginPlay();

	
	// only spawn touch controls on local player controllers
	if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogCPP_JSON_SHOOTER, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}
}

void ACPP_JSON_SHOOTERPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Context
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!SVirtualJoystick::ShouldDisplayTouchInterface())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
	
}
