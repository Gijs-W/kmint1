#pragma once
#include "IFSMHare.h"


class HareChaseCowState : public IFSMHare {

public:
	HareChaseCowState() {}
	virtual ~HareChaseCowState() {}

	void Handle(Rabbit* rabbit);
	void Finished(Rabbit* rabbit);

};