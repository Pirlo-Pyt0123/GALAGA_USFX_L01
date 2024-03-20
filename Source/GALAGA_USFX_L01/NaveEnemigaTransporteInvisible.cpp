// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporteInvisible.h"

void ANaveEnemigaTransporteInvisible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);

}

ANaveEnemigaTransporteInvisible::ANaveEnemigaTransporteInvisible()
{
	posicion = GetActorLocation();

}



void ANaveEnemigaTransporteInvisible::Mover(float DeltaTime)
{
	ANaveEnemigaTransporte::Mover(DeltaTime);
	ban++;
	if (ban > 500) {
		tepeX = rand() % 1600;
		tepeY = rand() % 1600;
		ban = 0;

	}

	else {
		SetActorLocation(FVector(tepeX, tepeY, GetActorLocation().Z));
		if (GetActorLocation().X < -1800) {
			SetActorLocation(FVector(posicion));
		}
	}

}

void ANaveEnemigaTransporteInvisible::destruirse()
{

}

void ANaveEnemigaTransporteInvisible::crearNaves()
{

}

void ANaveEnemigaTransporteInvisible::mejorarInvisibilidad()
{

}
