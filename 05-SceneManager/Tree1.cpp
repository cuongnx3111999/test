#include "Tree1.h"

void CTree1::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_TREE1)->Render(x, y);
	//RenderBoundingBox();
}

void CTree1::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - TREE1_BBOX_WIDTH / 2;
	t = y - TREE1_BBOX_HEIGHT / 2;
	r = l + TREE1_BBOX_WIDTH;
	b = t + TREE1_BBOX_HEIGHT;
}