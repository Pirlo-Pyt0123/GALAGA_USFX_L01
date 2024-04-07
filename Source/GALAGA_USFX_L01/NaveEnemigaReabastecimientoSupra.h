// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaReabastecimientoSupra.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaReabastecimientoSupra : public ANaveEnemigaReabastecimiento
{
	GENERATED_BODY()
	
private:
	float tamanoAumentado;
	int bandera = 1;
	
public:
	virtual void Tick(float DeltaTime)override;
	ANaveEnemigaReabastecimientoSupra();
	FORCEINLINE int GetTamanoAumentado() const { return tamanoAumentado; }

	FORCEINLINE void SetTamanoAumentado(int _tamanoAumentado) { tamanoAumentado = _tamanoAumentado; }

protected:
	virtual void Mover(float DeltaTime)override;
	virtual void destruirse();
	virtual void Escapar();
	

   
};
