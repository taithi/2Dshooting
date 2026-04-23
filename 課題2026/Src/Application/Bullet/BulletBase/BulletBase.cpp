#include "BulletBase.h"
#include"../../Player/Player.h"

void BulletBase::Init()
{

	flg = false;
	pos = { -610,-50 };
}

void BulletBase::Update()
{
    // クリック判定
    if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !flg)
    {
        // プレイヤーが持っているクリックした地点をゴールにする
        targetPos = m_player->GetPos();

        // 移動方向の計算
        //現在地から目的地までの「差分（距離）」を表す線（ベクトル）
        float x = targetPos.x - pos.x;
        float y = targetPos.y - pos.y;
        float z = sqrt(x * x + y * y);

        // 距離が0（クリックした場所がプレイヤーと重なっている）時の除算回避
        if (z > 0.01f) {
            /*「差分」を「全距離」で割ることで「その方向を向いた長さ1のベクトル」を作る
           これが向きの情報そのもの*/
            //最後に10.0fをすることで、方向はそのままに、速さを10にする
            velocity.x = (x / z) * 10.0f; 
            velocity.y = (y / z) * 10.0f; 
        }

        flg = true;
    }

    // 移動処理
    if (flg)
    {
        pos.x += velocity.x;
        pos.y += velocity.y;

        /*弾を飛ばすには、「目的地までのベクトル（方向と距離）」から「方向だけ」
          を取り出し、そこに「速さ」を掛ける必要があ*/

        //到達判定：目的地と現在の距離が移動量より小さくなったら終了
        //現在地から目的地までの「差分（距離）」を表す線（ベクトル）
        float dx = targetPos.x - pos.x; 
        float dy = targetPos.y - pos.y;

        //弾が目的地を通り過ぎて無限に飛んでいかないように、目的地に到達したかをチェック
        /*目的地と現在地との距離を毎回計算し、
        その距離が「1フレームで進む距離（速さ）」よりも小さくなったかを見てい*/
        if (sqrt(dx * dx + dy * dy) < 10.0f)
        {
            flg = false;
            pos = { -610,-50 };
        }

        /*弾の速さを 10.0f に設定しているからif文の最後に10.0f画は言っている
        もし距離が 10.0 より大きいなら、次のフレームで少なくともあと1回は移動
        逆に 10.0 より小さければ、次のフレームで移動すると目的地を通り過ぎている
        「通り過ぎるくらい近くなったなら、もう着いたことにしよう」という判断*/
        //この計算の 10.0f という数値は、「速度」と「判定範囲」の両方を制御していいる

    }
}
void BulletBase::Draw()
{


}

