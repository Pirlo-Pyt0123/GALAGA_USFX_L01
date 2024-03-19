// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaTransporteDesplegable.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaTransporteDesplegable : public ANaveEnemigaTransporte
{
	GENERATED_BODY()
private:
	float tiempoDesplegar;
	int bandera = 1;
	int contador = 0;

public:
	virtual void Tick(float DeltaTime) override;
	ANaveEnemigaTransporteDesplegable();
	FORCEINLINE int GetTiempoDesplegable() const { return tiempoDesplegar; }

	FORCEINLINE void SetTiempoDesplegable(int _tiempoDesplegar) { tiempoDesplegar = _tiempoDesplegar; }

protected:
	virtual void mover(float DeltaTime);
	virtual void destruirse();
	void crearNaves();
	
};
