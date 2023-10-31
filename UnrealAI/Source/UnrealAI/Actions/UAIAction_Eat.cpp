#include "UAIAction_Eat.h"

#include "Kismet/KismetSystemLibrary.h"
#include "UnrealAI/BaseItem.h"
#include "UnrealAI/BaseItemAction.h"
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

void UUAIAction_Eat::InitiateAvailableActionEvaluationTimer()
{
	//Super::InitiateAvailableActionEvaluationTimer();


	// A list of all the actions that can be evaluated.
	//AvailableActions;

	// Delay before updating the available actions array.
	//AvailableActionEvaluationDelay = 5.f;
	
	// The radius of the sphere used to find all available item actions
	//AvailableActionEvaluationRadius = 1000.f;



	// TODO: Get all available item actions
	/* Do this by: check for all BaseItem the radius and evaluate each each item for BaseItemActions.
	 * Cull all BaseItemAction with a positive score (i.e. not satisfying a need),
	 * then add the remainders to the AvailableActions array
	*/


	// TODO remove debug log that the timer has been initiated
	UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Eat::InitiateAvailableActionEvaluationTimer - Timer has been initiated!!!"));

	// TODO: Probably remove this as the initial Spawn() function should have already set the Sim
	// Break clause - only allow sim pawns
	if (!Sim)
	{
		UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Eat::InitiateAvailableActionEvaluationTimer - Sim is null"));
		return;
	}
	
	
	// Using UKismetSystemLibrary::SphereOverlapActors and the sim as the point of origin, get all the BaseItems using the AvailableActionEvaluationRadius
	TArray<AActor*> items;
	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes;
	objectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldDynamic));
	UKismetSystemLibrary::SphereOverlapActors(
		GetWorld(),
		Sim->GetActorLocation(),
		AvailableActionEvaluationRadius,
		objectTypes,
		TSubclassOf<AActor>(ABaseItem::StaticClass()),
		TArray<AActor*>(),
		items
		);
	
	
	// For each item, get all the BaseItemActions
	for (AActor* item : items)
	{
		// TODO: remove debug log that an actor has been found
		//UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Eat::InitiateAvailableActionEvaluationTimer - Actor has been found!!!"));	


		
		// Get the BaseItem
		ABaseItem* baseItem = Cast<ABaseItem>(item);
		if (!baseItem)
		{
			UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Eat::InitiateAvailableActionEvaluationTimer - Item is not a BaseItem"));
			continue;
		}

		// Get the interaction status
		if (!baseItem->IsInteractable())
		{
			UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Eat::InitiateAvailableActionEvaluationTimer - Item is not interactable"));
			continue;
		}

		// Get the list of actions
		TArray<TSubclassOf<UBaseItemAction>> actions = baseItem->GetActions();

		// Evaluate each action for a negative hunger score
		for (TSubclassOf<UBaseItemAction> action : actions)
		{
			// Get the action
			UBaseItemAction* baseItemAction = action.GetDefaultObject();
			if (!baseItemAction)
			{
				UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Eat::InitiateAvailableActionEvaluationTimer - Action is not a BaseItemAction"));
				continue;
			}

			// Get the score
			float score = baseItemAction->GetHunger();

			// If the score is negative, add it to the available actions
			if (score < 0.f)
			{
				AvailableActions.Add(action);

				// TODO: remove debug log that the action has been added.
				UE_LOG(LogTemp, Warning, TEXT("UUAIAction_Eat::InitiateAvailableActionEvaluationTimer - Action has been added!!!"));
			}
		}
	}
}
