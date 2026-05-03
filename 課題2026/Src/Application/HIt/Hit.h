#pragma once

class  RifleBullet;
class ReflectiveBlock;
class TargetBase;

class Hit
{
public:
	Hit() {};
	~Hit() {};
	void SetTarget( RifleBullet* rifleBullet){ m_rifleBullet = rifleBullet; }
	void CharaHit(RifleBullet* rifleBullet, TargetBase* targetBase);
	void BulletBlock(RifleBullet* rifleBullet, ReflectiveBlock* refBlock); //弾と反射ブロックの当たり判定と反射処理

private:
	RifleBullet* m_rifleBullet = nullptr;
	ReflectiveBlock* m_refBlock = nullptr;
	TargetBase* m_targetBase = nullptr;
};

