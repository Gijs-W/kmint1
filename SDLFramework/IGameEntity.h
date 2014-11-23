#pragma once
#include "IGameObject.h"
#include "eGameEntity.h"

class IGameEntity : public IGameObject
{
protected:
	eGameEntity m_Enum;
public:
	IGameEntity(){};
	eGameEntity getEnum(){ return m_Enum; };
	virtual ~IGameEntity(){};
};

