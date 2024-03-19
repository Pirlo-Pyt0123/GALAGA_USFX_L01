// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodriza.h"
#include "Math/UnrealMathUtility.h" // Necesario para FMath
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

    
}

void ANaveEnemigaNodriza::destruirse()
{

}

void ANaveEnemigaNodriza::Disparar(bool bAtacar)
{

}




