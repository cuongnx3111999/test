#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_STAIR6 26000
#define STAIR6_WIDTH 112
#define STAIR6_BBOX_WIDTH 112
#define STAIR6_BBOX_HEIGHT 31

class CStair6 : public CGameObject {
public:
	CStair6(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsBlocking() { return 0; }
	virtual int IsStair() { return 1; }
};