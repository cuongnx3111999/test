#include "MysteryBox.h"
#include "PlayScene.h"
#include "Game.h"

#include "debug.h"

CMysteryBox::CMysteryBox(float x, float y, int prize) : CGameObject(x, y) {
	if (prize == 1) {
		subObject = new CCoinFromBox(x, y);
		subObject->SetPosition(x, y - 16);
	}
	else if (prize == 2) {
		subObject = new CMushRoom(x, y);
		//subObject->SetPosition(x, y - 16);
	}
	taken_start = -1;
	SetState(MYSTERYBOX_STATE_FIRST);
	y0 = y;
}

void CMysteryBox::Render()
{
	int aniId = ID_ANI_MYSTERYBOX;
	if (state == MYSTERYBOX_STATE_TAKEN)
	{
		aniId = ID_ANI_MYSTERYBOX_TAKEN;
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CMysteryBox::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - MYSTERYBOX_BBOX_WIDTH / 2;
	t = y - MYSTERYBOX_BBOX_HEIGHT / 2;
	r = l + MYSTERYBOX_BBOX_WIDTH;
	b = t + MYSTERYBOX_BBOX_HEIGHT;
}

void CMysteryBox::SetState(int state)
{
	CGameObject::SetState(state);
	//if (this->state == MYSTERYBOX_STATE_TAKEN) return;
	switch (state)
	{
	case MYSTERYBOX_STATE_FIRST:
		break;
	case MYSTERYBOX_STATE_TAKEN:
		taken_start = GetTickCount64();
		CreateSubObject = true;
		break;
	}
}

void CMysteryBox::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (state == MYSTERYBOX_STATE_TAKEN) {
		y += vy * dt;
		if (GetTickCount64() - taken_start < 70) {
			vy = -0.1f;
		}
		else if (y < y0) {
			vy = 0.1f;
		}
		else {
			y = y0;
			vy = 0;
		}
	}
	CGameObject::Update(dt,coObjects);
}