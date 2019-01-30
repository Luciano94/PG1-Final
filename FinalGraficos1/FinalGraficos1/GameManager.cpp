#include "GameManager.h"

GameManager * GameManager::Instance = NULL;

GameManager::GameManager(){
	timer = 0;
	dt = DeltaTime::GetInstance();
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

float GameManager::GetTime()
{
	return timer;
}
