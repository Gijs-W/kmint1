#include "IFSMRabbitFlee.h"
#include "IFSMRabbitWander.h"
#include <time.h>

#include "MovingEntity.h"
#include "Cow.h"

IFSMRabbitFlee::IFSMRabbitFlee()
{
}

void IFSMRabbitFlee::Calculate(MovingEntity* entity, Instance* instance){

	//only flee if the target is within 'panic distance'
	Cow* target = instance->GetCow();
	if (entity->GetPosition().DistanceBetween(target->GetPosition()) > PANIC_DISTANCE * 3)
	{
		//switch states
		entity->SetState(new IFSMRabbitWander());
		return;
	}

	Vector2D newHeading = (entity->GetPosition() - target->GetPosition());
	newHeading.Normalize();

	entity->SetHeading(newHeading);
	entity->SetSpeed(FLEESPEED);

	entity->Move(0.0f);

}

IFSMRabbitFlee::~IFSMRabbitFlee()
{
}
