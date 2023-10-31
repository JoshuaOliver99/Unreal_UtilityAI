#pragma once

#include "CoreMinimal.h"
#include "BaseUAIAction.h"
#include "UAIAction_Eat.generated.h"

/**
 * A basic utility AI eat action.
 */
UCLASS()
class UNREALAI_API UUAIAction_Eat : public UBaseUAIAction
{
	GENERATED_BODY()

public:
	UFUNCTION(meta = (DisplayName = "Score"))
	virtual float Score(AAIController* Controller, APawn* Pawn) override;
	
	UFUNCTION(meta = (DisplayName = "Enter"))
	virtual void Enter(AAIController* Controller, APawn* Pawn) override;


protected:
	// override the InitiateAvailableActionEvaluationTimer
	virtual void InitiateAvailableActionEvaluationTimer() override;
};
