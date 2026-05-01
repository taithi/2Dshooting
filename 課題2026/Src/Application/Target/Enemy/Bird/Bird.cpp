#include "Bird.h"

void Bird::Init()
{

	tex.Load("Texture/birdDummy2.png");
	float y = rand() % 601 - 300;
	
	pos = { 100,y };
	move = { 0,0};
	flg = true;
	timerCount = 0;
	
}

void Bird::Update()
{

	if (flg == false)
	{
		// 毎フレームカウントを増やす
		timerCount++;

		// 5秒経過したか判定 (60fps * 5秒 = 300フレーム)
		if (timerCount >= 3 * 60)
		{

			float y = rand() % 601 - 300;

			pos = { 100,y };
			flg = true;
			timerCount = 0; // タイマーをリセット

		}
	}

	pos += move;

	mat = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
}

void Bird::Draw()
{
	if (flg)
	{

		Math::Color color = { 1,1,1,1 };
		SHADER.m_spriteShader.SetMatrix(mat);
		SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle(0, 0, 32, 32), &color);
	}


}	
