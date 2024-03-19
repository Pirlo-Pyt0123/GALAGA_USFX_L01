// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaReabastecimientoSupra.h"

void ANaveEnemigaReabastecimientoSupra::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

ANaveEnemigaReabastecimientoSupra::ANaveEnemigaReabastecimientoSupra()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnemyLevel5.EnemyLevel5'"));
	NaveEnemigaMesh->SetStaticMesh(Mesh.Object);	
}



void ANaveEnemigaReabastecimientoSupra::Mover(float DeltaTime)
{
	speed = -5;
	ANaveEnemigaReabastecimiento::Mover(DeltaTime);
	SetActorLocation(FVector(GetActorLocation().X - 2, GetActorLocation().Y, GetActorLocation().Z + 1 * bandera));
	if (GetActorLocation().Z > 800 || GetActorLocation().Z < 0) {
		bandera *= -1;
	}
	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(1200, -1000 + 400, 250.0f));
	}
}

void ANaveEnemigaReabastecimientoSupra::destruirse()
{

}

void ANaveEnemigaReabastecimientoSupra::Escapar()
{

}

void ANaveEnemigaReabastecimientoSupra::repara()
{

}

void ANaveEnemigaReabastecimientoSupra::Crecer()
{

}
