#pragma once
#include "Game.h"
#include "Textures.h"
#include "Scene.h"
#include "GameObject.h"
#include "Brick.h"
#include "Mario.h"
#include "Goomba.h"
#include "MysteryBox.h"
#include "Bush.h"
#include "Tree1.h"
#include "Tree2.h"
#include "Tree3.h"
#include "Tree4.h"
#include "WarpPipe.h"
#include "Cloud.h"
#include "Stair0.h"
#include "Stair1.h"
#include "Stair2.h"
#include "Stair3.h"
#include "Stair4.h"
#include "Stair5.h"
#include "Stair6.h"
#include "Stair7.h"
#include "Stair8.h"
#include "Stair9.h"
#include "Wood.h"
#include "PipeBelow.h"
#include "PipeAbove.h"
#include "BlackBackground.h"
#include "Prize.h"
#include "CoinFromBox.h"
#include "MushRoom.h"
#include "Koopas.h"
#include "WingGoomba.h"
#include "WingKoopas.h"
#include "PakkunFlower.h"
//#include "Koopas.h"


class CPlayScene: public CScene
{
static CPlayScene* __instance;
protected: 
	// A play scene has to have player, right? 
	LPGAMEOBJECT player;					

	vector<LPGAMEOBJECT> objects;

	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);

	void _ParseSection_ASSETS(string line);
	void _ParseSection_OBJECTS(string line);

	void LoadAssets(LPCWSTR assetFile);
	
public: 
	CPlayScene(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();

	LPGAMEOBJECT GetPlayer() { return player; }

	void Clear();
	void PurgeDeletedObjects();

	static bool IsGameObjectDeleted(const LPGAMEOBJECT& o);
	virtual void SpawnGameObject(CGameObject* obj, float x, float y);
};

typedef CPlayScene* LPPLAYSCENE;

