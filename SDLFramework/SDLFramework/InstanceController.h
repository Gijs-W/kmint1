#pragma once
#include "FWApplication.h"

class Cow;
class Instance;
class InstanceController
{
private:
	const std::string m_Textfile{ "../Resources/Files/cow_mate_logs.txt" };
	bool m_SingleInstance{ false };

	Instance* m_InstanceRed;
	Instance* m_InstanceGreen;
	Instance* m_InstanceBlue;
	Instance* m_InstanceYellow;

	float* Mate(Cow* Mom, Cow* Dad, int slice);
	void ClearMateInformation();
public:
	InstanceController(FWApplication* application);
	void Update(float dt);
	Instance* GetInstanceRed();
	Instance* GetInstanceGreen();
	Instance* GetInstanceBlue();
	Instance* GetInstanceYellow();

	void SaveRoundInformation(int m_RoundNumber);

	void Foreplay();

	~InstanceController();
};

