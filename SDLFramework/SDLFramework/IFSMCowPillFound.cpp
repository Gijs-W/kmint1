#include "IFSMCowPillFound.h"
#include "Instance.h"
#include "Cow.h"

#include <string>

IFSMCowPillFound::IFSMCowPillFound()
{
}


void IFSMCowPillFound::Calculate(MovingEntity* entity, Instance* instance) {

}

int IFSMCowPillFound::CatchPoints(Instance* instance){
	instance->GetCow()->AddPoints(1);
	//printf(("[SUPERCOW] superCow has this amount of points: "+ std::to_string(instance->GetCow()->GetPoints()) + "\n").c_str());
	return 0;
}


bool IFSMCowPillFound::ShouldResetState(){ 
	return false; 
}

IFSMCowPillFound::~IFSMCowPillFound()
{
}
