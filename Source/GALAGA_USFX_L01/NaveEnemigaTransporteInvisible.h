// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaTransporteInvisible.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaTransporteInvisible : public ANaveEnemigaTransporte
{
	GENERATED_BODY()
	
private:
	int superInvisible;

public:
	ANaveEnemigaTransporteInvisible();
	FORCEINLINE float GetSuperInvisible() const { return superInvisible; }
	FORCEINLINE void SetSuperInvisible(float superinvisibble) { superInvisible = superInvisible; }

protected:
	virtual void mover();
	virtual void destruirse();
	void crearNaves();
	void mejorarInvisibilidad();
};
