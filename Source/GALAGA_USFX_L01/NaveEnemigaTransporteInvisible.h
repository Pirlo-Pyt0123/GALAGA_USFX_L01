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
	int tepeX;
	int tepeY;
	int ban = 51;
	

public:
	virtual void Tick(float DeltaTime)override;
	ANaveEnemigaTransporteInvisible();
	FORCEINLINE float GetSuperInvisible() const { return superInvisible; }
	FORCEINLINE void SetSuperInvisible(float superinvisibble) { superInvisible = superInvisible; }

protected:
	virtual void Mover(float DeltaTime)override;
	virtual void destruirse();
	void crearNaves();
	void mejorarInvisibilidad();
};
