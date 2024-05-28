#include "Stair4.h"

void CStair4::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_STAIR4)->Render(x, y);
	//RenderBoundingBox();
}

void CStair4::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - STAIR4_BBOX_WIDTH / 2;
	t = y - STAIR4_BBOX_HEIGHT / 2;
	r = l + STAIR4_BBOX_WIDTH;
	b = t + STAIR4_BBOX_HEIGHT;
}