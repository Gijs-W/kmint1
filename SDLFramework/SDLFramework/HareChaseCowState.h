#pragma once
#include "IFSMHare.h"


class HareChaseCowState : public IFSMHare {

public:
	HareChaseCowState(Rabbit* rabbit);
	virtual ~HareChaseCowState() {}

	virtual void nextVertex(Vertex* vertex);
	virtual void generateRoute();

	void Handle();

	virtual std::string GetTexturePath() { return  "rabbit-2-red.png"; };
};