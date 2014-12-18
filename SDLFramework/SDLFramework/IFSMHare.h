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
	virtual std::string GetTexturePath() { return  "rabbit-2.png"; };

	virtual bool shouldMove(Vertex* vertex) { return true; };
	virtual void nextVertex(Vertex* vertex) = 0;
	virtual void generateRoute() = 0;

	bool containsSelf(Vertex* vertex);
};