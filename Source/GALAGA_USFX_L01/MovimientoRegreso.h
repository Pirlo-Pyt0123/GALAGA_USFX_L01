// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MovimientoRegreso.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GALAGA_USFX_L01_API UMovimientoRegreso : public UActorComponent
{
	GENERATED_BODY()
private:
	bool iniciar = false;
	FVector objetivo;

	//salto
	bool salto = false;
	bool altMax = false;
public:
	// Sets default values for this component's properties
	UMovimientoRegreso();
	void iniciarRegreso(bool _iniciar, FVector puntoObjetivo, float DeltaTime);
	void jump();
	void joinJump(float DeltaTime);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};