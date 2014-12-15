#include "Graph.h"
#include "IGameEntity.h"
#include "Cow.h"
#include "Rabbit.h"
#include "Pill.h"
#include "Gun.h"
#include "Edge.h"
#include <math.h>       /* pow */
#include <stdlib.h>     /* abs */
#include <stdexcept>
#include <iostream>
bool sortByGuessedTotalDistance(Vertex *lhs, Vertex *rhs) { //todo: give this method a proper position in the code
	return lhs->m_GuessedTotalDistance < rhs->m_GuessedTotalDistance;
}

Graph::Graph(FWApplication* application)
{
	m_application = application;
	m_Vertices = new vector <Vertex*>;
	IGameEntity* cow = new Cow(this);
	SDL_Texture* cowTexture = application->LoadTexture("cow-1.png"); //todo: delete
	cow->SetTexture(cowTexture);
	cow->SetSize(32, 32);

	IGameEntity* rabbit = new Rabbit(this);
	SDL_Texture* rabitTexture = application->LoadTexture("rabbit-2.png");//todo: delete
	rabbit->SetTexture(rabitTexture);
	rabbit->SetSize(32, 32);

	IGameEntity* pill = new Pill(this);
	SDL_Texture* pillTexture = application->LoadTexture("pill.png");//todo: delete
	pill->SetTexture(pillTexture);
	pill->SetSize(32, 32);

	IGameEntity* metalgun = new Gun(this);
	SDL_Texture* metalTexture = application->LoadTexture("gun-metal.png");//todo: delete
	metalgun->SetTexture(metalTexture);
	metalgun->SetSize(32, 32);


	SDL_Texture* vertexTexture = application->LoadTexture("node.png");//todo: delete

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

	Vertex* vertex6 = new Vertex();
	vertex6->SetOffset(256, 192);
	vertex6->SetSize(32, 32);
	vertex6->SetTexture(vertexTexture);
	Vertex* vertex7 = new Vertex();
	vertex7->SetOffset(160,288);
	vertex7->SetSize(32, 32);
	vertex7->SetTexture(vertexTexture);
	Vertex* vertex8 = new Vertex();
	vertex8->SetOffset(320, 288);
	vertex8->SetSize(32, 32);
	vertex8->SetTexture(vertexTexture);
	Vertex* vertex9 = new Vertex();
	vertex9->SetOffset(384, 224);
	vertex9->SetSize(32, 32);
	vertex9->SetTexture(vertexTexture);
	Vertex* vertex10 = new Vertex();
	vertex10->SetOffset(384, 128);
	vertex10->SetSize(32, 32);
	vertex10->SetTexture(vertexTexture);
	Vertex* vertex11 = new Vertex();
	vertex11->SetOffset(320, 32);
	vertex11->SetSize(32, 32);
	vertex11->SetTexture(vertexTexture);
	Vertex* vertex12 = new Vertex();
	vertex12->SetOffset(416, 32);
	vertex12->SetSize(32, 32);
	vertex12->SetTexture(vertexTexture);
	Vertex* vertex13 = new Vertex();
	vertex13->SetOffset(480, 64);
	vertex13->SetSize(32, 32);
	vertex13->SetTexture(vertexTexture);
	Vertex* vertex14 = new Vertex();
	vertex14->SetOffset(512, 160);
	vertex14->SetSize(32, 32);
	vertex14->SetTexture(vertexTexture);
	Vertex* vertex15 = new Vertex();
	vertex15->SetOffset(480, 256);
	vertex15->SetSize(32, 32);
	vertex15->SetTexture(vertexTexture);

	vertex1->ConnectTo(vertex2, 2000);
	vertex2->ConnectTo(vertex1, 2000);

	vertex2->ConnectTo(vertex3, 5000);
	vertex3->ConnectTo(vertex2, 5000);

	vertex1->ConnectTo(vertex3, 1000);
	vertex3->ConnectTo(vertex1, 1000);

	vertex3->ConnectTo(vertex4, 1000);
	vertex4->ConnectTo(vertex3, 1000);

	vertex4->ConnectTo(vertex5, 3000);
	vertex5->ConnectTo(vertex4, 3000);

	vertex3->ConnectTo(vertex5, 3000);
	vertex5->ConnectTo(vertex3, 3000);

	vertex5->ConnectTo(vertex11, 2000);
	vertex11->ConnectTo(vertex5, 2000);

	vertex11->ConnectTo(vertex12, 1500);
	vertex12->ConnectTo(vertex11, 1500);

	vertex5->ConnectTo(vertex6, 2000);
	vertex6->ConnectTo(vertex5, 2000);

	vertex11->ConnectTo(vertex9, 6000);
	vertex9->ConnectTo(vertex11, 6000);

	vertex12->ConnectTo(vertex10, 2500);
	vertex10->ConnectTo(vertex12, 2500);

	vertex10->ConnectTo(vertex13, 2600);
	vertex13->ConnectTo(vertex10, 2600);

	vertex10->ConnectTo(vertex14, 2700);
	vertex14->ConnectTo(vertex10, 2700);

	vertex14->ConnectTo(vertex9, 2600);
	vertex9->ConnectTo(vertex14, 2600);

	vertex9->ConnectTo(vertex15, 3000);
	vertex15->ConnectTo(vertex9, 3000);

	vertex9->ConnectTo(vertex8, 2000);
	vertex8->ConnectTo(vertex9, 2000);

	vertex8->ConnectTo(vertex7, 3500);
	vertex7->ConnectTo(vertex8, 3500);

	vertex2->ConnectTo(vertex7, 2600);
	vertex7->ConnectTo(vertex2, 2600);

	vertex1->addGameObject(cow);
	m_phoneBook.insert({ eCow, vertex1 });
	vertex5->addGameObject(rabbit);
	m_phoneBook.insert({ eRabbit, vertex5 });
	vertex10->addGameObject(pill);
	m_phoneBook.insert({ ePill, vertex10 });
	vertex14->addGameObject(metalgun);
	m_phoneBook.insert({ eGun, vertex14 });

	addVertex(vertex1);
	addVertex(vertex2);
	addVertex(vertex3);
	addVertex(vertex4);
	addVertex(vertex5);
	addVertex(vertex6);
	addVertex(vertex7);
	addVertex(vertex8);
	addVertex(vertex9);
	addVertex(vertex10);
	addVertex(vertex11);
	addVertex(vertex12);
	addVertex(vertex13);
	addVertex(vertex14);
	addVertex(vertex15);

	application->AddRenderable(vertex1);
	application->AddRenderable(vertex2);
	application->AddRenderable(vertex3);
	application->AddRenderable(vertex4);
	application->AddRenderable(vertex5);
	application->AddRenderable(vertex6);
	application->AddRenderable(vertex7);
	application->AddRenderable(vertex8);
	application->AddRenderable(vertex9);
	application->AddRenderable(vertex10);
	application->AddRenderable(vertex11);
	application->AddRenderable(vertex12);
	application->AddRenderable(vertex13);
	application->AddRenderable(vertex14);
	application->AddRenderable(vertex15);

	m_ClosedList = new vector<Vertex*>;
	m_OpenList = new vector<Vertex*>;
	

}

