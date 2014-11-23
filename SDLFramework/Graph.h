#pragma once
#include "Vertex.h"
#include <vector>
#include <list>
#include <queue>
#include "WanderingState.h"
#include "ChaseRabbitState.h"
#include "AcquireGunState.h"


using std::vector;
using std::list;

//using std::queue;
class ChaseRabbitState;
class IFSMCow;
class Graph
{
private:
	vector<Vertex*>* m_Vertices;


	vector<Vertex*>* m_ClosedList;
	vector<Vertex*>* m_OpenList;
	list<Vertex*>* m_Route;
	
	FWApplication* m_application;
	

public:
	// even geen zin in getters & setters
	Vertex* m_VertexCow;
	Vertex* m_VertexRabbit;
	Vertex* m_MachineGun;
	Vertex* m_Pill;
	IFSMCow* cowState = new WanderingState;
	Graph(FWApplication* application);
	void calculateRoute(Vertex* source, Vertex* target);
	void addVertex(Vertex* vertex);
	void nextStep();
	~Graph();
};

