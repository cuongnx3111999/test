#include "PakkunFlower3.h"
#include "debug.h"

CPakkun3::CPakkun3(float x, float y) :CGameObject(x, y)
{
	SetState(PAKKUN3_STATE_TOPLEFT);
}

void CPakkun3::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - PAKKUN3_BBOX_WIDTH / 2;
	top = y - PAKKUN3_BBOX_HEIGHT / 2;
	right = left + PAKKUN3_BBOX_WIDTH;
	bottom = top + PAKKUN3_BBOX_HEIGHT;
}

void CPakkun3::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	x += vx * dt;
	y += vy * dt;
	risetime += dt;
	if (risetime < 2000) {
		Rise();
	}
	else if (risetime < 4000) {
		Shoot();
	}
	else if (risetime < 9000) {
		Fall();
	}
	else risetime = 0;

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CPakkun3::Render()
{
	int aniId = ID_ANI_PAKKUN3_TOPLEFT;
	/*if (state == PAKKUN3_STATE_TOPLEFT)
	{
		aniId = ID_ANI_PAKKUN3_TOPLEFT;
	}
	else if (state == PAKKUN3_STATE_BOTLEFT)
	{
		aniId = ID_ANI_PAKKUN3_BOTLEFT;
	}
	else if (state == PAKKUN3_STATE_TOPRIGHT)
	{
		aniId = ID_ANI_PAKKUN3_TOPRIGHT;
	}
	else if (state == PAKKUN3_STATE_BOTRIGHT)
	{
		aniId = ID_ANI_PAKKUN3_BOTRIGHT;
	}*/
	if (!settime) {
		y0 = y;
		risetime = 0;
		settime = true;
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);

	//RenderBoundingBox();
}

void CPakkun3::SetState(int state)
{
	CGameObject::SetState(state);
}

void CPakkun3::Rise() {
	if (y < y0 - PAKKUN3_BBOX_HEIGHT) {
		y = y0 - PAKKUN3_BBOX_HEIGHT;
		vy = 0;
	}
	else
		vy = -0.016f;
}
void CPakkun3::Fall() {
	if (y > y0)
	{
		vy = 0;
		y = y0;
	}
	else
		vy = 0.016f;
}
void CPakkun3::Shoot() {
	vy = 0;
}
