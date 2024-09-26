#pragma once
#include "../../header/UI/UIElement/ImageView.h"


namespace Player
{
	class PlayerController;
	//enum class PlayerState;


	class PlayerView
	{
	private:
		UI::UIElement::ImageView* playerImage;
		sf::RenderWindow* gameWindow;

		PlayerController* playerController;

		float playerWidth;
		float playerHeight;

		void InitializePlayerImage();
		void DrawPlayer();
		void LoadPlayer();
		void CalculatePlayerDimensions();
		void UpdatePlayerPosition();
		sf::Vector2f CalculatePlayerPosition();

	public:
		PlayerView(PlayerController* controller);
		~PlayerView();

		void Initialize();
		void Update();
		void Render();
	};
}














