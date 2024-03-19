// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaReabastecimientoPeke.h"

ANaveEnemigaReabastecimientoPeke::ANaveEnemigaReabastecimientoPeke()
{

}

void ANaveEnemigaReabastecimientoPeke::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaReabastecimientoPeke::Mover(float DeltaTime)
{
	ANaveEnemigaReabastecimiento::Mover(DeltaTime);
	SetActorLocation(FVector(GetActorLocation().X - 2, GetActorLocation().Y, GetActorLocation().Z));
	SetActorRotation(FRotator(bandera, 90, 90));
	if (bandera >= 360) {
		bandera = 0;
	}
	bandera++;
	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(1200, -1000 + 600, 250.0f));
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
