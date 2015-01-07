#include "MovingEntity.h"

#include <math.h>       /* isfinite, sqrt */

MovingEntity::MovingEntity()
{
	m_CurrentState = nullptr;
}

void MovingEntity::Move(float delta){
	m_Position += m_Heading * m_Speed; // * delta;

	//Debug purpose:
	int x = (int)m_Position.x % SCREEN_WIDTH;
	int y = (int)m_Position.y % SCREEN_HEIGHT;

	if (x > SCREEN_WIDTH) x -= SCREEN_WIDTH;//possible fix for negavtive x/y values
	if (x <= 0) x += SCREEN_WIDTH;

	if (!isfinite(m_Position.x)){
		int i = 0;
	}
	if (!isfinite(m_Position.y)){
		int i = 0;
	}

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