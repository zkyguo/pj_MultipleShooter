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
	void SetAiming(bool bIsAiming);


	UFUNCTION(Server, Reliable)
	void ServerSetAiming(bool bIsAiming);

	UFUNCTION()
	void OnRep_EquippedWeapon();

	void FireButtonPressed(bool bIsFire);

	/**
	 * @brief Send Fire command from client to server
	 */
	UFUNCTION(Server, Reliable)
	void ServerFire();

	/**
	 * @brief Send Fire Command to all other client. Why multicast, because for autofire weapon, as we persist pressing on fire button
	 * But replicated can only detect changing value.So we need multicast to assure that weapon keep firing
	 */
	UFUNCTION(NetMulticast, Reliable)
	void MulticastFire();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	class ABlasterCharacter* Character;

	UPROPERTY(ReplicatedUsing = OnRep_EquippedWeapon)
	AWeapon* EquippedWeapon;

	UPROPERTY(Replicated)
	bool bAiming;

	UPROPERTY(EditAnywhere)
	float baseWalkSpeed;

	UPROPERTY(EditAnywhere)
	float CrouchWalkSpeed;

	UPROPERTY(EditAnywhere)
	float AimWalkSpeed;

	bool bFireButtonPressed;
};
