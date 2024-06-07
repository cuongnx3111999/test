#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_TITLE 50000
#define TITLE_WIDTH 180
#define TITLE_BBOX_WIDTH 112
#define TITLE_BBOX_HEIGHT 112

class CTitle : public CGameObject {
public:
	CTitle(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	int IsBlocking() { return 0; }
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};