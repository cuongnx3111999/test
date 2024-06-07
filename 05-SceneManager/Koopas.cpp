#include "Koopas.h"
#include "Goomba.h"
#include "WingGoomba.h"
#include "WingKoopas.h"
#include "debug.h"

CKoopas::CKoopas(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = KOOPAS_GRAVITY;
	SetState(KOOPAS_STATE_WALKING);
}
CKoopas::CKoopas(float x, float y, float border_left, float border_right) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = KOOPAS_GRAVITY;
	SetState(KOOPAS_STATE_WALKING);
	this->border_left = border_left;
	this->border_right = border_right;
}

void CKoopas::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
		left = x - KOOPAS_BBOX_WIDTH / 2;
		top = y - KOOPAS_BBOX_HEIGHT / 2;
		right = left + KOOPAS_BBOX_WIDTH;
		bottom = top + KOOPAS_BBOX_HEIGHT;
}

void CKoopas::OnNoCollision(DWORD dt)
{	
	x += vx * dt;
	y += vy * dt;
};

void CKoopas::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (e->ny < 0 && e->obj->IsStair())
	{
		vy = 0;
		//isOnPlatform = true;
	}
	if (e->obj->IsBlocking()) {
	if (e->ny != 0)
		{
			vy = 0;
		}
		else if (e->nx != 0)
		{
			vx = -vx;
		}
	}
	
	if (state == KOOPAS_STATE_SPINNING) 
	{
		if (dynamic_cast<CKoopas*>(e->obj)) 
			OnCollisionWithKoopas(e);
		if (dynamic_cast<CGoomba*>(e->obj))
			OnCollisionWithGoomba(e);
		if (dynamic_cast<CWingGoomba*>(e->obj))
			OnCollisionWithWingGoomba(e);
		if (dynamic_cast<CWingKoopas*>(e->obj))
			OnCollisionWithWingKoopas(e);
	}
	
}

void CKoopas::OnCollisionWithGoomba(LPCOLLISIONEVENT e) 
{
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);
	if (goomba->GetState() != GOOMBA_STATE_DIE)
	{
		goomba->SetState(GOOMBA_STATE_DIE_2);
	}
}
void CKoopas::OnCollisionWithWingGoomba(LPCOLLISIONEVENT e)
{
	CWingGoomba* Winggoomba = dynamic_cast<CWingGoomba*>(e->obj);
	Winggoomba->SetState(WINGGOOMBA_STATE_DIE);
}
void CKoopas::OnCollisionWithKoopas(LPCOLLISIONEVENT e) 
{
	CKoopas* koopas = dynamic_cast<CKoopas*>(e->obj);
	if (koopas->GetState() == KOOPAS_STATE_WALKING)
	{
		koopas->SetState(KOOPAS_STATE_DIE);
	}
}
void CKoopas::OnCollisionWithWingKoopas(LPCOLLISIONEVENT e)
{
	CWingKoopas* wingkoopas = dynamic_cast<CWingKoopas*>(e->obj);
	wingkoopas->SetState(WINGKOOPAS_STATE_DIE);
}

void CKoopas::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (y > 250) this->Delete();
	vy += ay * dt;
	vx += ax * dt;
	if (state == KOOPAS_STATE_WALKING) {
		if (border_left != 0 && x < border_left)
		{
			vx = abs(vx);
		}
		if (border_right != 0 && x > border_right)
		{
			vx = -abs(vx);
		}
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CKoopas::Render()
{
	int aniId;
	if (vx < 0) aniId = ID_ANI_KOOPAS_WALKING_LEFT;
	else aniId = ID_ANI_KOOPAS_WALKING_RIGHT;
	if (state == KOOPAS_STATE_IDLE)
	{
		aniId = ID_ANI_KOOPAS_IDLE;
	} 
	else if (state == KOOPAS_STATE_SPINNING) {
		aniId = ID_ANI_KOOPAS_SPINNING;
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CKoopas::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case KOOPAS_STATE_WALKING:
		vx = -KOOPAS_WALKING_SPEED;
		break;
	case KOOPAS_STATE_SPINNING:
		break;
	case KOOPAS_STATE_IDLE:
		y -= 4;
		vx = 0;
		break;
	case KOOPAS_STATE_DIE:
		y += 10;
		vy = 0.05f;
		break;
	}
}

void CKoopas::SpinLeft() {
	vx = KOOPAS_SPINNING_SPEED;
}

void CKoopas::SpinRight() {
	vx = -KOOPAS_SPINNING_SPEED;
}
