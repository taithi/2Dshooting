#include "SceneManager.h"
#include "../TitleScene/TitleScene.h"
#include "../GameScene/GameScene.h"
#include "../ResultScene/ResultScene.h"

void SceneManager::Update()
{
	if (m_crrentSceneType != m_nextSceneType)
	{
		ChangeScene(m_nextSceneType);
		return;
	}


	m_currentScene->Update();
}

void SceneManager::Draw2D()
{
	 m_currentScene->Draw();
}

void SceneManager::ImGuiUpdate()
{
	m_currentScene->ImGuiUpdate();
}

void SceneManager::Init()
{
	ChangeScene(m_crrentSceneType);
	

}

void SceneManager::ChangeScene(SceneType _sceneType)
{
	switch (_sceneType)
	{
	case SceneType::Title:
		m_currentScene = std::make_shared<TitleScene>();
		break;

	case SceneType::Game:
		m_currentScene = std::make_shared<GameScene>();
		break;

	case SceneType::Result:
		m_currentScene = std::make_shared<ResultScene>();
		break;
	}

	m_crrentSceneType = _sceneType;

	m_currentScene->Init();
}