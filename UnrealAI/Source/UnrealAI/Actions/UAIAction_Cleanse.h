#pragma once

#include "CoreMinimal.h"
#include "BaseUAIAction.h"
#include "UAIAction_Cleanse.generated.h"

/**
 * A basic utility AI clean self action.
 */
UCLASS()
class UNREALAI_API UUAIAction_Cleanse : public UBaseUAIAction
{
	GENERATED_BODY()

public:
	// Method for scoring the clean self action, can be overridden in Blueprint.
	UFUNCTION(meta = (DisplayName = "Score"))
	virtual float Score(AAIController* Controller, APawn* Pawn) override;
	
	// Method for entering the clean self action, can be overridden in Blueprint.
	UFUNCTION(meta = (DisplayName = "Enter"))
	virtual void Enter(AAIController* Controller, APawn* Pawn) override;
};
