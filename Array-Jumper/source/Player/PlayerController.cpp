#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"


namespace Player
{
	using namespace Event;
	using namespace Level;
	using namespace Global;
	using namespace Sound;


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

		event_service = ServiceLocator::getInstance()->getEventService();
		resetPlayer();
	}


	void PlayerController::Update()
	{
		playerView->update();
		readInput();
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


	void PlayerController::move(MovementDirection direction)
	{
		int steps, targetPosition;
		switch (direction)
		{
		case MovementDirection::FORWARD:
			steps = 1;
			break;
		case MovementDirection::BACKWARD:
			steps = -1;
			break;
		default:
			steps = 0;
			break;
		}

		targetPosition = playerModel->GetCurrentPosition() + steps;

		if (!isPositionInBound(targetPosition))
			return;

		playerModel->SetCurrentPosition(targetPosition);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::MOVE);
	}


	bool PlayerController::isPositionInBound(int targetPosition)
	{
		if (targetPosition >= 0 && targetPosition < LevelData::NUMBER_OF_BOXES)
			return true;
		return false;
	}


	void PlayerController::readInput()
	{
		if (event_service->pressedRightArrowKey() || event_service->pressedDKey())
		{
			if (event_service->heldSpaceKey())
				jump(MovementDirection::FORWARD);
			else
				move(MovementDirection::FORWARD);
		}
		if (event_service->pressedLeftArrowKey() || event_service->pressedAKey())
		{
			if (event_service->heldSpaceKey())
				jump(MovementDirection::BACKWARD);
			else
				move(MovementDirection::BACKWARD);
		}
	}


	void PlayerController::jump(MovementDirection direction)
	{
		int current_position = playerModel->GetCurrentPosition();
		BlockType box_value = ServiceLocator::getInstance()->GetLevelService()->getCurrentBoxValue(current_position);
		int steps, targetPosition;

		switch (direction)
		{
		case MovementDirection::FORWARD:
			steps = box_value;
			break;
		case MovementDirection::BACKWARD:
			steps = -box_value;
			break;
		default:
			steps = 0;
			break;
		}

		targetPosition = current_position + steps;

		if (!isPositionInBound(targetPosition))
			return;

		playerModel->SetCurrentPosition(targetPosition);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::JUMP);
	}
}









