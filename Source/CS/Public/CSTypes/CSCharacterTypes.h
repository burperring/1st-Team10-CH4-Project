#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Animation/AnimInstance.h"
#include "CsCharacterTypes.generated.h"

USTRUCT(BlueprintType)
struct FCharacterLobbyData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<USkeletalMesh> LobbyMesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UAnimInstance> LobbyAnimClass = nullptr;
};

UENUM(BlueprintType)
enum class ECharacterTypes : uint8
{
	ECT_Unoccupied UMETA(DisplayName = "Unoccupied"),
	ECT_Attacking UMETA(DisplayName = "Attacking"),
	ECT_Defending UMETA(DisplayName = "Defending"),
	ECT_Moving UMETA(DisplayName = "Moving"),
	ECT_Launch UMETA(DisplayName = "Launched"),
	ECT_Dodge UMETA(DisplayName = "Dodging"),
	ECT_Dead UMETA(DisplayName = "Dead")
};

UENUM(BlueprintType)
enum class EFacingDirection : uint8
{
	EFD_FacingRight UMETA(DisplayName = "FacingRight"),
	EFD_FacingLeft UMETA(DisplayName = "FacingLeft")
};

UENUM(BlueprintType)
enum class EJobTypes : uint8
{
	EJT_None UMETA(DisplayName = "None"),
	EJT_Fighter UMETA(DisplayName = "Fighter"),
	EJT_SwordMan UMETA(DisplayName = "SwordMan")
};

UENUM(BlueprintType)
enum class ELaunchTypes : uint8
{
	EDT_Nomal UMETA(DisplayName = "Nomal"),
	EDT_Launch UMETA(DisplayName = "Launch")
};

UENUM(BlueprintType)
enum class EGroundTypes : uint8
{
	EGT_Down UMETA(DisplayName = "Down"),
	EGT_Up UMETA(DisplayName = "Up")
};

UENUM(BlueprintType)
enum class EStandUpType : uint8
{
	EST_Nomal UMETA(DisplayName = "Nomal"),
	EST_StandUp UMETA(DisplayName = "StandUp")
};