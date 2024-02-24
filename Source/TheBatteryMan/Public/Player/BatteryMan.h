// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Blueprint/userWidget.h"
#include "BatteryMan.generated.h"

// Learning Enum in UE4
UENUM(BlueprintType)
enum PlayerTest
{
	ALIVE
};

UCLASS()
class THEBATTERYMAN_API ABatteryMan : public ACharacter
{
	GENERATED_BODY()

	// The Battery Man Stuff

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Battery Man|Variables", meta = (AllowPrivateAccess = "true"))
	float Power;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Battery Man|Variables", meta = (AllowPrivateAccess = "true"))
	float Power_Threshold;

	UFUNCTION()
	void OnBeginOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Sweep);

	UPROPERTY(EditAnywhere, Category = "Battery Man|UI HUD")
	TSubclassOf<UUserWidget> Player_Power_Widget_class;
	UUserWidget* Player_Power_Widget;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Battery Man|Variables", meta = (AllowPrivateAccess = "true"))
	int Charges;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Battery Man|Variables", meta = (AllowPrivateAccess = "true"))
	bool bDead;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly,Category = "FPS", meta = (AllowPrivateAccess = "true"))
	int FPS;

	// Learning Enum in UE4
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battery Man|Game Stuff", meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<PlayerTest>PlayerTest;
	
public:
	// Sets default values for this character's properties
	ABatteryMan();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Axis);
	void MoveRight(float Axis);

	void RestartGame();

	
public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool PlayerIsDead();
	int ReturnCharges();
};