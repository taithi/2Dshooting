#include "Player.h"
#include"Bullet/Bullet.h"

void C_Player::Init()
{
	tex.Load("Texture/player.png");
	pos = { 0,0 };
	move = { 0,0 };

	m_bullet = new C_Bullet();
	m_bullet->Init();
}

void C_Player::Update()
{
	//プレイヤー移動////////////////////////////////////////////////
	if (GetAsyncKeyState('D') & 0x8000) move.x += movePow;//右移動

	if (GetAsyncKeyState('A') & 0x8000) move.x -= movePow;//左移動

	if (GetAsyncKeyState('W') & 0x8000) move.y += movePow;//上移動

	if (GetAsyncKeyState('S') & 0x8000) move.y -= movePow;//下移動
	////////////////////////////////////////////////////////////////

	m_bullet->Update(pos.x, pos.y);

	pos = move;

	mat = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
}

void C_Player::Draw()
{
	Math::Color color = { 1,1,1,1 };
	SHADER.m_spriteShader.SetMatrix(mat);
	SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle(0, 0, 64, 64), &color);

	m_bullet->Draw();
}

void C_Player::Release()
{
	tex.Release();
	m_bullet->Release();
}

C_Player::~C_Player()
{
	 Release(); 

	 if (m_bullet)
	 {
		 delete m_bullet;
	 }
}
