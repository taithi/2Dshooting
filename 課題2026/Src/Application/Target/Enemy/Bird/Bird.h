#pragma once

#include "../../TargetBase/TargetBase.h"


class Bird :public TargetBase
{
public:

	Bird() {}
	~Bird() {}

	void Init()override;
	void Update()override;
	void Draw()override;
	
	int GetNum() { return birdNum; }
private:

	const int birdNum = 3;
	int timerCount; // タイマー用のカウンタ
	int radius = 16;
//	Math::Vector2 pos;
};

