#pragma once

#include "../../TargetBase/TargetBase.h"


class Bird :public TargetBase
{
public:

	Bird() {}
	~Bird() { Release(); }

	void Init()override;
	void Update()override;
	void Draw()override;
	
	int GetTimerCount() { return timerCount; }
	int GetNum() { return birdNum; }
private:
	void Release();
	const int birdNum = 3;
	int timerCount; // タイマー用のカウンタ
//	Math::Vector2 pos;
};

