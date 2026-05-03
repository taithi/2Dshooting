#include "PlayerMove.h"

void PlayerMove::Init()
{
	tex.Load("Texture/Cannon.png");
    pos = { 0,0};
	move = { -610,-50 };
}

void PlayerMove::Update()
{
	
	if (GetAsyncKeyState('W') & 0x8000)	move.y += movePow;
	if (GetAsyncKeyState('S') & 0x8000)	move.y -= movePow;

	pos = move;

	if (pos.y > 360 - 32 )
	{
		pos.y = 360 - 32;
	}

	if (pos.y < -360 + 32)
	{
		pos.y = -360 + 32;
	}

	
	mat = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
}

void PlayerMove::Draw()
{

	Math::Color color = { 1,1,1,1 };
	SHADER.m_spriteShader.SetMatrix(mat);
	SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle(0, 0, 64, 64), &color);

}

void PlayerMove::Release()
{
	tex.Release();
}
