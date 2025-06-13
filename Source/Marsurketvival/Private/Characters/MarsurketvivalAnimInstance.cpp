// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/MarsurketvivalAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Characters/MarsurketvivalCharacter.h"
#include "Kismet/KismetMathLibrary.h"

void UMarsurketvivalAnimInstance::NativeInitializeAnimation() 
{
	Super::NativeInitializeAnimation();



	
	MarsurketvivalCharacter =  Cast<AMarsurketvivalCharacter>(TryGetPawnOwner());
	if (MarsurketvivalCharacter) 
	{
		MarsurketvivalCharacterMovement = MarsurketvivalCharacter->GetCharacterMovement();
	}


}

void UMarsurketvivalAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (MarsurketvivalCharacterMovement)
	{

		GroundSpeed = UKismetMathLibrary::VSizeXY(MarsurketvivalCharacterMovement->Velocity);
		IsFalling = MarsurketvivalCharacterMovement->IsFalling();
	}
	
}