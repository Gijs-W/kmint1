#pragma once
#include "IFSMHare.h"
#include "HareWanderingState.h"

class HareWanderingStateGreen : public HareWanderingState {

public:
	virtual std::string getTexturePath() { return "rabbit-2-green.png";  }
};