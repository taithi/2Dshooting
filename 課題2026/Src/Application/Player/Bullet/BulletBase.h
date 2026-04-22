#pragma once

class C_Bullet
{
private:

	Math::Matrix mat;
	KdTexture tex;

	Math::Vector2 pos;
	Math::Vector2 move;
	bool flg;
	int wait = 0;

	POINT GetMousePos();

	void GetMousePos2(POINT* mousepos);
public:
	C_Bullet() {};
	~C_Bullet() {};


	void Init();
	void Update(int playerX, int playerY);
	void Draw();
	void Release();

	void SetFlg(bool m_flg) { flg = m_flg; }
}; 
