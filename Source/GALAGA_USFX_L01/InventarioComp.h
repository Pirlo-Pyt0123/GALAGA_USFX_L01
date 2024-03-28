// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MunicionBeta.h"

#include "InventarioComp.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_L01_API UInventarioComp : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<AMunicionBeta*> CurrentInventory;
	UFUNCTION()
	int32 AddToInventory(AMunicionBeta* ActorToAdd);
	UFUNCTION()
	void RemoveFromInventory(AMunicionBeta* ActorToRemove);
	// Sets default values for this component's properties
	UInventarioComp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
