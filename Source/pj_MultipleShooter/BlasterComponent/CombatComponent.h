// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <pj_MultipleShooter/Weapon/Weapon.h>
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PJ_MULTIPLESHOOTER_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatComponent();

	friend class ABlasterCharacter;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void EquipeWeapon(AWeapon* Weapon);


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(Replicated)
	AWeapon* EquippedWeapon;

	class ABlasterCharacter* Character;
		
};
