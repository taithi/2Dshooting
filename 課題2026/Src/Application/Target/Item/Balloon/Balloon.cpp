#include"Balloon.h"

void Balloon::Init()
{
	tex.Load("Texture/balloon.png");

	float y = rand() % 597 - 298;
	pos = { 660,y };

	move.x = -0.5;

	flg = true;

	droped = false;
	//item::balloon;
	m_dropItem = (TargetBase::item)(rand() % 2);

	//タイマー初期化
	m_respawnCount = 0;
}

void Balloon::Update()
{

	if (GetAsyncKeyState('F') & 0x8000)
	{
		flg = true;
	}

	if (flg)
	{
		if (pos.x < -660)
		{
			pos.x = 660;

			pos.y = rand() % 597 - 298;

			//再度出現するときにも、中身を再抽選する
			m_dropItem = (TargetBase::item)(rand() % 2);
			droped = false;
		}
	}
	else
	{
		// --- 風船が割れている（flg == false）時の処理 ---

		// ★15秒待機カウント（60fps × 15秒 = 900）
		m_respawnCount++;

		if (m_respawnCount >= 900)
		{
			// 15秒経過したら復活
			float y = rand() % 597 - 298;
			pos = { 660, y };   // 右端に戻す
			move.x = -0.5;      // 移動速度を戻す
			flg = true;         // 出現フラグON
			droped = false;     // ドロップ状態リセット
			m_dropItem = (TargetBase::item)(rand() % 2); // 中身再抽選

			m_respawnCount = 0; // タイマーリセット
		}
		else
		{
			pos = { 0,0 };
			move = { 0,0 };
		}

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
