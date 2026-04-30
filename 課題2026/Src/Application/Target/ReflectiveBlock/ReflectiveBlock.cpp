#include"ReflectiveBlock.h"

void ReflectiveBlock::Init()
{
	tex.Load("Texture/reflectiveBlock.png");
	pos = { 200,200 };
}

void ReflectiveBlock::Update()
{
	mat= Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
}

void ReflectiveBlock::Draw()
{

	Math::Color color = { 1,1,1,1 };

	SHADER.m_spriteShader.SetMatrix(mat);
	SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle(pos.x, pos.y, 64, 64), &color);

}
