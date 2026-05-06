#pragma once
class Bird;
class Ufo;
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
	void SetRefFlg(bool ref) { m_refFlg = ref; }
	void SetBird(Bird* bird) { m_bird = bird; }
	void SetUfo(Ufo* ufo) { m_ufo = ufo; }
	void SetScoFlg(bool sco) { scoFlg = sco; }

	int GetScore() { return m_score; }
	bool GetRefFlg() { return m_refFlg; }
private:
	void Release();
	
	static const int maxDigits = 5;
	int digits[maxDigits] = {};
	int m_score;
	bool m_refFlg;
	bool scoFlg;

	Bird* m_bird = nullptr;
	Ufo* m_ufo = nullptr;
};
