#pragma once
#include <string>

class Cow;
class Graph;
class IFSMCow {
	
public:
	virtual void Handle(Cow* cow) = 0;
	virtual void Finished(Cow* cow) = 0;
	virtual std::string GetTexturePath() = 0;
};