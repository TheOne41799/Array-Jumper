#pragma once
#include "../../header/UI/UIElement/ImageView.h"


namespace Player
{
	class PlayerController;

	class PlayerView
	{
	private:
		UI::UIElement::ImageView* playerImage;
		sf::RenderWindow* gameWindow;

		float playerWidth;
		float playerHeight;

		void InitializePlayerImage();
		void DrawPlayer();
		void LoadPlayer();
		void CalculatePlayerDimensions();
		void UpdatePlayerPosition();
		sf::Vector2f CalculatePlayerPosition();

	public:
		PlayerView(PlayerController* playerController);
		~PlayerView();

		void Initialize();
		void Update();
		void Render();
	};
}














