// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"


// Sets default values
ANaveEnemiga::ANaveEnemiga()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	// Create the mesh component
	NaveEnemigaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	//NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
	NaveEnemigaMesh->SetupAttachment(RootComponent);
	RootComponent = NaveEnemigaMesh;





}

void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
	posicion = GetActorLocation();
}


void ANaveEnemiga::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	

}



