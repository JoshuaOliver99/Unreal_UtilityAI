#include "UAIAction_Sleep.h"
#include "UnrealAI/SimPawn.h"

float UUAIAction_Sleep::Score(AAIController* Controller, APawn* Pawn)
{
	// Call the parent class Score method.
	Super::Score(Controller, Pawn);

	// Get the tiredness value.
	float tirednessValue = Sim->GetTiredness();
	
	// Use the curve to compute the score.
	float score = CoreScoreCurve->GetFloatValue(tirednessValue);
	
	
	// Return the desire to sleep.
	return score;
}

void UUAIAction_Sleep::Enter(AAIController* Controller, APawn* Pawn)
{
	// Call the parent class Enter method.
	Super::Enter(Controller, Pawn);

	
	// TODO: remove debug log that the action has been entered.
	UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Sleep::Enter - Pawn has entered the sleep action"));

	
	// Reduce tiredness.
	Sim->SetTiredness(FMath::Max(0.f, Sim->GetTiredness() - 50.f));
}
