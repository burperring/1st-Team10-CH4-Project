// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CSTypes/CSCharacterTypes.h"
#include "CSCombatComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CS_API UCSCombatComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UCSCombatComponent();
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, Category = "Combat")
    bool GetIsAttacking() const { return bIsAttacking; }

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void SetIsAttacking(bool bAttacking);

    UFUNCTION(NetMulticast, Reliable)
    void MultiSetMontageData(UAnimMontage* PlayMontage, FName Section);
    void MultiSetMontageData_Implementation(UAnimMontage* PlayMontage, FName Section);

    UFUNCTION(Server, Reliable)
    void ServerSetMontageData(UAnimMontage* PlayMontage, FName Section);
    void ServerSetMontageData_Implementation(UAnimMontage* PlayMontage, FName Section);

    UFUNCTION(Server, Reliable)
    void ServerStartAttack();
    void ServerStartAttack_Implementation();

    UFUNCTION(Server, Reliable)
    void ServerEndAttack();
    void ServerEndAttack_Implementation();

    // Combo Function
    void Combo1CntIncrease();
    int32 GetCombo1Cnt();
    void Combo2CntIncrease();
    int32 GetCombo2Cnt();
    void CanComboChange(bool Check);
    bool GetCanCombo();
    UFUNCTION(BlueprintCallable, Category = "Combo")
    void ResetComboData();

	UFUNCTION(BlueprintCallable, Category = "Combat")
    void ClearHitActors();

    UFUNCTION(Server, Reliable, BlueprintCallable)
    void Server_PerformHitCheck();
	void Server_PerformHitCheck_Implementation();

protected:
    virtual void BeginPlay() override;

    UAnimMontage* ServerPlayMontage;
    FName ServerSection;

    // Combo Data
    int32 iCombo_1_Cnt;
    int32 iCombo_2_Cnt;
    bool bCanCombo;

private:
    UPROPERTY(ReplicatedUsing = OnRep_IsAttacking)
    bool bIsAttacking = false;

    UFUNCTION()
    void OnRep_IsAttacking();

    UPROPERTY()
	TArray<TWeakObjectPtr<AActor>> HitActorsThisAttack;
};