#include "MovingEntity.h"


MovingEntity::MovingEntity()
{
	m_CurrentState = nullptr;
}

void MovingEntity::Move(float delta){
	m_Position += m_Heading * m_Speed; // * delta;

	//Debug purpose:
	int x = 800 - (int)m_Position.x % 800;
	int y = 800 - (int)m_Position.y % 800;

	//if (x > 800) x - 800;//possible fix for negavtive x/y values

	SetOffset(x, y);
}

void MovingEntity::SetState(IFSM* state){
	delete m_CurrentState;
	m_CurrentState = state;
}


MovingEntity::~MovingEntity()
{
	delete m_CurrentState;
}