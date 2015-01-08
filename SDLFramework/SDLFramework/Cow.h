#pragma once
#include "MovingEntity.h"
#include "Instance.h"

class Cow :
	public MovingEntity
{
private:
	float m_FleeChance;
	float m_FindPillChance;
	float m_FindGunChance;
	float m_HideChance;
public:
	Cow();
	Cow(float fleeChance, float findPillChance, float findGunChance, float hideChance);
	void Update(Instance* Instance, float deltatime);
	void ResetState();

	float GetFleeChance(){ return m_FleeChance; }
	void SetFleeChance(float chance) { m_FleeChance = chance; }
	float GetFindPillChance(){ return m_FindPillChance; }
	void SetFindPillChance(float chance) { m_FindPillChance = chance; }
	float GetFindGunChance(){ return m_FindGunChance; }
	void SetFindGunChance(float chance) { m_FindGunChance = chance; }
	float GetHideChance(){ return m_HideChance; }
	void SetHideChance(float chance) { m_HideChance = chance; }

	void SetChoiceChances(float fleeChance, float findPillChance, float findGunChance, float hideChance);

	~Cow();
};

