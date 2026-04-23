#include "main.h"
#include "Scene.h"
#include "Player/Player.h"
#include"Bullet/RifleBullet/RifleBullet.h"

void Scene::Draw2D()
{
	m_player->Draw();
	m_rifleBullet->Draw();
}

void Scene::Update()
{
	m_player->Update();
	m_rifleBullet->Update();
}

void Scene::Init()
{
	// 画像の読み込み処理
	
	m_player = new Player();
	m_player->Init();

	m_rifleBullet = new RifleBullet();
	m_rifleBullet->Init();
	m_rifleBullet->SetPlayer(m_player);

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

	if (m_rifleBullet)
	{
		delete m_rifleBullet;
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
		ImGui::Text("bullet: x%f y%f", m_rifleBullet->GetPos().x, m_rifleBullet->GetPos().y);
	}
	ImGui::End();
}
