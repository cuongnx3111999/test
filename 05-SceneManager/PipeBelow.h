#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_PIPEBELOW 31000
#define PIPEBELOW_WIDTH 30
#define PIPEBELOW_BBOX_WIDTH 30
#define PIPEBELOW_BBOX_HEIGHT 30

class CPipeBelow : public CGameObject {
public:
	CPipeBelow(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};