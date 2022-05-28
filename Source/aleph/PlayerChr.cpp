// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerChr.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerChr::APlayerChr()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerChr::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerChr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerChr::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerChr::move_forward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void APlayerChr::move_side(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void APlayerChr::look_vertical(float Axis)
{
	AddControllerPitchInput(Axis * Sensitivity);
}

void APlayerChr::look_horizontal(float Axis)
{
	AddControllerYawInput(Axis * Sensitivity);
}

void APlayerChr::noclip(int Mode)
{
	if(Mode == 0)
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		SetActorEnableCollision(true);
	} else if(Mode == 1)
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Flying);
		SetActorEnableCollision(false);
	}
}

