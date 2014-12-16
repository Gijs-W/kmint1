#pragma once
#include "IFSMCow.h"

class ChaseRabbitState : public IFSMCow {

public:
	ChaseRabbitState(Cow* cow);
	virtual ~ChaseRabbitState() {}

	virtual void nextVertex(Vertex* vertex);
	virtual void generateRoute();

	virtual std::string GetTexturePath() { return  "cow-red.png"; };
};