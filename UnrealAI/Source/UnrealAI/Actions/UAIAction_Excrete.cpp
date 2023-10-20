#include "UAIAction_Excrete.h"
#include "UnrealAI/SimPawn.h"

float UUAIAction_Excrete::Score(AAIController* Controller, APawn* Pawn)
{
	Super::Score(Controller, Pawn);


	// Get the bladder value.
	float bladderValue = Sim->GetBladder();

	// Use the curve to compute the score.
	float score = CoreScoreCurve->GetFloatValue(bladderValue);

	
	// TODO: remove debug log
	//UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Excrete::Score - bladderValue: %f, score: %f"), bladderValue, score);

	
	// Return the desire to excrete.
	return score;
}

void UUAIAction_Excrete::Enter(AAIController* Controller, APawn* Pawn)
{
	Super::Enter(Controller, Pawn);

	
	// TODO: remove debug log that the action has been entered.
	UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Excrete::Enter - Pawn has entered the use toilet action"));

	

	// Reduce bladder value.
	Sim->SetBladder(FMath::Max(0.f, Sim->GetBladder() - 50.f));
}
