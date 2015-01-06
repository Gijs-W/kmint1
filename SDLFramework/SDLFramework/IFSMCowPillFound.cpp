#include "IFSMCowPillFound.h"
#include "Instance.h"
#include "Cow.h"

IFSMCowPillFound::IFSMCowPillFound()
{
}


void IFSMCowPillFound::Calculate(MovingEntity* entity, Instance* instance) {

}

int IFSMCowPillFound::CatchPoints(Instance* instance){
	instance->GetCow()->AddPoints(1);
	return 0;
}


bool IFSMCowPillFound::ShouldResetState(){ 
	return false; 
}

IFSMCowPillFound::~IFSMCowPillFound()
{
}
