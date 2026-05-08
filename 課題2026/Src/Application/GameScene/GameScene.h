
#pragma once
#include "../SceneBase/SceneBase.h"

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
class Score;
class CountDown;
class Scene;

class GameScene : public SceneBase
{
public:


	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void ImGuiUpdate() override;

private:

	Player* m_player = nullptr;

	RifleBullet* m_rifleBullet = nullptr;

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

	Score* m_score = nullptr;

	CountDown* m_countDown = nullptr;

	Scene* m_scene = nullptr;

};