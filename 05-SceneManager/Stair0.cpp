#include "Stair0.h"

void CStair0::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_STAIR0)->Render(x, y);
	//RenderBoundingBox();
}

void CStair0::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - STAIR0_BBOX_WIDTH / 2;
	t = y - STAIR0_BBOX_HEIGHT / 2;
	r = l + STAIR0_BBOX_WIDTH;
	b = t + STAIR0_BBOX_HEIGHT;
}