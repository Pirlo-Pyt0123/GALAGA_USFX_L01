// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaNodrizaFabrica.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaNodrizaFabrica : public ANaveEnemigaNodriza
{
	GENERATED_BODY()
	
private:
	float capacidadExtra;
	bool bolivia = true;
	int semov;

public:
	ANaveEnemigaNodrizaFabrica();

	FORCEINLINE int GetCapacidadExtra() const { return capacidadExtra; }

	FORCEINLINE void SetCapacidadExtra(int _capacidadExtra) { capacidadExtra = _capacidadExtra; }

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void Mover(float DeltaTime)override;
	virtual void destruirse();
	
	virtual void Escapar();
	void generarNaves();
};
