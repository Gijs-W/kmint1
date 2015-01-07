#include "IFSMCowFlee.h"

#include "MovingEntity.h"
#include "Rabbit.h"

IFSMCowFlee::IFSMCowFlee()
{
}


void IFSMCowFlee::Calculate(MovingEntity* entity, Instance* instance){

	Rabbit* target = instance->GetRabbit();

	Vector2D newHeading = (entity->GetPosition() - target->GetPosition());
	newHeading.Normalize();

	entity->SetHeading(newHeading);

	entity->Move(0.0f);

}

IFSMCowFlee::~IFSMCowFlee()
{
}
