#pragma once
#include "IFSMHare.h"


class HareAcquireGunState : public IFSMHare {

public:
	HareAcquireGunState() {}
	virtual ~HareAcquireGunState() {}

	void Handle(Rabbit* rabbit);
	void Finished(Rabbit* rabbit);
	std::string GetTexturePath() { return  "rabbit-2-red.png"; };
};