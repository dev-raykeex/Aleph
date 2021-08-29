// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALEPH_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
		int DefaultHealth;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Character")
		int Health;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Character")
		int InfoMaxHealth = 100;

	UFUNCTION(BlueprintPure)
		int GetHealth() const { return Health; }

	UFUNCTION()
		void TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
};
