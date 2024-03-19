// Fill out your copyright notice in the Description page of Project Settings.


#include "naveEnemigaCazaVeloz.h"

AnaveEnemigaCazaVeloz::AnaveEnemigaCazaVeloz()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/IAaseet/fdd447e732b5_crea_una_nave_muy_a.fdd447e732b5_crea_una_nave_muy_a'"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);

	posicion = FVector(1200, -1000, 250);
	
}







void AnaveEnemigaCazaVeloz::Mover(float DeltaTime)
{
	AnaveEnemigaCaza::Mover(DeltaTime);
	speed = 3;
	SetActorLocation(FVector(GetActorLocation().X - speed, GetActorLocation().Y + speed * bandera, GetActorLocation().Z));
	if (GetActorLocation().Y < -1000 || GetActorLocation().Y > -600) {
		bandera *= -1;

	}
	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(posicion));
	}
}

void AnaveEnemigaCazaVeloz::destruirse()
{
	
}



void AnaveEnemigaCazaVeloz::Escapar()
{

}
