#include "Bell.h"
#include"../Balloon/Balloon.h"

void Bell::Init()
{

	tex.Load("Texture/bell.png");
	pos = { 0,0 };
	move = {0,0};
	gravity = 5.0f;
	jumpPow = 2.0f;
	timeCount = 0.0f;
	objectFlg = 1;
	flg = false;
	item::bell;
}

void Bell::Update()
{
	{
		if (flg == false && m_bulloon->GetFlg() == false && m_bulloon->GetDroped() == false && m_bulloon->GetDropItem() == item::bell)
		{

			pos = m_bulloon->GetPos();
			move = { 0,0 }; 
			flg = true;    
			timeCount = 0;
			objectFlg = 1.0f;

			m_bulloon->SetDroped(true);
		}
	}

	{
		if(flg)
		{
			timeCount++;
			if (timeCount > 5 * 60)
			{
				move.y -= gravity;
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

void Bell::Draw()
{
	if (flg)
	{
		Math::Color color = { 1,1,1,objectFlg };
		SHADER.m_spriteShader.SetMatrix(mat);
		SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle(0, 0, 128, 128), &color);
	}

}

void Bell::Release()
{

	tex.Release();

}
