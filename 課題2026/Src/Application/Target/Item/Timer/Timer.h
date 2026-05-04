#pragma once
#include"../../TargetBase/TargetBase.h"

class Timer :public TargetBase
{
public:
	Timer() {}
	~Timer() {}
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	void Release();
};