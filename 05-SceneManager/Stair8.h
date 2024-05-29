#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_STAIR8 28000
#define STAIR8_WIDTH 112
#define STAIR8_BBOX_WIDTH 112
#define STAIR8_BBOX_HEIGHT 96

class CStair8 : public CGameObject {
public:
	CStair8(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsBlocking() { return 0; }
	virtual int IsStair() { return 1; }
};