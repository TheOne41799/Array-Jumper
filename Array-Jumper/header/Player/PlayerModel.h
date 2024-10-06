#pragma once


namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
	};


	class PlayerModel
	{
	private:
		int currentPosition;
		PlayerState playerState;

	public:
		void initialize();

		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState state);

		int GetCurrentPosition();
		void SetCurrentPosition(int position);
	};
}
