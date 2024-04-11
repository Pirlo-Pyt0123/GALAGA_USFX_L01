// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "escudoPerron.h"
#include "GameFramework/PlayerInput.h"
#include "shieldActive.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GALAGA_USFX_L01_API UshieldActive : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UshieldActive();

	UFUNCTION(BlueprintCallable, Category = Cookbook)
	void Spawn();
	//esta
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> shieldSpawn;
	//AGALAGA_USFX_L01Pawn* NaveControl;
	//tiempo importante para hacer aparecer el escudo
	UPROPERTY(VisibleAnywhere)
	int tiempoAparecer = 230;
	float estaWea = 0.0f;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USceneComponent* ShieldActiveComponent;

	//float ShieldActivadoDelay = 0.0f;
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);
public:
	void OnKeyPressed();
};