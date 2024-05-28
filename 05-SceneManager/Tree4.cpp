#include "Tree4.h"

void CTree4::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_TREE4)->Render(x, y);
	//RenderBoundingBox();
}

void CTree4::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - TREE4_BBOX_WIDTH / 2;
	t = y - TREE4_BBOX_HEIGHT / 2;
	r = l + TREE4_BBOX_WIDTH;
	b = t + TREE4_BBOX_HEIGHT;
}