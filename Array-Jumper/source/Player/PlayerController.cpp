#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"


namespace Player
{
	PlayerController::PlayerController()
	{
		playerModel = new PlayerModel();
		playerView = new PlayerView(this);
	}


	PlayerController::~PlayerController()
	{
		Destroy();
	}


	void PlayerController::Initialize()
	{
		playerModel->initialize();
		playerView->initialize();

		resetPlayer();
	}


	void PlayerController::Update()
	{
		playerView->update();
	}


	void PlayerController::Render()
	{
		playerView->render();
	}


	void PlayerController::Destroy()
	{
		delete(playerModel);
		delete(playerView);
	}


	PlayerState PlayerController::GetPlayerState()
	{
		return playerModel->GetPlayerState();
	}


	void PlayerController::SetPlayerState(PlayerState state)
	{
		playerModel->SetPlayerState(state);
	}


	int PlayerController::getCurrentPosition()
	{
		return playerModel->GetCurrentPosition();
	}


	void PlayerController::resetPlayer()
	{
		playerModel->SetCurrentPosition(0);
		playerModel->SetPlayerState(PlayerState::ALIVE);
	}
}









