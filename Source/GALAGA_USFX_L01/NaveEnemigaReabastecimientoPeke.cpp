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
	// Obtiene la posición actual del actor
	FVector PosicionActual = GetActorLocation();

	// Genera un desplazamiento negativo en el eje X
	float DesplazamientoX = GetVelocidad() * DeltaTime; // Ajusta la velocidad según lo necesario

	// Establece la nueva posición con el desplazamiento en X y mantiene las coordenadas Y y Z
	FVector NuevaPosicion = FVector(PosicionActual.X + DesplazamientoX, PosicionActual.Y, PosicionActual.Z);

	// Establece la nueva posición del actor
	SetActorLocation(NuevaPosicion);
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
