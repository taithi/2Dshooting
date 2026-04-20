#include"Radar.h"

void C_Radar::Init()
{
	for (int i = 0; i < radarNum; i++)
	{
		move[i] = {0,0};
		flg[i] = false;
	}
	
}

void C_Radar::Update(int playerX, int playerY)
{
	if(wait ==0)
	{

		for (int i = 0; i < radarNum; i++)
		{

			if (flg[i])
			{

				pos[i].x = playerX;
				pos[i].y = playerY;

				size[i].x += 2;
				size[i].y += 2;
				break;
				
			}

			if (size[i].x == 1 && size[i].y == 1)
			{
				flg[i] = false;
				pos[i].x = 0;
				pos[i].y = 0;

				wait = 10;

			}
		}
	}



	wait--;
	if (wait < 0)
	{
		wait = 0;
	}

		for (int i = 0; i < radarNum; i++)
		{
			Math::Matrix trans = Math::Matrix::CreateTranslation(pos[i].x, pos[i].y, 0);
			Math::Matrix scale = Math::Matrix::CreateScale(size[i].x, size[i].y, 0);
			mat = scale * trans;
		}
}

void C_Radar::Draw()
{
	if(flg)
	{
		for (int i = 0; i < radarNum; i++)
		{
			Math::Color color = { 1,1,1,1 };

			SHADER.m_spriteShader.SetMatrix(mat);
			SHADER.m_spriteShader.DrawTex(tex, Math::Rectangle(0, 0, 64, 64), &color);
		}
	}
}