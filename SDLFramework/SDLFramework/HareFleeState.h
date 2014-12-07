#pragma once
#include "IFSMHare.h"


class HareFleeState : public IFSMHare {

public:
	HareFleeState() {}
	virtual ~HareFleeState() {}

	void Handle(Rabbit* rabbit);

};