void Graph::addVertex(Vertex* vertex){
	if (std::find(m_Vertices->begin(), m_Vertices->end(), vertex) == m_Vertices->end()) {
		m_Vertices->push_back(vertex);
	}
}

list<Vertex*> Graph::calculateRoute(Vertex* source, Vertex* target){
	if (source == target){
		//ERROR
		//throw std::invalid_argument("Source and target are the same!");
	}

	list<Vertex*> route;

	for (Vertex* vertex : *m_Vertices){
		vertex->m_VisitedBy = nullptr;
		vertex->m_MinDistance = std::numeric_limits<int>::max();
		vertex->m_GuessedTotalDistance = 0;
	}

	source->m_MinDistance = 0;
	m_OpenList->push_back(source);


	/* Loop through open list: */
	while (!m_OpenList->empty()) {
		Vertex* vertex = m_OpenList->front();
		m_OpenList->erase(m_OpenList->begin());

		/* Calculate guessed Distance: */
		float GuessedDistance;
		if (vertex == target){
			GuessedDistance = 0;
		}
		else{
			//Get X and Y value: Must be uint_32 because of the framework
			uint32_t sourceX, sourceY, targetX, targetY;
			vertex->GetOffset(sourceX, sourceY);
			target->GetOffset(targetX, targetY);

			//Convert to int for calculations
			int sourceXint = sourceX, sourceYint = sourceY, targetXint = targetX, targetYint = targetY;

			if (sourceYint == targetYint){
				GuessedDistance = abs(sourceXint - targetXint);
			}
			else if (sourceXint == targetXint){
				GuessedDistance = abs(sourceYint - targetYint);
			}
			else{
				//Calculate C length -> Pythagorean theorem
				int a = pow((float)(sourceXint - targetXint), 2);
				int b = pow((float)(sourceYint - targetYint), 2);
				GuessedDistance = abs(sqrt(a + b));// C
			}
		}


		// Visit each edge  
		for (Edge* edge : *vertex->getEdges())
		{
			Vertex* target = edge->getDestination();

			if (std::find(m_ClosedList->begin(), m_ClosedList->end(), target) == m_ClosedList->end()) {
				int distance = edge->getDistance();

				int totalDistance = vertex->m_MinDistance + distance;
				if ((totalDistance) < target->m_MinDistance) {
					//m_OpenList->remove(target);//?!?!??!
					target->m_MinDistance = totalDistance;
					target->m_GuessedTotalDistance = totalDistance + GuessedDistance;
					target->m_VisitedBy = vertex;
					m_OpenList->push_back(target);
				}
			}
		}
		m_ClosedList->push_back(vertex);

		// sort openlist by weight + guessedValue;
		std::sort(m_OpenList->begin(), m_OpenList->end(), sortByGuessedTotalDistance);

	}

	Vertex* current = target;
	while (current != nullptr && current != source){
		route.push_front(current);
		current = current->m_VisitedBy;
	}

	//m_OpenList->
	m_ClosedList->clear();

	return route;
}


