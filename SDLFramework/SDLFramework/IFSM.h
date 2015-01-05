#pragma once


class MovingEntity;
class IFSM {
public:
	IFSM(){};
	virtual void Calculate(MovingEntity* entity, MovingEntity* other){};
	virtual ~IFSM(){};
};