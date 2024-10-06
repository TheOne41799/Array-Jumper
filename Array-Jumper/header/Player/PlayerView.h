//#pragma once
//#include "../../header/UI/UIElement/ImageView.h"
//#include "../../header/Level/LevelModel.h"
//
//
//namespace Player
//{
//	class PlayerController;
//	//enum class PlayerState;
//
//
//	class PlayerView
//	{
//	private:
//		UI::UIElement::ImageView* playerImage;
//		sf::RenderWindow* gameWindow;
//
//		PlayerController* playerController;
//
//		Level::BoxDimensions current_box_dimensions;
//
//		float playerWidth;
//		float playerHeight;
//
//		void InitializePlayerImage();
//		void DrawPlayer();
//		void LoadPlayer();
//		void CalculatePlayerDimensions();
//		void UpdatePlayerPosition();
//		sf::Vector2f CalculatePlayerPosition();
//
//	public:
//		PlayerView(PlayerController* controller);
//		~PlayerView();
//
//		void Initialize();
//		void Update();
//		void Render();
//	};
//}
//
//
//
//
//
//
//
//
//
//
//
//
//




#pragma once
#include "../../header/Level/LevelModel.h"
#include "../../header/UI/UIElement/ImageView.h"


namespace Player
{
	class PlayerController;
	class PlayerView
	{
	private:
		// TODO: Fix spacing. References grouped together + properties grouped together. 
		sf::RenderWindow* game_window;
		PlayerController* player_controller;
		UI::UIElement::ImageView* player_image;

		float player_height;
		float player_width;
		Level::BoxDimensions current_box_dimensions;

		void initializePlayerImage();
		void drawPlayer();
		void loadPlayer();
		void calculatePlayerDimensions();
		void updatePlayerPosition();
		sf::Vector2f calulcatePlayerPosition();

	public:
		PlayerView(PlayerController* controller);
		~PlayerView();

		void initialize();
		void update();
		void render();

	};
}


