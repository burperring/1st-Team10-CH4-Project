// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CSTypes/CSCharacterTypes.h"
#include "CSAttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CS_API UCSAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCSAttributeComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	virtual void BeginPlay() override;

public:
	bool IsAlive();
	float GetHealthPercent();

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void UpdateFacingDirection(float XInput);

	UFUNCTION(Server, Reliable)
	void ServerUpdateFacingDirection(float XInput);

	UFUNCTION(Server, Reliable)
	void ServerUpdateRotation(FRotator NewRotation);

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	EFacingDirection GetFacingDirection() const { return FacingDirection; }

	FORCEINLINE float GetHealth() const { return Health; }
	FORCEINLINE float GetMaxHealth() const { return MaxHealth; }

private:
	UPROPERTY(ReplicatedUsing=OnRep_FacingDirection)
    EFacingDirection FacingDirection = EFacingDirection::EFD_FacingRight;

	UPROPERTY(EditAnywhere, Replicated, Category = "Actor Attributes")
	float Health;

	UPROPERTY(EditAnywhere, Replicated, Category = "Actor Attributes")
	float MaxHealth;

	UFUNCTION()
	void OnRep_Health();

	UFUNCTION()
	void OnRep_MaxHealth();
	
	UFUNCTION()
	void OnRep_FacingDirection();
};
