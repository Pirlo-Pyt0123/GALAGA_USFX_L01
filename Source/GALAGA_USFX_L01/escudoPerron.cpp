// Fill out your copyright notice in the Description page of Project Settings.


#include "escudoPerron.h"
#include "GALAGA_USFX_L01Pawn.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AescudoPerron::AescudoPerron()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/IAaseet/d2cf564cea56_create_a_plasma_shi.d2cf564cea56_create_a_plasma_shi'"));
	// Create the mesh component
	shieldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	shieldMesh->SetStaticMesh(ShipMesh.Object);
	shieldMesh->SetupAttachment(RootComponent);
	RootComponent = shieldMesh;

	DistanciaEscudoNave = 200.0f;



}

// Called when the game starts or when spawned
void AescudoPerron::BeginPlay()
{
	Super::BeginPlay();
	//shieldMesh->OnComponentBeginOverlap.AddDynamic(this, &AescudoPerron::OnOverlapBegin);
}

//void AescudoPerron::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* AnaveEnemigaCaza, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	AGALAGA_USFX_L01Pawn* EnemyShip = Cast<AGALAGA_USFX_L01Pawn>(AnaveEnemigaCaza);
//	if (EnemyShip)
//	{
//		// Destruir la nave
//		EnemyShip->Destroy();
//	}
//}

// Called every frame
void AescudoPerron::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	desaparecer();
	AGALAGA_USFX_L01Pawn* MyPawn = Cast<AGALAGA_USFX_L01Pawn>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (MyPawn)
	{
		// Obtener la posición y la rotación de la nave
		FVector NavePosicion = MyPawn->GetActorLocation();
		FRotator NaveRotacion = MyPawn->GetActorRotation();

		// Calcular la dirección hacia adelante de la nave
		FVector ForwardVector = NaveRotacion.Vector();

		// Calcular la posición del escudo delante de la nave
		FVector ShieldPosition = NavePosicion + ForwardVector * DistanciaEscudoNave;

		// Establecer la posición del escudo
		SetActorLocation(ShieldPosition);
		SetActorRotation(NaveRotacion);
	}


}

void AescudoPerron::desaparecer()
{
	time++;
	if (time >= 300)
	{
		Destroy();
		
	}

}

void AescudoPerron::reaparecer()
{
	
}

