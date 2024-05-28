#include "BlackBackground.h"

void CBlackBackground::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_BLACKBACKGROUND)->Render(x, y);
	//RenderBoundingBox();
}

void CBlackBackground::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BLACKBACKGROUND_BBOX_WIDTH / 2;
	t = y - BLACKBACKGROUND_BBOX_HEIGHT / 2;
	r = l + BLACKBACKGROUND_BBOX_WIDTH;
	b = t + BLACKBACKGROUND_BBOX_HEIGHT;
}