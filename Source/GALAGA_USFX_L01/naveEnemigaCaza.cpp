// Fill out your copyright notice in the Description page of Project Settings.


#include "naveEnemigaCaza.h"


AnaveEnemigaCaza::AnaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);


}

//voids mamalones
void AnaveEnemigaCaza::Mover()
{

}

void AnaveEnemigaCaza::destruirse()
{

}

void AnaveEnemigaCaza::Escapar()
{
}

