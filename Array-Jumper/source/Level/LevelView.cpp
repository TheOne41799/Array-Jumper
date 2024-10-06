#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"


namespace Level
{	
	using namespace Global;
	using namespace UI::UIElement;
	using namespace Level;


	LevelView::LevelView(LevelController* controller)
	{
		gameWindow = nullptr;
		levelController = controller;
		CreateImages();
	}


	LevelView::~LevelView()
	{
		DeleteImages();
	}


	void LevelView::Initialize()
	{
		gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		InitializeImages();
	}


	void LevelView::Update()
	{
		UpdateImages();
	}


	void LevelView::Render()
	{
		DrawLevel();
	}


	void LevelView::CreateImages()
	{
		backgroundImage = new ImageView();

		box_image = new ImageView();
		target_overlay_image = new ImageView();
		letter_one_overlay_image = new ImageView();
		letter_two_overlay_image = new ImageView();
		letter_three_overlay_image = new ImageView();
		obstacle_one_overlay_image = new ImageView();
		obstacle_two_overlay_image = new ImageView();
	}


	void LevelView::InitializeImages()
	{
		backgroundImage->initialize(Config::array_jumper_bg_texture_path, 
									gameWindow->getSize().x, 
									gameWindow->getSize().y,
									sf::Vector2f(0, 0));
		backgroundImage->setImageAlpha(backgroundAlpha);

		box_image->initialize(Config::box_texture_path, box_dimensions.box_width, 
							  box_dimensions.box_height, sf::Vector2f(0, 0));

		target_overlay_image->initialize(Config::target_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		letter_one_overlay_image->initialize(Config::letter_one_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		letter_two_overlay_image->initialize(Config::letter_two_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		letter_three_overlay_image->initialize(Config::letter_three_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		obstacle_one_overlay_image->initialize(Config::obstacle_01_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		obstacle_two_overlay_image->initialize(Config::obstacle_02_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
	}


	void LevelView::UpdateImages()
	{
		backgroundImage->update();

		box_image->update();
		target_overlay_image->update();
		letter_one_overlay_image->update();
		letter_two_overlay_image->update();
		letter_three_overlay_image->update();
		obstacle_one_overlay_image->update();
		obstacle_two_overlay_image->update();
	}


	void LevelView::DrawLevel()
	{
		backgroundImage->render();

		drawBox(sf::Vector2f(0, 0));
		BlockType blockTypeToDraw = levelController->getCurrentBoxValue(0);
		drawBoxValue(sf::Vector2f(0, 0), blockTypeToDraw);
	}


	void LevelView::DeleteImages()
	{
		delete(backgroundImage);

		delete(box_image);
		delete(target_overlay_image);
		delete(letter_one_overlay_image);
		delete(letter_two_overlay_image);
		delete(letter_three_overlay_image);
		delete(obstacle_one_overlay_image);
		delete(obstacle_two_overlay_image);
	}


	void LevelView::calculateBoxDimensions()
	{
		if (!gameWindow) return;

		box_dimensions.box_width = 300.f;
		box_dimensions.box_height = 300.f;
	}


	ImageView* LevelView::getBoxOverlayImage(BlockType block_type)
	{
		switch (block_type)
		{
		case BlockType::OBSTACLE_ONE:
			return obstacle_one_overlay_image;

		case BlockType::OBSTACLE_TWO:
			return obstacle_two_overlay_image;

		case BlockType::ONE:
			return letter_one_overlay_image;

		case BlockType::TWO:
			return letter_two_overlay_image;

		case BlockType::THREE:
			return letter_three_overlay_image;

		case BlockType::TARGET:
			return target_overlay_image;
		}
		return nullptr;
	}


	void LevelView::drawBox(sf::Vector2f position)
	{
		box_image->setPosition(position);
		box_image->render();
	}


	void LevelView::drawBoxValue(sf::Vector2f position, BlockType box_value)
	{
		ImageView* image = getBoxOverlayImage(box_value);
		image->setPosition(position);
		image->render();
	}
}









