#include "Stair3.h"

void CStair3::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_STAIR3)->Render(x, y);
	//RenderBoundingBox();
}

void CStair3::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - STAIR3_BBOX_WIDTH / 2;
	t = y - STAIR3_BBOX_HEIGHT / 2;
	r = l + STAIR3_BBOX_WIDTH;
	b = t + STAIR3_BBOX_HEIGHT;
}