#pragma once
#include "IFSMHare.h"


class HareAcquirePillState : public IFSMHare {

public:
	HareAcquirePillState() {}
	virtual ~HareAcquirePillState() {}

	void Handle(Rabbit* rabbit);
	void Finished(Rabbit* rabbit);

};