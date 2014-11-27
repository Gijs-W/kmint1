#pragma once
#include "IFSMCow.h"

class WanderingState : public IFSMCow {

public:
	WanderingState() {}
	virtual ~WanderingState() {}

	void Handle(Graph* graph);
	void Finished(Graph* graph);
	std::string GetTexturePath();

};