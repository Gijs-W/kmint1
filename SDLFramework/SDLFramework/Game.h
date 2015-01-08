#pragma once
#include "FWApplication.h"
#include "InstanceController.h"
#include <ctime>

using std::time_t;

class Game
{
private:
	bool m_Pause{ false };

	int m_RoundNumber{ 1 };//Current Round Number... Let's start with 1, okey?
	int m_RoundTime{ 30 };//Seconds per round
	int m_MaxRounds{ 5 };//Total amount of rounds
	int m_TimeRemaining;
	time_t m_StartingTime;
	time_t m_PauseTime;//Variable, used to stop the timer during pause

	bool m_GameOver = false;
	void NewRound();

	InstanceController* m_IC;

public:
	Game(FWApplication* application);
	void Update(float dt);
	int GetTimeRemaining();
	int GetRoundNumber();
	void ResetRoundTimer();
	void Pause();
	bool IsPause();
	bool GameOver();
	~Game();
};

