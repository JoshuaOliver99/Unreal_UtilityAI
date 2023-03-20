// Fill out your copyright notice in the Description page of Project Settings.


#include "UAI_Action_MoveToPlayer.h"

#include "UAI_PlayerController.h"
#include "Kismet/GameplayStatics.h"

void UUAI_Action_MoveToPlayer::Spawn(AAIController* Controller)
{
	Super::Spawn(Controller);
	//UE_LOG(LogTemp, Warning, TEXT("%s: Spawn"), *this->GetName());
}

void UUAI_Action_MoveToPlayer::Tick(float DeltaTime, AAIController* Controller, APawn* Pawn)
{
	Super::Tick(DeltaTime, Controller, Pawn);
	//UE_LOG(LogTemp, Warning, TEXT("%s: Tick"), *this->GetName());
}

bool UUAI_Action_MoveToPlayer::CanRun(AAIController* Controller, APawn* Pawn) const
{
	//UE_LOG(LogTemp, Warning, TEXT("%s: CanRun"), *this->GetName());
	return Super::CanRun(Controller, Pawn);
}

float UUAI_Action_MoveToPlayer::Score(AAIController* Controller, APawn* Pawn)
{
	//UE_LOG(LogTemp, Warning, TEXT("%s: Score"), *this->GetName());

	// ----- Am I aware of the player?


	
	// ----- Am I interested in the player?
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	
	// Get affiliation type
	// switch (Controller.GetAffiliation())

	// case: Ally
	
	// case: Enemy
	
	// case: Neutral



	
	// ----- Am I already at the player?
	
	const float Distance = FVector::Dist(Pawn->GetActorLocation(), PlayerPawn->GetActorLocation());
	if (Distance > 300)
	{
		return 80;
	}
	
	return Super::Score(Controller, Pawn);
}

void UUAI_Action_MoveToPlayer::Enter(AAIController* Controller, APawn* Pawn)
{
	Super::Enter(Controller, Pawn);

	
	UE_LOG(LogTemp, Warning, TEXT("%s: Enter"), *this->GetName());
	
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	Controller->MoveToActor(PlayerPawn);
}

void UUAI_Action_MoveToPlayer::Exit(AAIController* Controller, APawn* Pawn)
{
	Super::Exit(Controller, Pawn);
	UE_LOG(LogTemp, Warning, TEXT("%s: Exit"), *this->GetName());
}
