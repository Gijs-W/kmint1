#pragma once
#include <string>
class Graph;
class IFSMCow {
	
public:
	virtual void Handle(Graph* graph) = 0;
	virtual void Finished(Graph* graph) = 0;
	virtual std::string GetTexturePath() = 0;
};