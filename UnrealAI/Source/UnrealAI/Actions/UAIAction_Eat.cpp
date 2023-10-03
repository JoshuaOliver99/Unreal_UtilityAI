#include "UAIAction_Eat.h"
#include "UnrealAI/SimPawn.h"

float UUAIAction_Eat::Score(AAIController* Controller, APawn* Pawn)
{
	Super::Score(Controller, Pawn);

	// Try to cast to SimPawn.
	const ASimPawn* Sim = Cast<ASimPawn>(Pawn);
	if(!Sim)
	{
		UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Eat::Score - Context is not a SimPawn"));
		return 0.f;
	}

	// Return hunger.
	return Sim->GetHunger();
}

void UUAIAction_Eat::Enter(AAIController* Controller, APawn* Pawn)
{
	Super::Enter(Controller, Pawn);

	// Try to cast to SimPawn.
	ASimPawn* Sim = Cast<ASimPawn>(Pawn);
	if(!Sim)
	{
		UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Eat::Enter - Pawn is not a SimPawn"));
		return;
	}

	// Reduce hunger.
	Sim->SetHunger(FMath::Max(0.f, Sim->GetHunger() - 50.f));
}