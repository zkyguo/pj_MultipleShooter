// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/TextBlock.h>
#include "UI_OverHeadWidget.generated.h"


/**
 * 
 */
UCLASS()
class PJ_MULTIPLESHOOTER_API UUI_OverHeadWidget : public UUserWidget
{
	GENERATED_BODY()


public :
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> DisplayText;

	void SetDisplayText(FString &Content);

	UFUNCTION(BlueprintCallable)
	void ShowPlayerNetRole(const APawn* InPawn);

protected:
	//TODO: Move implementation to NativeDestruct if in UE5.1
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

};
