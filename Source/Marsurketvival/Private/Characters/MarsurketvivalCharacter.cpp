// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MarsurketvivalCharacter.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GroomComponent.h"

// Sets default values
AMarsurketvivalCharacter::AMarsurketvivalCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);


	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 300.f;

	Hair = CreateDefaultSubobject<UGroomComponent>(TEXT("Hair"));
	Hair->SetupAttachment(GetMesh());
	Hair->AttachmentName = FString("head");

	Eyebrows = CreateDefaultSubobject<UGroomComponent>(TEXT("Eyebrows"));
	Eyebrows->SetupAttachment(GetMesh());
	Eyebrows->AttachmentName = FString("head");


	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(CameraBoom);

}

// Called when the game starts or when spawned
void AMarsurketvivalCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMarsurketvivalCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMarsurketvivalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AMarsurketvivalCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &AMarsurketvivalCharacter::MoveRight);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &AMarsurketvivalCharacter::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &AMarsurketvivalCharacter::LookUp);

	PlayerInputComponent->BindAction(FName("Jump"), IE_Pressed, this, &ACharacter::Jump);

}

void AMarsurketvivalCharacter::MoveForward(float Value)
{
	//UE_LOG(LogTemp, Warning, TEXT("Value pries if: %f"), Value);
	if (Controller && (Value != 0.f))
	{
	//	UE_LOG(LogTemp, Warning, TEXT("Value: %f"), Value);
	//
	//	FVector Forward = GetActorForwardVector();
	//	AddMovementInput(Forward, Value);

		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f,ControlRotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);

	}
}

void AMarsurketvivalCharacter::MoveRight(float Value)
{
	if (Controller && (Value != 0.f))
	{
	//	FVector Right = GetActorRightVector();
	//	AddMovementInput(Right, Value);

		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);

	}
}

void AMarsurketvivalCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AMarsurketvivalCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}
