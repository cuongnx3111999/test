#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_FIREBALL 44000

#define	FIREBALL_WIDTH 8
#define FIREBALL_BBOX_WIDTH 8
#define FIREBALL_BBOX_HEIGHT 8

class CFireBall : public CGameObject {
protected:
	ULONGLONG appear;
	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsBlocking() { return 0; }

public:
	CFireBall(float x, float y, int direction); //direction: 1 - topleft, 2 - botleft, 3 - topright, 4 - botright

};