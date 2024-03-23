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
	int time = 0;
	
public:	
	// Sets default values for this actor's properties
	AescudoPerron();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* shieldMesh;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float DistanciaEscudoNave;


	/*UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);*/

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void desaparecer();
	void reaparecer();


	
};
