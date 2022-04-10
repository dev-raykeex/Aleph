// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HardwareDetails.generated.h"

/**
 * 
 */
UCLASS()
class ALEPH_API UHardwareDetails : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get CPU brand", Keywords = "CPU brand"), Category = "Game")
		static FString GetCPUBrand();
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get CPU cores", Keywords = "CPU cores"), Category = "Game")
		static int32 GetCPUCores();
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get CPU threads", Keywords = "CPU threads"), Category = "Game")
		static int32 GetCPUThreads();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get GPU brand", Keywords = "GPU brand"), Category = "Game")
		static FString GetGPUBrand();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get RAM capacity", Keywords = "RAM capacity"), Category = "Game")
		static int32 GetRAMCapacity();
};
