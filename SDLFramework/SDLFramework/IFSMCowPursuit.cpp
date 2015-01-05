#include "IFSMCowPursuit.h"

#include "MovingEntity.h"

IFSMCowPursuit::IFSMCowPursuit()
{
}


void IFSMCowPursuit::Calculate(MovingEntity* entity, MovingEntity* other){

	Vector2D newHeading = (other->GetPosition() - entity->GetPosition());
	newHeading.Normalize();

	entity->SetSpeed(PURSUITSPEED);
	entity->SetHeading(newHeading);
	entity->Move(0.0f);

}


IFSMCowPursuit::~IFSMCowPursuit()
{
}
