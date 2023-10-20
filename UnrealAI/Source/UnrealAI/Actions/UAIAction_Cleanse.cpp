#include "UAIAction_Cleanse.h"
#include "UnrealAI/SimPawn.h"

float UUAIAction_Cleanse::Score(AAIController* Controller, APawn* Pawn)
{
	Super::Score(Controller, Pawn);

	// Get the dirtiness value.
	float dirtinessValue = Sim->GetDirtiness();
	
	// Use the curve to compute the score.
	float score = CoreScoreCurve->GetFloatValue(dirtinessValue);
	
	
	// Return the desire to clean self.
	return score;
}

void UUAIAction_Cleanse::Enter(AAIController* Controller, APawn* Pawn)
{
	Super::Enter(Controller, Pawn);

	
	// TODO: remove debug log that the action has been entered.
	UE_LOG(LogTemp, Warning, TEXT("UUAIAction_UseToilet::Enter - Pawn has entered the use toilet action"));

	
	// Reduce dirtiness value.
	Sim->SetDirtiness(FMath::Max(0.f, Sim->GetDirtiness() - 50.f));
}
