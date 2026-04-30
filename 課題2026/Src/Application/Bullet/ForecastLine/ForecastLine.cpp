#include "ForecastLine.h"
#include"../../Player/Player.h"
#include"../../Player/PlayerMove/PlayerMove.h"
void ForecastLine::Init()
{
	tex.Load("Texture/forecastLine.png");

}

void ForecastLine::Update()
{

	//スタート地点
	Math::Vector2 startPos = m_playerMove->GetPos();

	// マウスの現在地（ターゲット）
	Math::Vector2 mousePos = { (float)m_player->mouse.x, (float)m_player->mouse.y };

	// スタートからターゲットまでの「差分」を計算
	float diffX = mousePos.x - startPos.x;
	float diffY = mousePos.y - startPos.y;

	// 全体の距離を lineNum (40) で割って、1ステップあたりの移動量を出す
	// これにより、常に40個目のドットがマウスの位置に重なる
	float stepX = diffX / (float)lineNum;
	float stepY = diffY / (float)lineNum;

	// 予測線の位置を計算
	for (int i = 0; i < lineNum; i++)
	{
		// 各ドットを step 分ずつずらして配置
		savePos[i].x = startPos.x + (stepX * i);
		savePos[i].y = startPos.y + (stepY * i);
	}
}

void ForecastLine::Draw()
{
    Math::Color color = { 1, 1, 1, 1 };

    for (int i = 0; i < lineNum; i++)
    {
        mat = Math::Matrix::CreateTranslation(savePos[i].x, savePos[i].y, 0);
        SHADER.m_spriteShader.SetMatrix(mat);

        // 予測線の画像サイズが大きい場合は Rectangle のサイズを小さくする
        SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle(0, 0, 16, 16), &color);
    }
}

void ForecastLine::Release()
{
	tex.Release();
}
