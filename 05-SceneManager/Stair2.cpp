#include "Stair2.h"

void CStair2::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_STAIR2)->Render(x, y);
	//RenderBoundingBox();
}

void CStair2::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - STAIR2_BBOX_WIDTH / 2;
	t = y - STAIR2_BBOX_HEIGHT / 2;
	r = l + STAIR2_BBOX_WIDTH;
	b = t + STAIR2_BBOX_HEIGHT;
}