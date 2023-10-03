// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UtilityAIAction.h"
#include "UAI_Action_RoamNearPlayer.generated.h"

/**
 * 
 */
UCLASS()
class UNREALAI_API UUAI_Action_RoamNearPlayer : public UUtilityAIAction
{
	GENERATED_BODY()

public:
	// Spawn (called when the action is instantiated, generally one time per brain)
	virtual void Spawn(AAIController* Controller) override;
	
	// Tick (called at every world tick if the action is the currently chosen one)
	virtual void Tick(float DeltaTime, AAIController* Controller, APawn* Pawn) override;

	// CanRun (returns a bool, if true, the default, the action will be taken into account for the final computation)
	virtual bool CanRun(AAIController* Controller, APawn* Pawn) const override;

	// Score (returns a float, the score of the action)
	virtual float Score(AAIController* Controller, APawn* Pawn) override;

	// Enter (called whenever the brain switches from another action to this one)
	virtual void Enter(AAIController* Controller, APawn* Pawn) override;

	// Exit (called whenever the brain switches to another action)
	virtual void Exit(AAIController* Controller, APawn* Pawn) override;
	
};
