#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelModel.h"


namespace Level
{
	LevelController::LevelController()
	{
		level_view = new LevelView(this);
		level_model = new LevelModel();
	}

	LevelController::~LevelController() {}

	void LevelController::initialize()
	{
		level_view->Initialize();
	}

	void LevelController::update()
	{
		level_view->Update();
	}

	void LevelController::render()
	{
		level_view->Render();
	}
}



