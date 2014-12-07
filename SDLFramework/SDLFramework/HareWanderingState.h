#pragma once
#include "IFSMHare.h"
#include "Rabbit.h"

class HareWanderingState : public IFSMHare {

public:
	HareWanderingState() {}
	virtual ~HareWanderingState() {}

	void Handle(Rabbit* rabbit);

};