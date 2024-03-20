// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporteDesplegable.h"

void ANaveEnemigaTransporteDesplegable::Tick(float DeltaTime)
{
		Super::Tick(DeltaTime);
	    mover(DeltaTime);
}

ANaveEnemigaTransporteDesplegable::ANaveEnemigaTransporteDesplegable()
{
	posicion = GetActorLocation();
}





void ANaveEnemigaTransporteDesplegable::mover(float DeltaTime)
{
		
	ANaveEnemigaTransporte::Mover(DeltaTime);
		speed = 3;
		SetActorLocation(FVector(GetActorLocation().X - speed, GetActorLocation().Y + speed * bandera, GetActorLocation().Z));
		if (GetActorLocation().Y < -1000 || GetActorLocation().Y > -600) {
			bandera *= -1;

		}
		if (GetActorLocation().X < -1800) {
			SetActorLocation(FVector(posicion));
		}
		
}

void ANaveEnemigaTransporteDesplegable::destruirse()
{

}

void ANaveEnemigaTransporteDesplegable::crearNaves()
{

}
