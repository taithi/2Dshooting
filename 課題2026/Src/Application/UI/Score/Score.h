#pragma once

#include"../uiBase/uiBase.h"

class Score :public UiBase
{
public:
	Score() {}
	~Score() { Release(); }
	void Init() override;
	void Update() override;
	void Draw() override;
	void SetScore(int sco) { m_score = sco; }

	int GetScore() { return m_score; }
private:
	void Release();
	
	static const int maxDigits = 5;
	int digits[maxDigits] = {};
	int m_score;
};
