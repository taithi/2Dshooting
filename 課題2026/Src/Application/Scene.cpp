#include "main.h"
#include "Scene.h"
#include "Player/Player.h"
#include"Bullet/RifleBullet/RifleBullet.h"
#include"Hit/Hit.h"
#include"Target/Enemy/Bird/Bird.h"
#include"Target/ReflectiveBlock/ReflectiveBlock.h"
#include"Bullet/ForecastLine/ForecastLine.h"
void Scene::Draw2D()
{
	m_rifleBullet->Draw();
	m_bird->Draw();
	m_player->Draw();
	m_refBlock->Draw();
	m_forecastLine->Draw();
}

void Scene::Update()
{
	
	m_rifleBullet->Update();
	m_bird->Update();
	m_player->Update();
	m_hit->CharaHit(m_rifleBullet, m_bird);
	m_hit->BulletBlock(m_rifleBullet, m_refBlock);
	m_refBlock->Update();
	m_forecastLine->Update();
}

void Scene::Init()
{
	// 画像の読み込み処理
	
	m_player = new Player();
	m_player->Init();

	m_rifleBullet = new RifleBullet();
	m_rifleBullet->Init();
	m_rifleBullet->SetPlayer(m_player);

	m_bird = new Bird();
	m_bird->Init();

	m_hit = new Hit();

	m_refBlock = new ReflectiveBlock();
	m_refBlock->Init();

	m_forecastLine = new ForecastLine();
	m_forecastLine->Init();
	m_forecastLine->SetPlayer(m_player);
	//m_hit->SetTarget(m_bird, m_rifleBullet);

	//player.set0wner(this);
	//bullet.SetOwner(this);
}

void Scene::Release()
{
	// 画像の解放処理
	if(m_player)		delete m_player;

	if (m_rifleBullet)	delete m_rifleBullet;

	if(m_bird)			delete m_bird;

	if (m_hit)			delete m_hit;

	if (m_refBlock)		delete m_refBlock;

	if (m_forecastLine) delete m_forecastLine;
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
		ImGui::Text("bulletFlg: %d", m_rifleBullet->GetFlg());

		ImGui::Text("bird: x%f y%f", m_bird->GetPos().x, m_bird->GetPos().y);
		ImGui::Text("birdFlg: %d", m_bird->GetFlg());

		ImGui::Text("RefBlock: x%f y%f", m_refBlock->GetPos().x, m_refBlock->GetPos().y);
	}
	ImGui::End();
}
