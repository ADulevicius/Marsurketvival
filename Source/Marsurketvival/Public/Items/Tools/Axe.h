// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Tools/Tool.h"
#include "Axe.generated.h"

/**
 * 
 */
UCLASS()
class MARSURKETVIVAL_API AAxe : public ATool
{
	GENERATED_BODY()
	
protected:

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
