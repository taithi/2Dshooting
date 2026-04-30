#pragma once
#include"../BulletBase/BulletBase.h"

class PlayerMove;

class RifleBullet : public BulletBase
{
public:
	RifleBullet() {};
	~RifleBullet() { Release(); };


	void Init()override;
	void Update() override;
	void Draw();
	void Release();
	void SetPlayerMove(PlayerMove* mov) { m_playerMove = mov; }

	Math::Vector2 GetPos() { return pos; }
	bool GetFlg() { return flg; }

	void SetFlg(bool m_flg) { flg = m_flg; }
	//void SetOwner(Scene* owner) { m_owner = owner; }
private:

	PlayerMove* m_playerMove = nullptr;
	
};
