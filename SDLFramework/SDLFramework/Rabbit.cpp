#include "Rabbit.h"
#include "Cow.h"
#include "IFSMRabbitChase.h"
#include "Instance.h"

Rabbit::Rabbit()
{
	SetSpeed(RABBIT_SPEED);
	ResetState();
}

void Rabbit::Update(Instance* instance, float deltatime){
	m_CurrentState->Calculate(this, instance);
}

void Rabbit::ResetState(){
	SetState(new IFSMRabbitChase());
}

Rabbit::~Rabbit()
{
}
