#include "WarpPipe.h"

void CWarpPipe::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_WARPPIPE)->Render(x, y);
	//RenderBoundingBox();
}

void CWarpPipe::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - WARPPIPE_BBOX_WIDTH / 2;
	t = y - WARPPIPE_BBOX_HEIGHT / 2;
	r = l + WARPPIPE_BBOX_WIDTH;
	b = t + WARPPIPE_BBOX_HEIGHT;
}