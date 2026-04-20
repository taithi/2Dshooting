#include"Bullet.h"

void C_Bullet::Init()
{
		pos = { 0,0 };
		move = {0,0};
		flg = false;
	
}

void C_Bullet::Update(int playerX, int playerY)
{
	

	if (GetAsyncKeyState('J') & 0x8000)
	{
		if (flg == false)
		{
			flg = true;

			move.x = playerX;
			move.y = playerY;
		}
		
	}
	
	if (flg == true)
	{
		move.y += 10;

		if (pos.y > 360 + 8)
		{
			flg = false;
		}
	}

			
	pos = move;
	Math::Matrix trans = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
	//Math::Matrix scale = Math::Matrix::CreateScale(size.x, size.y, 0);
	mat =  trans;
}

void C_Bullet::Draw()
{
	if(flg)
	{
			Math::Color color = { 1,1,1,1 };

			SHADER.m_spriteShader.SetMatrix(mat);
			SHADER.m_spriteShader.DrawTex(tex, Math::Rectangle(0, 0, 16, 16), &color);
	}
}