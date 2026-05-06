#pragma once
#include"../uiBase/uiBase.h"

class CountDown : public UiBase
{
public:
	CountDown() {}
	~CountDown() { Release(); }

	void Init() override;
	void Update() override;
	void Draw() override;
	void SetScore(int cou) { m_countDown = cou; }
	int GetScore() { return m_countDown; }
private:

	void Release();

	static const int maxDigits = 2;
	int digits[maxDigits] = {};
	int m_countDown;
	float m_timer = 0.0f;
};
