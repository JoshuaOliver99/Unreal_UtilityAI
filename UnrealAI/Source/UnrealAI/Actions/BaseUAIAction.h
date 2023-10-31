// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UtilityAIAction.h"
#include "BaseUAIAction.generated.h"

class UBaseItemAction;
class ASimPawn;
class UCurveFloat;

/**
 * 
 */
UCLASS()
class UNREALAI_API UBaseUAIAction : public UUtilityAIAction
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


	// ---------- Core Attributes ----------
protected:
	// The sim pawn to be evaluated and controlled.
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	ASimPawn* Sim;
	
	// The curve used to score the action.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	const UCurveFloat* CoreScoreCurve;


	// ---------- Action Evaluation ----------
protected:
	// A list of all the actions that can be evaluated.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Evaluation")
	TArray<TSubclassOf<UBaseItemAction>> AvailableActions;

	
	// Timer handle used to delay update of the available actions array. Invoked in the Spawn function
	FTimerHandle AvailableActionEvaluationTimerHandle;

	// Delay before updating the available actions array.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Evaluation")
	float AvailableActionEvaluationDelay = 5.f;
	
	// The radius of the sphere used to find all available item actions
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Evaluation")
	float AvailableActionEvaluationRadius = 1000.f;

	
	// Initiate the available action evaluation timer. Must be overriden in the child class.
	UFUNCTION(BlueprintCallable, Category = "Action Evaluation")
	virtual void InitiateAvailableActionEvaluationTimer() { UE_LOG(LogTemp, Warning, TEXT("InitiateAvailableActionEvaluationTimer not overwritten!")) };


};
