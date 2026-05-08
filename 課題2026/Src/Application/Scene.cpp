#include "main.h"
#include "Scene.h"
#include"GameScene/GameScene.h"
#include"SceneManager/SceneManager.h"


void Scene::Draw2D()
{
	SceneManager::Instance().Draw2D();
}

void Scene::Update()
{

	SceneManager::Instance().Update();

}

void Scene::Init()
{
	SceneManager::Instance().Init();
}

void Scene::Release()
{
	
}

void Scene::ImGuiUpdate()
{
	SceneManager::Instance().ImGuiUpdate();
}
