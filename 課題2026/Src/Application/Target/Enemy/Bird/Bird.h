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
	

	Math::Vector2 GetBirdPos() { return pos; }
	bool GetFlg() { return flg; }
	
private:
	int timerCount; // タイマー用のカウンタ

//	Math::Vector2 pos;
};

