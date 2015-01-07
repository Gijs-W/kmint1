#include "IFSMCowFindPill.h"
#include "IFSMCowPillFound.h"

#include "Instance.h"
#include "Pill.h"

IFSMCowFindPill::IFSMCowFindPill()
{
}

void IFSMCowFindPill::Calculate(MovingEntity* entity, Instance* instance){

	Pill* target = instance->GetPill();
	if (entity->GetPosition().DistanceBetween(target->GetPosition()) <= CATCH_DISTANCE)
	{
		//switch states
		printf("[Cow] found the Pill!\n");
		entity->SetState(new IFSMCowPillFound());
		instance->ResetEntities(false, false, true, false);
		return;
	}

	Vector2D newHeading = (target->GetPosition() - entity->GetPosition());
	newHeading.Normalize();

	entity->SetSpeed(PURSUITSPEED);
	entity->SetHeading(newHeading);
	entity->Move(0.0f);

}

IFSMCowFindPill::~IFSMCowFindPill()
{
}
