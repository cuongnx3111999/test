#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_STAIR4 24000
#define STAIR4_WIDTH 96
#define STAIR4_BBOX_WIDTH 96
#define STAIR4_BBOX_HEIGHT 32

class CStair4 : public CGameObject {
public:
	CStair4(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsBlocking() { return 0; }
	virtual int IsStair() { return 1; }
};