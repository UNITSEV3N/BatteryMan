// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/TestMode.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

ATestMode::ATestMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATestMode::BeginPlay()
{
	Super::BeginPlay();

	// Cast Player
	PlayerCharacter = Cast<ABatteryMan>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (PlayerCharacter == NULL)
	{
		PlayerCharacter = Cast<ABatteryMan>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	}

	FTimerHandle ObjectTimer;
	GetWorldTimerManager().SetTimer(ObjectTimer, this, &ATestMode::ATestMode::SpawnPlayerRecharge, FMath::RandRange(MIN, MAX), true);

	GEngine->bSmoothFrameRate = true;
	GEngine->SmoothedFrameRateRange = FFloatRange(30.0f, 61.0f);
}

void ATestMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATestMode::SpawnPlayerRecharge()
{
	float RandX = FMath::RandRange(Spawn_X_Min, Spawn_X_Max);
	float RandY = FMath::RandRange(Spawn_Y_Min, Spawn_Y_Max);

	FVector SpawnPosition = FVector(RandX, RandY, Spawn_Z);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);

	if (PlayerCharacter->PlayerIsDead() == false)
	{
		GetWorld()->SpawnActor(PlayerRecharge, &SpawnPosition, &SpawnRotation);
	}

	else if (PlayerCharacter->PlayerIsDead() == true)
	{
		// Do Nothing
	}	
}
