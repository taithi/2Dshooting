#include "main.h"
#include "Scene.h"
#include "Player/Player.h"

void Scene::Draw2D()
{
	m_player->Draw();
}

void Scene::Update()
{
	m_player->Update();
}

void Scene::Init()
{
	// 画像の読み込み処理
	
	m_player = new C_Player();
	m_player->Init();
	//player.set0wner(this);

	
	//bullet.SetOwner(this);
}

void Scene::Release()
{
	// 画像の解放処理
	if(m_player)
	{
		delete m_player;
	}
}

void Scene::ImGuiUpdate()
{
	//return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);

		ImGui::Text("player: x%f y%f", m_player->GetPos().x, m_player->GetPos().y);
		//ImGui::Text("bullet: x%f y%f", bullet.GetPos().x, bullet.GetPos().y);
	}
	ImGui::End();
}
