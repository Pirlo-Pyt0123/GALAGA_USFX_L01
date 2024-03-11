// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaReabastecimiento.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaReabastecimiento : public ANaveEnemiga
{
	GENERATED_BODY()
	
private:
	int EscudoAdicional;
	int Seguridad;

public:
	ANaveEnemigaReabastecimiento();
	FORCEINLINE int GetEscudoAdicional() const { return EscudoAdicional; }
	FORCEINLINE int GetSeguridad() const { return Seguridad; }

	FORCEINLINE void SetEscudoAdicional(int _EscudoAdicional) { EscudoAdicional = _EscudoAdicional; }
	FORCEINLINE void SetSeguridad(int _Seguridad) { Seguridad = _Seguridad; }

protected:
	virtual void mover();
	virtual void destruirse();
	virtual void Disparar(bool bDisparar);
	virtual void Escapar();
	
};
