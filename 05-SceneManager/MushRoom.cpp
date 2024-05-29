#include "MushRoom.h"

CMushRoom::CMushRoom(float x, float y) : CGameObject(x, y) {
	vx = 0;
	vy = -0.016f; 
	ay = 0;
}

void CMushRoom::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_MUSHROOM)->Render(x, y);
	RenderBoundingBox();
	if (!setAppear) {
		start = GetTickCount64();
		setAppear = true;
	} 
}

void CMushRoom::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - MUSHROOM_BBOX_WIDTH / 2;
	t = y - MUSHROOM_BBOX_HEIGHT / 2;
	r = l + MUSHROOM_BBOX_WIDTH;
	b = t + MUSHROOM_BBOX_HEIGHT;
}

void CMushRoom::OnNoCollision(DWORD dt) 
{
	x += vx * dt;
	y += vy * dt;
}

void CMushRoom::OnCollisionWith(LPCOLLISIONEVENT e) 
{
	if (GetTickCount64() - start > 500) {
		if (!e->obj->IsBlocking()) return;
		if (dynamic_cast<CMushRoom*>(e->obj)) return;

		if (e->ny != 0)
		{
			vy = 0;
		}
		else if (e->nx != 0)
		{
			vx = -vx;
		}
	}
	else return;
}

void CMushRoom::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if (GetTickCount64() - start > 500) {
		ay = MUSHROOM_GRAVITY;
		vx = -MUSHROOM_WALKING_SPEED;
	} else y += vy * dt;

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}