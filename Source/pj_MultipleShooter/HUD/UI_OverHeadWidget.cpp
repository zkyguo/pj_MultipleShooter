// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_OverHeadWidget.h"

void UUI_OverHeadWidget::SetDisplayText(FString& Content)
{
	if(DisplayText)
	{
		DisplayText->SetText(FText::FromString(Content));
	}
}

void UUI_OverHeadWidget::ShowPlayerNetRole(const APawn* InPawn)
{

	ENetRole LocalRole = InPawn->GetLocalRole();
	FString Role;
	switch(LocalRole)
	{
	case ENetRole::ROLE_Authority :
		Role = FString("Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy :
		Role = FString("Autonomous Proxy");
		break;
	case ENetRole::ROLE_SimulatedProxy :
		Role = FString("Simulated Proxy");
		break;
	case ENetRole::ROLE_None :
		Role = FString("None");
		break;
	}

	FString LocalRoleString = FString::Printf(TEXT("Local Role : %s"), *Role);
	SetDisplayText(LocalRoleString);
}

void UUI_OverHeadWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	//if destroy remove parentship
	RemoveFromParent();
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}
