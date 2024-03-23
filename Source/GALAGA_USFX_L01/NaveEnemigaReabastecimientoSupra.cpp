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


	posicion = GetActorLocation();

}



void ANaveEnemigaReabastecimientoSupra::Mover(float DeltaTime)
{
	velocity = -5;
	ANaveEnemigaReabastecimiento::Mover(DeltaTime);
	SetActorLocation(FVector(GetActorLocation().X - 2, GetActorLocation().Y, GetActorLocation().Z + 1 * bandera));
	if (GetActorLocation().X > 800 || GetActorLocation().X < 0) {
		bandera *= -1;
	}
	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(posicion));
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
