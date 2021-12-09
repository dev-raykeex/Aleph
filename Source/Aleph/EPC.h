// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EPC.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALEPH_API UEPC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEPC();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
		int MaxEnergy;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Character")
		int Energy;

	UFUNCTION(BlueprintPure)
		int GetEnergy() const { return Energy; }

	UFUNCTION(Exec, BlueprintCallable)
		void SetEnergy(int value);
};
