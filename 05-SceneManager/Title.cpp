#include "Title.h"

void CTitle::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_TITLE)->Render(x, y);
	//RenderBoundingBox();
}
void CTitle::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - TITLE_BBOX_WIDTH / 2;
	t = y - TITLE_BBOX_HEIGHT / 2;
	r = l + TITLE_BBOX_WIDTH;
	b = t + TITLE_BBOX_HEIGHT;
}
