#include "../../header/Player/PlayerModel.h"


namespace Player
{
	PlayerState PlayerModel::GetPlayerState()
	{
		return playerState;
	}


	void PlayerModel::SetPlayerState(PlayerState state)
	{
		playerState = state;
	}


	int PlayerModel::GetCurrentPosition()
	{
		return currentPosition;
	}


	void PlayerModel::SetCurrentPosition(int position)
	{
		currentPosition = position;
	}
}













