// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	int32 numberPlayers = GameState.Get()->PlayerArray.Num();

	if(numberPlayers == 2)
	{
		UWorld* World = GetWorld();
		if(World)
		{
			bUseSeamlessTravel = true;
			World->ServerTravel(FString("/Game/Maps/BlasterMap?listen"));
		}
	}

	if(GameState.Get())
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				1,
				60.f,
				FColor::Yellow,
				FString::Printf(TEXT("Players in Game : %d"), numberPlayers)
			);
		}

		if(APlayerState* PlayerState = NewPlayer->GetPlayerState<APlayerState>())
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(
					-1,
					60.f,
					FColor::Cyan,
					FString::Printf(TEXT("%s has joined the game!"), *PlayerState->GetPlayerName())
				);
			}
		}

		
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	
	Super::Logout(Exiting);
	if (APlayerState* PlayerState = Exiting->GetPlayerState<APlayerState>())
	{
		int32 numberPlayers = GameState.Get()->PlayerArray.Num();

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				1,
				60.f,
				FColor::Yellow,
				FString::Printf(TEXT("Players in Game : %d"), numberPlayers)
			);
		}

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				60.f,
				FColor::Cyan,
				FString::Printf(TEXT("%s has left the game!"), *PlayerState->GetPlayerName())
			);
		}
	}
}
