// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.generated.h"

UCLASS(abstract)
class GALAGA_USFX_L01_API ANaveEnemiga : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* NaveEnemigaMesh;


protected:

	
	float velocidad;
	FString nombre;
	int vida;
	float resistencia;
	float tiempoDisparo;
	float danoProducido;
	FVector posicion;
	int trayectoria;		//cada valor numerico representa a una funcion que la nave se mueva en dif posiciones 
	int capacidadPasajeros;
	int capacidadMunicion;
	int tipoNave;
	float exp;
	float energia;
	float peso;
	float volumen;
	float velocity;
	FVector posicionClones;





public:

	FORCEINLINE int GetCapacidadPasajeros() const { return capacidadPasajeros; }
	FORCEINLINE int GetCapacidadMunicion() const { return capacidadMunicion; }
	FORCEINLINE int GetTipoNave() const { return tipoNave; }
	FORCEINLINE int GetVida() const { return vida; }
	FORCEINLINE int GetTrayectoria() const { return trayectoria; }
	FORCEINLINE FVector GetPosicionClones() const { return posicionClones; }

	FORCEINLINE float GetResistencia() const { return resistencia; }
    //FORCEINLINE float GetVelocidad() const { return velocidad; }
	FORCEINLINE float GetSpeed() const { return velocity; }
	FORCEINLINE float GetDanoProducido() const { return danoProducido; }
	FORCEINLINE FString GetNombre() const { return nombre; }
	FORCEINLINE float GetTiempoDisparo() const { return tiempoDisparo; }
	FORCEINLINE FVector GetPosicion() const { return posicion; }
	FORCEINLINE float GetExp() const { return exp; }
	FORCEINLINE float GetEnergia() const { return energia; }
	FORCEINLINE float Getpeso() const { return peso; }
	FORCEINLINE float Getvolumen() const { return volumen; }


	FORCEINLINE void SetCapacidadPasajeros(int _capacidadPasajeros) { capacidadPasajeros = _capacidadPasajeros; }
	FORCEINLINE void SetResistencia(float _resistencia) { resistencia = _resistencia; }
    //FORCEINLINE void SetVelocidad(float _velocidad) { velocidad = _velocidad; }
	FORCEINLINE void SetSpeed(float _velocity) { velocity = _velocity; }
	FORCEINLINE void SetDanoProducido(float _danoProducido) { danoProducido = _danoProducido; }
	FORCEINLINE void SetNombre(FString _nombre) { nombre = _nombre; }
	FORCEINLINE void SetTiempoDisparo(float _tiempoDisparo) { tiempoDisparo = _tiempoDisparo; }
	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }
	FORCEINLINE void SetExp(float _exp) { exp = _exp; }
	FORCEINLINE void SetEnergia(float _energia) { energia = _energia; }
	FORCEINLINE void Setpeso(float _peso) { peso = _peso; }
	FORCEINLINE void Setvolumen(float _volumen) { volumen = _volumen; }
	FORCEINLINE void SetCapacidadMunicion(int _capacidadMunicion) { capacidadMunicion = _capacidadMunicion; }
	FORCEINLINE void SetTipoNave(int _tipoNave) { tipoNave = _tipoNave; }
	FORCEINLINE void SetVida(int _vida) { vida = _vida; }
	FORCEINLINE void SetTrayectoria(int _trayectoria) { trayectoria = _trayectoria; }
	FORCEINLINE void SetPosicionClones(FVector _posicionClones) { posicionClones = _posicionClones; }
	




public:
	// Sets default values for this actor's properties
	ANaveEnemiga();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	
	void Mover(float DeltaTime) PURE_VIRTUAL(ANaveEnemiga::Mover, );
	void Disparar() PURE_VIRTUAL(ANaveEnemiga::Disparar, );
	void Destruirse() PURE_VIRTUAL(ANaveEnemiga::Destruirse, );
	void Escapar() PURE_VIRTUAL(ANaveEnemiga::Escapar, );
};
