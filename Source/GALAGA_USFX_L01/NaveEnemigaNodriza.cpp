// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodriza.h"

ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnemyLevel3.EnemyLevel3'"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
	
}



void ANaveEnemigaNodriza::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Mover(DeltaTime);
}

void ANaveEnemigaNodriza::Mover(float DeltaTime)
{
    FVector PosicionActual = GetActorLocation();

    // Genera un desplazamiento negativo en el eje X, pero con una velocidad m�s alta
    float DesplazamientoX = -100.0f * DeltaTime; // Velocidad m�s alta que la clase base

    // Establece la nueva posici�n con el desplazamiento en X y mantiene las coordenadas Y y Z
    FVector NuevaPosicion = FVector(PosicionActual.X + DesplazamientoX, PosicionActual.Y, PosicionActual.Z);

    // Establece la nueva posici�n del actor
    SetActorLocation(NuevaPosicion);
}

void ANaveEnemigaNodriza::destruirse()
{

}

void ANaveEnemigaNodriza::Disparar(bool bAtacar)
{

}




