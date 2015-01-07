#include "IFSMCowWander.h"
#include "Instance.h"
#include "Rabbit.h"
#include "Cow.h"

Cow::Cow()
{
	SetSpeed(COW_SPEED);
	ResetState();

	SetChoiceChances(30 - (rand() % 20), 30 - (rand() % 20), 30 - (rand() % 20), 30 - (rand() % 20));
}

void Cow::Update(Instance* instance, float deltatime){
	m_CurrentState->Calculate(this, instance);
}


void Cow::ResetState(){
	SetState(new IFSMCowWander());
}

void Cow::SetChoiceChances(float fleeChance, float findPillChance, float findGunChance, float hideChance){
	float total = fleeChance + findPillChance + findGunChance + hideChance;
	m_FleeChance = fleeChance * 100 / total;
	m_FindPillChance = findPillChance * 100 / total;
	m_FindGunChance = findGunChance * 100 / total;
	m_HideChance = hideChance * 100 / total;
}

Cow::~Cow()
{

}
