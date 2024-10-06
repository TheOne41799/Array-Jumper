#pragma once
#include <SFML/Graphics.hpp>
#include <../../header/UI/UIElement/ImageView.h>
#include "LevelModel.h"


namespace Level
{
	class LevelController;


	class LevelView
	{
	private:
		sf::RenderWindow* gameWindow;
		LevelController* levelController;

		UI::UIElement::ImageView* backgroundImage;

		const float backgroundAlpha = 110.0f;

		BoxDimensions box_dimensions;

		UI::UIElement::ImageView* box_image;

		UI::UIElement::ImageView* target_overlay_image;
		UI::UIElement::ImageView* letter_one_overlay_image;
		UI::UIElement::ImageView* letter_two_overlay_image;
		UI::UIElement::ImageView* letter_three_overlay_image;
		UI::UIElement::ImageView* obstacle_one_overlay_image;
		UI::UIElement::ImageView* obstacle_two_overlay_image;

		void CreateImages();
		void InitializeImages();
		void UpdateImages();
		void DrawLevel();
		void DeleteImages();

		void calculateBoxDimensions();

		UI::UIElement::ImageView* getBoxOverlayImage(BlockType block_type);

		void drawBox(sf::Vector2f position);

		void drawBoxValue(sf::Vector2f position, BlockType box_value);

	public:
		LevelView(LevelController* controller);
		~LevelView();

		void Initialize();
		void Update();
		void Render();

		
	};
}












