#pragma once
#include <memory>

class SceneBase;

class SceneManager
{
public:
	enum SceneType
	{
		Title,
		Game,
		Result // リザルトシーンを追加
	};

	void Update();
	void Draw2D();
	void ImGuiUpdate(); // 追加
	void Init();
	void setNextScene(SceneType _nextScene)
	{
		m_nextSceneType = _nextScene;
	}

	SceneType GetCurrentSceneType() const
	{
		return m_crrentSceneType;
	}

private:
	
	void Release() {} // shared_ptrが自動解放するので空でOK
	void ChangeScene(SceneType _sceneType);

	std::shared_ptr<SceneBase> m_currentScene; // 現在のシーン
	SceneType m_crrentSceneType = SceneType::Title;
	SceneType m_nextSceneType = m_crrentSceneType;

	SceneManager() { Init(); }
	~SceneManager() { Release(); }

public:
	static SceneManager& Instance()
	{
		static SceneManager instance;
		return instance;
	}
};

// 呼び出しやすいようにマクロ化（任意）
#define SCENE_MANAGER SceneManager::Instance()