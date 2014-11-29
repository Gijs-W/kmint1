#pragma once
#include "IFSMHare.h"

class HareWanderingState : public IFSMHare {

public:
	HareWanderingState() {}
	virtual ~HareWanderingState() {}

	void Handle(Graph* graph);

};