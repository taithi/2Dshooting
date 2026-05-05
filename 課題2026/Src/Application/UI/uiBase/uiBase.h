#pragma once

class UiBase
{
public:
	UiBase() {}
	~UiBase() { Release(); }

	virtual void Init();
	virtual void Update();
	virtual void Draw();

protected:
	Math::Matrix mat;
	KdTexture tex;

	Math::Vector2 pos;      // 現在地
	Math::Vector2 targetPos;// 目的地点 (goolPos)
	Math::Vector2 move; // 毎フレームの移動量 (move)
	bool aliveFlg;               // 発射中フラグ

private:
	void Release();
};
