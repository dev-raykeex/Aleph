// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "C_HUD.generated.h"

/**
 * 
 */
UCLASS()
class ALEPH_API AC_HUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HUD", meta = (GetOptions = "Skins"))
		FString Skin = "Default";

	UFUNCTION(BlueprintCallable)
		TArray<FString> Skins() const
		{
			return {
				"Off",
				"Default"
			};
		}
};
