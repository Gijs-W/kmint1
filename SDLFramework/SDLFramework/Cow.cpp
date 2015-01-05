#include "IFSMCowPursuit.h"
#include "Game.h"
#include "Rabbit.h"
#include "Cow.h"

Cow::Cow()
{
	SetState(new IFSMCowPursuit());
}

void Cow::Update(Game* game, float deltatime){
	m_CurrentState->Calculate(this, game->GetRabbits());
}

Cow::~Cow()
{

}
