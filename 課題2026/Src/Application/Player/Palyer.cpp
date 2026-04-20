#include "Palyer.h"
#include "../Scene.h"

void C_Player::Init()
{
	pos = { 0,0 };
	move = { 0,0 };
}

void C_Player::Update()
{
	//プレイヤー移動////////////////////////////////////////////////
	if (GetAsyncKeyState('D') & 0x8000) move.x += movePow;//右移動

	if (GetAsyncKeyState('A') & 0x8000) move.x -= movePow;//左移動

	if (GetAsyncKeyState('W') & 0x8000) move.y += movePow;//上移動

	if (GetAsyncKeyState('S') & 0x8000) move.y -= movePow;//下移動
	////////////////////////////////////////////////////////////////

	pos = move;

	mat = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
}

void C_Player::Draw()
{
	Math::Color color = { 1,1,1,1 };
	SHADER.m_spriteShader.SetMatrix(mat);
	SHADER.m_spriteShader.DrawTex(tex, Math::Rectangle(0, 0, 64, 64), &color);
}

