#pragma once

class  RifleBullet;
class ReflectiveBlock;
class Bird;


class Hit
{
public:
	Hit() {};
	~Hit() {};
	void SetTarget(Bird* bird, RifleBullet* rifleBullet){ m_bird = bird; m_rifleBullet = rifleBullet; }
	void CharaHit(RifleBullet* rifleBullet, Bird* bird);
	void BulletBlock(RifleBullet* rifleBullet, ReflectiveBlock* refBlock);

private:
	RifleBullet* m_rifleBullet = nullptr;
	Bird* m_bird = nullptr;

};

