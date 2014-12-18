#pragma once
#include <string>
#include <list>
#include "eGameEntity.h"
class Vertex;
class Cow;
class Graph;
class IFSMCow {
protected:
	Cow* m_Cow;
public:
	IFSMCow() {};
	IFSMCow(Cow* cow);
	virtual void Handle();
	virtual std::string GetTexturePath() { return  "rabbit-2.png"; };

	virtual void nextVertex(Vertex* vertex) = 0;
	virtual void generateRoute() = 0;

	bool containsSelf(Vertex* vertex);
};