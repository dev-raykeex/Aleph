// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CableComponent.h"
#include "GameFramework/Character.h"
#include "PlayerChr.generated.h"

UCLASS()
class ALEPH_API APlayerChr : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerChr();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input")
		float Sensitivity = 0.25f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input: Controller")
		float ZSensitivity = 25.0f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input: Controller")
		float YSensitivity = 45.0f;

	UFUNCTION(BlueprintPure)
		float GetSens() const { return Sensitivity; }
	UFUNCTION(BlueprintPure)
		float GetZSens() const { return ZSensitivity; }
	UFUNCTION(BlueprintPure)
		float GetYSens() const { return YSensitivity; }

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Movement Speed")
		float BaseWalkSpeed = 375.0f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Movement Speed")
		float BaseWalkSpeedMultiplier = 2.2f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Movement Speed")
		float BaseCrouchSpeed = 150.0f;

	UFUNCTION(BlueprintCallable, Category = "Character: Movement")
		void move_forward(float Value);
	UFUNCTION(BlueprintCallable, Category = "Character: Movement")
		void move_side(float Value);

	UFUNCTION(BlueprintCallable, Category = "Character: Movement")
		void look_vertical(float Axis);
	UFUNCTION(BlueprintCallable, Category = "Character: Movement")
		void look_horizontal(float Axis);
		
	UFUNCTION(Exec)
		void noclip(int Mode); // 0 = disable, 1 = enable

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Movement - Dash")
		int DashMode = 0; // 0 = disabled, 1 = sprint, 2 = dash
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character: Movement - Dash")
		float DashAxis = 0.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character: Movement - Dash")
		bool IsWalkingV = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character: Movement - Dash")
		bool IsWalkingH = false;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Status")
		bool bIsChatting = false;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Status")
		bool bIsGrabbing = false;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Status")
		bool bIsCrouching = false;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Status")
		bool bIsGrappling = false;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Status")
		bool bIsPulling = false;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Status")
		bool bIsWallrunning = false;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Status")
		bool bIsFlashOn = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Status")
		bool bCanUseFlash = true;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Status")
		bool bCanUseWallrunning = true;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character: Interaction")
		float GrabDistance = 256.0f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Interaction")
		float OutlineRange = 256.0f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Interaction")
		float OutlineRadius = 128.0f;

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Movement - Grapple")
		FVector GrappleLocation;

	UFUNCTION(BlueprintCallable, Category = "Trace")
		bool Trace(float Distance);
	UFUNCTION(BlueprintCallable, Category = "GrapplingHook")
		void Grapple(float Distance);
	UFUNCTION(BlueprintCallable, Category = "GrapplingHook")
		void GrappleTick();
	UFUNCTION(BlueprintCallable, Category = "GrapplingHook")
		void GrappleStop();
};
