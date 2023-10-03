// Fill out your copyright notice in the Description page of Project Settings.


#include "UAI_Action_RoamNearPlayer.h"

#include "UAI_Action_MoveToPlayer.h"
#include "Kismet/GameplayStatics.h"

void UUAI_Action_RoamNearPlayer::Spawn(AAIController* Controller)
{
	Super::Spawn(Controller);
	//UE_LOG(LogTemp, Warning, TEXT("%s: Spawn"), *this->GetName());
}

void UUAI_Action_RoamNearPlayer::Tick(float DeltaTime, AAIController* Controller, APawn* Pawn)
{
	Super::Tick(DeltaTime, Controller, Pawn);


	if (Controller->IsFollowingAPath() == false)
	{
		const APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		const float MaxRoamDistance = FMath::RandRange(0.f, 200.f);
		const float Angle = FMath::RandRange(0.f, 360.f) * PI / 180.f;

		const FVector NewLocationOffset = FVector(FMath::Cos(Angle) * MaxRoamDistance, FMath::Sin(Angle) * MaxRoamDistance, 0.f);
		const FVector LocationNearPlayer = PlayerPawn->GetActorLocation() + NewLocationOffset;
	
		Controller->MoveToLocation(LocationNearPlayer);
	}
}

bool UUAI_Action_RoamNearPlayer::CanRun(AAIController* Controller, APawn* Pawn) const
{
	return Super::CanRun(Controller, Pawn);
}

float UUAI_Action_RoamNearPlayer::Score(AAIController* Controller, APawn* Pawn)
{
	//UE_LOG(LogTemp, Warning, TEXT("%s: Score"), *this->GetName());

	
	
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	// ----- Am I aware of the player?
	
	// ----- Am I interested in the player?

	// ----- Am I near enough to roam?
	const float Distance = FVector::Dist(Pawn->GetActorLocation(), PlayerPawn->GetActorLocation());

	
	// TODO: if (PlayerPawn has not moved recently)
	
	if (Distance < 500)
	{
		return 90;
		
		if (Controller->IsFollowingAPath() == false)
		{
			
		}
	}

	
	return Super::Score(Controller, Pawn);
}

void UUAI_Action_RoamNearPlayer::Enter(AAIController* Controller, APawn* Pawn)
{
	Super::Enter(Controller, Pawn);
	
	UE_LOG(LogTemp, Warning, TEXT("%s: Enter"), *this->GetName());

	
	const APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	const float MaxRoamDistance = FMath::RandRange(0.f, 200.f);
	const float Angle = FMath::RandRange(0.f, 360.f) * PI / 180.f;

	const FVector NewLocationOffset = FVector(FMath::Cos(Angle) * MaxRoamDistance, FMath::Sin(Angle) * MaxRoamDistance, 0.f);
	const FVector LocationNearPlayer = PlayerPawn->GetActorLocation() + NewLocationOffset;
	
	Controller->MoveToLocation(LocationNearPlayer);
}

void UUAI_Action_RoamNearPlayer::Exit(AAIController* Controller, APawn* Pawn)
{
	Super::Exit(Controller, Pawn);
	UE_LOG(LogTemp, Warning, TEXT("%s: Exit"), *this->GetName());
}
