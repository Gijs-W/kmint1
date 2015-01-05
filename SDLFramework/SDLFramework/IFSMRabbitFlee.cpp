#include "IFSMRabbitFlee.h"
#include "IFSMRabbitWander.h"
#include <time.h>

#include "MovingEntity.h"

IFSMRabbitFlee::IFSMRabbitFlee()
{
}

void IFSMRabbitFlee::Calculate(MovingEntity* entity, MovingEntity* other){

	//only flee if the target is within 'panic distance'. Work in distance //squared space.

	if (entity->GetPosition().DistanceBetween(other->GetPosition()) > PANNICDISTANCE * 3)
	{
		//switch states
		entity->SetState(new IFSMRabbitWander());
		return;
	}

	Vector2D newHeading = (entity->GetPosition() - other->GetPosition());
	newHeading.Normalize();

	entity->SetHeading(newHeading);
	entity->SetSpeed(FLEESPEED);

	entity->Move(0.0f);

}

IFSMRabbitFlee::~IFSMRabbitFlee()
{
}
