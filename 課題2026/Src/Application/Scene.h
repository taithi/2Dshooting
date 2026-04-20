#pragma once
#include"Player/Palyer.h"
#include"Player/Radar.h"

class Scene
{
private:

	// テクスチャ ・・・ 画像データ
	KdTexture m_playerTex;
	KdTexture m_radarTex;

	// 行列 ・・・ 座標などの情報
	Math::Matrix matrix;

	C_Player player;
	C_Radar radar;
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

	C_Radar* GetRadar() { return &radar; }
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
