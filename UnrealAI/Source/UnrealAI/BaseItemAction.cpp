// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItemAction.h"

bool UBaseItemAction::CanPerform() const
{
	return false;
}

void UBaseItemAction::Perform()
{
}

float UBaseItemAction::GetUtilityScore() const
{
	return 0;
}
