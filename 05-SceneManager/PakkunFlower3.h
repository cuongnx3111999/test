#pragma once
#include "GameObject.h"

#define PAKKUN3_BBOX_WIDTH 16
#define PAKKUN3_BBOX_HEIGHT 22

#define PAKKUN3_STATE_TOPLEFT 100
#define PAKKUN3_STATE_BOTLEFT 200
#define PAKKUN3_STATE_TOPRIGHT 300
#define PAKKUN3_STATE_BOTRIGHT 400

#define ID_ANI_PAKKUN3_TOPLEFT_IDLE 43011
#define ID_ANI_PAKKUN3_TOPLEFT_SHOOT 43012
#define ID_ANI_PAKKUN3_BOTLEFT_IDLE 43021
#define ID_ANI_PAKKUN3_BOTLEFT_SHOOT 43022
#define ID_ANI_PAKKUN3_TOPRIGHT_IDLE 43031
#define ID_ANI_PAKKUN3_TOPRIGHT_SHOOT 43032
#define ID_ANI_PAKKUN3_BOTRIGHT_IDLE 43041
#define ID_ANI_PAKKUN3_BOTRIGHT_SHOOT 43042

class CPakkun3 : public CGameObject
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

	virtual void Rise();
	virtual void Fall();
	virtual void Shoot();

public:
	CPakkun3(float x, float y);
	virtual void SetState(int state);
};
