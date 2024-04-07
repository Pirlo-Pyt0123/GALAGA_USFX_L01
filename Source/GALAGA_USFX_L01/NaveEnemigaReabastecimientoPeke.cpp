// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaReabastecimientoPeke.h"

ANaveEnemigaReabastecimientoPeke::ANaveEnemigaReabastecimientoPeke()
{
	posicion = GetActorLocation();

}

void ANaveEnemigaReabastecimientoPeke::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaReabastecimientoPeke::Mover(float DeltaTime)
{
	velocity = -5;
	ANaveEnemigaReabastecimiento::Mover(DeltaTime);
	SetActorLocation(FVector(GetActorLocation().X - 2, GetActorLocation().Y, GetActorLocation().Z + 1 * bandera));
	if (GetActorLocation().Z > 800 || GetActorLocation().Z < 0) {
		bandera *= -1;
	}
	if (GetActorLocation().X < -1800) {
		SetActorLocation(posicion);
	}
}



void ANaveEnemigaReabastecimientoPeke::destruirse()
{

}

void ANaveEnemigaReabastecimientoPeke::Escapar()
{


}

void ANaveEnemigaReabastecimientoPeke::regaloRandom()
{

}
