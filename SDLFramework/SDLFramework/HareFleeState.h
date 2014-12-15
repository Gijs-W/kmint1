#pragma once
#include "IFSMHare.h"


class HareFleeState : public IFSMHare {
public:
	HareFleeState(Rabbit* rabbit);
	virtual ~HareFleeState() {}

	void Handle();
	virtual void nextVertex(Vertex* vertex) {};
	virtual void generateRoute() {};
};