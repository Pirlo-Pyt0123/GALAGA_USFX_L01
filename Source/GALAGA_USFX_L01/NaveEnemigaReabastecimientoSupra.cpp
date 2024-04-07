// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaReabastecimientoSupra.h"

void ANaveEnemigaReabastecimientoSupra::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

ANaveEnemigaReabastecimientoSupra::ANaveEnemigaReabastecimientoSupra()
{
	
	posicion = GetActorLocation();

}



void ANaveEnemigaReabastecimientoSupra::Mover(float DeltaTime)
{
	velocity = 3;
	SetActorLocation(FVector(GetActorLocation().X - velocity, GetActorLocation().Y + velocity * bandera, GetActorLocation().Z));
	if (GetActorLocation().Y > GetPosicion().Y + 100 || GetActorLocation().Y < GetPosicion().Y - 200) {
		bandera *= -1;

	}
	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(posicion));
	}
}

void ANaveEnemigaReabastecimientoSupra::destruirse()
{

}

void ANaveEnemigaReabastecimientoSupra::Escapar()
{

}


