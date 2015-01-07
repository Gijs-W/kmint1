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
	auto application = new FWApplication(50, 50, 800, 800);
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));

	Game* game = new Game(application);

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

		application->UpdateGameObjects();
		game->Update(application->GetDeltaTime());

		application->SetColor(Color(0, 0, 0, 255));// For the letter colour
		application->DrawText("[Round] " + std::to_string(game->GetRoundNumber()), 400, 20);
		application->DrawText("[Seconds Remaining] " + std::to_string(game->GetTimeRemaining()), 400, 40);
		application->SetColor(Color(255, 255, 255, 255));// For the background

		application->RenderGameObjects();

		if (game->GameOver()){
			application->Quit();
		}
		application->EndTick();


	}
		
	return EXIT_SUCCESS;
}