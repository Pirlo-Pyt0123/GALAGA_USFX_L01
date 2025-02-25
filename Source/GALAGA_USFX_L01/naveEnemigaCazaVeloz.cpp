// Fill out your copyright notice in the Description page of Project Settings.


#include "naveEnemigaCazaVeloz.h"

AnaveEnemigaCazaVeloz::AnaveEnemigaCazaVeloz()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/IAaseet/fdd447e732b5_crea_una_nave_muy_a.fdd447e732b5_crea_una_nave_muy_a'"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);

	posicion = GetActorLocation();
	
}







void AnaveEnemigaCazaVeloz::Mover(float DeltaTime)
{
	AnaveEnemigaCaza::Mover(DeltaTime);
	velocity = 3;
	SetActorLocation(FVector(GetActorLocation().X - velocity, GetActorLocation().Y + velocity * bandera, GetActorLocation().Z));
	if (GetActorLocation().Y > GetPosicion().Y + 100 || GetActorLocation().Y < GetPosicion().Y - 200) {
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
