// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodrizaFabrica.h"

ANaveEnemigaNodrizaFabrica::ANaveEnemigaNodrizaFabrica()
{
	GetActorRelativeScale3D();
	//aumenta el tamano de la nave
	SetActorScale3D(FVector(4, 4, 4));
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
	if (bolivia) {
		semov = rand() % 1600;
		bolivia = false;
	}

	else {
		if (semov > GetActorLocation().Y) {
			SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y + 1, GetActorLocation().Z));
		}
		else if (semov < GetActorLocation().Y) {
			SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y - 1, GetActorLocation().Z));
		}
		else {
			bolivia = true;
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
