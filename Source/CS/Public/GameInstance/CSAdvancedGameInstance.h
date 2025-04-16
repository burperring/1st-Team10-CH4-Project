#pragma once

#include "CoreMinimal.h"
#include "AdvancedFriendsGameInstance.h"
#include "CSTypes/CSGameTypes.h"
#include "CSTypes/CSCharacterTypes.h"
#include "Data/CSCharacterRow.h"
#include "Data/CSLevelRow.h"
#include "Data/CSPlayerLobbyData.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "CSAdvancedGameInstance.generated.h"

UCLASS()
class CS_API UCSAdvancedGameInstance : public UAdvancedFriendsGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	/** MatchType 관련 게터&세터 */
	UFUNCTION(BlueprintCallable)
	void SetMatchType(EMatchType NewType);
	UFUNCTION(BlueprintPure)
	EMatchType GetMatchType() const { return MatchType; }
	UFUNCTION(BlueprintCallable)
	void ResetLobbySettings();

	/** Travel 관련 함수 */
	UFUNCTION(BlueprintCallable)
	void StartArcadeMode();
	UFUNCTION(BlueprintCallable)
	void HostServerTravel();
	UFUNCTION(BlueprintCallable)
	void ServerTravelToLevel(FName LevelID);
	UFUNCTION(BlueprintCallable)
	void OpenLevelByID(FName LevelID);

	/** 로비 데이터 컨트롤 */
	void SetPlayerLobbyData(const FString& PlayerName, const FPlayerLobbyData& Data);
	FPlayerLobbyData GetPlayerLobbyData(const FString& PlayerName) const;

	/** 데이터 테이블 Row 반환 */
	const FCharacterRow* FindCharacterRowByJob(EJobTypes Job) const;
	const FLevelRow* FindLevelRow(FName RowName) const;

	UPROPERTY(BlueprintReadWrite)
	bool bAutoHostIfNoSession;

	UPROPERTY(BlueprintReadWrite)
	int32 ExpectedPlayerCount;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UDataTable> CharacterData;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UDataTable> AIData;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UDataTable> LevelData;

private:
	IOnlineSessionPtr SessionInterface;
	TSharedPtr<FOnlineSessionSearch> SessionSearch;
	FDelegateHandle DestroySessionCompleteDelegateHandle;

	UPROPERTY()
	EMatchType MatchType;

	UPROPERTY()
	TMap<FString, FPlayerLobbyData> PlayerLobbyDataMap;
};
