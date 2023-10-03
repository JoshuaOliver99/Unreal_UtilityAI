#include "UAIAction_UseToilet.h"
#include "UnrealAI/SimPawn.h"

float UUAIAction_UseToilet::Score(AAIController* Controller, APawn* Pawn)
{
	Super::Score(Controller, Pawn);

	// Try to cast to SimPawn.
	const ASimPawn* Sim = Cast<ASimPawn>(Pawn);
	if(!Sim)
	{
		UE_LOG(LogTemp, Warning, TEXT("UUAIAction_UseToilet::Score - Pawn is not a SimPawn"));
		return 0.f;
	}

	// Return bladder value.
	return Sim->GetBladder();
}

void UUAIAction_UseToilet::Enter(AAIController* Controller, APawn* Pawn)
{
	Super::Enter(Controller, Pawn);

	// Try to cast to SimPawn.
	ASimPawn* Sim = Cast<ASimPawn>(Pawn);
	if(!Sim)
	{
		UE_LOG(LogTemp, Warning, TEXT("UUAIAction_UseToilet::Enter - Pawn is not a SimPawn"));
		return;
	}

	// Reduce bladder value.
	Sim->SetBladder(FMath::Max(0.f, Sim->GetBladder() - 50.f));
}
