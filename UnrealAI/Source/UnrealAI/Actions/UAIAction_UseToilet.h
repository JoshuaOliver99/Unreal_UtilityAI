#pragma once

#include "CoreMinimal.h"
#include "UtilityAIAction.h"
#include "UAIAction_UseToilet.generated.h"

/**
 * A basic utility AI use toilet action.
 */
UCLASS()
class UNREALAI_API UUAIAction_UseToilet : public UUtilityAIAction
{
	GENERATED_BODY()

public:
	// Method for scoring the use toilet action, can be overridden in Blueprint.
	UFUNCTION(meta = (DisplayName = "Score"))
	virtual float Score(AAIController* Controller, APawn* Pawn) override;
	
	// Method for entering the use toilet action, can be overridden in Blueprint.
	UFUNCTION(meta = (DisplayName = "Enter"))
	virtual void Enter(AAIController* Controller, APawn* Pawn) override;
};
