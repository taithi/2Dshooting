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
	int GetRadius() { return radius; }			// 当たり判定用の半径…32
	Math::Vector2 GetFuturePos() { return pos + move; }
protected:
	Math::Vector2 pos;
	Math::Vector2 move;
	Math::Matrix mat;
	KdTexture tex;

	bool flg;
	int moveSpeed;
	int radius = 32;
};

