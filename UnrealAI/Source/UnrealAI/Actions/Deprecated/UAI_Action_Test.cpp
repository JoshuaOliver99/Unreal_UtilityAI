// Fill out your copyright notice in the Description page of Project Settings.


#include "UAI_Action_Test.h"

void UUAI_Action_Test::Spawn(AAIController* Controller)
{
	Super::Spawn(Controller);
	UE_LOG(LogTemp, Warning, TEXT("%s: Spawn"), *this->GetName());
}

void UUAI_Action_Test::Tick(float DeltaTime, AAIController* Controller, APawn* Pawn)
{
	Super::Tick(DeltaTime, Controller, Pawn);
	UE_LOG(LogTemp, Warning, TEXT("%s: Tick"), *this->GetName());
}

bool UUAI_Action_Test::CanRun(AAIController* Controller, APawn* Pawn) const
{
	UE_LOG(LogTemp, Warning, TEXT("%s: CanRun"), *this->GetName());
	return Super::CanRun(Controller, Pawn);
}

float UUAI_Action_Test::Score(AAIController* Controller, APawn* Pawn)
{
	UE_LOG(LogTemp, Warning, TEXT("%s: Score"), *this->GetName());
	return Super::Score(Controller, Pawn);
}

void UUAI_Action_Test::Enter(AAIController* Controller, APawn* Pawn)
{
	Super::Enter(Controller, Pawn);
	UE_LOG(LogTemp, Warning, TEXT("%s: Enter"), *this->GetName());
}

void UUAI_Action_Test::Exit(AAIController* Controller, APawn* Pawn)
{
	Super::Exit(Controller, Pawn);
	UE_LOG(LogTemp, Warning, TEXT("%s: Exit"), *this->GetName());
}
