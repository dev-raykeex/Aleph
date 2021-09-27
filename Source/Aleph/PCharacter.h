// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PCharacter.generated.h"

UCLASS()
class ALEPH_API APCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Debug")
		bool AllowDebug = false;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Movement")
		float BaseWalkSpeed = 450.0f;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Movement")
		float BaseCrouchSpeed = 150.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		float BaseWalkMultiplier = 1.0f;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
		bool IsGrabbing = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera")
		bool IsZoomed = false;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
		int InputAmount = 0;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
		float GrabDistance = 180.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
		float OutlineRange = 256.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
		float OutlineRadius = 128.0f;

// This section is dedicated to the WR mechanic in the game
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		float DefaultGravity = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		float WR_Speed = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		float WR_TargetGravity = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		float WR_JumpHeight = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		bool WR = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		bool WR_Left = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		bool WR_Right = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		bool WR_Gravity = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		bool WR_Suppressed = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		FVector WR_Normal = FVector(0.0f, 0.0f, 0.0f);

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		float D_Axis = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		bool IsWalkingV = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		bool IsWalkingH = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
