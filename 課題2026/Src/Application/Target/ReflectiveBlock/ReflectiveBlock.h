#pragma once
#include"../TargetBase/TargetBase.h"

class ReflectiveBlock :public TargetBase
{
public:
	ReflectiveBlock() {}
	~ReflectiveBlock() {}
	void Init()override;
	void Update()override;
	void Draw()override;
private:
};