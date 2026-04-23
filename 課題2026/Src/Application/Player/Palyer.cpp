#include "../main.h"
#include "Player.h"

void Player::Init()
{
	tex.Load("Texture/player.png");
	pos = { 0,0 };
	move = { 0,0 };

}

void Player::Update()
{
	
	GetMousePos2(&mouse);
	pos.x = mouse.x;
	pos.y = mouse.y;
	mat = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
}

void Player::Draw()
{
	Math::Color color = { 1,1,1,1 };
	SHADER.m_spriteShader.SetMatrix(mat);
	SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle(0, 0, 64, 64), &color);
}


void Player::Release()
{
	tex.Release();
}

POINT Player::GetMousePos()
{
	POINT mousepos; //戻り値

	//マウスの座標取得
	GetCursorPos(&mouse);

	return mousepos;
}

void Player::GetMousePos2(POINT* mousepos)
{
	GetCursorPos(mousepos);
	ScreenToClient(APP.m_window.GetWndHandle(), mousepos);

	mousepos->x -= ScrWidth / 2;
	mousepos->y -= ScrHeight / 2;
	mousepos->y *= -1;
}

