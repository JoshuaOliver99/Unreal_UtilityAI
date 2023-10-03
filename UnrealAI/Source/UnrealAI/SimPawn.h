// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SimPawn.generated.h"

UCLASS()
class UNREALAI_API ASimPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASimPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;





// ---------- Custom code ----------

public:
	// Attributes representing the current state of each need.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float Hunger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float Tiredness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float Loneliness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float Dirtiness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float Bladder;


public:
	// Getter and Setter for Hunger.
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetHunger() const { return Hunger; }
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetHunger(float Value) { Hunger = FMath::Clamp(Value, 0.f, 100.f); }

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetTiredness() const { return Tiredness; }
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetTiredness(float Value) { Tiredness = FMath::Clamp(Value, 0.f, 100.f); }
	
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetLoneliness() const { return Loneliness; }
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetLoneliness(float Value) { Loneliness = FMath::Clamp(Value, 0.f, 100.f); }
	
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetDirtiness() const { return Dirtiness; }
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetDirtiness(float Value) { Dirtiness = FMath::Clamp(Value, 0.f, 100.f); }

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetBladder() const { return Bladder; }
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetBladder(float Value) { Bladder = FMath::Clamp(Value, 0.f, 100.f); }
};
