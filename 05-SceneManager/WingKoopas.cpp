<<<<<<< HEAD
=======
#include "Koopas.h"
#include "WingKoopas.h"
#include "Goomba.h"
#include "debug.h"

CWingKoopas::CWingKoopas(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = WINGKOOPAS_GRAVITY;
	vx = -KOOPAS_WALKING_SPEED;
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

	if (dynamic_cast<CKoopas*>(e->obj)) return;
	if (dynamic_cast<CGoomba*>(e->obj)) return;
	if (dynamic_cast<CWingKoopas*>(e->obj)) return;
	if (!e->obj->IsBlocking()) return;
	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
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
	if (vx < 0) aniId = ID_ANI_WINGKOOPAS;
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CWingKoopas::SetState(int state)
{
	CGameObject::SetState(state);
	if (state == WINGKOOPAS_STATE_DIE) {
		subObject = new CKoopas(x, y);
		subObject->SetPosition(x, y + 4);
		CreateSubObject = true;
		timer = GetTickCount64();
	}
}
>>>>>>> parent of d28a2ef (add intro scene and pakkun1 files)
