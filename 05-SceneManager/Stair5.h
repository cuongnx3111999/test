#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_STAIR5 25000
#define STAIR5_WIDTH 64
#define STAIR5_BBOX_WIDTH 64
#define STAIR5_BBOX_HEIGHT 111

class CStair5 : public CGameObject {
public:
	CStair5(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsBlocking() { return 0; }
	virtual int IsStair() { return 1; }
};