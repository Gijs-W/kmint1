#include "IFSMRabbitChase.h"

#include "MovingEntity.h"
#include "Cow.h"

IFSMRabbitChase::IFSMRabbitChase()
{
}

void IFSMRabbitChase::Calculate(MovingEntity* entity, Instance* instance){

	Cow* target = instance->GetCow();
	if (entity->GetPosition().DistanceBetween(target->GetPosition()) <= CATCH_DISTANCE)
	{
		//switch states
		printf("[Rabbit] caught the Cow!\n");
		instance->ResetEntities(true, true, false, false);
		return;
	}

	Vector2D newHeading = (target->GetPosition() - entity->GetPosition());
	newHeading.Normalize();

	entity->SetSpeed(PURSUITSPEED);
	entity->SetHeading(newHeading);
	entity->Move(0.0f);

}

IFSMRabbitChase::~IFSMRabbitChase()
{
}
