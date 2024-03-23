// Fill out your copyright notice in the Description page of Project Settings.


#include "vidas.h"

// Sets default values
Avidas::Avidas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	PrimaryActorTick.bCanEverTick = true;
	tablavidas.Add("corazon", 1);
	tablavidas.Add("escudo", 0);
}

// Called when the game starts or when spawned
void Avidas::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Avidas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ListarVida();
	temporizador++;

}

void Avidas::CalcularVida(FString, int)
{

}

void Avidas::InsertarVida(FString _name)
{
	tablavidas[_name] += 1;
}

void Avidas::EliminarVida(FString _name)
{
	tablavidas[_name] -= 1;
}

void Avidas::ModificarVida(FString _name, int newvida)
{
	tablavidas[_name] = newvida;
}

void Avidas::ListarVida()
{
	Getcorazones();
	Getescudos();
}

void Avidas::Getcorazones()
{
	int numvidas = tablavidas["corazon"];
	FString VidasString = FString::FromInt(numvidas);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("VIDAS: ") + VidasString);

	/*if (temporizador == 1) {
		GEngine->ClearOnScreenDebugMessages();
		temporizador = 0;
	}*/
}

void Avidas::Getescudos()
{
	int numescudo = tablavidas["escudo"];
	FString EscudoString = FString::FromInt(numescudo);
	GEngine->AddOnScreenDebugMessage(-5, 10.0f, FColor::Blue, TEXT("ESCUDO: ") + EscudoString);

	if (temporizador >= 1.5) {
		GEngine->ClearOnScreenDebugMessages();
		temporizador = 0;
	}
}
