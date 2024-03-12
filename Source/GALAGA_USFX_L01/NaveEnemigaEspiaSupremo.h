// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaEspiaSupremo.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaEspiaSupremo : public ANaveEnemigaEspia
{
	GENERATED_BODY()
	
private:
	float barraVida;

public:
	ANaveEnemigaEspiaSupremo();
	FORCEINLINE int GetBarraVida() const { return barraVida; }
	FORCEINLINE void SetBarraVida(int _BarraVida) { barraVida = _BarraVida; }
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void Mover(float DeltaTime)override;

	virtual void destruirse();
	virtual void Disparar(bool bAtacar);
	virtual void Escapar();
};
