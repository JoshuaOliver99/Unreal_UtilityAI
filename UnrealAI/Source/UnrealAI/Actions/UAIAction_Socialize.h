#pragma once

#include "CoreMinimal.h"
#include "BaseUAIAction.h"
#include "UAIAction_Socialize.generated.h"

/**
 * A basic utility AI socialize action.
 */
UCLASS()
class UNREALAI_API UUAIAction_Socialize : public UBaseUAIAction
{
	GENERATED_BODY()

public:
	// Blueprint event for scoring the socialize action.
	UFUNCTION(meta = (DisplayName = "Score"))
	virtual float Score(AAIController* Controller, APawn* Pawn) override;
    
	// Blueprint event for entering the socialize action.
	UFUNCTION(meta = (DisplayName = "Enter"))
	virtual void Enter(AAIController* Controller, APawn* Pawn) override;
};
