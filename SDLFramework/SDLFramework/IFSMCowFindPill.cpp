#include "IFSMCowFindPill.h"

#include "Instance.h"
#include "Pill.h"

IFSMCowFindPill::IFSMCowFindPill()
{
}

void IFSMCowFindPill::Calculate(MovingEntity* entity, Instance* instance){

	Pill* target = instance->GetPill();
	Vector2D newHeading = (target->GetPosition() - entity->GetPosition());
	newHeading.Normalize();

	entity->SetSpeed(PURSUITSPEED);
	entity->SetHeading(newHeading);
	entity->Move(0.0f);

}

IFSMCowFindPill::~IFSMCowFindPill()
{
}
