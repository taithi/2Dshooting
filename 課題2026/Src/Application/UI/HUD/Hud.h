#pragma once
#include"../uiBase/uiBase.h"

class Hud: public UiBase
{
public:
	Hud() {}
	~Hud() { Release(); }

	void Init();
	void Update();
	void Draw();

private:
	void Release();

};