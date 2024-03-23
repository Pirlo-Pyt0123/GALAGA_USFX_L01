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
	//	// Obtener la posici�n actual de la nave objetivo (tu nave)
	//	FVector PosicionObjetivo = NaveObjetivo->GetActorLocation();

	//	// Calcular la direcci�n hacia la nave objetivo
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

	// Genera un desplazamiento negativo en el eje X, pero con una velocidad m�s alta
//loat DesplazamientoX = -250.0f * DeltaTime; // Velocidad m�s alta que la clase base

	// Establece la nueva posici�n con el desplazamiento en X y mantiene las coordenadas Y y Z
	//ector NuevaPosicion = FVector(PosicionActual.X + DesplazamientoX, PosicionActual.Y, PosicionActual.Z);

	// Establece la nueva posici�n del actor
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


