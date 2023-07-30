// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include <Camera/CameraComponent.h>
#include <Components/WidgetComponent.h>
#include <pj_MultipleShooter/Weapon/Weapon.h>
#include "pj_MultipleShooter/BlasterComponent/CombatComponent.h"
#include "pj_MultipleShooter/BlasterType/TurnInPlace.h"
#include "pj_MultipleShooter/Interfaces/InteractWithCrosshairsInterface.h"
#include "BlasterCharacter.generated.h"

UCLASS()
class PJ_MULTIPLESHOOTER_API ABlasterCharacter : public ACharacter, public IInteractWithCrosshairsInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABlasterCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	// Initialize components
	virtual void PostInitializeComponents() override;
	void PlayFireMontage(bool isAiming);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void CrouchButtonPressed();
	void CrouchButtonReleased();
	void EquipeButtonPressed();
	void AimButtonPressed();
	void AimButtonReleassed();
	void FireButtonPressed();
	void FireButtonReleased();

	void AimOffset(float DeltaTime);
	virtual void Jump() override;

	

private:
	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UWidgetComponent* OverheadWdiget;

	/**
	 * @brief Weapon use on UI propose
	 */
	UPROPERTY(ReplicatedUsing = OnRep_OverlappingWeapon)
	AWeapon* OverlappingWeapon;

	UFUNCTION()
	void OnRep_OverlappingWeapon(AWeapon* LastWeapon);

	//Here track all replicatedUsing.Which share to all client info
	UPROPERTY(VisibleAnywhere)
	UCombatComponent* CombatComponent;

	UFUNCTION(Server,Reliable) //Reliable = once Equip Button pressed, we 
	void ServerEquipButtonPressed();

	
	/**
	*  Character anim Rotation
	*/
	float AO_Yaw;
	float AO_Pitch;
	float InterpAO_Yaw;
	FRotator StartingAimRotator;

	ETurningInPlace TurningInPlace;
	void TurnInPlace(float DeltaTime);

	UPROPERTY(EditAnywhere, Category = Combat)
	UAnimMontage* FireWeaponMontage;

	

public:
	void SetOverlappingWeapon(AWeapon* Weapon);
	bool IsWeaponEquipped();
	bool IsAiming();
	FORCEINLINE float GetAOYaw() const { return AO_Yaw; }
	FORCEINLINE float GetAOPitch() const { return AO_Pitch; }
	AWeapon* GetEquippedWeapon();
	FORCEINLINE ETurningInPlace GetETurningInPlace() const { return TurningInPlace; }
	FVector GetHitTarget() const;

	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
