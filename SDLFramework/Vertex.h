#pragma once
#include <vector>
#include "IGameObject.h"

using std::vector;

class Edge;

class Vertex: public IGameObject
{
private:
	vector<Edge*>* m_Edges;
	IGameObject* m_GameObject;
public:
	Vertex();
	void Update(float dt);

	void ConnectTo(Vertex* vertex, int distance);
	vector<Edge*>* getEdges();
	void setGameObject(IGameObject* gameObject);
	IGameObject* takeGameObject();

	void Draw();

	Vertex* m_VisitedBy = nullptr;
	int m_MinDistance;

	~Vertex();
};

