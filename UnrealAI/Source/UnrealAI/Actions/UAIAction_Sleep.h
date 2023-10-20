#pragma once

#include "CoreMinimal.h"
#include "BaseUAIAction.h"
#include "UAIAction_Sleep.generated.h"

/**
 * A basic utility AI sleep action.
 */
UCLASS()
class UNREALAI_API UUAIAction_Sleep : public UBaseUAIAction
{
	GENERATED_BODY()

public:
	// Blueprint event for scoring the sleep action.
	UFUNCTION(meta = (DisplayName = "Score"))
	virtual float Score(AAIController* Controller, APawn* Pawn) override;
    
	// Blueprint event for entering the sleep action.
	UFUNCTION(meta = (DisplayName = "Enter"))
	virtual void Enter(AAIController* Controller, APawn* Pawn) override;
};
