#include "Ufo.h"
#include "../../../Bullet/BulletBase/BulletBase.h"
#include <cmath>

void Ufo::Init()
{
    tex.Load("Texture/ufo.png");
    flg = true;
    radius = 40;
    pos = { 300.0f, 0.0f }; // UFOの初期位置
    move = { -2.0f, 0.0f };
}

void Ufo::Update()
{
	if (!flg) return;

	// ==========================================
	// 1. よけている最中の処理
	// ==========================================
	if (dodgeTime > 0)
	{
		dodgeTime--;
		if (dodgeTime == 0)
		{
			// よけ終わったら、通常のX軸の動き（左へ進む）に戻る！
			move = { -2.0f, 0.0f };

			// 少しの間（約1秒）はお休みして、次の弾に備える
			coolTime = 30;
		}
	}

	// ==========================================
	// 2. お休み時間（クールタイム）のカウントダウン
	// ==========================================
	if (coolTime > 0)
	{
		coolTime--;
	}

	// ==========================================
	// 3. 回避判定（よけていない ＆ お休み時間じゃない 時だけ）
	// ==========================================
	if (m_bullet != nullptr && m_bullet->GetFlg() && dodgeTime == 0 && coolTime == 0)
	{
		Math::Vector2 bulletPos = m_bullet->GetPos();

		float dx = bulletPos.x - pos.x;
		float dy = bulletPos.y - pos.y;
		float distToBullet = sqrt(dx * dx + dy * dy);

		if (distToBullet < 150.0f && distToBullet > 0.1f)
		{
			float ufoAngle = atan2f(move.y, move.x);
			float bulletAngle = atan2f(dy, dx);
			float angleDiff = bulletAngle - ufoAngle;
			while (angleDiff > 3.141592f) angleDiff -= 3.141592f * 2.0f;
			while (angleDiff < -3.141592f) angleDiff += 3.141592f * 2.0f;

			float limit = 50.0f * (3.141592f / 180.0f);

			if (fabs(angleDiff) < limit)
			{
				float dodgeSpeed = 15.0f;

				if (fabs(dx) > fabs(dy))
				{
					if (dy > 0) move = { 5.0f, -dodgeSpeed };
					else        move = { 5.0f,  dodgeSpeed };
				}
				else
				{
					if (dx > 0) move = { -dodgeSpeed, 5.0f };
					else        move = { dodgeSpeed, 5.0f };
				}

				// 【追加】15フレーム（約0.25秒）だけ、この方向にサッとよける
				dodgeTime = 15;
			}
		}
	}
	
	refTime++;
	/*if (refTime>8*60)
	{
		move.x *= -1;
		refTime = 0;
	}*/


	float margin = 50.0f;

	// 右端
	if (pos.x > 640 - margin) {
		pos.x = 640 - margin; // 【常に実行】これ以上外に出ないようにする
		if (moveCoolTime == 0) {
			move.x *= -2; move.y *= -3;
			moveCoolTime = 60; // 1秒間のクールタイムへ
		}
	}
	// 左端
	if (pos.x < -640 + margin) {
		pos.x = -640 + margin;
		if (moveCoolTime == 0) {
			move.x *= -2; move.y *= -2;
			moveCoolTime = 60;
		}
	}
	// 上端
	if (pos.y > 265 - margin) {
		pos.y = 265 - margin; 
		if (moveCoolTime == 0) {
			move.y *= -2; move.x *= 1;
			moveCoolTime = 60;
		}
	}
	// 下端
	if (pos.y < -360 + margin) {
		pos.y = -360 + margin; 
		if (moveCoolTime == 0) {
			move.y *= -2; move.x *= 3;
			moveCoolTime = 60;
		}
	}

	// 実際の移動処理
	pos.x += move.x;
	pos.y += move.y;

	// 行列の更新
	mat = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
}

void Ufo::Draw()
{
    if (flg)
    {
        Math::Color color = { 1,1,1,1 };
        SHADER.m_spriteShader.SetMatrix(mat);
        SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle(0, 0, 80, 80), &color);
    }
}

void Ufo::Release()
{
    tex.Release();
}