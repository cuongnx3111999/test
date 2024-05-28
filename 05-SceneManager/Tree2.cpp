#include "Tree2.h"

void CTree2::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_TREE2)->Render(x, y);
	//RenderBoundingBox();
}

void CTree2::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - TREE2_BBOX_WIDTH / 2;
	t = y - TREE2_BBOX_HEIGHT / 2;
	r = l + TREE2_BBOX_WIDTH;
	b = t + TREE2_BBOX_HEIGHT;
}