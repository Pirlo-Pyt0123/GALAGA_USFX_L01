// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveEnemigaTransporte.h"


void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);

	
}


ANaveEnemigaTransporte::ANaveEnemigaTransporte()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnemyLevel5.EnemyLevel5'"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
	
}

void ANaveEnemigaTransporte::Mover(float DeltaTime)
{
	//ector PosicionActual = GetActorLocation();

	// Genera un desplazamiento negativo en el eje X, pero con una velocidad más alta
//loat DesplazamientoX = -250.0f * DeltaTime; // Velocidad más alta que la clase base

	// Establece la nueva posición con el desplazamiento en X y mantiene las coordenadas Y y Z
	//ector NuevaPosicion = FVector(PosicionActual.X + DesplazamientoX, PosicionActual.Y, PosicionActual.Z);

	// Establece la nueva posición del actor
	//ActorLocation(NuevaPosicion);
}


void ANaveEnemigaTransporte::destruirse()
{

}

void ANaveEnemigaTransporte::Disparar(bool bDisparar)
{

}

void ANaveEnemigaTransporte::Escapar()
{

}


