// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_SimsStatDisplay.generated.h"

class UProgressBar;

/**
 * 
 */

//UCLASS()
UCLASS(Blueprintable, BlueprintType)
class UNREALAI_API UUW_SimsStatDisplay : public UUserWidget
{
	GENERATED_BODY()


protected:
	
	// references to the progress bars
	UProgressBar* HungerBarRef;
	UProgressBar* TirednessBarRef;
	UProgressBar* LonelinessBarRef;
	UProgressBar* DirtinessBarRef;
	UProgressBar* BladderBarRef;

	//UPROPERTY(BlueprintReadWrite, meta = (BindWidget))

	
public:
	// Sets the progress of the hunger bar.
	UFUNCTION(BlueprintCallable, Category = "Update")
	void SetHungerBarProgress(float HungerPercentage);

	// Sets the progress of the tiredness bar.
	UFUNCTION(BlueprintCallable, Category = "Update")
	void SetTirednessBarProgress(float TirednessPercentage);

	// Sets the progress of the loneliness bar.
	UFUNCTION(BlueprintCallable, Category = "Update")
	void SetLonelinessBarProgress(float LonelinessPercentage);

	// Sets the progress of the dirtiness bar.
	UFUNCTION(BlueprintCallable, Category = "Update")
	void SetDirtinessBarProgress(float DirtinessPercentage);

	// Sets the progress of the bladder bar.
	UFUNCTION(BlueprintCallable, Category = "Update")
	void SetBladderBarProgress(float BladderPercentage);

	UFUNCTION(BlueprintCallable, Category = "Update")
	void UpdateStats(float Hunger, float Tiredness, float Loneliness, float Dirtiness, float Bladder)
	{
		SetHungerBarProgress(Hunger);
		SetTirednessBarProgress(Tiredness);
		SetLonelinessBarProgress(Loneliness);
		SetDirtinessBarProgress(Dirtiness);
		SetBladderBarProgress(Bladder);
	}
	
protected:
	// Called when the widget is constructed.
	virtual void NativeConstruct() override;

	// Gets the reference to the hunger bar widget.
	UProgressBar* GetHungerBarRef() const {return HungerBarRef;};

	// Gets the reference to the tiredness bar widget.
	UProgressBar* GetTirednessBarRef() const {return TirednessBarRef;}

	// Gets the reference to the loneliness bar widget.
	UProgressBar* GetLonelinessBarRef() const {return LonelinessBarRef;}

	// Gets the reference to the dirtiness bar widget.
	UProgressBar* GetDirtinessBarRef() const {return DirtinessBarRef;}

	// Gets the reference to the bladder bar widget.
	UProgressBar* GetBladderBarRef() const {return BladderBarRef;}

	
	UWidget* FindWidgetRecursive(UWidget* Widget, const FName& Name);
};
