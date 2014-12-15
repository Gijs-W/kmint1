#pragma once
#include "IFSMHare.h"


class HareAcquirePillState : public IFSMHare {

public:
	HareAcquirePillState(Rabbit* rabbit);
	virtual ~HareAcquirePillState() {}

	virtual void nextVertex(Vertex* vertex);
	virtual void generateRoute();

	virtual std::string GetTexturePath() { return  "rabbit-2-yellow.png"; };

};