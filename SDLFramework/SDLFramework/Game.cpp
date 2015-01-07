#include "Game.h"
#include "Instance.h"
#include "Cow.h"

#include <string>
#include <map>
#include <vector>

using std::map;
using std::vector;

Game::Game(FWApplication* application)
{
	m_RoundNumber = 1;
	m_RoundTime = 30;
	ResetRoundTimer();
	m_InstanceRed	 = new Instance(application, "red");
	if (!SingleInstance){
		m_InstanceGreen  = new Instance(application, "green");
		m_InstanceBlue	 = new Instance(application, "blue");
		m_InstanceYellow = new Instance(application, "yellow");
	}
}

void Game::Update(float dt){
	m_InstanceRed->Update(dt);
	if (!SingleInstance){
		m_InstanceGreen->Update(dt);
		m_InstanceBlue->Update(dt);
		m_InstanceYellow->Update(dt);
	}

	m_TimeRemaining = m_RoundTime - (std::time(nullptr) - m_StartingTime);
	if (m_TimeRemaining < 0){
		NewRound();
	}
}

Instance* Game::GetInstanceRed(){
	return m_InstanceRed;
}
Instance* Game::GetInstanceGreen(){
	return m_InstanceGreen;
}
Instance* Game::GetInstanceBlue(){
	return m_InstanceBlue;
}
Instance* Game::GetInstanceYellow(){
	return m_InstanceYellow;
}

int Game::GetTimeRemaining(){
	return m_TimeRemaining;
}
int Game::GetRoundNumber(){
	return m_RoundNumber;
}

void Game::ResetRoundTimer(){
	m_StartingTime = std::time(nullptr);
	m_TimeRemaining = m_RoundTime;
}

void Game::NewRound(){
	
	m_InstanceRed->SaveRoundInformation();
	if (!SingleInstance){
		m_InstanceGreen->SaveRoundInformation();
		m_InstanceBlue->SaveRoundInformation();
		m_InstanceYellow->SaveRoundInformation();
	}


	map<Cow*, float> cowMap;
	cowMap[m_InstanceRed->GetCow()] = m_InstanceRed->GetCow()->GetPoints() / 100.0f * 4.0f;
	cowMap[m_InstanceGreen->GetCow()] = m_InstanceGreen->GetCow()->GetPoints() / 100.0f * 4.0f;
	cowMap[m_InstanceBlue->GetCow()] = m_InstanceBlue->GetCow()->GetPoints() / 100.0f * 4.0f;
	cowMap[m_InstanceYellow->GetCow()] = m_InstanceYellow->GetCow()->GetPoints() / 100.0f * 4.0f;

	vector<Cow*> cowVector;
	while (cowVector.size() < 4){
		Cow* cowResult = nullptr;
		float highestValue = -100;//uhh, should actually be most negative float or something

		for (auto &value : cowMap){
			if (value.second > highestValue){
				cowResult = value.first;
			}
		}

		cowMap[cowResult] -= 1.0f;
		cowVector.push_back(cowResult);
	}

	Cow* firstCow = cowVector.at(0);
	cowVector.erase(cowVector.begin());
	int firstCowsPartner = (rand() % 3);
	Cow* secondCow = cowVector.at(firstCowsPartner);
	cowVector.erase(cowVector.begin() + firstCowsPartner);
	Cow* thirdCow = cowVector.at(0);
	cowVector.erase(cowVector.begin());
	Cow* fourthCow = cowVector.at(0);
	cowVector.erase(cowVector.begin());


	SetCowChoices(m_InstanceRed->GetCow(), firstCow, secondCow, (rand() % 3));
	SetCowChoices(m_InstanceGreen->GetCow(), secondCow, firstCow, (rand() % 3));
	SetCowChoices(m_InstanceBlue->GetCow(), thirdCow, fourthCow, (rand() % 3));
	SetCowChoices(m_InstanceYellow->GetCow(), fourthCow, thirdCow, (rand() % 3));

	m_InstanceRed->NewRound();
	if (!SingleInstance){
		m_InstanceGreen->NewRound();
		m_InstanceBlue->NewRound();
		m_InstanceYellow->NewRound();
	}

	if (m_RoundNumber >= 5){
		m_GameOver = true;
		return;
	}
	m_RoundNumber++;
	ResetRoundTimer();
}

bool Game::GameOver(){
	return m_GameOver;
}


void Game::SetCowChoices(Cow* target, Cow* Mom, Cow* Dad, int slice){
	float fleeChance = Mom->GetFleeChance();
	float findPillChance = (slice > 1) ? Mom->GetFindPillChance() : Dad->GetFindPillChance();
	float findGunChance = (slice < 3) ? Mom->GetFindGunChance() : Dad->GetFindGunChance();
	float hideChance = Dad->GetHideChance();
	target->SetChoiceChances(fleeChance, findPillChance, findGunChance, hideChance);
}

Game::~Game()
{
}
