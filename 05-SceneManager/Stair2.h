#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_STAIR2 22000
#define STAIR2_WIDTH 80
#define STAIR2_BBOX_WIDTH 80
#define STAIR2_BBOX_HEIGHT 48

class CStair2 : public CGameObject {
public:
	CStair2(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};