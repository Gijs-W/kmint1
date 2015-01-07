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
	auto application = new FWApplication();
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
					game->Pause();
					break;
				default:
					break;
				}
			}
		}

		application->UpdateGameObjects();
		if (!game->IsPause()){
			game->Update(application->GetDeltaTime());
		}
		application->RenderGameObjects();

		application->SetColor(Color(0, 0, 0, 255));// For the letter colour
		application->DrawTextWithWhiteBorder("[Round] " + std::to_string(game->GetRoundNumber()), SCREEN_WIDTH / 2, 20);
		application->DrawTextWithWhiteBorder("[Seconds Remaining] " + std::to_string(game->GetTimeRemaining()), SCREEN_WIDTH / 2, 40);
		if (game->IsPause()){
			application->DrawTextWithWhiteBorder("[PAUSE]", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
			application->SetColor(Color(238, 233, 233, 255));// For the background
		}
		else{
			application->SetColor(Color(255, 255, 255, 255));// For the background
		}


		if (game->GameOver()){
			application->Quit();
		}
		application->EndTick();


	}
		
	return EXIT_SUCCESS;
}