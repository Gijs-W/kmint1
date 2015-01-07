#pragma once
#include "FWApplication.h"
#include <ctime>

class Cow;
class Instance;
class Game
{
private:
	bool m_SingleInstance{ false };
	bool m_Pause{ false };

	int m_RoundNumber{ 1 };//Current Round Number... Let's start with 1, okey?
	int m_RoundTime{ 30 };//Seconds per round
	int m_MaxRounds{ 100 };//Total amount of rounds
	int m_TimeRemaining;
	std::time_t m_StartingTime;
	std::time_t m_PauseTime;//Variable, used to stop the timer during pause
	Instance* m_InstanceRed;
	Instance* m_InstanceGreen;
	Instance* m_InstanceBlue;
	Instance* m_InstanceYellow;

	bool m_GameOver = false;
	void NewRound();

	void SetCowChoices(Cow* target, Cow* Mom, Cow* Dad, int slice);
public:
	Game(FWApplication* application);
	void Update(float dt);
	Instance* GetInstanceRed();
	Instance* GetInstanceGreen();
	Instance* GetInstanceBlue();
	Instance* GetInstanceYellow();
	int GetTimeRemaining();
	int GetRoundNumber();
	void ResetRoundTimer();
	void Pause();
	bool IsPause();
	bool GameOver();
	~Game();
};

