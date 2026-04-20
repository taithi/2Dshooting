#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	player.Draw();
	bullet.Draw();
}

void Scene::Update()
{
	player.Update();
	bullet.Update(player.GetPos().x,player.GetPos().y );
}

void Scene::Init()
{
	// 画像の読み込み処理
	m_playerTex.Load("Texture/player.png");
	player.SetTex(&m_playerTex);
	player.Init();
	player.set0wner(this);

	m_bulletTex.Load("Texture/bullet.png");
	bullet.SetTex(&m_bulletTex);
	bullet.Init();
	bullet.SetOwner(this);
}

void Scene::Release()
{
	// 画像の解放処理
	m_playerTex.Release();
	m_bulletTex.Release();
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

		ImGui::Text("player: x%f y%f", player.GetPos().x, player.GetPos().y);
		ImGui::Text("bullet: x%f y%f", bullet.GetPos().x, bullet.GetPos().y);
	}
	ImGui::End();
}
