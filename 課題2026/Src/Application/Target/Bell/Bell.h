#pragma once
#include"../TargetBase/TargetBase.h"

class Balloon;

class Bell :public TargetBase
{
public:
	Bell() {}
	~Bell() { Release(); }

	void Init() override;
	void Update() override;
	void Draw() override;
	void SetTagetBase(Balloon* bell) { m_bulloon = bell; }

private:
	void Release();

	Balloon* m_bulloon = nullptr;

	float gravity;
	float jumpPow;
	float objectFlg;
};