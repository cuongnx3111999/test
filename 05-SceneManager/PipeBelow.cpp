#include "PipeBelow.h"

void CPipeBelow::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_PIPEBELOW)->Render(x, y);
	//RenderBoundingBox();
}

void CPipeBelow::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - PIPEBELOW_BBOX_WIDTH / 2;
	t = y - PIPEBELOW_BBOX_HEIGHT / 2;
	r = l + PIPEBELOW_BBOX_WIDTH;
	b = t + PIPEBELOW_BBOX_HEIGHT;
}