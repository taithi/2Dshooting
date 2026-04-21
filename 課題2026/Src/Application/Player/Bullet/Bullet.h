#pragma once

class Scene;

class C_Bullet
{
private:

	Scene* m_owner;

	Math::Matrix mat;
	KdTexture tex;

	Math::Vector2 pos;
	Math::Vector2 move;
	bool flg;
	int wait = 0;
public:
	C_Bullet() {};
	~C_Bullet() {};


	void Init();
	void Update(int playerX, int playerY);
	void Draw();
	void Release();

	void SetFlg(bool m_flg) { flg = m_flg; }
	void SetOwner(Scene* owner) { m_owner = owner; }

	Math::Vector2 GetPos() { return pos; }
};
