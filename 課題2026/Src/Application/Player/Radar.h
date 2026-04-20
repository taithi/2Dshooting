#pragma once

class Scene;

class C_Radar
{
private:

	Scene* m_owner;

	Math::Matrix mat;
	KdTexture* tex;

	const static int radarNum = 5;
	Math::Vector2 pos[radarNum];
	Math::Vector2 move[radarNum];
	Math::Vector2 size[radarNum];
	bool flg[radarNum];
	int wait = 0;
public:

	void Init();
	void Update(int playerX,int playerY);
	void Draw();
	void SetTex(KdTexture* m_tex) { tex = m_tex; }
	void SetFlg(bool m_flg,int num) { flg[num] = m_flg; }
	void SetOwner(Scene* owner){m_owner = owner;}
};
