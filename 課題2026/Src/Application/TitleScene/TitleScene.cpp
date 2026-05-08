#include "TitleScene.h"
#include"../SceneManager/SceneManager.h"

void TitleScene::Init()
{}

void TitleScene::Update()
{

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (keyFlg == false)
		{

			SceneManager::Instance().setNextScene(SceneManager::SceneType::Game);

			keyFlg = true;
		}
	}
	else
	{
		keyFlg = false;
	}

}

void TitleScene::Draw()
{

	SHADER.m_spriteShader.DrawString(0, 0, "title画面", Math::Vector4(1, 0, 0, 1));

}

void TitleScene::Release()
{}

void TitleScene::ImGuiUpdate()
{}
