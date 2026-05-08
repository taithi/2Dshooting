#pragma once

class GameScene;

class Scene
{
private:

	// テクスチャ ・・・ 画像データ
	KdTexture m_playerTex;

	// 行列 ・・・ 座標などの情報
	Math::Matrix matrix;

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

	//scenetype GetType() { return  nowscene; }

private:
	//GameScene* m_gameScene = nullptr;

	Scene() {}
public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}

	//GAMEシーン
	GameScene* m_GameScene = nullptr;
};

#define SCENE Scene::GetInstance()
