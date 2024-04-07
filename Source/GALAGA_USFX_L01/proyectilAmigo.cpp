// Fill out your copyright notice in the Description page of Project Settings.


#include "proyectilAmigo.h"

// Sets default values
AproyectilAmigo::AproyectilAmigo()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and configure the projectile mesh component

}

// Called when the game starts or when spawned
void AproyectilAmigo::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AproyectilAmigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}




