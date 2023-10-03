#include "UAIAction_Sleep.h"
#include "UnrealAI/SimPawn.h"

float UUAIAction_Sleep::Score(AAIController* Controller, APawn* Pawn)
{
	// Call the parent class Score method.
	Super::Score(Controller, Pawn);

	// Try to cast to SimPawn.
	const ASimPawn* Sim = Cast<ASimPawn>(Pawn);
	if(!Sim)
	{
		// Log a warning if the cast fails.
		UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Sleep::Score - Context is not a SimPawn"));
		return 0.f;
	}

	// Return tiredness.
	return Sim->GetTiredness();
}

void UUAIAction_Sleep::Enter(AAIController* Controller, APawn* Pawn)
{
	// Call the parent class Enter method.
	Super::Enter(Controller, Pawn);

	// Try to cast to SimPawn.
	ASimPawn* Sim = Cast<ASimPawn>(Pawn);
	if(!Sim)
	{
		// Log a warning if the cast fails.
		UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Sleep::Enter - Pawn is not a SimPawn"));
		return;
	}

	// Reduce tiredness.
	Sim->SetTiredness(FMath::Max(0.f, Sim->GetTiredness() - 50.f));
}
