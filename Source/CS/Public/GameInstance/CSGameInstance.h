#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CSTypes/CSGameTypes.h"
#include "CSTypes/CSCharacterTypes.h"
#include "Data/CSCharacterRow.h"
#include "Data/CSLevelRow.h"
#include "Data/CSPlayerLobbyData.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"      
#include "FindSessionsCallbackProxy.h" 
#include "CSGameInstance.generated.h"

UCLASS()
class CS_API UCSGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UCSGameInstance(); 

	virtual void Init() override;
	virtual void Shutdown() override;

	UFUNCTION(BlueprintCallable, Category = "Session")
	void HostSession(EMatchType TypeToHost);

	UFUNCTION(BlueprintCallable, Category = "Session")
	void FindSessions();
	void JoinFoundSession(const FOnlineSessionSearchResult& SearchResult);

	UFUNCTION(BlueprintCallable, Category = "Game Flow")
	void StartArcadeMode();

	UFUNCTION(BlueprintCallable, Category = "Game Flow")
	void ServerTravelToLevel(FName LevelID);
	UFUNCTION(BlueprintCallable, Category = "Game Flow")
	void OpenLevelByID(FName LevelID);

	UFUNCTION(BlueprintCallable)
	void SetMatchType(EMatchType NewType);
	UFUNCTION(BlueprintPure, Category = "Game Flow")
	EMatchType GetMatchType() const { return MatchType; }
	UFUNCTION(BlueprintCallable)
	void ResetLobbySettings();

	const FCharacterRow* FindCharacterRowByJob(EJobTypes Job) const;
	const FLevelRow* FindLevelRow(FName RowName) const;

	bool bIsSessionCreated;

	void SetPlayerLobbyData(const FString& PlayerName, const FPlayerLobbyData& Data);
	FPlayerLobbyData GetPlayerLobbyData(const FString& PlayerName) const;

	UPROPERTY(BlueprintReadWrite, Category = "Match")
	bool bAutoHostIfNoSession;

private:
	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void OnFindSessionsComplete(bool bWasSuccessful);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);

	FDelegateHandle DestroySessionCompleteDelegateHandle;

	IOnlineSessionPtr SessionInterface;
	TSharedPtr<FOnlineSessionSearch> SessionSearch;

	UPROPERTY()
	EMatchType MatchType;

public:
	UPROPERTY(BlueprintReadWrite, Category = "Match")
	int32 ExpectedPlayerCount;

	UPROPERTY()
	TMap<FString, FPlayerLobbyData> PlayerLobbyDataMap;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DataTables")
	TObjectPtr<UDataTable> CharacterData; 

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DataTables")
	TObjectPtr<UDataTable> AIData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DataTables")
	TObjectPtr<UDataTable> LevelData;
};
