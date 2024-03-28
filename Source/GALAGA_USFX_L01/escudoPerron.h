// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "escudoPerron.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AescudoPerron : public AActor
{
	GENERATED_BODY()
private:

	UPROPERTY(VisibleAnywhere)
   float coolTime = 0;

   UPROPERTY(VisibleAnywhere)
   class USphereComponent* CollisionComponent;

	
public:	
	// Sets default values for this actor's properties
	AescudoPerron();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* shieldMesh;

	//Metodo 

	FORCEINLINE void desaparecer(float _coolTime);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float DistanciaEscudoNave;
	UFUNCTION()
	void OnShieldOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);





public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	



};
