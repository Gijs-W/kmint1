#pragma once
#include "Vertex.h"
#include <vector>

using std::vector;

class Graph
{
private:
	vector<Vertex*>* m_Vertices;
public:
	Graph();
	void addVertex(Vertex* vertex);
	~Graph();
};

