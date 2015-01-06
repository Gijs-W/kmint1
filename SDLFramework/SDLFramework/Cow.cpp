#include "IFSMCowWander.h"
#include "Instance.h"
#include "Rabbit.h"
#include "Cow.h"

Cow::Cow()
{
	ResetState();
}

void Cow::Update(Instance* instance, float deltatime){
	m_CurrentState->Calculate(this, instance);
}


void Cow::ResetState(){
	SetState(new IFSMCowWander());
}

Cow::~Cow()
{

}
