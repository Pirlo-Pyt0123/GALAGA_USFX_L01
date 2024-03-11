// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaReabastecimiento.h"

ANaveEnemigaReabastecimiento::ANaveEnemigaReabastecimiento()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
	
}




void ANaveEnemigaReabastecimiento::mover()
{
}

void ANaveEnemigaReabastecimiento::destruirse()
{
}

void ANaveEnemigaReabastecimiento::Disparar(bool bDisparar)
{
}

void ANaveEnemigaReabastecimiento::Escapar()
{

}
