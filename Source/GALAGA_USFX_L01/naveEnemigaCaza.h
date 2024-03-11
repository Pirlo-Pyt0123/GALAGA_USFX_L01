
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "naveEnemigaCaza.generated.h"




UCLASS()
class GALAGA_USFX_L01_API AnaveEnemigaCaza : public ANaveEnemiga
{
	GENERATED_BODY()
private:

	int cantidadBombas;

public:
	AnaveEnemigaCaza();

	FORCEINLINE int GetCantidadBombas() const { return cantidadBombas; }
	FORCEINLINE void SetCantidadBombas(int _cantidadBombas) { cantidadBombas = _cantidadBombas; }
	


protected:
	virtual void Mover();
	virtual void destruirse();
	virtual void Escapar();

};