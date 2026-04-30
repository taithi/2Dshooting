#pragma once
#include"../BulletBase/BulletBase.h"

class Player;

class ForecastLine: public BulletBase
{
public:
		ForecastLine() {};
		~ForecastLine() { Release(); };
		void Init() override;
		void Update() override;
		void Draw() override;
		void SetPlayer(Player* pla) { m_player = pla; }

private:
	Player* m_player = nullptr;

	void Release();
	int lineNum = 15; // 予測線の数
	Math::Vector2 savePos[40];
	Math::Vector2 sMove;
	};	