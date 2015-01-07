#include "IFSMCowWander.h"
#include "IFSMCowFlee.h"
#include "IFSMCowFindPill.h"
#include "IFSMCowFindGun.h"
#include "IFSMCowHide.h"
#include <time.h>

#include "MovingEntity.h"
#include "Rabbit.h"
#include "Cow.h"

IFSMCowWander::IFSMCowWander()
{
}

void IFSMCowWander::Calculate(MovingEntity* entity, Instance* instance){

	//only flee if the target is within 'panic distance'. Work in distance //squared space.
	Rabbit* target = instance->GetRabbit();

	if (entity->GetPosition().DistanceBetween(target->GetPosition()) < PANIC_DISTANCE)
	{
		//switch states:
		int random = 100 - (rand() % 100);
		
		float fleeChance = instance->GetCow()->GetFleeChance();
		float findPillChance = instance->GetCow()->GetFindPillChance();
		float findGunChance = instance->GetCow()->GetFindGunChance();
		//float hideChance = instance->GetCow()->GetHideChance();//Not needed, since we got 'else'

		if (random < fleeChance){
			printf("[Cow] CowFlee activated!\n");
			entity->SetState(new IFSMCowFlee());
		}
		else if (random < fleeChance + findPillChance){
			printf("[Cow] CowFindPill activated!\n");
			entity->SetState(new IFSMCowFindPill());
		}
		else if (random < fleeChance + findPillChance + findGunChance){
			printf("[Cow] CowFindGun activated!\n");
			entity->SetState(new IFSMCowFindGun());
		}
		else{
			printf("[Cow] CowHide activated!\n");
			entity->SetState(new IFSMCowHide());
		}
		return;
	}

	srand(time(nullptr));
	int iX = 13 - (rand() % 25);
	int iY = 13 - (rand() % 25);

	Vector2D newHeading = Vector2D((float)iX, (float)iY);
	newHeading.Normalize();

	entity->SetHeading(newHeading);

	entity->Move(0.0f);

}

IFSMCowWander::~IFSMCowWander()
{
}
