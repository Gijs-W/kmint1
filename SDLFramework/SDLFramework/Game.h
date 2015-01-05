#pragma once
#include "FWApplication.h"

class Rabbit;
class Cow;
class Game
{
private:
	Cow* m_Cow;
	Rabbit* m_Rabbit;
public:
	Game(FWApplication* application);
	void Update(float dt);
	Cow* GetCows();
	Rabbit* GetRabbits();
	~Game();
};

