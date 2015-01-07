#include "IFSMRabbitChase.h"

#include "MovingEntity.h"
#include "Cow.h"

#include <string>

IFSMRabbitChase::IFSMRabbitChase()
{
}

void IFSMRabbitChase::Calculate(MovingEntity* entity, Instance* instance){

	Cow* target = instance->GetCow();
	if (entity->GetPosition().DistanceBetween(target->GetPosition()) <= CATCH_DISTANCE)
	{
		//switch states
		printf(("[Rabbit-" + instance->GetColour() + "] caught the " + instance->GetColour() + " Cow!\n").c_str());
		entity->AddPoints(target->GetState()->CatchPoints(instance));
		//printf(("[Rabbit] POINTS -> " + std::to_string(entity->GetPoints()) + "\n").c_str());
		instance->ResetEntities(true, true, false, false);
		return;
	}

	Vector2D newHeading = (target->GetPosition() - entity->GetPosition());
	newHeading.Normalize();

	entity->SetHeading(newHeading);
	entity->Move(0.0f);

}

IFSMRabbitChase::~IFSMRabbitChase()
{
}
