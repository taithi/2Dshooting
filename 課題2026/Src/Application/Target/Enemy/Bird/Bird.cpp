#include "Bird.h"

void Bird::Init()
{

	tex.Load("Texture/birdDummy2.png");
	// x軸: -500 ～ 576
	float x = rand() % 1077 - 500;

	// y軸: -298 ～ 298
	float y = rand() % 597 - 298;
	
	pos = { x,y };
	move = { 0,0};
	flg = true;
	radius = 16;
	timerCount = 0;
	
}

void Bird::Update()
{

	/*pos.x -= 3.0f;

	if (pos.x < -640)
	{
		pos.x = 640;
	}*/

	if (flg == false)
	{
		//pos = { -9999.0f, -9999.0f };
		// 毎フレームカウントを増やす
		timerCount++;

		// 5秒経過したか判定 (60fps * 3秒 = 300フレーム)
		if (timerCount >= 3 * 60)
		{
			// x軸: -500 ～ 576
			float x = rand() % 1077 - 500;

			// y軸: -298 ～ 298
			float y = rand() % 597 - 298;

			pos = { x,y };
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
void Bird::Release()
{
	tex.Release();

}

