#include "UAIAction_Eat.h"
#include "UnrealAI/SimPawn.h"

float UUAIAction_Eat::Score(AAIController* Controller, APawn* Pawn)
{
	Super::Score(Controller, Pawn);

	// Get the hunger value.
	float hungerValue = Sim->GetHunger();
	
	// Use the curve to compute the score.
	float score = CoreScoreCurve->GetFloatValue(hungerValue);
	
	
	// Return the desire to eat.
	return score;
}

void UUAIAction_Eat::Enter(AAIController* Controller, APawn* Pawn)
{
	Super::Enter(Controller, Pawn);


	// TODO: remove debug log that the action has been entered.
	UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Eat::Enter - Pawn has entered the eat action"));
	

	// Reduce hunger.
	Sim->SetHunger(FMath::Max(0.f, Sim->GetHunger() - 50.f));
}