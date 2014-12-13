#pragma once
#include "IFSMHare.h"


class HareAcquireGunState : public IFSMHare {

public:
	HareAcquireGunState() {}
	virtual ~HareAcquireGunState() {}

	void Handle(Rabbit* rabbit);
	void Finished(Rabbit* rabbit);

};