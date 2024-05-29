#include "Prize.h"

void CPrize::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_PRIZE)->Render(x, y);
	//RenderBoundingBox();
}

void CPrize::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - PRIZE_BBOX_WIDTH / 2;
	t = y - PRIZE_BBOX_HEIGHT / 2;
	r = l + PRIZE_BBOX_WIDTH;
	b = t + PRIZE_BBOX_HEIGHT;
}