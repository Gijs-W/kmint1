#pragma once
#include "IFSMHare.h"


class HareChaseCowState : public IFSMHare {

public:
	HareChaseCowState() {}
	virtual ~HareChaseCowState() {}

	void Handle(Rabbit* rabbit);
	void Finished(Rabbit* rabbit);
	std::string GetTexturePath() { return  "rabbit-2-red.png"; };
};