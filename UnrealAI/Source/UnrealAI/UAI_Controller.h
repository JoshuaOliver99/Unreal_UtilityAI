// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "UAI_Controller.generated.h"

/**
 * 
 */
UCLASS()
class UNREALAI_API AUAI_Controller : public AAIController
{
	GENERATED_BODY()

public:
	
	AUAI_Controller();

public:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UUtilityAIComponent* UtilityAIComponent;
};
