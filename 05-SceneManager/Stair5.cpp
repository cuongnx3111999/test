#include "Stair5.h"

void CStair5::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_STAIR5)->Render(x, y);
	//RenderBoundingBox();
}

void CStair5::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - STAIR5_BBOX_WIDTH / 2;
	t = y - STAIR5_BBOX_HEIGHT / 2;
	r = l + STAIR5_BBOX_WIDTH;
	b = t + STAIR5_BBOX_HEIGHT;
}