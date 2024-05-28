#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_TREE1 15000
#define TREE1_WIDTH 128
#define TREE1_BBOX_WIDTH 128
#define TREE1_BBOX_HEIGHT 65

class CTree1 : public CGameObject {
public:
	CTree1(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
};