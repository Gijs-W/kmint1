#pragma once
#include "IFSMHare.h"


class HareAcquireGunState : public IFSMHare {

public:
	HareAcquireGunState(Rabbit* rabbit);
	virtual ~HareAcquireGunState() {}

	bool shouldMove(Vertex* vertex);
	virtual void nextVertex(Vertex* vertex);
	virtual void generateRoute();

	virtual std::string GetTexturePath() { return  "rabbit-2-purple.png"; };
};