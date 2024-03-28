// Fill out your copyright notice in the Description page of Project Settings.


#include "InventarioComp.h"

int32 UInventarioComp::AddToInventory(AMunicionBeta* ActorToAdd)
{
	return CurrentInventory.Add(ActorToAdd);
}

void UInventarioComp::RemoveFromInventory(AMunicionBeta* ActorToRemove)
{
	CurrentInventory.Remove(ActorToRemove);
}

// Sets default values for this component's properties
UInventarioComp::UInventarioComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventarioComp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventarioComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

