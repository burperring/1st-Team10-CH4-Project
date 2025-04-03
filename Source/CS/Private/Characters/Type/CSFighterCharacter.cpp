// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Type/CSFighterCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedPlayerInput.h"
#include "GameFramework/CharacterMovementComponent.h"

ACSFighterCharacter::ACSFighterCharacter()
{
}

void ACSFighterCharacter::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(FighterMappingContext, 1);
		}
	}
}

void ACSFighterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ACSFighterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(HCombo1Action, ETriggerEvent::Started, this, &ACSFighterCharacter::PlayHCombo1Montage);
	}
}

void ACSFighterCharacter::PlayHCombo1Montage()
{
	PlayPlayerMontage(HAttackMontage, "Kick1");
}

