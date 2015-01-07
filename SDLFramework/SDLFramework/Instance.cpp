#include "Instance.h"
#include "Rabbit.h"
#include "Cow.h"
#include "Pill.h"
#include "Gun.h"
#include "IFSM.h"

#include <string>


Instance::Instance(FWApplication* application, std::string colour)
{
	m_Colour = colour;

	m_Cow = new Cow();
	SDL_Texture* cowTexture = application->LoadTexture("Cow/cow-" + colour + ".png");
	m_Cow->SetTexture(cowTexture);
	m_Cow->SetSize(32, 32);
	application->AddRenderable(m_Cow);

	m_Rabbit = new Rabbit();
	SDL_Texture* rabitTexture = application->LoadTexture("Rabbit/rabbit-" + colour + ".png");
	m_Rabbit->SetTexture(rabitTexture);
	m_Rabbit->SetSize(32, 32);
	application->AddRenderable(m_Rabbit);

	m_Pill = new Pill();
	SDL_Texture* pillTexture = application->LoadTexture("Pill/pill-" + colour + ".png");
	m_Pill->SetTexture(pillTexture);
	m_Pill->SetSize(32, 32);
	application->AddRenderable(m_Pill);

	m_Gun = new Gun();
	SDL_Texture* gunTexture = application->LoadTexture("Gun/gun-" + colour + ".png");
	m_Gun->SetTexture(gunTexture);
	m_Gun->SetSize(32, 32);
	application->AddRenderable(m_Gun);

	ResetEntities(true, true, true, true);
}

void Instance::Update(float dt){
	m_Cow->Update(this, dt);
	m_Rabbit->Update(this, dt);
	m_Pill->Update(this, dt);
	m_Gun->Update(this, dt);
}

Cow* Instance::GetCow(){
	return m_Cow;
}
Rabbit* Instance::GetRabbit(){
	return m_Rabbit;
}
Pill* Instance::GetPill(){
	return m_Pill;
}
Gun* Instance::GetGun(){
	return m_Gun;
}

void Instance::ResetEntities(bool Cow, bool Rabbit, bool Pill, bool Gun){
	if (Cow) ResetCow();
	if (Rabbit) ResetRabbit();
	if (Pill) ResetPill();
	if (Gun) ResetGun();
}

void Instance::HardResetEntities(){
	HardResetCow();
	HardResetRabbit();
	ResetPill();
	ResetGun();
}

void Instance::ResetCow(){
	int x = 400 - (rand() % 400);
	int y = 800 - (rand() % 800);
	m_Cow->SetPosition(Vector2D(x, y));
	m_Cow->SetOffset(x, y);
	if (m_Cow->GetState()->ShouldResetState()){
		m_Cow->ResetState();
	}
}

void Instance::HardResetCow(){
	ResetCow();
	m_Cow->AddPoints(-m_Cow->GetPoints());
	m_Cow->ResetState();
}

void Instance::ResetRabbit(){
	int x = m_Cow->GetPosition().x + 400;
	int y = m_Cow->GetPosition().y;
	m_Rabbit->SetPosition(Vector2D(x, y));
	m_Rabbit->SetOffset(x, y);
	//m_Rabbit->ResetState();
	m_Rabbit->AddPoints(-m_Rabbit->GetPoints());
}

void Instance::HardResetRabbit(){
	ResetCow();
	m_Rabbit->AddPoints(-m_Rabbit->GetPoints());
}

void Instance::ResetPill(){
	int x = 800 - (rand() % 800);
	int y = 800 - (rand() % 800);
	m_Pill->SetPosition(Vector2D(x, y));
	m_Pill->SetOffset(x, y);
}

void Instance::ResetGun(){
	int x = 800 - (rand() % 800);
	int y = 800 - (rand() % 800);
	m_Gun->SetPosition(Vector2D(x, y));
	m_Gun->SetOffset(x, y);
}

void Instance::NewRound(){

	//Hard Reset All entities:
	HardResetEntities();

}

void Instance::SaveRoundInformation(){

	//Save data to file
	printf("-----------------------------\n");
	printf(("--- Colour: " + m_Colour + " ---\n").c_str());
	printf(("--- Cow Points: " + std::to_string(m_Cow->GetPoints()) + " ---\n").c_str());
	printf(("--- Rabbit Points: " + std::to_string(m_Rabbit->GetPoints()) + " ---\n").c_str());

}


void Instance::DeleteEntity(IGameObject* entity){
	//m_Application->RemoveTexture(entity->GetTexture());//Todo.. fix
	delete entity;
}
Instance::~Instance()
{
	DeleteEntity(m_Cow);
	DeleteEntity(m_Rabbit);
	DeleteEntity(m_Pill);
	DeleteEntity(m_Gun);
}
