#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Game.h"

int main(int args[])
{
	srand(time(0));
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication(50,50,800,800);
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));

	Game* game = new Game(application);
	int TimeRemaining = 30;

	//while (true){}
	while (application->IsRunning())
	{
		application->StartTick();
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.scancode){
				case SDL_SCANCODE_SPACE:

					break;
				default:
					break;
				}
			}
		}

		// For the background
		application->SetColor(Color(255, 255, 255, 255));

		application->UpdateGameObjects();
		application->RenderGameObjects();
		game->Update(application->GetDeltaTime());
		if (TimeRemaining != game->GetTimeRemaining()){
			TimeRemaining = game->GetTimeRemaining();
			printf(("[GAMELOOP] Time Remaining of round " + std::to_string(game->GetRoundNumber()) + ": " + std::to_string(game->GetTimeRemaining()) + "\n").c_str());
		}
		//application->DrawText("test", 10, 10);//hmm.. how did i broke this >.<
		if (game->GameOver()){
			application->Quit();
		}
		application->EndTick();


	}

	return EXIT_SUCCESS;
}