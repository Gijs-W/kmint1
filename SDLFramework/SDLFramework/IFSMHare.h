#pragma once
#include <string>
class Graph;
class IFSMHare {

public:
	virtual void Handle(Graph* graph) = 0;
};