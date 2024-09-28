#pragma once
#include <SFML/Graphics.hpp>
#include <../../header/UI/UIElement/ImageView.h>



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

		void CreateImages();
		void InitializeImages();
		void UpdateImages();
		void DrawLevel();
		void DeleteImages();

	public:
		LevelView(LevelController* controller);
		~LevelView();

		void Initialize();
		void Update();
		void Render();
	};
}












