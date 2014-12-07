#pragma once
#include "IFSMCow.h"

class AcquireGunState : public IFSMCow {

public:
	AcquireGunState() {}
	virtual ~AcquireGunState() {}

	void Handle(Cow* cow);
	void Finished(Cow* cow);
	std::string GetTexturePath();
};