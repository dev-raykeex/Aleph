// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerChr.h"

#include "CSL_Window.h"
#include "Camera/CameraActor.h"
#include "Kismet/KismetMathLibrary.h"
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

bool APlayerChr::Trace(float Distance)
{
	FCollisionQueryParams TraceParams;
	FHitResult HitResult;
	
	if(UWorld* World = GetWorld())
	{
		APlayerCameraManager* Camera = World->GetFirstPlayerController()->PlayerCameraManager;
		FVector CamWorldLocation = Camera->GetCameraLocation();
		FVector CamForwardVec = Camera->GetActorForwardVector() * Distance + CamWorldLocation;
		
		bool bDidTrace = GetWorld()->LineTraceSingleByChannel(HitResult, CamWorldLocation, CamForwardVec, ECC_Visibility, TraceParams);
		if(bDidTrace)
		{
			GrappleLocation = HitResult.Location;
			return HitResult.GetComponent()->IsSimulatingPhysics();
		} else {
			GrappleLocation = FVector(0,0,0);
			UCSL_Window::PrintToConsole("Character", "Error", "No hit registered.");
			return false;
		}
	}
	return nullptr;
}

void APlayerChr::Grapple(float Distance)
{
	Trace(Distance);
	if(!Trace(Distance))
	{
		bIsGrappling = true;
		GetCharacterMovement()->SetMovementMode(MOVE_Flying);
		UCableComponent* Cable = FindComponentByClass<UCableComponent>();
		if(Cable->IsValidLowLevel())
		{
			Cable->SetVisibility(true);
		}
	}
}

void APlayerChr::GrappleTick()
{
	if(bIsGrappling)
	{
		GetCharacterMovement()->AddForce(UKismetMathLibrary::Normal(UKismetMathLibrary::GetDirectionUnitVector(GetActorLocation(), GrappleLocation) + ((GetInputAxisValue("move_sideways") * GetActorRightVector()) * 0.5f)) * 300000.0f);
		UCableComponent* Cable = FindComponentByClass<UCableComponent>();
		Cable->EndLocation = UKismetMathLibrary::InverseTransformLocation(GetActorTransform(), GrappleLocation);
		if((UKismetMathLibrary::Vector_Distance(GrappleLocation, GetActorLocation()) <= 256.0f) || (UKismetMathLibrary::Vector_Distance(GrappleLocation, GetActorLocation()) >= 3072.0f))
		{
			GrappleStop();
		}
	}
}

void APlayerChr::GrappleStop()
{
	bIsGrappling = false;
	GrappleLocation = FVector(0, 0, 0);
	GetCharacterMovement()->SetMovementMode(MOVE_Falling);
	UCableComponent* Cable = FindComponentByClass<UCableComponent>();
	if(Cable->IsValidLowLevel())
	{
		Cable->SetVisibility(false);
	}
}

