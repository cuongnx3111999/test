#include "MysteryBox.h"

void CMysteryBox::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_MYSTERYBOX)->Render(x, y);
	//RenderBoundingBox();
}

void CMysteryBox::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - MYSTERYBOX_BBOX_WIDTH / 2;
	t = y - MYSTERYBOX_BBOX_HEIGHT / 2;
	r = l + MYSTERYBOX_BBOX_WIDTH;
	b = t + MYSTERYBOX_BBOX_HEIGHT;
}