#pragma once
#include"../../TargetBase/TargetBase.h"

class Bell :public TargetBase
{
public:
	Bell() {}
	~Bell() { Release(); }

	void Init() override;
	void Update() override;
	void Draw() override;
	
private:
	void Release();
	//風船の中に隠されているアイテム
	item m_dropItem;
};