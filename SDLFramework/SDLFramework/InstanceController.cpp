#include "InstanceController.h"

#include "Instance.h"
#include "Cow.h"

#include <string>
#include <fstream>

#include <map>
#include <vector>

using std::map;
using std::vector;
using std::to_string;

InstanceController::InstanceController(FWApplication* application)
{
	ClearMateInformation();
	m_InstanceRed = new Instance(application, "red");
	if (!m_SingleInstance){
		m_InstanceGreen = new Instance(application, "green");
		m_InstanceBlue = new Instance(application, "blue");
		m_InstanceYellow = new Instance(application, "yellow");
	}
}


void InstanceController::Update(float dt){
	m_InstanceRed->Update(dt);
	if (!m_SingleInstance){
		m_InstanceGreen->Update(dt);
		m_InstanceBlue->Update(dt);
		m_InstanceYellow->Update(dt);
	}

}


void InstanceController::SaveRoundInformation(int roundNumber){
	m_InstanceRed->SaveRoundInformation(roundNumber);
	if (!m_SingleInstance){
		m_InstanceGreen->SaveRoundInformation(roundNumber);
		m_InstanceBlue->SaveRoundInformation(roundNumber);
		m_InstanceYellow->SaveRoundInformation(roundNumber);
	}

}

Instance* InstanceController::GetInstanceRed(){
	return m_InstanceRed;
}
Instance* InstanceController::GetInstanceGreen(){
	return m_InstanceGreen;
}
Instance* InstanceController::GetInstanceBlue(){
	return m_InstanceBlue;
}
Instance* InstanceController::GetInstanceYellow(){
	return m_InstanceYellow;
}

