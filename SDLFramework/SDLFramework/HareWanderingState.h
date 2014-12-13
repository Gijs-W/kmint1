#pragma once
#include "IFSMHare.h"


class HareWanderingState : public IFSMHare {

public:
	HareWanderingState() {}
	virtual ~HareWanderingState() {}

	void Handle(Rabbit* rabbit);
	void Finished(Rabbit* rabbit);
	virtual std::string getTexturePath() { return "rabbit-2.png";  }
};