#include "ResultScene.h"
#include"../SceneManager/SceneManager.h"

void ResultScene::Init()
{}

void ResultScene::Update()
{

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (keyFlg == false)
		{

			SceneManager::Instance().setNextScene(SceneManager::SceneType::Title);

			keyFlg = true;
		}
	}
	else
	{
		keyFlg = false;
	}

}

void ResultScene::Draw()
{

	SHADER.m_spriteShader.DrawString(0, 0, "リザルト画面", Math::Vector4(1, 0, 0, 1));

}

void ResultScene::Release()
{

	

}

void ResultScene::ImGuiUpdate()
{}
