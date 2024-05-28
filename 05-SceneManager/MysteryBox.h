#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_MYSTERYBOX 12000

#define MYSTERYBOX_WIDTH 16
#define MYSTERYBOX_BBOX_WIDTH 16
#define MYSTERYBOX_BBOX_HEIGHT 16

class CMysteryBox : public CGameObject {
public:
	CMysteryBox(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};