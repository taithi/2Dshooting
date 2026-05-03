#include"Balloon.h"

void Balloon::Init()
{
	tex.Load("Texture/Balloon.png");

	float y = rand() % 597 - 298;
	pos = { 660,y };

	move.x = -0.5;

	flg = true;
}

void Balloon::Update()
{
	if (flg)
	{
		if (pos.x < -660)
		{
			pos.x = 660;

			pos.y= rand() % 597 - 298;
		}
	}
	else
	{
		pos = { 0,0 };
	}
	

	pos += move;

	mat = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
}
void Balloon::Draw()
{

	if(flg)
	{
	
		Math::Color color = { 1,1,1,1 };
		SHADER.m_spriteShader.SetMatrix(mat);
		SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle(0, 0, 64, 64), &color);
	
	}

}

void Balloon::Release()
{

	tex.Release();

}
