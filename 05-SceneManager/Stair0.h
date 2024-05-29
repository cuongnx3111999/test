#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_STAIR0 20000
#define STAIR0_WIDTH 48
#define STAIR0_BBOX_WIDTH 48
#define STAIR0_BBOX_HEIGHT 48

class CStair0 : public CGameObject {
public:
	CStair0(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsBlocking() { return 0; }
	virtual int IsStair() { return 1; }
};