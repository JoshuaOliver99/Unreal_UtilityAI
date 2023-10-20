// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseUAIAction.h"

#include "UnrealAI/SimPawn.h"

// Spawn (called when the action is instantiated, generally one time per brain)
void UBaseUAIAction::Spawn(AAIController* Controller)
{
	Super::Spawn(Controller);


	
	// Break clause - only allow sim pawns
	if (!Controller)
	{
		UE_LOG(LogTemp, Warning, TEXT("UBaseUAIAction::Spawn - Controller is null"));
		return;
	}
	APawn* Pawn = Controller->GetPawn();
	if (!Pawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("UBaseUAIAction::Spawn - Pawn is null"));
		return;
	}
	Sim = Cast<ASimPawn>(Pawn);
	if(!Sim)
	{
		UE_LOG(LogTemp, Warning, TEXT("UBaseUAIAction::Spawn - Pawn is not a SimPawn"));
		return;
	}


	// Break clause - only allow valid score curves
	if (!CoreScoreCurve)
	{
		UE_LOG(LogTemp, Warning, TEXT("UBaseUAIAction::Spawn - CoreScoreCurve is null"));
		return;
	}
}

// Tick (called at every world tick if the action is the currently chosen one)
void UBaseUAIAction::Tick(float DeltaTime, AAIController* Controller, APawn* Pawn)
{
	Super::Tick(DeltaTime, Controller, Pawn);
}

// CanRun (returns a bool, if true, the default, the action will be taken into account for the final computation)
bool UBaseUAIAction::CanRun(AAIController* Controller, APawn* Pawn) const
{
	return Super::CanRun(Controller, Pawn);
}

// Score (returns a float, the score of the action)
float UBaseUAIAction::Score(AAIController* Controller, APawn* Pawn)
{
	// Break clause - only allow valid score curves
	if (!CoreScoreCurve)
	{
		UE_LOG(LogTemp, Warning, TEXT("UBaseUAIAction::Tick - CoreScoreCurve is null"));
		return 0.0f;
	}
	
	return Super::Score(Controller, Pawn);
}

// Enter (called whenever the brain switches from another action to this one)
void UBaseUAIAction::Enter(AAIController* Controller, APawn* Pawn)
{
	Super::Enter(Controller, Pawn);
}

// Exit (called whenever the brain switches to another action)
void UBaseUAIAction::Exit(AAIController* Controller, APawn* Pawn)
{
	Super::Exit(Controller, Pawn);
}