// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspiaPsicopata.h"

ANaveEnemigaEspiaPsicopata::ANaveEnemigaEspiaPsicopata()
{
	posicion = FVector(1200, -1000, 250);
	posicion = FVector(1200, 1000, 250);
	float xc=200,yc=50,zc=250;
	
}



void ANaveEnemigaEspiaPsicopata::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);

}

void ANaveEnemigaEspiaPsicopata::Mover(float DeltaTime)
{
	ANaveEnemigaEspia::Mover(DeltaTime);
	bandera++;
	if (bandera < 300 && bandera >0) {

		SetActorLocation(FVector(GetActorLocation().X + GetSpeed(), GetActorLocation().Y, GetActorLocation().Z));
	}
	else if (bandera > 300) {
		bandera = -100;
	}
	else {
		SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y + GetSpeed(), GetActorLocation().Z));
	}

	if (GetActorLocation().X < -1800) {

		SetActorLocation(FVector(posicion));

	}
	
}

void ANaveEnemigaEspiaPsicopata::destruirse()
{
	ANaveEnemigaEspia::destruirse();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("NaveEnemigaEspiaPsicopata destruida"));
	Destroy();

}

void ANaveEnemigaEspiaPsicopata::Disparar(bool bAtacar)
{
	 ANaveEnemigaEspia::Disparar(bAtacar);
	if (bAtacar) {
		
		
	}
	else {
		

	}
}
