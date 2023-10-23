// Fill out your copyright notice in the Description page of Project Settings.


#include "SimsGameMode.h"

#include "EngineUtils.h"
#include "SimPawn.h"
#include "UW_SimsStatDisplay.h"

ASimsGameMode::ASimsGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASimsGameMode::BeginPlay()
{
	Super::BeginPlay();  // Call the parent class's BeginPlay method

	// Get the SimPawn reference
	for (TActorIterator<ASimPawn> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		SimPawnRef = *ActorItr;
		break;
	}

	// Get the PlayerController to create and display the widget
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController && SimPawnRef && SimsStatDisplayWidgetClass)
	{
		SimsStatDisplayWidget = CreateWidget<UUW_SimsStatDisplay>(PlayerController, SimsStatDisplayWidgetClass);
		if (SimsStatDisplayWidget)
		{
			SimsStatDisplayWidget->AddToViewport();

			// debug
			UE_LOG(LogTemp, Warning, TEXT("Widget created and added to viewport"));
		}
	}
}

void ASimsGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Update the Sim stats in the widget
	if (SimsStatDisplayWidget && SimPawnRef)
	{
		SimsStatDisplayWidget->UpdateStats(
			SimPawnRef->GetHunger() / 100,
			SimPawnRef->GetTiredness() / 100,
			SimPawnRef->GetLoneliness() / 100,
			SimPawnRef->GetDirtiness() / 100,
			SimPawnRef->GetBladder() / 100
		);
	}
}
