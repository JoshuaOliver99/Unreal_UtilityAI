// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseItem.generated.h"

class UBaseItemAction;

UCLASS()
class UNREALAI_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;




	// ---------- Getters & Setters ----------
public:
	// Function to get the display name of the item
	UFUNCTION(BlueprintPure, Category = "Item Properties")
	FString GetDisplayName() const {return Name;};

	
	// Function to check if item is interactable
	UFUNCTION(BlueprintPure, Category = "Interactions")
	bool IsInteractable() const {return Actions.Num() > 0;};

	// Function to get the list of actions that can be performed with/on this item
	UFUNCTION(BlueprintPure, Category = "Interactions")
	TArray<TSubclassOf<UBaseItemAction>> GetActions() const {return Actions;};
	
	
	
	// ---------- Core properties ----------
protected:
	// The display name of the item
	UPROPERTY(EditAnywhere ,BlueprintReadWrite, Category = "Item Properties")
	FString Name;

	
	// List of actions that can be performed with/on this item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
	TArray<TSubclassOf<UBaseItemAction>> Actions;

	
	// Mesh for the physical representation of the item
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	UStaticMeshComponent* ItemMesh;

	// Generic collider for the item. Specific colliders can be added in subclasses
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	UPrimitiveComponent* ItemCollider;
};
