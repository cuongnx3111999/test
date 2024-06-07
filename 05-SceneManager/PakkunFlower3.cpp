#include "PakkunFlower3.h"
#include "fireball.h"
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
	x += vx * dt;
	y += vy * dt;
	float x1 = CGame::GetInstance()->GetCurrentScene()->xMario;
	float y1 = CGame::GetInstance()->GetCurrentScene()->yMario;
	if (x1 < x && y1 < y) {
		SetState(PAKKUN3_STATE_TOPLEFT);
	}
	else if (x1 < x && y1 > y) {
		SetState(PAKKUN3_STATE_BOTLEFT);
	}
	else if (x1 > x && y1 < y) {
		SetState(PAKKUN3_STATE_TOPRIGHT);
	}
	else if (x1 > x && y1 > 1) {
		SetState(PAKKUN3_STATE_BOTRIGHT);
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CPakkun3::Render()
{
	int aniId = ID_ANI_PAKKUN3_TOPLEFT_IDLE;
	if (state == PAKKUN3_STATE_TOPLEFT && phase == 0)
		aniId = ID_ANI_PAKKUN3_TOPLEFT_IDLE;
	else if (state == PAKKUN3_STATE_TOPLEFT && phase == 1)
		aniId = ID_ANI_PAKKUN3_TOPLEFT_SHOOT;
	else if (state == PAKKUN3_STATE_BOTLEFT && phase == 0)
		aniId = ID_ANI_PAKKUN3_BOTLEFT_IDLE;
	else if (state == PAKKUN3_STATE_BOTLEFT && phase == 1)
		aniId = ID_ANI_PAKKUN3_BOTLEFT_SHOOT;
	else if (state == PAKKUN3_STATE_TOPRIGHT && phase == 0)
		aniId = ID_ANI_PAKKUN3_TOPRIGHT_IDLE;
	else if (state == PAKKUN3_STATE_TOPRIGHT && phase == 1)
		aniId = ID_ANI_PAKKUN3_TOPRIGHT_SHOOT;
	else if (state == PAKKUN3_STATE_BOTRIGHT && phase == 0)
		aniId = ID_ANI_PAKKUN3_BOTRIGHT_IDLE;
	else if (state == PAKKUN3_STATE_BOTRIGHT && phase == 1)
		aniId = ID_ANI_PAKKUN3_BOTRIGHT_SHOOT;
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
	phase = 0; chargefireball = false;
	if (y > y0 + 6)
	{
		vy = 0;
		y = y0 + 6;
	}
	else
		vy = 0.016f;
}
void CPakkun3::Shoot() {
	phase = 1;
	if (!chargefireball) {
		subObject = NULL;
		switch (state) {
		case (PAKKUN3_STATE_TOPLEFT):
			subObject = new CFireBall(x, y, 1); break;
		case (PAKKUN3_STATE_BOTLEFT):
			subObject = new CFireBall(x, y, 2); break;
		case (PAKKUN3_STATE_TOPRIGHT):
			subObject = new CFireBall(x, y, 3); break;
		case (PAKKUN3_STATE_BOTRIGHT):
			subObject = new CFireBall(x, y, 4); break;
		}
		subObject->SetPosition(x, y - 4);
		chargefireball = true;
		CreateSubObject = true;
	}
	vy = 0;
}

void CPakkun3::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};
