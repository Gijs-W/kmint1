#pragma once
#include "IFSMCow.h"

class CowSleepState : public IFSMCow {
private:
	int sleepRounds = 0;
public:
	CowSleepState(Cow* cow);
	virtual ~CowSleepState() {}

	virtual void nextVertex(Vertex* vertex);
	virtual void generateRoute();

	virtual std::string GetTexturePath() { return  "cow-hulk.png"; };
};