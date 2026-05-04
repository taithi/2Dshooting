#pragma once
#include"../../TargetBase/TargetBase.h"

class  RefBlockMini :public TargetBase
{
public:
	RefBlockMini() {}
	~RefBlockMini() { Release(); }

	void Init() override;
	void Update() override;
	void Draw()  override;

private:
	void Release();
};