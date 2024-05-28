#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_BLACKBACKGROUND 40000
#define BLACKBACKGROUND_WIDTH 336
#define BLACKBACKGROUND_BBOX_WIDTH 336
#define BLACKBACKGROUND_BBOX_HEIGHT 416

class CBlackBackground : public CGameObject {
public:
	CBlackBackground(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
};