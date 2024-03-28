
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "Particles/ParticleSystemComponent.h" // Incluir la cabecera para componentes de partículas
#include "naveEnemigaCaza.generated.h"


UCLASS()
class GALAGA_USFX_L01_API AnaveEnemigaCaza : public ANaveEnemiga
{
	GENERATED_BODY()
protected:
	//int bandera = 1;
	int cantidadBombas;

	uint32 bDisparando : 1;
	FTimerHandle TimerHandle_ShotTimerExpired;
	
	//efecto 
	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	class UParticleSystem* ExplosionParticles;

	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
	class USoundBase* ExploSound;

public:
	AnaveEnemigaCaza();

	UPROPERTY(category = GamePlay, EditAnywhere, BlueprintReadWrite)
    FVector GunOfsset;

	UPROPERTY(category = GamePlay, EditAnywhere, BlueprintReadWrite)
	float FireRate;


	FORCEINLINE int GetCantidadBombas() const { return cantidadBombas; }
	FORCEINLINE void SetCantidadBombas(int _cantidadBombas) { cantidadBombas = _cantidadBombas; }
	
	virtual void Tick(float DeltaTime) override;


protected:
	virtual void Mover(float DeltaTime);
	virtual void Disparar(FVector DireccionFuego);
	virtual void Escapar();

public:
	void ShotTimerExpired();
	UFUNCTION()
	void FuncionDeManejoDeColision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};