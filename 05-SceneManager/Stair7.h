#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_STAIR7 27000
#define STAIR7_WIDTH 112
#define STAIR7_BBOX_WIDTH 112
#define STAIR7_BBOX_HEIGHT 63

class CStair7 : public CGameObject {
public:
	CStair7(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsBlocking() { return 0; }
	virtual int IsStair() { return 1; }
};