void InstanceController::Foreplay(){

	if (m_SingleInstance){
		m_InstanceRed->HardResetEntities();
		return; //Can't make love on your own!
	}

	int cowAmount{ 4 };//Amount of cows in the game.. and thus how many babies we must produce :3

	///////////////////////////////////////////////////////////////////
	// Get Current Cows and add them to a map (with points as value) //
	///////////////////////////////////////////////////////////////////

	map<Cow*, float> cowMap;
	cowMap[m_InstanceRed->GetCow()] = m_InstanceRed->GetCow()->GetPoints() / 100.0f * cowAmount;
	cowMap[m_InstanceGreen->GetCow()] = m_InstanceGreen->GetCow()->GetPoints() / 100.0f * cowAmount;
	cowMap[m_InstanceBlue->GetCow()] = m_InstanceBlue->GetCow()->GetPoints() / 100.0f * cowAmount;
	cowMap[m_InstanceYellow->GetCow()] = m_InstanceYellow->GetCow()->GetPoints() / 100.0f * cowAmount;

	/////////////////////////////////////////////////////////////////////
	// Pick 4 best candidates for mating (could be the same one twice) //
	/////////////////////////////////////////////////////////////////////

	vector<Cow*> cowVector;
	while (cowVector.size() < cowAmount){
		Cow* cowResult = nullptr;
		float highestValue = -100;//uhh, should actually be most negative float or something

		for (auto &value : cowMap){
			if (value.second > highestValue){
				cowResult = value.first;
				highestValue = value.second;
			}
		}

		cowMap[cowResult] -= 1.0f;
		cowVector.push_back(cowResult);
	}

	int firstCowPosition = (rand() % cowVector.size());
	Cow* firstCow = cowVector.at(firstCowPosition);
	cowVector.erase(cowVector.begin() + firstCowPosition);
	int firstCowsPartnerPosition = (rand() % cowVector.size());
	Cow* secondCow = cowVector.at(firstCowsPartnerPosition);
	cowVector.erase(cowVector.begin() + firstCowsPartnerPosition);
	Cow* thirdCow = cowVector.at(0);
	cowVector.erase(cowVector.begin());
	Cow* fourthCow = cowVector.at(0);
	cowVector.erase(cowVector.begin());



	////////////////////////////////////////////////////
	// Calculate Calf values, based on chosen parents //
	////////////////////////////////////////////////////

	int slicePosition{ 2 };//Hardcoded slicing at position two

	float* calf1 = Mate(firstCow, secondCow, slicePosition);
	float* calf2 = Mate(secondCow, firstCow, slicePosition);
	float* calf3 = Mate(thirdCow, fourthCow, slicePosition);
	float* calf4 = Mate(fourthCow, thirdCow, slicePosition);


	////////////////////////////
	// Log parents + babies:  //
	////////////////////////////
	std::ofstream output_file(m_Textfile, std::ios::app);

	output_file << "\n-----------------------------------------\n";
	output_file << "\n--- Cow1:  " + to_string(firstCow->GetFleeChance()) + " " + to_string(firstCow->GetFindPillChance()) + " " + to_string(firstCow->GetFindGunChance()) + " " + to_string(firstCow->GetHideChance()) + "\n";
	output_file <<   "--- Cow2:  " + to_string(secondCow->GetFleeChance()) + " " + to_string(secondCow->GetFindPillChance()) + " " + to_string(secondCow->GetFindGunChance()) + " " + to_string(secondCow->GetHideChance()) + "\n";
	output_file <<   "--- Calf1: " + to_string(calf1[0]) + " " + to_string(calf1[1]) + " " + to_string(calf1[2]) + " " + to_string(calf1[3]) + "\n";
	output_file <<   "--- Calf2: " + to_string(calf2[0]) + " " + to_string(calf2[1]) + " " + to_string(calf2[2]) + " " + to_string(calf2[3]) + "\n";
	
	output_file << "\n--- Cow3:  " + to_string(thirdCow->GetFleeChance()) + " " + to_string(thirdCow->GetFindPillChance()) + " " + to_string(thirdCow->GetFindGunChance()) + " " + to_string(thirdCow->GetHideChance()) + "\n";
	output_file <<   "--- Cow4:  " + to_string(fourthCow->GetFleeChance()) + " " + to_string(fourthCow->GetFindPillChance()) + " " + to_string(fourthCow->GetFindGunChance()) + " " + to_string(fourthCow->GetHideChance()) + "\n";
	output_file <<   "--- Calf3: " + to_string(calf3[0]) + " " + to_string(calf3[1]) + " " + to_string(calf3[2]) + " " + to_string(calf3[3]) + "\n";
	output_file <<   "--- Calf4: " + to_string(calf4[0]) + " " + to_string(calf4[1]) + " " + to_string(calf4[2]) + " " + to_string(calf4[3]) + "\n";
	

	////////////////////
	// Set New Values //
	////////////////////

	m_InstanceRed->GetCow()->SetChoiceChances(calf1[0], calf1[1], calf1[2], calf1[3]);
	m_InstanceGreen->GetCow()->SetChoiceChances(calf2[0], calf2[1], calf2[2], calf2[3]);
	m_InstanceBlue->GetCow()->SetChoiceChances(calf3[0], calf3[1], calf3[2], calf3[3]);
	m_InstanceYellow->GetCow()->SetChoiceChances(calf4[0], calf4[1], calf4[2], calf4[3]);

	////////////////////////////
	// Log Normalised babies: //
	////////////////////////////

	output_file << "\n--- Calf1: " + to_string(m_InstanceRed->GetCow()->GetFleeChance()) + " " + to_string(m_InstanceRed->GetCow()->GetFindPillChance()) + " " + to_string(m_InstanceRed->GetCow()->GetFindGunChance()) + " " + to_string(m_InstanceRed->GetCow()->GetHideChance()) + " (Normalised)\n";
	output_file <<   "--- Calf2: " + to_string(m_InstanceGreen->GetCow()->GetFleeChance()) + " " + to_string(m_InstanceGreen->GetCow()->GetFindPillChance()) + " " + to_string(m_InstanceGreen->GetCow()->GetFindGunChance()) + " " + to_string(m_InstanceGreen->GetCow()->GetHideChance()) + " (Normalised)\n";
	output_file <<	 "--- Calf3: " + to_string(m_InstanceBlue->GetCow()->GetFleeChance()) + " " + to_string(m_InstanceBlue->GetCow()->GetFindPillChance()) + " " + to_string(m_InstanceBlue->GetCow()->GetFindGunChance()) + " " + to_string(m_InstanceBlue->GetCow()->GetHideChance()) + " (Normalised)\n";
	output_file <<   "--- Calf4: " + to_string(m_InstanceYellow->GetCow()->GetFleeChance()) + " " + to_string(m_InstanceYellow->GetCow()->GetFindPillChance()) + " " + to_string(m_InstanceYellow->GetCow()->GetFindGunChance()) + " " + to_string(m_InstanceYellow->GetCow()->GetHideChance()) + " (Normalised)\n";

	//Memory handling: delete temporary variables
	delete calf1;
	delete calf2;
	delete calf3;
	delete calf4;

	/////////////////////////
	// Hard Reset entities //	(Basically resets position + removes the 'immortal' state from the cow, in case he found a pill in the previous round)
	/////////////////////////

	m_InstanceRed->HardResetEntities();
	m_InstanceGreen->HardResetEntities();
	m_InstanceBlue->HardResetEntities();
	m_InstanceYellow->HardResetEntities();
}

float* InstanceController::Mate(Cow* Mom, Cow* Dad, int slice){
	float* result = new float[4];
	result[0] = Mom->GetFleeChance();
	result[1] = (slice > 1) ? Mom->GetFindPillChance() : Dad->GetFindPillChance();
	result[2] = (slice < 2) ? Mom->GetFindGunChance() : Dad->GetFindGunChance();
	result[3] = Dad->GetHideChance();
	return result;
}


void InstanceController::ClearMateInformation(){
	std::ofstream output_file(m_Textfile);
	output_file << "Mate behaviour:\n";
}




InstanceController::~InstanceController()
{
}
