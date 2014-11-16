#include "Graph.h"
#include "Cow.h"
#include "Edge.h"


Graph::Graph(FWApplication* application)
{
	m_Vertices = new vector <Vertex*>;
	IGameObject* cow = new Cow();
	SDL_Texture* cowTexture = application->LoadTexture("cow-1.png"); //todo: delete
	cow->SetTexture(cowTexture);
	cow->SetSize(32, 32);

	IGameObject* rabbit = new Cow();
	SDL_Texture* rabitTexture = application->LoadTexture("rabbit-2.png");//todo: delete
	rabbit->SetTexture(rabitTexture);
	rabbit->SetSize(32, 32);

	SDL_Texture* vertexTexture = application->LoadTexture("pill.png");//todo: delete

	Vertex* vertex1 = new Vertex();
	vertex1->SetOffset(32, 160);
	vertex1->SetSize(32, 32);
	vertex1->SetTexture(vertexTexture);
	Vertex* vertex2 = new Vertex();
	vertex2->SetOffset(128, 224);
	vertex2->SetSize(32, 32);
	vertex2->SetTexture(vertexTexture);
	Vertex* vertex3 = new Vertex();
	vertex3->SetOffset(96,96);
	vertex3->SetSize(32, 32);
	vertex3->SetTexture(vertexTexture);
	Vertex* vertex4 = new Vertex();
	vertex4->SetOffset(160, 32);
	vertex4->SetSize(32, 32);
	vertex4->SetTexture(vertexTexture);
	Vertex* vertex5 = new Vertex();
	vertex5->SetOffset(256, 128);
	vertex5->SetSize(32, 32);
	vertex5->SetTexture(vertexTexture);

	vertex1->ConnectTo(vertex2, 2);
	vertex2->ConnectTo(vertex1, 2);

	vertex2->ConnectTo(vertex3, 5);
	vertex3->ConnectTo(vertex2, 5);

	vertex1->ConnectTo(vertex3, 1);
	vertex3->ConnectTo(vertex1, 1);

	vertex3->ConnectTo(vertex4, 1);
	vertex4->ConnectTo(vertex3, 1);

	vertex4->ConnectTo(vertex5, 3);
	vertex5->ConnectTo(vertex4, 3);

	vertex3->ConnectTo(vertex5, 3);
	vertex5->ConnectTo(vertex3, 3);

	vertex1->setGameObject(cow);
	m_VertexCow = vertex1;
	vertex5->setGameObject(rabbit);
	m_VertexRabbit = vertex5;

	addVertex(vertex1);
	addVertex(vertex2);
	addVertex(vertex3);
	addVertex(vertex4);
	addVertex(vertex5);

	application->AddRenderable(vertex1);
	application->AddRenderable(vertex2);
	application->AddRenderable(vertex3);
	application->AddRenderable(vertex4);
	application->AddRenderable(vertex5);

	m_Route = new list<Vertex*>();
	m_ClosedList = new vector<Vertex*>;
	m_OpenList = new queue<Vertex*>;
	
	calculateRoute();

}

void Graph::addVertex(Vertex* vertex){
	if (std::find(m_Vertices->begin(), m_Vertices->end(), vertex) == m_Vertices->end()) {
		m_Vertices->push_back(vertex);
	}
}

void Graph::calculateRoute(){
	m_Route->clear();

	m_VertexCow->m_MinDistance = 0;
	m_OpenList->push(m_VertexCow);
	
	for (Vertex* vertex : *m_Vertices){
		vertex->m_VisitedBy = nullptr;
		vertex->m_MinDistance = std::numeric_limits<int>::max();
	}

	while (!m_OpenList->empty()) {
		Vertex* vertex = m_OpenList->front();
		m_OpenList->pop();

		// Visit each edge exiting u

		for (Edge* edge : *vertex->getEdges())
		{
			Vertex* target = edge->getDestination();

			if (std::find(m_ClosedList->begin(), m_ClosedList->end(), target) == m_ClosedList->end()) {
				int distance = edge->getDistance();

				int totalDistance = vertex->m_MinDistance + distance;
				if (totalDistance < target->m_MinDistance) {
					//m_OpenList->remove(target);//?!?!??!
					target->m_MinDistance = totalDistance;
					target->m_VisitedBy = vertex;
					m_OpenList->push(target);
				}
			}
		}
		m_ClosedList->push_back(vertex);
	}

	Vertex* current = m_VertexRabbit;
	while (current != nullptr && current != m_VertexCow){
		m_Route->push_front(current);
		current = current->m_VisitedBy;
	}
	

	//m_OpenList->
	m_ClosedList->clear();
}


void Graph::nextStep(){
	if (m_Route->size() > 1){

		IGameObject* cow = m_VertexCow->takeGameObject();
		m_VertexCow = m_Route->front();
		m_Route->pop_front();
		m_VertexCow->setGameObject(cow);
	}
	else{

		IGameObject* cow = m_VertexCow->takeGameObject();
		IGameObject* rabbit = m_VertexRabbit->takeGameObject();

		m_VertexCow = m_Route->front();
		m_Route->pop_front();
		m_VertexCow->setGameObject(cow);

		int result;
		Vertex* newRabbitVertex;
		do{
			result = rand() % (m_Vertices->size());
			newRabbitVertex = m_Vertices->at(result);
		} while (newRabbitVertex == m_VertexCow);

		m_VertexRabbit = newRabbitVertex;
		m_VertexRabbit->setGameObject(rabbit);

		calculateRoute();
	}
}

Graph::~Graph()
{
	delete m_Vertices;//todo: delete inhoudd
	delete m_OpenList;
	delete m_ClosedList;
	delete m_VertexCow;
	delete m_VertexRabbit;
	delete m_Route;
}
