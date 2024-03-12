// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodrizaFabrica.h"

ANaveEnemigaNodrizaFabrica::ANaveEnemigaNodrizaFabrica()
{

}


void ANaveEnemigaNodrizaFabrica::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaNodrizaFabrica::Mover(float DeltaTime)
{
	// Obtiene la posici�n actual del actor
	FVector PosicionActual = GetActorLocation();

	// Genera un desplazamiento negativo en el eje X
	float DesplazamientoX = GetVelocidad() * DeltaTime; // Ajusta la velocidad seg�n lo necesario

	// Establece la nueva posici�n con el desplazamiento en X y mantiene las coordenadas Y y Z
	FVector NuevaPosicion = FVector(PosicionActual.X + DesplazamientoX, PosicionActual.Y, PosicionActual.Z);

	// Establece la nueva posici�n del actor
	SetActorLocation(NuevaPosicion);
}

void ANaveEnemigaNodrizaFabrica::destruirse()
{

}

void ANaveEnemigaNodrizaFabrica::Disparar(bool bDisparar)
{

}

void ANaveEnemigaNodrizaFabrica::Escapar()
{

}

void ANaveEnemigaNodrizaFabrica::generarNaves()
{

}
