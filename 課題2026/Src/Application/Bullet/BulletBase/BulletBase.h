#pragma once

class Player;

class BulletBase
{
public:
	BulletBase() {};
	~BulletBase() { Release(); };


	virtual void Init();
	virtual void Update() ;
	virtual void Draw();

	void SetFlg(bool m_flg) { flg = m_flg; }
	void SetPlayer(Player* pla) { m_player = pla; }
	Math::Vector2 GetPos() { return pos; }
	Math::Vector2 GetMove() { return move; }
	int GetRadius() { return radius; }					// 当たり判定用の半径…8
	Math::Vector2 GetFuturePos() { return pos + move; }
	void SetMove(Math::Vector2 m_move) { move = m_move; }
	void SetPos(Math::Vector2 m_pos) { pos = m_pos; }
protected:

	void Release();

	Math::Matrix mat;
	KdTexture tex;

	Math::Vector2 pos;      // 現在地
	Math::Vector2 targetPos;// 目的地点 (goolPos)
	Math::Vector2 move; // 毎フレームの移動量 (move)
	bool flg;               // 発射中フラグ

	Player* m_player;
	int radius = 8;			
	int wait = 0;

	

}; 
