// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspiaPsicopata.h"

ANaveEnemigaEspiaPsicopata::ANaveEnemigaEspiaPsicopata()
{

}



void ANaveEnemigaEspiaPsicopata::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaEspiaPsicopata::Mover(float DeltaTime)
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

void ANaveEnemigaEspiaPsicopata::destruirse()
{

}

void ANaveEnemigaEspiaPsicopata::Disparar(bool bAtacar)
{

}
