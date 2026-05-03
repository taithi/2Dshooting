#pragma once

class TargetBase
{

public:
	TargetBase() {}
	~TargetBase() {}

	virtual void Init() {}
	virtual void Update() {}
	virtual void Draw() {}
	void SetFlg(bool m_flg) { flg = m_flg; }

	Math::Vector2 GetPos() { return pos; }
	void SetPos(Math::Vector2 s_pos) { pos = s_pos; }
	int GetRadius() { return radius; }			// 当たり判定用の半径…32
	Math::Vector2 GetFuturePos() { return pos + move; }
	//Math::Vector2 GetBirdPos() { return pos; }
	bool GetFlg() { return flg; }
protected:
	Math::Matrix mat;
	KdTexture tex;

	Math::Vector2 pos;
	Math::Vector2 move;
	float posX;
	float posY;
	float moveX;
	float moveY;

	bool flg;
	int moveSpeed;
	int radius = 32;
};

