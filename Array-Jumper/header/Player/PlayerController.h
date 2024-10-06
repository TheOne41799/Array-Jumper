#pragma once
#include "../../header/Event/EventService.h"
#include "MovementDirection.h"


namespace Player
{
	class PlayerModel;
	class PlayerView;
	enum class PlayerState;


	class PlayerController
	{
	private:
		PlayerModel* playerModel;
		PlayerView* playerView;

		Event::EventService* event_service;

		void Destroy();
		void resetPlayer();

		void move(MovementDirection direction);
		bool isPositionInBound(int targetPosition);

		void readInput();

		void jump(MovementDirection direction);

	public:
		PlayerController();
		~PlayerController();

		void Initialize();
		void Update();
		void Render();

		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState state);

		int getCurrentPosition();
	};
}










