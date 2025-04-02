#include "GameModes/CSMainMenuGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameInstance/CSGameInstance.h"
#include "GameFramework/PlayerController.h"
#include "Controller/CSPlayerController.h"

void ACSMainMenuGameMode::BeginPlay()
{
    Super::BeginPlay();

}

void ACSMainMenuGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    if (ACSPlayerController* PC = Cast<ACSPlayerController>(NewPlayer))
    {
        // 클라이언트 RPC 호출 (아직 구현되지 않았을 수 있으므로 주의)
        // PC->Client_ShowUI(MainMenuWidgetClass);
    }
}

void ACSMainMenuGameMode::TryStartMatch()
{
    if (const UCSGameInstance* GI = GetGameInstance<UCSGameInstance>())
    {
        switch (GI->MatchType)
        {
        case EMatchType::EMT_Single:
            UGameplayStatics::OpenLevel(this, FName("TutorialLevel"));
            break;
        case EMatchType::EMT_Versus:
        case EMatchType::EMT_Coop:
            UGameplayStatics::OpenLevel(this, FName("LobbyLevel"));
            break;
        default:
            UE_LOG(LogTemp, Warning, TEXT("[MainMenu] Invalid MatchType set in GameInstance."));
            break;
        }
    }
}