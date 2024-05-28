#include "Stair7.h"

void CStair7::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_STAIR7)->Render(x, y);
	//RenderBoundingBox();
}

void CStair7::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - STAIR7_BBOX_WIDTH / 2;
	t = y - STAIR7_BBOX_HEIGHT / 2;
	r = l + STAIR7_BBOX_WIDTH;
	b = t + STAIR7_BBOX_HEIGHT;
}