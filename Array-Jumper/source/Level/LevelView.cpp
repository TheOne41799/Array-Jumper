#include "../../header/Level/LevelView.h"
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
	}


	void LevelView::InitializeImages()
	{
		backgroundImage->initialize(Config::array_jumper_bg_texture_path, 
									gameWindow->getSize().x, 
									gameWindow->getSize().y,
									sf::Vector2f(0, 0));
		backgroundImage->setImageAlpha(backgroundAlpha);
	}


	void LevelView::UpdateImages()
	{
		backgroundImage->update();
	}


	void LevelView::DrawLevel()
	{
		backgroundImage->render();
	}


	void LevelView::DeleteImages()
	{
		delete(backgroundImage);
	}
}









