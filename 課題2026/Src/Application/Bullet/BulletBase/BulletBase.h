#pragma once

class Player;

class BulletBase
{
public:
	BulletBase() {};
	~BulletBase() {};


	void Init();
	virtual void Update() ;
	void Draw();

	void SetFlg(bool m_flg) { flg = m_flg; }
	void SetPlayer(Player* pla) { m_player = pla; }
	
protected:

	Math::Matrix mat;
	KdTexture tex;

	Math::Vector2 pos;      // 現在地
	Math::Vector2 targetPos;// 目的地点 (goolPos)
	Math::Vector2 velocity; // 毎フレームの移動量 (move)
	bool flg;               // 発射中フラグ

	Player* m_player;

	int wait = 0;

	

}; 
