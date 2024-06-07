#include "Koopas.h"
#include "WingKoopas.h"
#include "Goomba.h"
#include "debug.h"

CWingKoopas::CWingKoopas(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = WINGKOOPAS_GRAVITY;
	vx = -WINGKOOPAS_WALKING_SPEED;
}

void CWingKoopas::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - KOOPAS_BBOX_WIDTH / 2;
	top = y - KOOPAS_BBOX_HEIGHT / 2;
	right = left + KOOPAS_BBOX_WIDTH;
	bottom = top + KOOPAS_BBOX_HEIGHT;
}

void CWingKoopas::OnNoCollision(DWORD dt)
{
	if (jump_timer > 2000) {
		vy -= 0.3;
		jump_timer = 0;
	}
	else jump_timer += dt;
	x += vx * dt;
	y += vy * dt;
};

void CWingKoopas::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (e->ny < 0 && e->obj->IsStair())
	{
		vy = 0;
		//isOnPlatform = true;
	}
	if (!e->obj->IsBlocking()) return;
	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
	if (dynamic_cast<CKoopas*>(e->obj)) return;
	if (dynamic_cast<CGoomba*>(e->obj)) return;
	if (dynamic_cast<CWingKoopas*>(e->obj)) return;
}

void CWingKoopas::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;
	if (state == WINGKOOPAS_STATE_DIE && GetTickCount64() - timer > 50) {
		this->Delete();
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CWingKoopas::Render()
{
	int aniId;
	if (vx < 0) aniId = ID_ANI_WINGKOOPAS_LEFT;
	else aniId = ID_ANI_WINGKOOPAS_RIGHT;
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CWingKoopas::SetState(int state)
{
	CGameObject::SetState(state);
	if (state == WINGKOOPAS_STATE_DIE) {
		subObject = new CKoopas(x, y);
		subObject->SetPosition(x, y - 10);
		CreateSubObject = true;
		timer = GetTickCount64();
	}
}
