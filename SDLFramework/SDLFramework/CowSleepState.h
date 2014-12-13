#pragma once
#include "IFSMCow.h"

class CowSleepState : public IFSMCow {
private:
	int sleepRounds = 0;
public:
	CowSleepState() {}
	virtual ~CowSleepState() {}

	void Handle(Cow* cow);
	void Finished(Cow* cow);
	std::string GetTexturePath();

};