#include "../../header/Player/PlayerView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"


namespace Player
{
	using namespace UI::UIElement;
	using namespace Global;



	PlayerView::PlayerView(PlayerController* playerController)
	{
		gameWindow = nullptr;
		playerImage = new ImageView();
	}


	PlayerView::~PlayerView(){}


	void PlayerView::Initialize()
	{
		gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		LoadPlayer();
	}


	void PlayerView::Update()
	{
		UpdatePlayerPosition();
	}


	void PlayerView::Render()
	{
		DrawPlayer();
	}


	void PlayerView::CalculatePlayerDimensions()
	{
		playerWidth = 1000.0f;
		playerHeight = 1000.0f;
	}


	void PlayerView::InitializePlayerImage()
	{
		playerImage->initialize(Config::character_texture_path, playerWidth, playerHeight, sf::Vector2f(0, 0));
	}


	void PlayerView::LoadPlayer()
	{
		CalculatePlayerDimensions();
		InitializePlayerImage();
	}


	sf::Vector2f PlayerView::CalculatePlayerPosition()
	{
		return sf::Vector2f(0, 0);
	}


	void PlayerView::UpdatePlayerPosition()
	{
		playerImage->setPosition(CalculatePlayerPosition());
		
	}


	void PlayerView::DrawPlayer()
	{
		playerImage->render();
	}
}













