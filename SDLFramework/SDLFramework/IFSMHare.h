#pragma once
#include <string>
class Graph;
class Rabbit;
class IFSMHare {

public:
	virtual void Handle(Rabbit* rabbit) = 0;
	virtual void Finished(Rabbit* rabbit) = 0;
	virtual std::string GetTexturePath() { return  "rabbit-2.png"; };
};