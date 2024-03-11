// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaNodriza.generated.h"

/**
 *
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaNodriza : public ANaveEnemiga
{
	GENERATED_BODY()
private:
	int Dureza;
	int EscudoExtra;

public:
	ANaveEnemigaNodriza();

	FORCEINLINE int GetDureza() const { return Dureza; }
	FORCEINLINE int GetEscudoExtra() const { return EscudoExtra; }

	FORCEINLINE void SetDureza(int _Dureza) { Dureza = _Dureza; }
	FORCEINLINE void SetSensores(int _EscudoExtra) { EscudoExtra = _EscudoExtra; }


protected:
	virtual void Mover();
	virtual void destruirse();
	virtual void Disparar(bool bAtacar);

};
