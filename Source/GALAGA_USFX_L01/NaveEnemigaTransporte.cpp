// Fill out your copyright notice in the Description page of Project Settings.

#include "GALAGA_USFX_L01Pawn.h"
#include "NaveEnemigaTransporte.h"

//AGALAGA_USFX_L01Pawn* NaveObjetivo;

void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);

	//if (NaveObjetivo != nullptr)
	//{
	//	// Obtener la posición actual de la nave objetivo (tu nave)
	//	FVector PosicionObjetivo = NaveObjetivo->GetActorLocation();

	//	// Calcular la dirección hacia la nave objetivo
	//	FVector Direccion = (PosicionObjetivo - GetActorLocation()).GetSafeNormal();

	//	// Mover la nave enemiga hacia la nave objetivo
	//	FVector NuevaPosicion = GetActorLocation() + Direccion * VelocidadSeguimiento * DeltaTime;
	//	SetActorLocation(NuevaPosicion);

	//}
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


