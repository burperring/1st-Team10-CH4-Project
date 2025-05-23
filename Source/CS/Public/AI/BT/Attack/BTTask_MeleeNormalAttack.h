
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_MeleeNormalAttack.generated.h"

UCLASS()
class CS_API UBTTask_MeleeNormalAttack : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
		
public:
	explicit UBTTask_MeleeNormalAttack(FObjectInitializer const& ObjectInitializer);

protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	UFUNCTION()
	void FinishAttack();

	TWeakObjectPtr<UBehaviorTreeComponent> CachedOwnerComp;
};

