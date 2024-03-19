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
	speed = 3;
	SetActorLocation(FVector(GetActorLocation().X - speed, GetActorLocation().Y + speed * bandera, GetActorLocation().Z));
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
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("NaveEnemigaCazaSigilosa Escapar"));
	SetActorLocation(FVector(GetActorLocation().X - speed, GetActorLocation().Y + speed * bandera, GetActorLocation().Z));
	if (GetActorLocation().Y < -1000 || GetActorLocation().Y > -600) {
		bandera *= -1;

	}
	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(posicion));
		SetActorLocation(FVector(1200, -1000, 250));
	}

}
