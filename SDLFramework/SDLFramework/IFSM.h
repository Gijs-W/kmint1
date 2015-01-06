#pragma once

#define PANIC_DISTANCE 300.0f
#define CATCH_DISTANCE 10.0f

#define PURSUITSPEED 6.0f
#define FLEESPEED 3.0f
#define WANDERINGSPEED 2.0f

class Instance;
class MovingEntity;
class IFSM {
public:
	IFSM(){};
	virtual void Calculate(MovingEntity* entity, Instance* instance){};
	virtual int CatchPoints(Instance* instance){ return 0; };
	virtual bool ShouldResetState(){ return true; };
	virtual ~IFSM(){};
};