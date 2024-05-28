#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_TREE4 18000
#define TREE4_WIDTH 96
#define TREE4_BBOX_WIDTH 96
#define TREE4_BBOX_HEIGHT 130

class CTree4 : public CGameObject {
public:
	CTree4(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
};