#pragma once
#include "IFSMCow.h"
#include "WanderingState.h"
class ChaseRabbitState : public IFSMCow {

public:
	ChaseRabbitState() {}
	virtual ~ChaseRabbitState() {}

	void Handle(Graph* graph);
	void Finished(Graph* graph);
	std::string GetTexturePath();
	virtual void HandleHareState(Graph* graph);
};