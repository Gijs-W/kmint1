#include "IFSMCowPursuit.h"

#include "MovingEntity.h"
#include "Instance.h"
#include "Rabbit.h"

IFSMCowPursuit::IFSMCowPursuit()
{
}


void IFSMCowPursuit::Calculate(MovingEntity* entity, Instance* instance){

	Rabbit* target = instance->GetRabbit();
	Vector2D newHeading = (target->GetPosition() - entity->GetPosition());
	newHeading.Normalize();

	entity->SetHeading(newHeading);
	entity->Move(0.0f);

}


IFSMCowPursuit::~IFSMCowPursuit()
{
}
