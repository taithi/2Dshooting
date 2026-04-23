#pragma once

class Scene;
class RifleBullets;

class Player
{
private:
	Math::Vector2 pos;
	Math::Vector2 move;
	KdTexture tex;
	Math::Matrix mat;
	Scene* m_owner;
	static const int movePow = 5;

	int scroll;

	void Release();
	RifleBullets* m_rifleBullets = nullptr;
public:
	Player() {};
	~Player() { Release(); };
	void Init();
	void Update();
	void Draw();
	Math::Vector2 GetPos() { return pos; }
	void set0wner(Scene* owner) { m_owner = owner; }

	//マウス座標(メンバにｘとｙを持つ型)						
	POINT mouse; //毎府フレームのマウス座標
	POINT clickPos; //クリックした瞬間のマウス座標
	POINT releasePos; //クリックした瞬間のマウス座標
	bool clickFlg; //クリック入力用フラ
	float radian;

	int ScrWidth = 1280;  // 画面の横幅
	int ScrHeight = 720;  // 画面の縦幅

	POINT GetMousePos();

	void GetMousePos2(POINT* mousepos);
};
