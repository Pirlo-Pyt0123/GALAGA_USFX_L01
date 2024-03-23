// Fill out your copyright notice in the Description page of Project Settings.


#include "naveEnemigaCaza.h"


AnaveEnemigaCaza::AnaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnemyLevel1.EnemyLevel1'"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);

    PrimaryActorTick.bCanEverTick = true;
}

void AnaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
	

}
  
//voids mamalones


void AnaveEnemigaCaza::Mover(float DeltaTime)
{
	velocity = 1;
	SetActorLocation(FVector(GetActorLocation().X - velocity, GetActorLocation().Y, GetActorLocation().Z));

}

void AnaveEnemigaCaza::destruirse()
{

}

void AnaveEnemigaCaza::Escapar()
{

}

