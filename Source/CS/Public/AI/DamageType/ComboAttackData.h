#pragma once

#include "CoreMinimal.h"
#include "CSTypes/CSCharacterTypes.h"
#include "ComboAttackData.generated.h"

USTRUCT(BlueprintType)
struct FComboAttackData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName SectionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ELaunchTypes DType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TraceStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TraceEnd;
};
