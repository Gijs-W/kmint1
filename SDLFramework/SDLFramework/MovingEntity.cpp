#include "MovingEntity.h"


MovingEntity::MovingEntity()
{
	m_CurrentState = nullptr;
}

void MovingEntity::Move(float delta){
	m_Position += m_Heading * m_Speed; // * delta;

	//Debug purpose:
	//int i = 800 - (int)m_Position.x % 800;
	//int y = 600 - (int)m_Position.y % 600;

	SetOffset(800 - (int)m_Position.x % 800, 600 - (int)m_Position.y % 600);
}

void MovingEntity::SetState(IFSM* state){
	delete m_CurrentState;
	m_CurrentState = state;
}

MovingEntity::~MovingEntity()
{
	delete m_CurrentState;
}