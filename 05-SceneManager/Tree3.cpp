#include "Tree3.h"

void CTree3::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_TREE3)->Render(x, y);
	//RenderBoundingBox();
}

void CTree3::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - TREE3_BBOX_WIDTH / 2;
	t = y - TREE3_BBOX_HEIGHT / 2;
	r = l + TREE3_BBOX_WIDTH;
	b = t + TREE3_BBOX_HEIGHT;
}