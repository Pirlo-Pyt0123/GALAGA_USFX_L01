// Fill out your copyright notice in the Description page of Project Settings.


#include "naveEnemigaCazaSigilosa.h"
#include "naveEnemigaCaza.h"

AnaveEnemigaCazaSigilosa::AnaveEnemigaCazaSigilosa()
{
	posicion = GetActorLocation();
}
void AnaveEnemigaCazaSigilosa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);

}



void AnaveEnemigaCazaSigilosa::Mover(float DeltaTime)
{
	AnaveEnemigaCaza::Mover(DeltaTime);
	velocity = 3;
	SetActorLocation(FVector(GetActorLocation().X - velocity, GetActorLocation().Y + velocity * bandera, GetActorLocation().Z));
	if (GetActorLocation().Y < -1000 || GetActorLocation().Y > -600) {
		bandera *= -1;

	}
	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(posicion));
	}
}

void AnaveEnemigaCazaSigilosa::destruirse()
{


}


void AnaveEnemigaCazaSigilosa::Escapar()
{
	
}
