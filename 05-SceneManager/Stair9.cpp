#include "Stair9.h"

void CStair9::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_STAIR9)->Render(x, y);
	//RenderBoundingBox();
}

void CStair9::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - STAIR9_BBOX_WIDTH / 2;
	t = y - STAIR9_BBOX_HEIGHT / 2;
	r = l + STAIR9_BBOX_WIDTH;
	b = t + STAIR9_BBOX_HEIGHT;
}