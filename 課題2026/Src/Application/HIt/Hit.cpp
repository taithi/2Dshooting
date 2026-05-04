#include "Hit.h"
#include"../Bullet/RifleBullet/RifleBullet.h"
#include"../Target/ReflectiveBlock/ReflectiveBlock.h"
#include"../Target/TargetBase/TargetBase.h"

void Hit::CharaHit(RifleBullet* rifleBullet, TargetBase* targetBase)
{
	m_rifleBullet = rifleBullet;
	m_targetBase = targetBase;

	const float x = m_targetBase->GetPos().x - m_rifleBullet->GetPos().x;
	const float y = m_targetBase->GetPos().y - m_rifleBullet->GetPos().y;	
	const float z = sqrtf(x * x + y * y);


	if (z < m_targetBase->GetRadius() + m_rifleBullet->GetRadius())
	{

		if (m_targetBase->GetFlg() && m_rifleBullet->GetFlg())
		{

			Math::Vector2 pos= rifleBullet->GetPos();
			//当たったときの処理
			m_rifleBullet->SetFlg(false);
			m_rifleBullet->SetPos(pos);
			m_targetBase->SetFlg(false);
			
		}
	}
}

//弾と反射ブロックの当たり判定と反射処理
void Hit::BulletBlock(RifleBullet* rifleBullet, ReflectiveBlock* refBlock)
{
	const float bulletRight = rifleBullet->GetPos().x + rifleBullet->GetRadius();
	const float bulletLeft = rifleBullet->GetPos().x - rifleBullet->GetRadius();
	const float bulletTop = rifleBullet->GetPos().y + rifleBullet->GetRadius();
	const float bulletBottom = rifleBullet->GetPos().y - rifleBullet->GetRadius();

	const float nextRight = rifleBullet->GetFuturePos().x + rifleBullet->GetRadius();
	const float nextLeft = rifleBullet->GetFuturePos().x - rifleBullet->GetRadius();
	const float nextTop = rifleBullet->GetFuturePos().y + rifleBullet->GetRadius();
	const float nextBottom = rifleBullet->GetFuturePos().y - rifleBullet->GetRadius();

	const float blockRight = refBlock->GetPos().x + refBlock->GetRadius();
	const float blockLeft = refBlock->GetPos().x - refBlock->GetRadius();
	const float blockTop = refBlock->GetPos().y + refBlock->GetRadius();
	const float blockBottom = refBlock->GetPos().y - refBlock->GetRadius();


	// 1. 衝突判定
	if (nextRight > blockLeft && nextLeft < blockRight &&
		nextTop > blockBottom && nextBottom < blockTop)
	{
		Math::Vector2 velocity = rifleBullet->GetMove();

		// 2. 衝突した面を判定して反射させる
		// 前のフレームでの位置を使って「どの面から侵入したか」を判定する

		// 左右の衝突チェック (前のフレームでは横の範囲外だったか)
		if ((bulletRight <= blockLeft && nextRight >= blockLeft) ||
			(bulletLeft >= blockRight && nextLeft <= blockRight))
		{
			velocity.x *= -2.0f; // 横反射
			refBlock->SetFlg(false);
		}

		// 上下の衝突チェック (前のフレームでは縦の範囲外だったか)
		if ((bulletTop <= blockBottom && nextTop >= blockBottom) ||
			(bulletBottom >= blockTop && nextBottom <= blockTop))
		{
			velocity.y *= -2.0f; // 縦反射
			refBlock->SetFlg(false);
		}

		// 速度を更新
		rifleBullet->SetMove(velocity);

	}
}

