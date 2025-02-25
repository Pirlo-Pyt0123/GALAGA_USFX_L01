// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "vidas.generated.h"

UCLASS()
class GALAGA_USFX_L01_API Avidas : public AActor
{
	GENERATED_BODY()
protected:
	float vidaMaxima;
	float vidaActual;
	float sinVida;
	FVector posicion;
	float temporizador = 0;

	UPROPERTY(EditAnywhere)
	TMap<FString, int> tablavidas;


public:
	FORCEINLINE float GetVidamaxima() const { return vidaMaxima; }
	FORCEINLINE float GetVidaactual() const { return vidaActual; }
	FORCEINLINE float GetSinvida() const { return sinVida; }
	
	

	FORCEINLINE void SetVidamaxima(float _vidamaxima) { vidaMaxima = _vidamaxima; }
	FORCEINLINE void SetRecordactual(float _vidaactual) { vidaActual = _vidaactual; }
	FORCEINLINE void SetSinvida(float _sinvida) { sinVida = _sinvida; }


	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }
	FORCEINLINE void CalcularVida(FString, int);
	FORCEINLINE void InsertarVida(FString);
	FORCEINLINE void EliminarVida(FString);
	FORCEINLINE void ModificarVida(FString, int);
	FORCEINLINE void ListarVida();
	FORCEINLINE void Getcorazones();
	FORCEINLINE void Getescudos();




public:	
	// Sets default values for this actor's properties
	Avidas();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
