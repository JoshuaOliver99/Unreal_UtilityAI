// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseItemAction.generated.h"

class ABaseItem;

/**
 * Base class for all item-specific actions
 */

UCLASS(Blueprintable)
class UNREALAI_API UBaseItemAction : public UObject
{
	GENERATED_BODY()



	// ---------- Constructors ----------
public:
	// Default constructor
	UBaseItemAction();

	


	// ---------- Getters & Setters ----------
public:
	// Get name of this action
	UFUNCTION(BlueprintPure, Category = "Action Properties")
	FString GetActionName() const { return Name; }


	// Get the base alteration to Hunger when this action is performed
	UFUNCTION(Category = "Action Properties")
	float GetHunger() const { return Hunger; }

	// Get the base alteration to Tiredness when this action is performed
	UFUNCTION(BlueprintPure, Category = "Action Properties")
	float GetTiredness() const { return Tiredness; }

	// Get the base alteration to Loneliness when this action is performed
	UFUNCTION(BlueprintPure, Category = "Action Properties")
	float GetLoneliness() const { return Loneliness; }

	// Get the base alteration to Dirtiness when this action is performed
	UFUNCTION(BlueprintPure, Category = "Action Properties")
	float GetDirtiness() const { return Dirtiness; }

	// Get the base alteration to Bladder when this action is performed
	UFUNCTION(BlueprintPure, Category = "Action Properties")
	float GetBladder() const { return Bladder; }


	
	// ---------- Core properties ----------
protected:
	// The display name of the item action
	UPROPERTY(EditAnywhere ,BlueprintReadWrite, Category = "Action Properties")
	FString Name = "Unnamed Action";

	
	// The base alteration to Hunger when this action is performed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Properties")
	float Hunger = 0;

	// The base alteration to Tiredness when this action is performed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Properties")
	float Tiredness = 0;

	// The base alteration to Loneliness when this action is performed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Properties")
	float Loneliness = 0;

	// The base alteration to Dirtiness when this action is performed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Properties")
	float Dirtiness	= 0;

	// The base alteration to Bladder when this action is performed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Properties")
	float Bladder = 0;



// TODO: Review these properties
	
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
