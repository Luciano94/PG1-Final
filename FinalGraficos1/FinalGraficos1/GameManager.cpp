#include "GameManager.h"

GameManager * GameManager::Instance = NULL;

GameManager::GameManager(){
	timer = 0;
	dt = DeltaTime::GetInstance();
	gS = GameStates::Menu;
	beClose = false;
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

float GameManager::GetTime(){
	return timer;
}

void GameManager::InitGame(){
	gS = GameStates::Gameplay;
	timer = 0;
	beClose = false;
}

void GameManager::GoToMenu(){
	gS = GameStates::Menu;
}

void GameManager::GoToCredits(){
	gS = GameStates::CreditsMenu;
}

void GameManager::GoToHowTo(){
	gS = GameStates::HowToMenu;
}

void GameManager::Exit(){
	beClose = true;
}

GameStates GameManager::getActualState(){
	return gS;
}

bool GameManager::BeClose(){
	return beClose;
}
