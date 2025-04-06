#include "GameStates/CSGameStateBase.h"
#include "Controller/CSPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

ACSGameStateBase::ACSGameStateBase()
{
	MatchPhase = EMatchPhase::EMP_None;
	RemainingMatchTime = 0;
}

void ACSGameStateBase::OnRep_MatchPhase()
{
	if (ACSPlayerController* CSPlayerController = Cast<ACSPlayerController>(UGameplayStatics::GetPlayerController(this, 0)))
	{
		/*CSPlayerController->OnMatchPhaseChanged();*/
	}
}

void ACSGameStateBase::OnRep_RemainingMatchTime()
{
	if (ACSPlayerController* CSPlayerController = Cast<ACSPlayerController>(UGameplayStatics::GetPlayerController(this, 0)))
	{
		/*CSPlayerController->UpdateMatchTimeUI(RemainingMatchTime);*/
	}
}

void ACSGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACSGameStateBase, MatchPhase);
	DOREPLIFETIME(ACSGameStateBase, RemainingMatchTime);
}
