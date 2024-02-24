// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Player/BatteryMan.h"
#include "TestMode.generated.h"

/**
 * 
 */
UCLASS()
class THEBATTERYMAN_API ATestMode : public AGameModeBase
{
	GENERATED_BODY()

	ATestMode();
	
	UPROPERTY(EditAnywhere, Category = "Battery Man Game Mode|Battery Spawn")
	TSubclassOf<AActor> PlayerRecharge;

	UPROPERTY(EditAnywhere, Category = "Battery Man Game Mode|Battery Spawn Hight")
	float Spawn_Z = 50.f;

	UPROPERTY(EditAnywhere, Category = "Battery Man Game Mode|Region")
	float Spawn_X_Min;

	UPROPERTY(EditAnywhere, Category = "Battery Man Game Mode|Region")
	float Spawn_X_Max;

	UPROPERTY(EditAnywhere, Category = "Battery Man Game Mode|Region")
	float Spawn_Y_Min;

	UPROPERTY(EditAnywhere, Category = "Battery Man Game Mode|Region")
	float Spawn_Y_Max;

	UPROPERTY(EditAnywhere, Category = "Battery Man Game Mode|Duration")
	int MIN = 2;

	UPROPERTY(EditAnywhere, Category = "Battery Man Game Mode|Duration")
	int MAX = 5;

	public:
		ABatteryMan* PlayerCharacter;

	void SpawnPlayerRecharge();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
