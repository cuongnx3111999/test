#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_STAIR9 29000
#define STAIR9_WIDTH 48
#define STAIR9_BBOX_WIDTH 48
#define STAIR9_BBOX_HEIGHT 144

class CStair9 : public CGameObject {
public:
	CStair9(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsBlocking() { return 0; }
	virtual int IsStair() { return 1; }
};