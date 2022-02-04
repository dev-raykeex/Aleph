// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class ALEPH_API AMainHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HUD", meta = (GetOptions = "Skins"))
		FString UIStyle = "Alternative";

	UFUNCTION(BlueprintCallable)
		TArray<FString> Skins() const
		{
			return {
				"Off",
				"Modern",
				"Aleph",
				"Alternative",
				"Classic"
			};
		}
};
