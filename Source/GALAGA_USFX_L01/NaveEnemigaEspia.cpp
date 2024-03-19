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
	speed = -3;
	SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z));
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

