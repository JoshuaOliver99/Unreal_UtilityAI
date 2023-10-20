// Fill out your copyright notice in the Description page of Project Settings.


#include "SimPawn.h"

// Sets default values
ASimPawn::ASimPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set default values for attributes.
	Hunger = 50.f;
	Tiredness = 50.f;
	Loneliness = 50.f;
	Dirtiness = 50.f;
	Bladder = 50.f;
}

// Called when the game starts or when spawned
void ASimPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASimPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Increment Hunger, Tiredness, Bladder, Loneliness, and Dirtiness over time.
	Hunger = FMath::Clamp(Hunger + DeltaTime * 10.f, 0.f, 100.f);
	Tiredness = FMath::Clamp(Tiredness + DeltaTime * 10.f, 0.f, 100.f);
	Bladder = FMath::Clamp(Bladder + DeltaTime * 5.f, 0.f, 100.f);
	Loneliness = FMath::Clamp(Loneliness + DeltaTime * 5.f, 0.f, 100.f);
	Dirtiness = FMath::Clamp(Dirtiness + DeltaTime * 10.f, 0.f, 100.f);

	// Debug log the current values.
	//UE_LOG(LogTemp, Log, TEXT("Hunger: %f, Tiredness: %f, Loneliness: %f, Dirtiness: %f"), Hunger, Tiredness, Loneliness, Dirtiness);
}

// Called to bind functionality to input
void ASimPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

