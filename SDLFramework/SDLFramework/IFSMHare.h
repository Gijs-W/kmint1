#pragma once
#include <string>
class Vertex;
class Graph;
class Rabbit;
class IFSMHare {
protected:
	Rabbit* m_Rabbit;

public:
	IFSMHare() {};
	IFSMHare(Rabbit* rabbit);
	virtual void Handle();
//	virtual std::string GetTexturePath() { return  "rabbit-2.png"; };

	virtual void nextVertex(Vertex* vertex) = 0;
	virtual void generateRoute() = 0;
};