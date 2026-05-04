#pragma once

#include"../../TargetBase/TargetBase.h"

class Balloon : public TargetBase
{
public:
	Balloon() {}
	~Balloon() { Release(); }

	void Init() override;
	void Update() override;
	void Draw() override;

	// 追加：選ばれたアイテムを取得する関数
	TargetBase::item GetDropItem() { return m_dropItem; }

	bool GetDroped() { return droped; }
	// ★追加：アイテムをドロップしたことを設定する関数
	void SetDroped(bool b) { droped = b; }

private:
	void Release();

	//風船の中に隠されているアイテム
	TargetBase::item m_dropItem;

	bool droped;

	int m_respawnCount;
};
