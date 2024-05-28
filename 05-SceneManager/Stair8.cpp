#include "Stair8.h"

void CStair8::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_STAIR8)->Render(x, y);
	//RenderBoundingBox();
}

void CStair8::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - STAIR8_BBOX_WIDTH / 2;
	t = y - STAIR8_BBOX_HEIGHT / 2;
	r = l + STAIR8_BBOX_WIDTH;
	b = t + STAIR8_BBOX_HEIGHT;
}