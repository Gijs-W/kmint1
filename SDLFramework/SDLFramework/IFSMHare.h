#pragma once
#include <string>
class Graph;
class Rabbit;
class IFSMHare {

public:
	virtual void Handle(Rabbit* rabbit) = 0;
};