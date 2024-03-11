// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "naveEnemigaCaza.h"
#include "naveEnemigaCazaVeloz.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API AnaveEnemigaCazaVeloz : public AnaveEnemigaCaza
{
	GENERATED_BODY()
	
private:
	int turbo;

public:
	AnaveEnemigaCazaVeloz();
	FORCEINLINE int GetTurbo() const { return turbo; }

	FORCEINLINE void SetTurbo(int _Turbo) { turbo = _Turbo; }

protected:
	virtual void Mover();
	virtual void destruirse();
	virtual void Escapar();
};
