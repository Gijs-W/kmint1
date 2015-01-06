#include "IFSMCowFindGun.h"

#include "Instance.h"
#include "Gun.h"

IFSMCowFindGun::IFSMCowFindGun()
{
}

void IFSMCowFindGun::Calculate(MovingEntity* entity, Instance* instance){

	Gun* target = instance->GetGun();
	Vector2D newHeading = (target->GetPosition() - entity->GetPosition());
	newHeading.Normalize();

	entity->SetSpeed(PURSUITSPEED);
	entity->SetHeading(newHeading);
	entity->Move(0.0f);

}

IFSMCowFindGun::~IFSMCowFindGun()
{
}
