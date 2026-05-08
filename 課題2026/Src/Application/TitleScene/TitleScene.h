#pragma once
#include"../SceneBase/SceneBase.h"

class TitleScene :public SceneBase
{
public:


	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void ImGuiUpdate() override;

private:
};