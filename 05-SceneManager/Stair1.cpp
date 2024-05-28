#include "Stair1.h"

void CStair1::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_STAIR1)->Render(x, y);
	//RenderBoundingBox();
}

void CStair1::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - STAIR1_BBOX_WIDTH / 2;
	t = y - STAIR1_BBOX_HEIGHT / 2;
	r = l + STAIR1_BBOX_WIDTH;
	b = t + STAIR1_BBOX_HEIGHT;
}