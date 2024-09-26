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
		playerView->Initialize();
	}


	void PlayerController::Update()
	{
		playerView->Update();
	}


	void PlayerController::Render()
	{
		playerView->Render();
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
}









