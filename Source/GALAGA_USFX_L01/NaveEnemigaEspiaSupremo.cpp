// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspiaSupremo.h"

ANaveEnemigaEspiaSupremo::ANaveEnemigaEspiaSupremo()
{
	posicion = GetActorLocation();

}



void ANaveEnemigaEspiaSupremo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaEspiaSupremo::Mover(float DeltaTime)
{
	ANaveEnemigaEspia::Mover(DeltaTime);
	bandera++;
	if (bandera < 300 && bandera >0) {

		SetActorLocation(FVector(GetActorLocation().X + GetSpeed(), GetActorLocation().Y, GetActorLocation().Z));
	}
	else if (bandera > 300) {
		bandera = -100;
	}
	else {
		SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y + GetSpeed(), GetActorLocation().Z));
	}

	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(posicion));
	}
}

void ANaveEnemigaEspiaSupremo::destruirse()
{

}

void ANaveEnemigaEspiaSupremo::Disparar(bool bAtacar)
{

}

void ANaveEnemigaEspiaSupremo::Escapar()
{

}
