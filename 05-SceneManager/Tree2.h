#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_TREE2 16000
#define TREE2_WIDTH 127
#define TREE2_BBOX_WIDTH 127
#define TREE2_BBOX_HEIGHT 65

class CTree2 : public CGameObject {
public:
	CTree2(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
};