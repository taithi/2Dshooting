#pragma once
#include"../TargetBase/TargetBase.h"

class ReflectiveBlock :public TargetBase
{
public:
	ReflectiveBlock() {}
	~ReflectiveBlock() { Release(); }
	void Init()override;
	void Update()override;
	void Draw()override;
	

private:
	void Release();
	int timerCount;
};