#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_PRIZE 34000

#define PRIZE_WIDTH 26
#define PRIZE_BBOX_WIDTH 26
#define PRIZE_BBOX_HEIGHT 26

class CPrize : public CGameObject {
public:
	CPrize(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
};