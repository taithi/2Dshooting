#pragma once

class  RifleBullet;
class ReflectiveBlock;
class TargetBase;
class Score;

class Hit
{
public:
	Hit() {};
	~Hit() {};
	void SetTarget( RifleBullet* rifleBullet){ m_rifleBullet = rifleBullet; }
	void CharaHit(RifleBullet* rifleBullet, TargetBase* targetBase);
	void BulletBlock(RifleBullet* rifleBullet, ReflectiveBlock* refBlock); //弾と反射ブロックの当たり判定と反射処理
	void SetScore(Score* score) { m_score = score; }

private:
	RifleBullet* m_rifleBullet = nullptr;
	ReflectiveBlock* m_refBlock = nullptr;
	TargetBase* m_targetBase = nullptr;
	Score* m_score = nullptr;
};

