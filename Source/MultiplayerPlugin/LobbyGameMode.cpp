#include "LobbyGameMode.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	int32 NumOfPlayers;
	// GameState is a local variable of GameMode so no need to initialize it or give it value.
	if (GameState)
	{
		NumOfPlayers = GameState.Get()->PlayerArray.Num();
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Green, FString::Printf(TEXT("Number of players in the session: %d"), NumOfPlayers));

		APlayerState* PlayerState = NewPlayer->GetPlayerState<APlayerState>();
		if (PlayerState != nullptr)
		{
			FString PlayerName = PlayerState->GetPlayerName();
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("%s has joined the game."), *PlayerName));
		}
	}
}

void ALobbyGameMode::Logout(AController* ExitingPlayer)
{
	Super::Logout(ExitingPlayer);

	int32 NumOfPlayers;
	// GameState is a local variable of GameMode so no need to initialize it or give it value.
	if (GameState)
	{
		NumOfPlayers = GameState.Get()->PlayerArray.Num();
	}
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Green, FString::Printf(TEXT("Number of players in the session: %d"), (NumOfPlayers - 1) ));

		APlayerState* PlayerState = ExitingPlayer->GetPlayerState<APlayerState>();
		if (PlayerState != nullptr)
		{
			FString PlayerName = PlayerState->GetPlayerName();
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("%s has left the game."), *PlayerName));
		}
	}
}