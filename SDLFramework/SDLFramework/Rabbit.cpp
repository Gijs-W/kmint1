#include "Rabbit.h"
#include "Cow.h"
#include "IFSMRabbitFlee.h"
#include "Game.h"

Rabbit::Rabbit()
{
	SetState(new IFSMRabbitFlee());
}


void Rabbit::Update(Game* game, float deltatime){
	m_CurrentState->Calculate(this, game->GetCows());
}

Rabbit::~Rabbit()
{
}
