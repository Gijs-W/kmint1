#include "Game.h"
#include "Rabbit.h"
#include "Cow.h"

Game::Game(FWApplication* application)
{
	m_Rabbit = new Rabbit();
	SDL_Texture* rabitTexture = application->LoadTexture("rabbit-2.png");//todo: delete
	m_Rabbit->SetTexture(rabitTexture);
	m_Rabbit->SetSize(32, 32);
	m_Rabbit->SetPosition(Vector2D(100, 100));
	m_Rabbit->SetOffset(1000, 1000);

	m_Cow = new Cow();
	SDL_Texture* cowTexture = application->LoadTexture("cow-1.png"); //todo: delete
	m_Cow->SetTexture(cowTexture);
	m_Cow->SetSize(32, 32);
	m_Rabbit->SetOffset(1300, 1000);

	application->AddRenderable(m_Cow);
	application->AddRenderable(m_Rabbit);
}

void Game::Update(float dt){
	m_Rabbit->Update(this, dt);
	m_Cow->Update(this, dt);
}


Cow* Game::GetCows(){ 
	return m_Cow; 
}
Rabbit* Game::GetRabbits(){ 
	return m_Rabbit; 
}

Game::~Game()
{
}
