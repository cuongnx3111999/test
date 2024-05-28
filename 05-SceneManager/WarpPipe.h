#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_WARPPIPE 16000
#define WARPPIPE_WIDTH 32
#define WARPPIPE_BBOX_WIDTH 32
#define WARPPIPE_BBOX_HEIGHT 32

class CWarpPipe : public CGameObject {
public:
	CWarpPipe(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};