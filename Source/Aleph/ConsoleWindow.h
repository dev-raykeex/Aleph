// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Misc/OutputDeviceFile.h"
#include "ConsoleWindow.generated.h"

/**
 * 
 */
UCLASS()
class ALEPH_API UConsoleWindow : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable)
		void PrintLogInConsole();
	
	FString LogFile;
	FOutputDeviceFile* OutputDeviceFile;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	FString LogContent;
};
