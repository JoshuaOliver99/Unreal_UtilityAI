#include "UAIAction_Socialize.h"
#include "UnrealAI/SimPawn.h"

float UUAIAction_Socialize::Score(AAIController* Controller, APawn* Pawn)
{
	// Call the parent class Score method.
	Super::Score(Controller, Pawn);

	// Try to cast to SimPawn.
	const ASimPawn* Sim = Cast<ASimPawn>(Pawn);
	if(!Sim)
	{
		// Log a warning if the cast fails.
		UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Socialize::Score - Context is not a SimPawn"));
		return 0.f;
	}

	// Return loneliness.
	return Sim->GetLoneliness();
}

void UUAIAction_Socialize::Enter(AAIController* Controller, APawn* Pawn)
{
	// Call the parent class Enter method.
	Super::Enter(Controller, Pawn);

	// Try to cast to SimPawn.
	ASimPawn* Sim = Cast<ASimPawn>(Pawn);
	if(!Sim)
	{
		// Log a warning if the cast fails.
		UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Socialize::Enter - Pawn is not a SimPawn"));
		return;
	}

	// Reduce loneliness.
	Sim->SetLoneliness(FMath::Max(0.f, Sim->GetLoneliness() - 50.f));
}