void Graph::Update(float dt){

	/* Update all gameEntities: */

	m_phoneBook.at(eRabbit)->getGameObject(eRabbit)->Update(dt);
	m_phoneBook.at(eCow)->getGameObject(eCow)->Update(dt);

	/*for (auto& kv : m_phoneBook) {
		if (kv.first != eCow && kv.first != eRabbit){
			IGameEntity *entity = kv.second->getGameObject(kv.first);
			entity->Update(dt);
		}
	}*/
}

list<Vertex*> Graph::getRoute(eGameEntity source, eGameEntity target){

	//search vectors
	Vertex* v_source = m_phoneBook.at(source);
	Vertex* v_target = m_phoneBook.at(target);

	return calculateRoute(v_source, v_target);
}

void Graph::moveGameObject(Vertex* target, eGameEntity entity){
	IGameEntity* target_entity = m_phoneBook.at(entity)->takeGameObject(entity);
	target->addGameObject(target_entity);
 	m_phoneBook[entity] = target;

	// notify entities
	for (auto &vertex : m_phoneBook) {
		if (vertex.first != entity) {
			vertex.second->getGameObject(vertex.first)->entityMovedNotification(entity);
		}
	}
}

void Graph::respawn(eGameEntity entity) {
	Vertex* current = m_phoneBook.at(entity);
	Vertex* newVertex;
	do {
		newVertex = m_Vertices->at(rand() % (m_Vertices->size() -1));
	} while (current == newVertex);
	newVertex->addGameObject(current->takeGameObject(entity));




	m_phoneBook[entity] = newVertex;
	std::cout << "Respawning " << entity << std::endl;
	if (entity == eCow || entity == eRabbit) {
		Rabbit* rabbit = (Rabbit*) m_phoneBook[eRabbit]->getGameObject(eRabbit);
		rabbit->setState(new HareWanderingState(rabbit));
		rabbit->m_hasPill = false;
	}

	// notify entities
	for (auto &vertex : m_phoneBook) {
		if (vertex.first != entity) {
			vertex.second->getGameObject(vertex.first)->entityMovedNotification(entity);
		}
	}

//m_phoneBook.at(eRabbit)->getGameObject(eRabbit)->clearRoute();

}

