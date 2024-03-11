// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspia.h"

ANaveEnemigaEspia::ANaveEnemigaEspia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
	
}





void ANaveEnemigaEspia::mover()
{

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

