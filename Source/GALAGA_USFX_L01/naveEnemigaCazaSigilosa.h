// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "naveEnemigaCaza.h"
#include "naveEnemigaCazaSigilosa.generated.h"

/**
 *
 */
UCLASS()
class GALAGA_USFX_L01_API AnaveEnemigaCazaSigilosa : public AnaveEnemigaCaza
{
	GENERATED_BODY()
	
private:
	int PoderSigilo;

public:

	AnaveEnemigaCazaSigilosa();

	FORCEINLINE int GetPoderSigilo() const { return PoderSigilo; }

	FORCEINLINE void SetPoderSigilo(int _PoderSigilo) { PoderSigilo = _PoderSigilo; }

protected:
	virtual void Mover();
	virtual void destruirse();
	virtual void Escapar();
};
