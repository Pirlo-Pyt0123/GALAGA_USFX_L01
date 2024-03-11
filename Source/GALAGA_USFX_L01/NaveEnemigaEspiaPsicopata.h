// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaEspiaPsicopata.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaEspiaPsicopata : public ANaveEnemigaEspia
{
	GENERATED_BODY()
	
private:

	float furia;
	float locura;

public:
	ANaveEnemigaEspiaPsicopata();
	FORCEINLINE int GetFuria() const { return furia; }
    FORCEINLINE int GetLocura() const { return locura; }
    FORCEINLINE void SetFuria(int _furia) { furia = _furia; }
	FORCEINLINE void SetLocura(int _Locura) { locura = _Locura; }

protected:
	virtual void Mover();
	virtual void destruirse();
	virtual void Disparar(bool bAtacar);
};
