#pragma once

#include"../TargetBase/TargetBase.h"

class Balloon : public TargetBase
{
public:
	Balloon() {}
	~Balloon() { Release(); }

	void Init() override;
	void Update() override;
	void Draw() override;

private:
	void Release();

};
