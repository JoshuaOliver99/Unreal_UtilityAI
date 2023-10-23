// Fill out your copyright notice in the Description page of Project Settings.


#include "UW_SimsStatDisplay.h"

#include "Components/PanelWidget.h"
#include "Components/ProgressBar.h"


void UUW_SimsStatDisplay::NativeConstruct()
{
	Super::NativeConstruct();
	
	//  Get the references to the progress bars. Find root widget and start the recursive search from there
	if (UWidget* RootWidget = GetRootWidget())
	{
		HungerBarRef = Cast<UProgressBar>(FindWidgetRecursive(RootWidget, TEXT("HungerBar")));
		TirednessBarRef = Cast<UProgressBar>(FindWidgetRecursive(RootWidget, TEXT("TirednessBar")));
		LonelinessBarRef = Cast<UProgressBar>(FindWidgetRecursive(RootWidget, TEXT("LonelinessBar")));
		DirtinessBarRef = Cast<UProgressBar>(FindWidgetRecursive(RootWidget, TEXT("DirtinessBar")));
		BladderBarRef = Cast<UProgressBar>(FindWidgetRecursive(RootWidget, TEXT("BladderBar")));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("RootWidget is null"));
	
	
	// Check if the references are valid.
	if (!HungerBarRef) UE_LOG(LogTemp, Warning, TEXT("HungerBarRef is null"));
	if (!TirednessBarRef) UE_LOG(LogTemp, Warning, TEXT("TirednessBarRef is null"));
	if (!LonelinessBarRef) UE_LOG(LogTemp, Warning, TEXT("LonelinessBarRef is null"));
	if (!DirtinessBarRef) UE_LOG(LogTemp, Warning, TEXT("DirtinessBarRef is null"));
	if (!BladderBarRef) UE_LOG(LogTemp, Warning, TEXT("BladderBarRef is null"));
}


void UUW_SimsStatDisplay::SetHungerBarProgress(float HungerPercentage)
{
	if (HungerBarRef)
		HungerBarRef->SetPercent(HungerPercentage);
}

void UUW_SimsStatDisplay::SetTirednessBarProgress(float TirednessPercentage)
{
	if (TirednessBarRef)
		TirednessBarRef->SetPercent(TirednessPercentage);
}

void UUW_SimsStatDisplay::SetLonelinessBarProgress(float LonelinessPercentage)
{
	if (LonelinessBarRef)
		LonelinessBarRef->SetPercent(LonelinessPercentage);
}

void UUW_SimsStatDisplay::SetDirtinessBarProgress(float DirtinessPercentage)
{
	if (DirtinessBarRef)
		DirtinessBarRef->SetPercent(DirtinessPercentage);
}

void UUW_SimsStatDisplay::SetBladderBarProgress(float BladderPercentage)
{
	if (BladderBarRef)
		BladderBarRef->SetPercent(BladderPercentage);
}




// Recursive function to find a widget by name
UWidget* UUW_SimsStatDisplay::FindWidgetRecursive(UWidget* Widget, const FName& Name)
{
	if (Widget)
	{
		if (Widget->GetFName() == Name)
		{
			UE_LOG(LogTemp, Log, TEXT("Widget found: %s"), *(Widget->GetFName().ToString()));
			return Widget;
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Null widget passed to FindWidgetRecursive"));
		return nullptr;
	}

	// Cast to UPanelWidget since it's a common parent class for widgets that can have children
	if (UPanelWidget* PanelWidget = Cast<UPanelWidget>(Widget))
	{
		for (int32 i = 0; i < PanelWidget->GetChildrenCount(); ++i)
		{
			if (UWidget* FoundWidget = FindWidgetRecursive(PanelWidget->GetChildAt(i), Name))
			{
				return FoundWidget;
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Widget %s is not a UPanelWidget"), *(Widget->GetFName().ToString()));
	}

	return nullptr;
}
