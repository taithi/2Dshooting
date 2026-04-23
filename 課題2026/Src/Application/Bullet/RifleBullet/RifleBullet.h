#pragma once
#include"../BulletBase/BulletBase.h"

class RifleBullet : public BulletBase
{
public:
	RifleBullet() {};
	~RifleBullet() { Release(); };


	void Init();
	void Update() override;
	void Draw();
	void Release();
	Math::Vector2 GetPos() { return pos; }
	void SetFlg(bool m_flg) { flg = m_flg; }
	//void SetOwner(Scene* owner) { m_owner = owner; }
private:


};
