// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporteDesplegable.h"

void ANaveEnemigaTransporteDesplegable::Tick(float DeltaTime)
{
		Super::Tick(DeltaTime);
	    mover(DeltaTime);
}

ANaveEnemigaTransporteDesplegable::ANaveEnemigaTransporteDesplegable()
{
	posicion = FVector(1200, -1000, 250);
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
			SetActorLocation(FVector(1200, -1000, 250));
		}
		
}

void ANaveEnemigaTransporteDesplegable::destruirse()
{

}

void ANaveEnemigaTransporteDesplegable::crearNaves()
{

}
