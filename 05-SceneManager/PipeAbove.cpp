#include "PipeAbove.h"

void CPipeAbove::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_PIPEABOVE)->Render(x, y);
	//RenderBoundingBox();
}

void CPipeAbove::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - PIPEABOVE_BBOX_WIDTH / 2;
	t = y - PIPEABOVE_BBOX_HEIGHT / 2;
	r = l + PIPEABOVE_BBOX_WIDTH;
	b = t + PIPEABOVE_BBOX_HEIGHT;
}