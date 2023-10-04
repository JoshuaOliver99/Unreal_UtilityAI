// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseItemAction.generated.h"

class ABaseItem;

/**
 * Base class for all item-specific actions
 */
UCLASS()
class UNREALAI_API UBaseItemAction : public UObject
{
	GENERATED_BODY()
	
public:
	// Reference to the item associated with this action
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Action Properties")
	ABaseItem* Item;

	// Reference to the actor performing the action
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Action Properties")
	AActor* Actor;

	// Virtual method to check if this action can be performed
	UFUNCTION(BlueprintCallable, Category = "Action Methods")
	virtual bool CanPerform() const;

	// Virtual method to perform this action
	UFUNCTION(BlueprintCallable, Category = "Action Methods")
	virtual void Perform();

	// Virtual method to get the utility score of this action
	UFUNCTION(BlueprintCallable, Category = "Action Methods")
	virtual float GetUtilityScore() const;
};
