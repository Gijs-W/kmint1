#pragma once
#include "IFSMCow.h"
#include "ChaseRabbitState.h"
class AcquireGunState : public IFSMCow {

public:
	AcquireGunState() {}
	virtual ~AcquireGunState() {}

	void Handle(Graph* graph);
	void Finished(Graph* graph);
	std::string GetTexturePath();
};