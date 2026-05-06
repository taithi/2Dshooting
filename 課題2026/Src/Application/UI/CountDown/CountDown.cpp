#include "CountDown.h"

void CountDown::Init()
{
	tex.Load("Texture/number.png");
	m_countDown = 60;


}

void CountDown::Update()
{

	if(m_countDown>0)
	{

		m_timer += 1.0f / 60.0f;// 60FPSの場合、1フレームで約0.016秒加算
		if (m_timer >= 1.0f)// 1秒たったら
		{
			m_countDown--;// カウントを減らす
			m_timer = 0;  // タイマーリセット
		}

		
	}

	if (m_countDown < 0) m_countDown = 0;

	int tmp = m_countDown;

	for (int i = maxDigits - 1; i >= 0; --i)
	{
		digits[i] = tmp % 10;
		tmp /= 10;
	}

	mat = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);

}

void CountDown::Draw()
{

	// 1. 行列をシェーダーにセット（位置・回転・拡大縮小）
	// mat は Score::Update で作成された行列
	SHADER.m_spriteShader.SetMatrix(mat);

	// 2. 描画開始（すでに別の場所で Begin されている場合は不要ですが、安全のため）
	// ただし KdSpriteShader 内で自動で判定しているので個別呼び出しは必須ではない

	for (int i = 0; i < maxDigits; ++i)
	{
		// 数字1つの矩形（スプライトシート上の位置）
		// 例: 横59px、縦95pxの数字が並んでいる場合
		Math::Rectangle srcRect = { (long)(59 * digits[i]), 0, 59, 95 };

		// 表示位置の計算
		// 行列(mat)が適用されるため、ここでは (0, 0) からの相対座標を指定する
		float startX = -((maxDigits * 59.0f) / 2.0f); // 全体の中央揃えのためのオフセット
		float drawX = startX + (i * 59.0f);

		// 第2,3引数が座標、第4,5引数がサイズ
		SHADER.m_spriteShader.DrawTex(
			&tex,
			(int)drawX + 150, 310, 59, 95,
			&srcRect,
			&Math::Color(1, 1, 1, 1)
		);
	}

}

void CountDown::Release()
{
	tex.Release();

}