void Graph::ReShuffleAllExcept(eGameEntity exception){

	Vertex* exceptionVertex = m_phoneBook.at(exception);

 	std::map<eGameEntity, Vertex*>::iterator it = m_phoneBook.begin();

	for (; it != m_phoneBook.end(); it++){
		if (it->first == exception){
			continue;
		}
		Vertex* newVertex;
		do{
			int result = rand() % (m_Vertices->size());
			newVertex = m_Vertices->at(result);
		} while (newVertex == exceptionVertex);

		m_phoneBook[it->first] = newVertex;
	//	m_phoneBook.insert({ it->first, newVertex });

		moveGameObject(newVertex, it->first);
	}

	/* Update all gameEntities: */
	/*for (const auto& kv : m_phoneBook) {
		if (kv.first == exception){
			continue;
		}
		Vertex* newVertex;
		do{
			int result = rand() % (m_Vertices->size());
			newVertex = m_Vertices->at(result);
		} while (newVertex == exceptionVertex);

		m_phoneBook[kv.first] = newVertex;
	}*/
}

/*

// Wat de haas doet is afhankelijk van de koe! Eigenlijk heeft de haas hierdoor 2 states. Als de koe niet aan het chases is
// zal de status van de haas inactief zijn. Anders zal hij vluchten, indien mogelijk.
cowState->HandleHareState(this);
if (m_Route->size() > 1){

	IGameEntity* cow = m_VertexCow->takeGameObject(eCow);
	m_VertexCow = m_Route->front();
	m_Route->pop_front();
	m_VertexCow->addGameObject(cow);
}
else if (m_Route->size() == 1){

	IGameEntity* cow = m_VertexCow->takeGameObject(eCow);
	IGameEntity* rabbit = m_VertexRabbit->takeGameObject(eRabbit);
	IGameEntity* pill = m_Pill->takeGameObject(ePill);
	IGameEntity* machinegun = m_MachineGun->takeGameObject(eGun);

	m_VertexCow = m_Route->front();
	m_Route->pop_front();
	m_VertexCow->addGameObject(cow);

	// copy pasten is cool
	int result;
	Vertex* newRabbitVertex;
	do{
		result = rand() % (m_Vertices->size());
		newRabbitVertex = m_Vertices->at(result);
	} while (newRabbitVertex == m_VertexCow);

	Vertex* newPillVertex;
	do {
		result = rand() % (m_Vertices->size());
		newPillVertex = m_Vertices->at(result);
	} while (newPillVertex == m_VertexCow);

	Vertex* newGunVertex;
	do {
		result = rand() % (m_Vertices->size());
		newGunVertex = m_Vertices->at(result);
	} while (newGunVertex == m_VertexCow);


	m_VertexRabbit = newRabbitVertex;
	m_VertexRabbit->addGameObject(rabbit);

	m_Pill = newPillVertex;
	m_Pill->addGameObject(pill);

	m_MachineGun = newGunVertex;
	m_MachineGun->addGameObject(machinegun);

	cowState->Finished(this);
	cowState->Handle(this);
	cow->SetTexture(m_application->LoadTexture(cowState->GetTexturePath()));
	//calculateRoute(m_VertexCow, m_VertexRabbit);

	*/

Graph::~Graph()
{
	delete m_Vertices;//todo: delete inhoudd
	delete m_OpenList;
	delete m_ClosedList;
}
