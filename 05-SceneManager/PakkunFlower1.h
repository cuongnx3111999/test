#pragma once
#include "GameObject.h"

#define PAKKUN1_BBOX_WIDTH 16
#define PAKKUN1_BBOX_HEIGHT 30

#define PAKKUN1_STATE_TOPLEFT 100
#define PAKKUN1_STATE_BOTLEFT 200
#define PAKKUN1_STATE_TOPRIGHT 300
#define PAKKUN1_STATE_BOTRIGHT 400

#define ID_ANI_PAKKUN1_TOPLEFT_IDLE 41011
#define ID_ANI_PAKKUN1_TOPLEFT_SHOOT 41012
#define ID_ANI_PAKKUN1_BOTLEFT_IDLE 41021
#define ID_ANI_PAKKUN1_BOTLEFT_SHOOT 41022
#define ID_ANI_PAKKUN1_TOPRIGHT_IDLE 41031
#define ID_ANI_PAKKUN1_TOPRIGHT_SHOOT 41032
#define ID_ANI_PAKKUN1_BOTRIGHT_IDLE 41041
#define ID_ANI_PAKKUN1_BOTRIGHT_SHOOT 41042

class CPakkun1 : public CGameObject
{
protected:

	ULONGLONG chargetime, risetime;
	float y0;
	bool settime = false, chargefireball = false;
	int phase; // if pakkun is shooting or not

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void Rise(DWORD dt);
	virtual void Fall(DWORD dt);
	virtual void Shoot(DWORD dt);


public:
	CPakkun1(float x, float y);
	virtual void SetState(int state);
};