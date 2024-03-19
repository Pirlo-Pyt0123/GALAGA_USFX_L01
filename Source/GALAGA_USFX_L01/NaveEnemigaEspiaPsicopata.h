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
	int bandera = 1;
	FVector coordenadasNave;
	float furia;
	float locura;
	ANaveEnemigaEspia* disparo;

public:
	ANaveEnemigaEspiaPsicopata();

	FORCEINLINE FVector GetEncontrado() const { return coordenadasNave; }

	FORCEINLINE void SetEncontrado(FVector _coordenadasNave) { coordenadasNave = _coordenadasNave; }
	FORCEINLINE int GetFuria() const { return furia; }
    FORCEINLINE int GetLocura() const { return locura; }
    FORCEINLINE void SetFuria(int _furia) { furia = _furia; }
	FORCEINLINE void SetLocura(int _Locura) { locura = _Locura; }


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void Mover(float DeltaTime)override;

	virtual void destruirse();
	virtual void Disparar(bool bAtacar);
};
