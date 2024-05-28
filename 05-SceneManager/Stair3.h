#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_STAIR3 23000
#define STAIR3_WIDTH 64
#define STAIR3_BBOX_WIDTH 64
#define STAIR3_BBOX_HEIGHT 80

class CStair3 : public CGameObject {
public:
	CStair3(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};