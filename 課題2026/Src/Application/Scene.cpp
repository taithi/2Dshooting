#include "main.h"
#include "Scene.h"
#include "Player/Player.h"
#include"Bullet/RifleBullet/RifleBullet.h"
#include"Hit/Hit.h"
#include"Target/Enemy/Bird/Bird.h"
#include"Target/ReflectiveBlock/ReflectiveBlock.h"
#include"Bullet/ForecastLine/ForecastLine.h"
#include"Player/PlayerMove/PlayerMove.h"
#include"Target/Item/Balloon/Balloon.h"
#include"Target/Item/Bell/Bell.h"
#include"Target/TargetBase/TargetBase.h"
#include"Target/Item/Timer/Timer.h"
#include"Target/Item/ReflectiveBlockMini/ReflectiveBlockMini.h"
#include"Target/Enemy/Ufo/Ufo.h"
#include"UI/uiBase/uiBase.h"
#include"UI/HUD/Hud.h"

void Scene::Draw2D()
{
	
	for (int i = 0; i < BIRD_NUM; i++)
	{
			m_bird[i]->Draw();
	}
	
	for (int i = 0; i< REF_Num; i++)
	{
		m_refBlock[i]->Draw();
	}
	m_forecastLine->Draw();
	m_playerMove->Draw();

	m_balloon->Draw();

	m_timer->Draw();

	m_refBlockMini->Draw();

	m_bell->Draw();

	m_ufo->Draw();

	m_hud->Draw();
	//m_uiBase->Draw();

	m_rifleBullet->Draw();

	m_player->Draw();
}

void Scene::Update()
{

	m_rifleBullet->Update();
	for (int i = 0; i < BIRD_NUM; i++)
	{
			m_bird[i]->Update();
			m_hit->CharaHit(m_rifleBullet, m_bird[i]);
	}
		for (int i = 0; i < REF_Num; i++)
		{
			m_hit->BulletBlock(m_rifleBullet, m_refBlock[i]);
			m_refBlock[i]->Update();
		}
		m_forecastLine->Update();
		m_balloon->Update();
		m_hit->CharaHit(m_rifleBullet, m_balloon);
		m_playerMove->Update();
		m_player->Update();

		m_bell->Update();

		m_timer->Update();

		m_refBlockMini->Update();

		m_ufo->Update();
		m_hit->CharaHit(m_rifleBullet, m_ufo);

		m_hud->Update();

		//m_uiBase->Update();

}

void Scene::Init()
{
	//アプリ起動時に1回だけ現在の時間を使って乱数を設定する
	srand((unsigned int)time(nullptr));
	m_hit = new Hit();


	for (int i = 0; i < BIRD_NUM; i++)
	{
		m_bird[i] = new Bird();
		m_bird[i]->Init(); 
	}

	for (int i = 0; i < REF_Num; i++)
	{
		m_refBlock[i] = new ReflectiveBlock();
		m_refBlock[i]->Init();
	}

	// 画像の読み込み処理
	
	// 修正例 — Scene::Init
	m_player = new Player();
	m_player->Init();

	m_playerMove = new PlayerMove();
	m_playerMove->Init();

	m_balloon = new Balloon();
	m_balloon->Init();

	m_rifleBullet = new RifleBullet();
	m_rifleBullet->Init();
	m_rifleBullet->SetPlayer(m_player);
	m_rifleBullet->SetPlayerMove(m_playerMove); 
	m_bulletBase = new BulletBase();
	m_bulletBase->Init();
	//m_bulletBase->SetPlayerMoove(m_playerMove);

	m_forecastLine = new ForecastLine();
	m_forecastLine->Init();
	m_forecastLine->SetPlayer(m_player);
	m_forecastLine->SetPlayerMove(m_playerMove);

	m_bell = new Bell();
	m_bell->Init();
	m_bell->SetTagetBase(m_balloon);
	
	m_timer = new Timer();
	m_timer->Init();
	m_timer->SetTagetBase(m_balloon);

	m_refBlockMini = new RefBlockMini();
	m_refBlockMini->Init();
	m_refBlockMini->SetTagetBase(m_balloon);

	m_ufo = new Ufo();
	m_ufo->Init();
	m_ufo->SetBullet(m_rifleBullet);

	m_hud = new Hud();
	m_hud->Init();

	/*m_uiBase = new UiBase();
	m_uiBase->Init();*/
	//m_hit->SetTarget(m_bird, m_rifleBullet);
}

void Scene::Release()
{
	// 画像の解放処理
	if(m_player)		delete m_player;

	if (m_rifleBullet)	delete m_rifleBullet;

	// 配列をループして鳥をすべて解放する
	for (int i = 0; i < BIRD_NUM; i++)
	{
		if (m_bird[i] != nullptr)
		{
			delete m_bird[i];
			m_bird[i] = nullptr; 
		}
	}

	if (m_hit)			delete m_hit;

	for (int i = 0; i < REF_Num; i++)
	{
		if(m_refBlock[i]!=nullptr)
		{
			delete m_refBlock[i];
			m_refBlock[i] = nullptr;
		}
	}

	if (m_forecastLine) delete m_forecastLine;

	if (m_balloon) delete m_balloon;

	if (m_playerMove)	delete m_playerMove;

	if (m_bulletBase) delete m_bulletBase;

	if (m_bell) delete m_bell;

	if (m_timer) delete m_timer;

	if (m_refBlockMini) delete m_refBlockMini;

	if (m_ufo) delete m_ufo;

	if (m_hud) delete m_hud;

	//if (m_uiBase) delete m_uiBase;
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
		for (int i = 0; i < BIRD_NUM; i++)
		{
			ImGui::Text("bird: x%f y%f", m_bird[i]->GetPos().x, m_bird[i]->GetPos().y);
			ImGui::Text("birdFlg: %d", m_bird[i]->GetFlg());
			ImGui::Text("BirdTimer%d: %d", i,m_bird[i]->GetTimerCount());
		}
		for (int i = 0; i < REF_Num; i++)
		{
			ImGui::Text("RefBlockFlg: %d", m_refBlock[i]->GetFlg());
			ImGui::Text("RefBlock: x%f y%f", m_refBlock[i]->GetPos().x, m_refBlock[i]->GetPos().y);
		}

		ImGui::Text("PlayerMove: x%f y%f", m_playerMove->GetPos().x, m_playerMove->GetPos().y);
		ImGui::Text("BalloonPos: x%f y%f", m_balloon->GetPos().x, m_balloon->GetPos().y);
		ImGui::Text("BalloonFlg: %d", m_balloon->GetFlg());
	}
	ImGui::End();
}
