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

public:
	ANaveEnemigaReabastecimientoSupra();
	FORCEINLINE int GetTamanoAumentado() const { return tamanoAumentado; }

	FORCEINLINE void SetTamanoAumentado(int _tamanoAumentado) { tamanoAumentado = _tamanoAumentado; }

protected:
	virtual void mover();
	virtual void destruirse();
	virtual void Escapar();
	void repara();
	void Crecer();

   
};
