#pragma once
#include "FWApplication.h"

class Instance;
class Game
{
private:
	Instance* m_InstanceRed;
	Instance* m_InstanceGreen;
	Instance* m_InstanceBlue;
	Instance* m_InstanceYellow;
public:
	Game(FWApplication* application);
	void Update(float dt);
	Instance* GetInstanceRed();
	Instance* GetInstanceGreen();
	Instance* GetInstanceBlue();
	Instance* GetInstanceYellow();
	~Game();
};

