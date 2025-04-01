// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CSAttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CS_API UCSAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCSAttributeComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;


private:
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float Health;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float MaxHealth;

public:
	void ReceiveDamage(float Damage);
	bool IsAlive();
	float GetHealthPercent();
};
