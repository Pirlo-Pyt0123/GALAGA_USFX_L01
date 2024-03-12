// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaNodrizaComando.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaNodrizaComando : public ANaveEnemigaNodriza
{
	GENERATED_BODY()
private:
	int Agresividad;

public:

	ANaveEnemigaNodrizaComando();

	FORCEINLINE int GetAgresividad() const { return Agresividad; }

	FORCEINLINE void SetAgresividad(int _Agresividad) { Agresividad = _Agresividad; }


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void Mover(float DeltaTime)override;
	virtual void destruirse();
	virtual void Disparar(bool bAtacar);
};
