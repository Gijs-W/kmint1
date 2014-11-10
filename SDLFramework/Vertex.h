#pragma once
#include <vector>

using std::vector;

class Vertex
{
private:
	vector<Edge*>* m_Edges;
public:
	Vertex();
	void ConnectTo(Vertex* vertex, int distance);
	vector<Edge*>* getEdges();
	~Vertex();
};

