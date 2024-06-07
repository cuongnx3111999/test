#pragma once
#include "GameObject.h"

#define PAKKUN3_BBOX_WIDTH 160
#define PAKKUN3_BBOX_HEIGHT 24

#define PAKKUN3_STATE_TOPLEFT 100
#define PAKKUN3_STATE_BOTLEFT 200
#define PAKKUN3_STATE_TOPRIGHT 300
#define PAKKUN3_STATE_BOTRIGHT 300

#define ID_ANI_PAKKUN3_TOPLEFT 43001
#define ID_ANI_PAKKUN3_BOTLEFT 43002
#define ID_ANI_PAKKUN3_TOPRIGHT 43003
#define ID_ANI_PAKKUN3_BOTRIGHT 43004

class CPakkun3 : public CGameObject
{
protected:

	ULONGLONG chargetime, risetime;
	float y0;
	bool settime = false;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }

	virtual void Rise();
	virtual void Fall();
	virtual void Shoot();

public:
	CPakkun3(float x, float y);
	virtual void SetState(int state);
};
