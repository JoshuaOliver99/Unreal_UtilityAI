// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SimsGameMode.generated.h"

class UUW_SimsStatDisplay;
class ASimPawn;

/**
 * 
 */
UCLASS()
class UNREALAI_API ASimsGameMode : public AGameModeBase
{
	GENERATED_BODY()

	ASimsGameMode();

public:
	
	// Override the BeginPlay method
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY()
	ASimPawn* SimPawnRef;

	// Reference to the widget instance
	UUW_SimsStatDisplay* SimsStatDisplayWidget;

	// Class of the Blueprint version of the SimsStatDisplayWidget
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUW_SimsStatDisplay> SimsStatDisplayWidgetClass;

};
