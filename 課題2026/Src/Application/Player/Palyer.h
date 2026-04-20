#pragma once

class Scene;
class C_Player
{
private:
	Math::Vector2 pos;
	Math::Vector2 move;
	KdTexture *tex;
	Math::Matrix mat;
	Scene* m_owner;
	static const int movePow = 5;

	int scroll;
public:
	void SetTex(KdTexture *m_tex) { tex = m_tex; }
	void Init();
	void Update();
	void Draw();
	void CommandKey();
	Math::Vector2 GetPos() { return pos; }
	void set0wner(Scene* owner) { m_owner = owner; }
};
