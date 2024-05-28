#include "Stair6.h"

void CStair6::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_STAIR6)->Render(x, y);
	//RenderBoundingBox();
}

void CStair6::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - STAIR6_BBOX_WIDTH / 2;
	t = y - STAIR6_BBOX_HEIGHT / 2;
	r = l + STAIR6_BBOX_WIDTH;
	b = t + STAIR6_BBOX_HEIGHT;
}