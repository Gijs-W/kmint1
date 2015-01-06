#pragma once
#include "IGameObject.h"
#include "Vector2D.h"

//#define SCREEN_WIDTH 800.0f
//#define SCREEN_HEIGHT 800.0f

class IFSM;
class MovingEntity :
	public IGameObject
{
protected:

	Vector2D m_Position;
	Vector2D m_Heading;
	float m_Speed;

	float m_MaxSpeed;
	float m_MaxTurnRate;

	IFSM* m_CurrentState;
private:
	FWApplication* m_Application;
public:
	MovingEntity();
	virtual void Update(float deltaTime){}; //Todo:

	virtual Vector2D GetPosition() { return m_Position; }
	virtual void SetPosition(Vector2D vec) { m_Position = vec; }

	virtual Vector2D GetHeading() { return m_Heading; }
	virtual void SetHeading(Vector2D vec) { m_Heading = vec; }

	virtual float GetSpeed() { return m_Speed; }
	virtual void SetSpeed(float speed) { m_Speed = speed; }

	virtual void SetState(IFSM* state);
	virtual void ResetState(){};

	virtual void Move(float delta);
	virtual ~MovingEntity();
};

