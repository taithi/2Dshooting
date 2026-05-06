#include"ReflectiveBlock.h"

void ReflectiveBlock::Init()
{
	tex.Load("Texture/reflectiveBlock.png");
	// x軸: -500 ～ 576
	float x = rand() % 1077 - 500;

	float y = rand() % 502 - 298;
	pos = { x,y };
	timerCount = 0;
	flg = true;
}

void ReflectiveBlock::Update()
{

	if (flg == false)
	{
	
		timerCount++;

		// 5秒経過したか判定 (60fps * 5秒 = 300フレーム)
		if (timerCount >= 3 * 60)
		{
			// x軸: -500 ～ 576
			float x = rand() % 1077 - 500;

			float y = rand() % 502 - 298;
			pos = { x,y };
			flg = true;
			timerCount = 0;
		}
	}

	mat= Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
}

void ReflectiveBlock::Draw()
{
	if(flg)
	{
		Math::Color color = { 1,1,1,1 };

		SHADER.m_spriteShader.SetMatrix(mat);
		SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle(pos.x, pos.y, 64, 64), &color);
	}

}

void ReflectiveBlock::Release()
{
	tex.Release();
}

