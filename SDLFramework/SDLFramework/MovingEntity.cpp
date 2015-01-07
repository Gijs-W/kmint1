#include "MovingEntity.h"


MovingEntity::MovingEntity()
{
	m_CurrentState = nullptr;
}

void MovingEntity::Move(float delta){
	m_Position += m_Heading * m_Speed; // * delta;

	//Debug purpose:
	int x =  (int)m_Position.x % 800;
	int y =  (int)m_Position.y % 800;

	if (x > 800) x -= 800;//possible fix for negavtive x/y values
	if (x <= 0) x += 800;

	SetOffset(x, y);
}

void MovingEntity::SetState(IFSM* state){
	delete m_CurrentState;
	m_CurrentState = state;
}

IFSM* MovingEntity::GetState(){
	return m_CurrentState;
}


void MovingEntity::AddPoints(int points){
	m_Points += points;
}
int MovingEntity::GetPoints(){
	return m_Points;
}

MovingEntity::~MovingEntity()
{
	delete m_CurrentState;
}