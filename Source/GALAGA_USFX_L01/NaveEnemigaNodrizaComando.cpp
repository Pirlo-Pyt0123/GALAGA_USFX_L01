// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodrizaComando.h"

ANaveEnemigaNodrizaComando::ANaveEnemigaNodrizaComando()
{

}



void ANaveEnemigaNodrizaComando::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaNodrizaComando::Mover(float DeltaTime)
{
	ANaveEnemigaNodriza::Mover(DeltaTime);
	speed = 3;
	SetActorLocation(FVector(GetActorLocation().X - speed, GetActorLocation().Y - speed * bandera, GetActorLocation().Z));
	if (GetActorLocation().Y < -1200 || GetActorLocation().Y > -800) {
		bandera *= -1;
	}
	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(posicion));
		SetActorLocation(FVector(1200, -1000, 250));

	}
}

void ANaveEnemigaNodrizaComando::destruirse()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("NaveEnemigaNodrizaComando destruida"));
	Destroy();
	

}

void ANaveEnemigaNodrizaComando::Disparar(bool bAtacar)
{

}

