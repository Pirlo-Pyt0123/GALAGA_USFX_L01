// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MunicionBeta.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API AMunicionBeta : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MunicionBetaMesh;
	AMunicionBeta();
	virtual void PickUp();
	virtual void PutDown(FTransform TargetLocation);

	
};
