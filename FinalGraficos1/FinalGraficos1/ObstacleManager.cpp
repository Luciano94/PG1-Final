#include "ObstacleManager.h"

ObstacleManager * ObstacleManager::Instance = NULL;

ObstacleManager * ObstacleManager::GetInstance(){
	if (Instance == NULL) {
		Instance = new ObstacleManager();
	}
	return Instance;
}

ObstacleManager::ObstacleManager(){
	srand((unsigned)time(0));
	obsSpeedS1 = O_SPEED;
	obsSpeedS2 = O_SPEED;
	CreateListOfS1();
	CreateListOfS2();
}

void ObstacleManager::CreateListOfS1(){
	listOfS1 = new list<Obstacle*>();
	Obstacle * obs;
	float posX = 0;
	for (int i = 0; i < 10; i++){
		obs = new Obstacle(O_TEXTURE, posX);
		listOfS1->push_back(obs);
		posX += 60;
	}
}

void ObstacleManager::CreateListOfS2(){
	listOfS2 = new list<Obstacle*>();
	Obstacle * obs;
	float posX = 600;
	for (int i = 0; i < 10; i++) {
		obs = new Obstacle(O_TEXTURE, posX);
		listOfS1->push_back(obs);
		posX += 60;
	}
}



ObstacleManager::~ObstacleManager(){
	DeleteListOfS1();
	DeleteListOfS2();
}


void ObstacleManager::DeleteListOfS1(){
	for (list<Obstacle*>::iterator iter = listOfS1->begin(); 
	iter != listOfS1->end(); ++iter)
		delete *iter;

	delete listOfS1;
}


void ObstacleManager::DeleteListOfS2(){
	for (list<Obstacle*>::iterator iter = listOfS2->begin();
		iter != listOfS2->end(); ++iter)
		delete *iter;

	delete listOfS2;
}

void ObstacleManager::Draw(sf::RenderWindow &win){
	DrawObs(win);
}

void ObstacleManager::DrawObs(sf::RenderWindow & win){
	for (list<Obstacle*>::iterator iter = listOfS1->begin();
		iter != listOfS1->end(); ++iter) 
		(*iter)->Draw(win);

	for (list<Obstacle*>::iterator iter = listOfS2->begin();
		iter != listOfS2->end(); ++iter) 
		(*iter)->Draw(win);
}

void ObstacleManager::Update(float dt){
	UpdateObs(dt);
}

float ObstacleManager::GetSpeedS1(){
	return obsSpeedS1;
}

float ObstacleManager::GetSpeedS2() {
	return obsSpeedS2;
}

void ObstacleManager::UpdateObs(float dt){
	for (list<Obstacle*>::iterator iter = listOfS1->begin();
		iter != listOfS1->end(); ++iter)
		(*iter)->Update(dt);

	for (list<Obstacle*>::iterator iter = listOfS2->begin();
		iter != listOfS2->end(); ++iter)
		(*iter)->Update(dt);
}
