// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Logros.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ALogros : public AActor
{
	GENERATED_BODY()
private:

	//enum Medallas { ONE, FIVE, TEEN, FIFTEEN, HUNDRED };
	FVector posicion;
	int temporizador = 0;



	//agregar el uso de TMap
	UPROPERTY(EditAnywhere)
	TMap<FString, int> tablavidas;
	




public:
	//getters
	FORCEINLINE FVector GetPosicion() { return posicion; }

	//setters
	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }

	//FORCEINLINE void CalcularVida(FString, int);
	FORCEINLINE void InsertarVida(FString);
	FORCEINLINE void EliminarVida(FString);
	FORCEINLINE void ModificarVida(FString, int);
	FORCEINLINE void ListarVida();
	FORCEINLINE void Getcorazones();
	FORCEINLINE void Getescudos();

public:	
	// Sets default values for this actor's properties
	ALogros();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
