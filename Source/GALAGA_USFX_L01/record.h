// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "record.generated.h"

UCLASS()
class GALAGA_USFX_L01_API Arecord : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	float recordMaximo;
	float recordActual;
	FString playerName;
	float insertarVida;
	

	 
	 
public:

	FORCEINLINE float GetRecordmaximo() const { return recordMaximo; }
	FORCEINLINE float GetRecordactual() const { return recordActual; }
	FORCEINLINE FString GetPlayername() const { return playerName; }
	FORCEINLINE float GetInsertarVida() const { return insertarVida; }	

	FORCEINLINE void SetRecordmaximo(float _recordmaximo) { recordMaximo = _recordmaximo; }
	FORCEINLINE void SetRecordactual(float _recordactual) { recordActual = _recordactual; }
	FORCEINLINE void SetPlayername(FString _nombre) { playerName = _nombre; }
	FORCEINLINE void SetInsertarVida(float _insertarVida) { insertarVida = _insertarVida; }
public:	
	// Sets default values for this actor's properties
	Arecord();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	
};
