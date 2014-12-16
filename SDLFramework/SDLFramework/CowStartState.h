#pragma once
#include "IFSMCow.h"

class CowStartState : public IFSMCow {

public:
	CowStartState(Cow* cow);
	virtual ~CowStartState() {}

	virtual void nextVertex(Vertex* vertex) {}
	virtual void generateRoute();

	virtual std::string GetTexturePath() { return  "cow.png"; };
};