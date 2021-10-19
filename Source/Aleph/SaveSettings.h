// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveSettings.generated.h"

/**
 * 
 */
UCLASS()
class ALEPH_API USaveSettings : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Gameplay")
		FString UIStyle;
};
