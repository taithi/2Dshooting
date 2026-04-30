#pragma once

class PlayerMove
{
public:
	PlayerMove() {}
	~PlayerMove() { Release(); }
	void Init();
	void Update();
	void Draw();
	Math::Vector2 GetPos() { return pos; }
private:
	void Release();

	Math::Matrix	mat;
	KdTexture		tex;

	Math::Vector2	pos;
	Math::Vector2	move;
	int movePow=5;
};