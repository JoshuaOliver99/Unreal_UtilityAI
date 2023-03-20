// Fill out your copyright notice in the Description page of Project Settings.


#include "UAI_Controller.h"

#include "UtilityAIComponent.h"

AUAI_Controller::AUAI_Controller()
{
	UtilityAIComponent = CreateDefaultSubobject<UUtilityAIComponent>(TEXT("Utility AI Component"));
}