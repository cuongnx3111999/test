#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_TREE3 17000
#define TREE3_WIDTH 64
#define TREE3_BBOX_WIDTH 64
#define TREE3_BBOX_HEIGHT 49

class CTree3 : public CGameObject {
public:
	CTree3(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
};