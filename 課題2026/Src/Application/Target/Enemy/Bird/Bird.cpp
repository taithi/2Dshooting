#include "Bird.h"

void Bird::Init()
{
	pos = { 0,100 };
	flg = true;
	timerCount = 0;

	tex.Load("Texture/birdDummy.png");
}

void Bird::Update()
{
	pos = { 0,100 };

	/*if (flg == false)
	{
		int time = 5*60;

		do
		{
			time--;
		} while (time == 0);

		if (time <= 0)
		{
			flg = true;
			time = 5*60;
		}
	}*/

	if (flg == false)
	{
		// 毎フレームカウントを増やす
		timerCount++;

		// 5秒経過したか判定 (60fps * 5秒 = 300フレーム)
		if (timerCount >= 5 * 60)
		{
			flg = true;
			timerCount = 0; // タイマーをリセット
		}
	}

	mat = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
}

void Bird::Draw()
{
	if (flg)
	{

		Math::Color color = { 1,1,1,1 };
		SHADER.m_spriteShader.SetMatrix(mat);
		SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle(0, 0, 64, 64), &color);
	}


}	
