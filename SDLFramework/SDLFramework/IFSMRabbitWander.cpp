#include "IFSMRabbitFlee.h"
#include "IFSMRabbitWander.h"
#include <time.h>

#include "MovingEntity.h"
#include "Cow.h"

IFSMRabbitWander::IFSMRabbitWander()
{
}


void IFSMRabbitWander::Calculate(MovingEntity* entity, Instance* instance){

	//only flee if the target is within 'panic distance'. Work in distance //squared space.
	Cow* target = instance->GetCow();
	if (entity->GetPosition().DistanceBetween(target->GetPosition()) < PANIC_DISTANCE)
	{
		//switch states
		entity->SetState(new IFSMRabbitFlee());
		return;
	}

	srand(time(nullptr));

	int iX = 13 - (rand() % 25);
	int iY = 13 - (rand() % 25);

	Vector2D newHeading = Vector2D((float)iX, (float)iY);

	newHeading.Normalize();

	entity->SetHeading(newHeading);
	entity->SetSpeed(WANDERINGSPEED);

	entity->Move(0.0f);

}

IFSMRabbitWander::~IFSMRabbitWander()
{
}
