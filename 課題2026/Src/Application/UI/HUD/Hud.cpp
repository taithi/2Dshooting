#include "Hud.h"

void Hud::Init()
{
	tex.Load("Texture/gameUi4.png");
	pos = { 0,309 };
	aliveFlg = true;
}

void Hud::Update()
{
	{
		if (!aliveFlg) return;

		mat = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
	}

}

void Hud::Draw()
{
	{
		if (!aliveFlg) return;

		Math::Color color = { 1,1,1,1 };

		SHADER.m_spriteShader.SetMatrix(mat);
		SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle(0, 0, 1277, 100), &color);
	}

}

void Hud::Release()
{

	tex.Release();

}
