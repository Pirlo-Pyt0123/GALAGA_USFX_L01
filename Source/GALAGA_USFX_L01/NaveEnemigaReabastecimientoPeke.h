// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaReabastecimientoPeke.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaReabastecimientoPeke : public ANaveEnemigaReabastecimiento
{
	GENERATED_BODY()
	
private:
	int reparador;
	int bandera = 1;
	FVector coordenadasNave;
public:
	ANaveEnemigaReabastecimientoPeke();
	FORCEINLINE int GetReparador() const { return reparador; }

	FORCEINLINE void SetReparador(int _Reparador) { reparador = _Reparador; }
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void Mover(float DeltaTime)override;

	virtual void destruirse();
	virtual void Escapar();
	void regaloRandom();
};
