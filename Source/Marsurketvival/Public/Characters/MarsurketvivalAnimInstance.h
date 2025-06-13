// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
//#include "GameFramework/CharacterMovementComponent.h"
#include "MarsurketvivalAnimInstance.generated.h"


/**
 * 
 */
UCLASS()
class MARSURKETVIVAL_API UMarsurketvivalAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float Deltatime) override;

	UPROPERTY(BlueprintReadOnly)
	class AMarsurketvivalCharacter* MarsurketvivalCharacter;



	UPROPERTY(BlueprintReadOnly, Category = Movement)
	class UCharacterMovementComponent* MarsurketvivalCharacterMovement;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	bool IsFalling;
};
