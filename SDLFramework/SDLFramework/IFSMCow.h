#pragma once
#include <string>
#include <list>
#include "eGameEntity.h"
class Vertex;
class Cow;
class Graph;
class IFSMCow {

public:
	virtual void Handle(Cow* cow) = 0;
	virtual void Finished(Cow* cow) = 0;
	virtual std::string GetTexturePath() = 0;

	virtual void entityMovedNotification(Cow *cow, eGameEntity entity) {};
};