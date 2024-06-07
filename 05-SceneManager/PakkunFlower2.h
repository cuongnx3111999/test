#pragma once
#include "GameObject.h"

#define PAKKUN2_BBOX_WIDTH 16
#define PAKKUN2_BBOX_HEIGHT 24

#define ID_ANI_PAKKUN2 42000

class CPakkun2 : public CGameObject
{
protected:
	ULONGLONG risetime;

	bool settime = false;
	float y0;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }

	virtual void Rise();
	virtual void Fall();

public:
	CPakkun2(float x, float y) {}
	virtual void SetState(int state);
};