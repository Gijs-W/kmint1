#include "Game.h"


Game::Game(FWApplication* application)
{
	m_IC = new InstanceController(application);
	ResetRoundTimer();
}

void Game::Update(float dt){
	m_IC->Update(dt);

	m_TimeRemaining = m_RoundTime - (time(nullptr) - m_StartingTime);
	if (m_TimeRemaining < 0){
		NewRound();
	}
}

int Game::GetTimeRemaining(){
	return m_TimeRemaining;
}
int Game::GetRoundNumber(){
	return m_RoundNumber;
}

void Game::ResetRoundTimer(){
	m_StartingTime = time(nullptr);
	m_TimeRemaining = m_RoundTime;
}

void Game::NewRound(){
	
	m_IC->SaveRoundInformation(m_RoundNumber);

	if (m_RoundNumber >= m_MaxRounds){
		m_GameOver = true;
		return;
	}

	m_IC->Foreplay();//Let the cows make love and let the new generation take over!
	
	m_RoundNumber++;
	ResetRoundTimer();
}

bool Game::GameOver(){
	return m_GameOver;
}

void Game::Pause(){
	m_Pause = !m_Pause;
	if (m_Pause){
		m_PauseTime = std::time(nullptr);
	}
	else{
		m_StartingTime += std::time(nullptr) - m_PauseTime;
	}
}
bool Game::IsPause(){
	return m_Pause;
}




Game::~Game()
{
}
