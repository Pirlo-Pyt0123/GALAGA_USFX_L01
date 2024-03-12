// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspia.h"

ANaveEnemigaEspia::ANaveEnemigaEspia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnemyLevel2.EnemyLevel2'"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
	
}






void ANaveEnemigaEspia::Tick(float DeltaTime)
{

    Super::Tick(DeltaTime);
    Mover(DeltaTime);
}

void ANaveEnemigaEspia::Mover(float DeltaTime)
{
    FVector PosicionActual = GetActorLocation();

    // Genera un desplazamiento negativo en el eje X, pero con una velocidad más alta
    float DesplazamientoX = -300.0f * DeltaTime; // Velocidad más alta que la clase base

    // Establece la nueva posición con el desplazamiento en X y mantiene las coordenadas Y y Z
    FVector NuevaPosicion = FVector(PosicionActual.X + DesplazamientoX, PosicionActual.Y, PosicionActual.Z);

    // Establece la nueva posición del actor
    SetActorLocation(NuevaPosicion);
}

void ANaveEnemigaEspia::destruirse()
{

}

void ANaveEnemigaEspia::Disparar(bool bDisparar)
{

}


void ANaveEnemigaEspia::Escapar()
{

}

