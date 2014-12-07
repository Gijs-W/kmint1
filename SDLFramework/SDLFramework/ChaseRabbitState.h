#pragma once
#include "IFSMCow.h"

class ChaseRabbitState : public IFSMCow {

public:
	ChaseRabbitState() {}
	virtual ~ChaseRabbitState() {}

	void Handle(Cow* cow);
	void Finished(Cow* cow);
	std::string GetTexturePath();
};