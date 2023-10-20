#include "UAIAction_Socialize.h"
#include "UnrealAI/SimPawn.h"

float UUAIAction_Socialize::Score(AAIController* Controller, APawn* Pawn)
{
	// Call the parent class Score method.
	Super::Score(Controller, Pawn);

	// Get the loneliness value.
	float lonelinessValue = Sim->GetLoneliness();
	
	// Use the curve to compute the score.
	float score = CoreScoreCurve->GetFloatValue(lonelinessValue);
	
	
	// Return the desire to socialize.
	return score;
}

void UUAIAction_Socialize::Enter(AAIController* Controller, APawn* Pawn)
{
	// Call the parent class Enter method.
	Super::Enter(Controller, Pawn);

	
	// TODO: remove debug log that the action has been entered.
	UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Socialize::Enter - Pawn has entered the socialize action"));

	
	// Reduce loneliness.
	Sim->SetLoneliness(FMath::Max(0.f, Sim->GetLoneliness() - 50.f));
}
