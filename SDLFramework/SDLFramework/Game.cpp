#include "Game.h"
#include "Instance.h"

using std::string;

Game::Game(FWApplication* application)
{
	m_RoundNumber = 1;
	m_RoundTime = 30;
	ResetRoundTimer();
	m_InstanceRed	 = new Instance(application, "red");
	if (!SingleInstance){
		m_InstanceGreen  = new Instance(application, "green");
		m_InstanceBlue	 = new Instance(application, "blue");
		m_InstanceYellow = new Instance(application, "yellow");
	}
}

void Game::Update(float dt){
	m_InstanceRed->Update(dt);
	if (!SingleInstance){
		m_InstanceGreen->Update(dt);
		m_InstanceBlue->Update(dt);
		m_InstanceYellow->Update(dt);
	}

	m_TimeRemaining = m_RoundTime - (std::time(nullptr) - m_StartingTime);
	if (m_TimeRemaining < 0){
		NewRound();
	}
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

int Game::GetTimeRemaining(){
	return m_TimeRemaining;
}
int Game::GetRoundNumber(){
	return m_RoundNumber;
}

void Game::ResetRoundTimer(){
	m_StartingTime = std::time(nullptr);
	m_TimeRemaining = m_RoundTime;
}

void Game::NewRound(){
	if (m_RoundNumber >= 5){
		m_GameOver = true;
		return;
	}
	m_RoundNumber++;
	ResetRoundTimer();
	
	m_InstanceRed->NewRound();
	if (!SingleInstance){
		m_InstanceGreen->NewRound();
		m_InstanceBlue->NewRound();
		m_InstanceYellow->NewRound();
	}

}

bool Game::GameOver(){
	return m_GameOver;
}

Game::~Game()
{
}
