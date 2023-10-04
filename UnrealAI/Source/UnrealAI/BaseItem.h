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




	// ---------- Added items ----------
	// TODO: Review & Neaten into caegories


	// The display name of the item
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Properties")
	FString Name;

	// List of actions that can be performed with/on this item
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Properties")
	TArray<UBaseItemAction*> Actions;

	


	
	// Mesh for the physical representation of the item
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	UStaticMeshComponent* ItemMesh;

	// Generic collider for the item. Specific colliders can be added in subclasses
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	UPrimitiveComponent* ItemCollider;

	
	// Function to check if item is interactable
	UFUNCTION(BlueprintPure, Category = "Interactions")
	bool IsInteractable() const {return Actions.Num() > 0;};
};
