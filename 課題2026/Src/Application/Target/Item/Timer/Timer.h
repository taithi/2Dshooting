#pragma once
#include"../../TargetBase/TargetBase.h"
class CountDown;

class Timer :public TargetBase
{
public:
	Timer() {}
	~Timer() {}
	void Init() override;
	void Update() override;
	void Draw() override;
	void SetCountDown(CountDown* cou) { m_countDown = cou; }
private:
	void Release();
	CountDown* m_countDown=nullptr;
};