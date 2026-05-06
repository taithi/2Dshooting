#include "Timer.h"
#include"../../../UI/CountDown/CountDown.h"
#include"../Balloon/Balloon.h"

void Timer::Init()
{

	tex.Load("Texture/timer2.png");
	pos = { 0,0 };
	move = { 0,0 };
	gravity = 5.0f;
	jumpPow = 2.0f;
	timeCount = 0.0f;
	objectFlg = 1;
	flg = false;
}

void Timer::Update()
{
	{
		if (flg == false && m_bulloon->GetFlg() == false && m_bulloon->GetDroped() == false && m_bulloon->GetDropItem() == item::timer)
		{

			pos = m_bulloon->GetPos();
			move = { 0,0 };
			flg = true;
			timeCount = 0;
			objectFlg = 1.0f;
			m_bulloon->SetDroped(true);
			m_countDown->SetCount(5);
			flg = true;
		}

	}

	{

		if (flg)
		{
			timeCount++;
			if (timeCount > 5 * 60)
			{
				move.y -= gravity;
				//pos.x = 0;
			}
			else
			{
				// 0.5秒待機中：30フレームごとに表示/非表示を切り替える
				// 60で割った余りが 30より小さいか（0〜29）、それ以上か（30〜59）
				if (timeCount % 60 < 30)
				{
					objectFlg = 1.0f; // 表示
				}
				else
				{
					objectFlg = 0.0f; // 非表示（透明）
				}
			}



			if (pos.y < -360)
			{
				flg = false;
			}
		}
	}

	pos += move;

	mat = Math::Matrix::CreateTranslation(pos.x, pos.y, 1);
}
void Timer::Draw()
{
	if (flg)
	{
		Math::Color color = { 1,1,1,objectFlg };
		SHADER.m_spriteShader.SetMatrix(mat);
		SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle(0, 0, 64, 91), &color);
	}

}

void Timer::Release()
{

	tex.Release();

}
