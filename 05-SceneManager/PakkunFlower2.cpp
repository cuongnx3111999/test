#include "PakkunFlower2.h"
#include "debug.h"

void CPakkun2::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - PAKKUN2_BBOX_WIDTH / 2;
	top = y - PAKKUN2_BBOX_HEIGHT / 2;
	right = left + PAKKUN2_BBOX_WIDTH;
	bottom = top + PAKKUN2_BBOX_HEIGHT;
}

void CPakkun2::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	x += vx * dt;
	y += vy * dt;
	risetime += dt;
	if (risetime < 2000) {
		Rise();
	}
	else if (risetime < 7000) {
		Fall();
	}
	else risetime = 0;
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CPakkun2::Render()
{
	if (!settime) {
		y0 = y;
		risetime = 0;
		settime = true;
	}
	CAnimations::GetInstance()->Get(ID_ANI_PAKKUN2)->Render(x, y);

	//RenderBoundingBox();
}

void CPakkun2::SetState(int state)
{
	CGameObject::SetState(state);
}

void CPakkun2::Rise() {
	if (y < y0 - PAKKUN2_BBOX_HEIGHT) {
		y = y0 - PAKKUN2_BBOX_HEIGHT;
		vy = 0;
	}
	else
		vy = -0.016f;
}
void CPakkun2::Fall() {
	if (y > y0)
	{
		vy = 0;
		y = y0;
	}
	else
		vy = 0.016f;
}