// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaReabastecimiento.h"

ANaveEnemigaReabastecimiento::ANaveEnemigaReabastecimiento()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/IAaseet/Nave01/78722f052210_crea_una_nave_alien.78722f052210_crea_una_nave_alien'"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
	
}



void ANaveEnemigaReabastecimiento::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaReabastecimiento::Mover(float DeltaTime)
{
	//ector PosicionActual = GetActorLocation();

	// Genera un desplazamiento negativo en el eje X, pero con una velocidad m�s alta
//loat DesplazamientoX = GetVelocidad()* DeltaTime; // Velocidad m�s alta que la clase base

	// Establece la nueva posici�n con el desplazamiento en X y mantiene las coordenadas Y y Z
	//ector NuevaPosicion = FVector(PosicionActual.X + DesplazamientoX, PosicionActual.Y, PosicionActual.Z);

	// Establece la nueva posici�n del actor
//etActorLocation(NuevaPosicion);


}

void ANaveEnemigaReabastecimiento::destruirse()
{
}

void ANaveEnemigaReabastecimiento::Disparar(bool bDisparar)
{
}

void ANaveEnemigaReabastecimiento::Escapar()
{

}
