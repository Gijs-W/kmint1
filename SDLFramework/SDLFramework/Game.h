#pragma once
#include "FWApplication.h"
#include <ctime>

class Cow;
class Instance;
class Game
{
private:
	bool SingleInstance = false;

	int m_RoundNumber;
	int m_RoundTime;
	int m_TimeRemaining;
	std::time_t m_StartingTime;
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
	bool GameOver();
	~Game();
};

