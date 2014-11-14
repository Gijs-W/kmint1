#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Cow.h"
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"

int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));
	


	//own shizzle:
	IGameObject* cow = new Cow();
	SDL_Texture* cowTexture = application->LoadTexture("cow-1.png"); //todo: delete
	cow->SetTexture(cowTexture);

	IGameObject* rabbit = new Cow();
	SDL_Texture* rabitTexture = application->LoadTexture("rabbit-2.png");//todo: delete
	rabbit->SetTexture(rabitTexture);

	/* Make Graph */
	Graph* graph = new Graph();

	Vertex* vertex1 = new Vertex();
	vertex1->SetOffset(1, 5);
	Vertex* vertex2 = new Vertex();
	vertex2->SetOffset(4,7);
	Vertex* vertex3 = new Vertex();
	vertex3->SetOffset(3,3);
	Vertex* vertex4 = new Vertex();
	vertex4->SetOffset(5,1);
	Vertex* vertex5 = new Vertex();
	vertex5->SetOffset(8, 4);

	vertex1->ConnectTo(vertex2, 2);
	vertex2->ConnectTo(vertex1, 2);

	vertex2->ConnectTo(vertex3, 3);
	vertex3->ConnectTo(vertex2, 3);

	vertex1->ConnectTo(vertex3, 1);
	vertex3->ConnectTo(vertex1, 1);

	vertex3->ConnectTo(vertex4, 1);
	vertex4->ConnectTo(vertex3, 1);

	vertex4->ConnectTo(vertex5, 2);
	vertex5->ConnectTo(vertex4, 2);

	vertex3->ConnectTo(vertex5, 3);
	vertex5->ConnectTo(vertex3, 3);

	vertex1->setGameObject(cow);
	vertex5->setGameObject(rabbit);

	//* own shizzle end

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
				switch (event.key.keysym.sym){

				default:
					break;
				}
			}
		}
		
		application->SetColor(Color(0, 0, 0, 255));
		//application->DrawText("Welcome to KMint", 800 / 2, 600 / 2);
		
		// For the background
		application->SetColor(Color(255, 255, 255, 255));


		application->UpdateGameObjects();
		application->AddRenderable(cow);

		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}