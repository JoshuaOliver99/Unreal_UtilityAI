#pragma once

#include "CoreMinimal.h"
#include "BaseUAIAction.h"
#include "UAIAction_Excrete.generated.h"

class UCurveFloat;

/**
 * A basic utility AI use toilet action.
 */
UCLASS()
class UNREALAI_API UUAIAction_Excrete : public UBaseUAIAction
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
