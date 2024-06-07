#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_CURTAIN 51000
#define CURTAIN_WIDTH 337
#define CURTAIN_BBOX_WIDTH 337
#define CURTAIN_BBOX_HEIGHT 282

class CCurtain : public CGameObject {
public:
	CCurtain(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt);
	int IsBlocking() { return 0; }
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};