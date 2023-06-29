// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MultiplayerSessionsSubsystem.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Menu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMenu : public UUserWidget
{
	GENERATED_BODY()
		
public :
	UFUNCTION(BlueprintCallable)
	void MenuSetup(int32 NumOfPublicConnection = 4, FString TypeMath = FString(TEXT("FreeForAll")));

protected:
	virtual bool Initialize() override;
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);
	void OnFindSession(const TArray<FOnlineSessionSearchResult>& SessionSearchResults, bool bWasSuccessful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	UFUNCTION()
	void OnDestroySession(bool bWasSuccessful);
	UFUNCTION()
	void OnStartSession(bool bWasSuccessful);

private:
	int32 NumPublicConnect{4};
	FString MatchType{"FreeForAll"};

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> JoinButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> HostButton;

	UFUNCTION()
	void OnJoinButtonClicked();

	UFUNCTION()
	void OnHostButtonClicked();

	/**
	 * @brief Remove the Menu when entering to the game
	 */
	void MenuTearDown();


private:
	//Use to handle all online functionnality
	UMultiplayerSessionsSubsystem* MultiplayerSessionsSubsystem;



};
