// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodriza.h"

ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
	
}



void ANaveEnemigaNodriza::Mover()
{

}

void ANaveEnemigaNodriza::destruirse()
{

}

void ANaveEnemigaNodriza::Disparar(bool bAtacar)
{

}




