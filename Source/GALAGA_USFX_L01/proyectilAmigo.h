// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "proyectilAmigo.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AproyectilAmigo : public AActor
{
	GENERATED_BODY()
private:

public:	
	// Sets default values for this actor's properties
	AproyectilAmigo();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* ProjectileMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
	TSubclassOf<AproyectilAmigo> ProjectileClass;

   



   


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
