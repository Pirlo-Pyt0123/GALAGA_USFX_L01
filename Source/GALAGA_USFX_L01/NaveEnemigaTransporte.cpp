// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporte.h"



ANaveEnemigaTransporte::ANaveEnemigaTransporte()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
	
}

void ANaveEnemigaTransporte::mover()
{

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


