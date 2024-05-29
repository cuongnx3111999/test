#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_MYSTERYBOX 12000
#define ID_ANI_MYSTERYBOX_TAKEN 12001

#define MYSTERYBOX_WIDTH 16
#define MYSTERYBOX_BBOX_WIDTH 16
#define MYSTERYBOX_BBOX_HEIGHT 16

#define MYSTERYBOX_STATE_FIRST	100
#define MYSTERYBOX_STATE_TAKEN	200

class CMysteryBox : public CGameObject {
public:
	CMysteryBox(float x, float y, int prize); //prize = 1: money, prize = 2: mushroom
	virtual void SetState(int state);

protected:
	float ax = 0;
	float ay = 0;

	float y0;

	ULONGLONG taken_start;

	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);

	
};