// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodrizaFabrica.h"

ANaveEnemigaNodrizaFabrica::ANaveEnemigaNodrizaFabrica()
{
	GetActorRelativeScale3D();
	//aumenta el tamano de la nave
	SetActorScale3D(FVector(2, 2, 2));
	posicion = GetActorLocation();



 
}


void ANaveEnemigaNodrizaFabrica::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaNodrizaFabrica::Mover(float DeltaTime)
{
	ANaveEnemigaNodriza::Mover(DeltaTime);
	if (ban) {
		posicionmov = rand() % 1600;
		ban = false;
	}

	else {
		if (posicionmov > GetActorLocation().Y) {
			SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y + 1, GetActorLocation().Z));
		}
		else if (posicionmov < GetActorLocation().Y) {
			SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y - 1, GetActorLocation().Z));
		}
		else {
			ban = true;
		}

	}


}

void ANaveEnemigaNodrizaFabrica::destruirse()
{

}

void ANaveEnemigaNodrizaFabrica::Escapar()
{

}

void ANaveEnemigaNodrizaFabrica::generarNaves()
{

}
