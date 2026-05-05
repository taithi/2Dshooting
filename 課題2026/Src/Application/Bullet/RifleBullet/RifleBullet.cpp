#include"RifleBullet.h"
#include"../../Player/PlayerMove/PlayerMove.h"

void RifleBullet::Init()
{
	tex.Load("Texture/bullet.png");
}

void RifleBullet::Update()
{

	


	// 親クラスの移動計算を呼び出す
		BulletBase::Update();
		
	if (!flg)
	{
		pos= m_playerMove->GetPos();
	}

	//pos += move;

	// 確定した pos を使って行列を更新
	mat = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
}

void RifleBullet::Draw()
{
	if (flg)
	{
		Math::Color color = { 1,1,1,1 };

		SHADER.m_spriteShader.SetMatrix(mat);
		SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle(0, 0, 16, 16), &color);
	}
}

void RifleBullet::Release()
{
	tex.Release();
}