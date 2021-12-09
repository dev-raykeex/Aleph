// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HPC.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALEPH_API UHPC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHPC();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
		int MaxHealth;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Character")
		int Health;

	UFUNCTION(BlueprintPure)
		int GetHealth() const { return Health; }

	UFUNCTION(Exec, BlueprintCallable)
		void SetHealth(int value);

	UFUNCTION()
		void TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
};
