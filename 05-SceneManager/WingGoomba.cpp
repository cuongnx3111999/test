#include "WingGoomba.h"
#include "Goomba.h"
#include "debug.h"

CWingGoomba::CWingGoomba(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = WINGGOOMBA_GRAVITY;
	vx = -WINGGOOMBA_WALKING_SPEED;
	jump_timer = 0;
}

void CWingGoomba::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - WINGGOOMBA_BBOX_WIDTH / 2;
	top = y - WINGGOOMBA_BBOX_HEIGHT / 2;
	right = left + WINGGOOMBA_BBOX_WIDTH;
	bottom = top + WINGGOOMBA_BBOX_HEIGHT;
}

void CWingGoomba::OnNoCollision(DWORD dt)
{
	if (jump_timer > 2000) {
		vy -= 0.3;
		jump_timer = 0;
	}
	else jump_timer += dt;
	x += vx * dt;
	y += vy * dt;
};

void CWingGoomba::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (e->ny < 0 && e->obj->IsStair())
	{
		vy = 0;
		//isOnPlatform = true;
	}
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CWingGoomba*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CWingGoomba::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;
	if (state == WINGGOOMBA_STATE_DIE && GetTickCount64() - timer > 50) {
		this->Delete();
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CWingGoomba::Render()
{
	int aniId = ID_ANI_WINGGOOMBA;

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}
void CWingGoomba::SetState(int state)
{
	CGameObject::SetState(state);
	if (state == WINGGOOMBA_STATE_DIE) {
		subObject = new CGoomba(x, y);
		subObject->SetPosition(x, y + 4);
		CreateSubObject = true;
		timer = GetTickCount64();
	}
}

