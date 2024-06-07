#pragma once
#include "GameObject.h"

#define WINGGOOMBA_GRAVITY 0.001f
#define WINGGOOMBA_WALKING_SPEED 0.05f


#define WINGGOOMBA_BBOX_WIDTH 20
#define WINGGOOMBA_BBOX_HEIGHT 24

#define WINGGOOMBA_STATE_DIE 100

#define ID_ANI_WINGGOOMBA 38000

class CWingGoomba : public CGameObject
{
protected:
	float ax;
	float ay;

	ULONGLONG timer, jump_timer;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CWingGoomba(float x, float y);
	virtual void SetState(int state);
};