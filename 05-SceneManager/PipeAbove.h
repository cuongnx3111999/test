#pragma once
#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_PIPEABOVE 32000
#define PIPEABOVE_WIDTH 32
#define PIPEABOVE_BBOX_WIDTH 32
#define PIPEABOVE_BBOX_HEIGHT 216

class CPipeAbove : public CGameObject {
public:
	CPipeAbove(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};