#pragma once

class Player;
class RifleBullet;
class Bird;
class Hit;
class ReflectiveBlock;
class ForecastLine;
class PlayerMove;
class BulletBase;
class Balloon;
class Bell;
class TargetBase;
class Timer;
class RefBlockMini;
class Ufo;
class uiBase;
class Hud;

class Scene
{
private:

	// テクスチャ ・・・ 画像データ
	KdTexture m_playerTex;

	// 行列 ・・・ 座標などの情報
	Math::Matrix matrix;

	Player*m_player=nullptr;

	RifleBullet* m_rifleBullet=nullptr;

	static const int BIRD_NUM = 3; // 鳥の最大数
	Bird* m_bird[BIRD_NUM] = { nullptr };

	Hit* m_hit = nullptr;
	static const int REF_Num = 2;
	ReflectiveBlock* m_refBlock[REF_Num] = { nullptr };

	ForecastLine* m_forecastLine = nullptr;

	PlayerMove* m_playerMove = nullptr;

	BulletBase* m_bulletBase = nullptr;

	Balloon* m_balloon = nullptr;

	Bell* m_bell = nullptr;

	TargetBase* m_targetBase = nullptr;

	Timer* m_timer = nullptr;

	RefBlockMini* m_refBlockMini = nullptr;

	Ufo* m_ufo = nullptr;

	//UiBase* m_uiBase = nullptr;

	Hud* m_hud = nullptr;

public:
	//static const int BIRD_NUM = 3; // 鳥の最大数
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
