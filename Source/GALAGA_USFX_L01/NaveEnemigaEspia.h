// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaEspia.generated.h"

/**
 *
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaEspia : public ANaveEnemiga
{
	GENERATED_BODY()
	
private:
	
	int Invisibilidad;
	int Sensores;
	
public:
	ANaveEnemigaEspia();

	FORCEINLINE int GetInvisibilidad() const { return Invisibilidad; }
	FORCEINLINE int GetSensores() const { return Sensores; }


	FORCEINLINE void SetInvisibilidad(int _Invisibilidad) { Invisibilidad = _Invisibilidad; }
	FORCEINLINE void SetSensores(int _Sensores) { Sensores = _Sensores; }
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void Mover(float DeltaTime);

	virtual void destruirse();
	virtual void Disparar(bool bDisparar);
	virtual void Escapar();
};
