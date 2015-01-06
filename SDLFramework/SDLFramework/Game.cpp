#include "Game.h"
#include "Instance.h"

using std::string;

Game::Game(FWApplication* application)
{
	m_InstanceRed	 = new Instance(application, "red");
	//m_InstanceGreen  = new Instance(application, "green");
	//m_InstanceBlue	 = new Instance(application, "blue");
	//m_InstanceYellow = new Instance(application, "yellow");
}

void Game::Update(float dt){
	m_InstanceRed->Update(dt);
	//m_InstanceGreen->Update(dt);
	//m_InstanceBlue->Update(dt);
	//m_InstanceYellow->Update(dt);
}

Instance* Game::GetInstanceRed(){
	return m_InstanceRed;
}
Instance* Game::GetInstanceGreen(){
	return m_InstanceGreen;
}
Instance* Game::GetInstanceBlue(){
	return m_InstanceBlue;
}
Instance* Game::GetInstanceYellow(){
	return m_InstanceYellow;
}

Game::~Game()
{
}
