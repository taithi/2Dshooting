#pragma once

class Balloon;

class TargetBase
{

public:

	enum item {

		bell,
		timer,
		refBlockMini,
	};


	TargetBase() {}
	~TargetBase() {}

	virtual void Init() {}
	virtual void Update() {}
	virtual void Draw() {}
	void SetFlg(bool m_flg) { flg = m_flg; }

	void SetTagetBase(Balloon* bell) { m_bulloon = bell; }
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
	Balloon* m_bulloon = nullptr;
	float posX;
	float posY;
	float moveX;
	float moveY;
	float gravity;
	float jumpPow;
	float objectFlg;

	bool flg;
	int moveSpeed;
	int radius = 32;
	int timeCount;
};

