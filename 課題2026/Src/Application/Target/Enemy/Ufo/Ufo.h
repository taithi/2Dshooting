#pragma once

#include"../../TargetBase/TargetBase.h"

class BulletBase;

class Ufo : public TargetBase
{
public:
	Ufo() {}
	~Ufo(){ Release(); }
	void Init()override;
	void Update()override;
	void Draw()override;

	void SetBullet(BulletBase* bullet) { m_bullet = bullet; }
private:
	void Release();

	BulletBase* m_bullet = nullptr;
	
	int dodgeTime = 0; // よけている時間
	int coolTime = 0;  // 連続でよけないための休憩時間
	int refTime = 0;

	int moveCoolTime = 0;
};
