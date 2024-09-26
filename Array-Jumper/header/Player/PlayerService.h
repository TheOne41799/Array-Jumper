#pragma once


namespace Player
{
	class PlayerController;

	class PlayerService
	{
	private:
		PlayerController* playerController;

		void Destroy();

	public:
		PlayerService();
		~PlayerService();

		void Initialize();
		void Update();
		void Render();
	};
}








