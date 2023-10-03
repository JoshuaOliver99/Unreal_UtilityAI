#include "UAIAction_CleanSelf.h"
#include "UnrealAI/SimPawn.h"

float UUAIAction_CleanSelf::Score(AAIController* Controller, APawn* Pawn)
{
	Super::Score(Controller, Pawn);

	// Try to cast to SimPawn.
	const ASimPawn* Sim = Cast<ASimPawn>(Pawn);
	if(!Sim)
	{
		UE_LOG(LogTemp, Warning, TEXT("UUAIAction_CleanSelf::Score - Pawn is not a SimPawn"));
		return 0.f;
	}
	
	// Return dirtiness value.
	return Sim->GetDirtiness();
}

void UUAIAction_CleanSelf::Enter(AAIController* Controller, APawn* Pawn)
{
	Super::Enter(Controller, Pawn);

	// Try to cast to SimPawn.
	ASimPawn* Sim = Cast<ASimPawn>(Pawn);
	if(!Sim)
	{
		UE_LOG(LogTemp, Warning, TEXT("UUAIAction_CleanSelf::Enter - Pawn is not a SimPawn"));
		return;
	}

	// Reduce dirtiness value.
	Sim->SetDirtiness(FMath::Max(0.f, Sim->GetDirtiness() - 50.f));
}
