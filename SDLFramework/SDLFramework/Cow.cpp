#include "IFSMCowWander.h"
#include "Instance.h"
#include "Rabbit.h"
#include "Cow.h"

Cow::Cow()
{
	ResetState();

	int fleeChance = 30 - (rand() % 20);
	int findPillChance = 30 - (rand() % 20);
	int findGunChance = 30 - (rand() % 20);
	int hideChance = 30 - (rand() % 20);
	float total = fleeChance + findPillChance + findGunChance + hideChance;
	m_FleeChance = fleeChance * 100 / total;
	m_FindPillChance = findPillChance * 100 / total;
	m_FindGunChance = findGunChance * 100 / total;
	m_HideChance = hideChance * 100 / total;
}

void Cow::Update(Instance* instance, float deltatime){
	m_CurrentState->Calculate(this, instance);
}


void Cow::ResetState(){
	SetState(new IFSMCowWander());
}

Cow::~Cow()
{

}
