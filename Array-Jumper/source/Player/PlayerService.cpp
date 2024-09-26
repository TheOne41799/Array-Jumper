#include "../../header/Player/PlayerService.h"
#include "../../header/Player/PlayerController.h"


namespace Player
{
	PlayerService::PlayerService()
	{
		playerController = new PlayerController();
	}


	PlayerService::~PlayerService()
	{
		Destroy();
	}


	void PlayerService::Initialize()
	{
		playerController->Initialize();
	}


	void PlayerService::Update()
	{
		playerController->Update();
	}


	void PlayerService::Render()
	{
		playerController->Render();
	}


	void PlayerService::Destroy()
	{
		delete(playerController);
	}
}











