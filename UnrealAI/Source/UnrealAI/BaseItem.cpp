// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItem.h"

#include "Components/SphereComponent.h"


// Sets default values
ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create and attach a static mesh component
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	RootComponent = ItemMesh;

	// Create and attach a generic collider component
	ItemCollider = CreateDefaultSubobject<USphereComponent>(TEXT("ItemCollider"));
	ItemCollider->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

