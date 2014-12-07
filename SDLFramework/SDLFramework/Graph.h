#pragma once
#include "Vertex.h"
#include <vector>
#include <list>
#include <queue>
#include <map>

using std::vector;
using std::list;

//using std::queue;
class Graph
{
private:
	vector<Vertex*>* m_Vertices;


	vector<Vertex*>* m_ClosedList;
	vector<Vertex*>* m_OpenList;
	
	
	

public:
	// even geen zin in getters & setters
	FWApplication* m_application;
	std::map<eGameEntity, Vertex*> m_phoneBook;
	Graph(FWApplication* application);
	list<Vertex*> calculateRoute(Vertex* source, Vertex* target);
	list<Vertex*> Graph::getRoute(eGameEntity source, eGameEntity target);
	void Graph::ReShuffleAllExcept(eGameEntity focusEntity);
	void moveGameObject(Vertex* target, eGameEntity entity);
	void addVertex(Vertex* vertex);
	void Update(float dt);
	~Graph();
};

