#pragma once
#include "GameObject.h"

#define WINGKOOPAS_GRAVITY 0.001f
#define WINGKOOPAS_WALKING_SPEED 0.05f

#define WINGKOOPAS_BBOX_WIDTH 16
#define WINGKOOPAS_BBOX_HEIGHT 28

#define WINGKOOPAS_STATE_DIE 100

#define ID_ANI_WINGKOOPAS_LEFT 39001
#define ID_ANI_WINGKOOPAS_RIGHT 39002

class CWingKoopas : public CGameObject
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
	CWingKoopas(float x, float y);
	virtual void SetState(int state);
};