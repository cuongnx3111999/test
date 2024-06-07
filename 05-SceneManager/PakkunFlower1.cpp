#include "PakkunFlower1.h"
#include "fireball.h"
#include "debug.h"

CPakkun1::CPakkun1(float x, float y) :CGameObject(x, y)
{
	SetState(PAKKUN1_STATE_TOPLEFT);
}

void CPakkun1::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - PAKKUN1_BBOX_WIDTH / 2;
	top = y - PAKKUN1_BBOX_HEIGHT / 2;
	right = left + PAKKUN1_BBOX_WIDTH;
	bottom = top + PAKKUN1_BBOX_HEIGHT;
}

void CPakkun1::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	risetime += dt;
	if (risetime < 2000) {
		Rise(dt);
	}
	else if (risetime < 5000) {
		Shoot(dt);
	}
	else if (risetime < 10000) {
		Fall(dt);
	}
	else risetime = 0;
	x += vx * dt;
	y += vy * dt;
	float x1 = CGame::GetInstance()->GetCurrentScene()->xMario;
	float y1 = CGame::GetInstance()->GetCurrentScene()->yMario;
	if (x1 < x && CGame::GetInstance()->GetCurrentScene()->yMario < y) {
		SetState(PAKKUN1_STATE_TOPLEFT);
	}
	else if (x1 < x && y1 > y) {
		SetState(PAKKUN1_STATE_BOTLEFT);
	}
	else if (x1 > x && y1 < y) {
		SetState(PAKKUN1_STATE_TOPRIGHT);
	}
	else if (x1 > x && y1 > 1) {
		SetState(PAKKUN1_STATE_BOTRIGHT);
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CPakkun1::Render()
{
	int aniId = ID_ANI_PAKKUN1_TOPLEFT_IDLE;
	if (state == PAKKUN1_STATE_TOPLEFT && phase == 0)
		aniId = ID_ANI_PAKKUN1_TOPLEFT_IDLE;
	else if (state == PAKKUN1_STATE_TOPLEFT && phase == 1)
		aniId = ID_ANI_PAKKUN1_TOPLEFT_SHOOT;
	else if (state == PAKKUN1_STATE_BOTLEFT && phase == 0)
		aniId = ID_ANI_PAKKUN1_BOTLEFT_IDLE;
	else if (state == PAKKUN1_STATE_BOTLEFT && phase == 1)
		aniId = ID_ANI_PAKKUN1_BOTLEFT_SHOOT;
	else if (state == PAKKUN1_STATE_TOPRIGHT && phase == 0)
		aniId = ID_ANI_PAKKUN1_TOPRIGHT_IDLE; 
	else if (state == PAKKUN1_STATE_TOPRIGHT && phase == 1)
		aniId = ID_ANI_PAKKUN1_TOPRIGHT_SHOOT;
	else if (state == PAKKUN1_STATE_BOTRIGHT && phase == 0)
		aniId = ID_ANI_PAKKUN1_BOTRIGHT_IDLE;
	else if (state == PAKKUN1_STATE_BOTRIGHT && phase == 1)
		aniId = ID_ANI_PAKKUN1_BOTRIGHT_SHOOT;
	if (!settime) {
		y0 = y;
		risetime = 0;
		settime = true;
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	
	//RenderBoundingBox();
}

void CPakkun1::SetState(int state)
{
	CGameObject::SetState(state);
}

void CPakkun1::Rise(DWORD dt) {
	if (vy < 0 && y < y0 - PAKKUN1_BBOX_HEIGHT) {
		y = y0 - PAKKUN1_BBOX_HEIGHT;
		vy = 0;
	}
	else
		vy = -0.016f;
}
void CPakkun1::Fall(DWORD dt) {
	phase = 0; chargefireball = false;
	if (y > y0 && vy > 0)
	{
		vy = 0;
		y = y0;
	}
	else
	vy = 0.016f;
}
void CPakkun1::Shoot(DWORD dt) {
	phase = 1;
	if (!chargefireball) {
		subObject = NULL;
		switch (state) {
		case (PAKKUN1_STATE_TOPLEFT):
			subObject = new CFireBall(x, y, 1); break;
		case (PAKKUN1_STATE_BOTLEFT):
			subObject = new CFireBall(x, y, 2); break;
		case (PAKKUN1_STATE_TOPRIGHT):
			subObject = new CFireBall(x, y, 3); break;
		case (PAKKUN1_STATE_BOTRIGHT):
			subObject = new CFireBall(x, y, 4); break;
		}
		chargefireball = true;
		CreateSubObject = true;
	}
	vy = 0;
}

void CPakkun1::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};
