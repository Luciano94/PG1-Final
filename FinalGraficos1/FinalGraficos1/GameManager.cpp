#include "GameManager.h"

GameManager * GameManager::Instance = NULL;

GameManager::GameManager(){
	timer = 0;
	dt = DeltaTime::GetInstance();
	gS = GameStates::Gameplay;
}

GameManager * GameManager::GetInstance()
{
	if (Instance == NULL) {
		Instance = new GameManager();
	}
	return Instance;
}

GameManager::~GameManager(){
	delete Instance;
}

void GameManager::Update(){
	timer += dt->Get();
}

void GameManager::p1Win(){
	gS = GameStates::P1WinScreen;
}

void GameManager::p2Win(){
	gS = GameStates::P2WinScreen;
}

float GameManager::GetTime()
{
	return timer;
}

GameStates GameManager::getActualState(){
	return gS;
}
