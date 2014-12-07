#pragma once
#include "IFSMCow.h"

class WanderingState : public IFSMCow {

public:
	WanderingState() {}
	virtual ~WanderingState() {}

	void Handle(Cow* cow);
	void Finished(Cow* cow);
	std::string GetTexturePath();

};