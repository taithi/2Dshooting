#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	player.Draw();
	radar.Draw();
}

void Scene::Update()
{
	player.Update();
	radar.Update(player.GetPos().x,player.GetPos().y );
}

void Scene::Init()
{
	// 画像の読み込み処理
	m_playerTex.Load("Texture/player.png");
	player.SetTex(&m_playerTex);
	player.Init();
	player.set0wner(this);

	m_radarTex.Load("Texture/radar.png");
	radar.SetTex(&m_radarTex);
	radar.Init();
	radar.SetOwner(this);
}

void Scene::Release()
{
	// 画像の解放処理
	m_playerTex.Release();
	m_radarTex.Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
