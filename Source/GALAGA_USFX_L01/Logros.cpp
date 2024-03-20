// Fill out your copyright notice in the Description page of Project Settings.


#include "Logros.h"

// Sets default values
ALogros::ALogros()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Segun el TMap
	tablavidas.Add("corazon", 1);
	tablavidas.Add("escudo", 0);

}

// Called when the game starts or when spawned
void ALogros::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALogros::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//segun el TMap
	ListarVida();
	temporizador++;
}

//void ALogros::CalcularVida(FString, int)
///{

//}

void ALogros::InsertarVida(FString _name)
{
	tablavidas[_name] += 1;
}

void ALogros::EliminarVida(FString _name)
{
	tablavidas[_name] -= 1;
}

void ALogros::ModificarVida(FString _name, int newvida)
{
	tablavidas[_name] = newvida;
}

void ALogros::ListarVida()
{
	Getcorazones();
	Getescudos();
}

void ALogros::Getcorazones()
{
	int numvidas = tablavidas["corazon"];
	FString VidasString = FString::FromInt(numvidas);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("VIDAS: ") + VidasString);

	if (temporizador == 1) {
		GEngine->ClearOnScreenDebugMessages();
		temporizador = 0;
	}
}

void ALogros::Getescudos()
{
	int numescudos = tablavidas["escudo"];
	FString EscudosString = FString::FromInt(numescudos);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("ESCUDOS: ") + EscudosString);

	if (temporizador == 1) {
		GEngine->ClearOnScreenDebugMessages();
		temporizador = 0;
	}
}
