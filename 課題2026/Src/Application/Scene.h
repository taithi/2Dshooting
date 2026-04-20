#pragma once
#include"Player/Palyer.h"
#include"Player/Bullet.h"

class Scene
{
private:

	// テクスチャ ・・・ 画像データ
	KdTexture m_playerTex;
	KdTexture m_bulletTex;

	// 行列 ・・・ 座標などの情報
	Math::Matrix matrix;

	C_Player player;
	C_Bullet bullet;

public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	// 描画処理
	void Draw2D();

	// GUI処理
	void ImGuiUpdate();

	C_Bullet* GetRadar() { return &bullet; }
	C_Player* GetPlayer() { return &player; }
private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
