// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Tools/Axe.h"
#include "Characters/MarsurketvivalCharacter.h"




void AAxe::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	Super::OnSphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	AMarsurketvivalCharacter* MarsurCharacter = Cast<AMarsurketvivalCharacter>(OtherActor);
		if (MarsurCharacter)
		{
			FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, true);
			ItemMesh->AttachToComponent(MarsurCharacter->GetMesh(), TransformRules, FName("RightHandSocket"));
		}
}

void AAxe::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnSphereEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

}