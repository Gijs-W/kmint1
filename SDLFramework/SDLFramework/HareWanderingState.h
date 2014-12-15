#pragma once
#include "IFSMHare.h"


class HareWanderingState : public IFSMHare {
private:
	void run();
public:
	HareWanderingState(Rabbit* rabbit);
	virtual ~HareWanderingState() {}

	void Handle();
	
	//virtual std::string getTexturePath() { return "rabbit-2.png";  }

	virtual void nextVertex(Vertex* vertex) {};
	virtual void generateRoute() {};
};