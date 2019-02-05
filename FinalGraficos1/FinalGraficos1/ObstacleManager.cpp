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
	cM = CollisionManager::GetInstance();
	gM = GameManager::GetInstance();
	CreateListOfS1();
	CreateListOfS2();
}

void ObstacleManager::CreateListOfS1(){
	listOfS1 = new list<Obstacle*>();
	Obstacle * obs;
	float posX = 60;
	for (int i = 0; i < 8; i++){
		obs = new Obstacle(posX);
		listOfS1->push_back(obs);
		posX += 60;
	}
}

void ObstacleManager::CreateListOfS2(){
	listOfS2 = new list<Obstacle*>();
	Obstacle * obs;
	float posX = 660;
	for (int i = 0; i < 8; i++) {
		obs = new Obstacle(posX);
		listOfS2->push_back(obs);
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

void ObstacleManager::BoostSpeedS1(float _speed){
	cout << obsSpeedS1 << endl;
	obsSpeedS1 += _speed;
	for (list<Obstacle*>::iterator iter = listOfS1->begin();
		iter != listOfS1->end(); ++iter)
		(*iter)->SetSpeed(obsSpeedS1);
}

void ObstacleManager::BoostSpeedS2(float _speed){
	cout << obsSpeedS2 << endl;
	obsSpeedS2 += _speed;
	for (list<Obstacle*>::iterator iter = listOfS2->begin();
		iter != listOfS2->end(); ++iter)
		(*iter)->SetSpeed(obsSpeedS2);
}

void ObstacleManager::UpdateObs(float dt){
	for (list<Obstacle*>::iterator iter = listOfS1->begin();
		iter != listOfS1->end(); ++iter)
		(*iter)->Update(dt);

	for (list<Obstacle*>::iterator iter = listOfS2->begin();
		iter != listOfS2->end(); ++iter)
		(*iter)->Update(dt);
}

void ObstacleManager::CheckCollisions(Player1 * p1, Player2 * p2){
	for (list<Obstacle*>::iterator iter = listOfS1->begin();
		iter != listOfS1->end(); ++iter) {
		
		if (cM->DetectCollision((*iter)->GetPos(), p1->GetPos(), 
			O_WIDTH, O_HEIGHT, P_WIDTH, P_HEIGHT)) {
			gM->p2Win();
		}
	}

	for (list<Obstacle*>::iterator iter = listOfS2->begin();
		iter != listOfS2->end(); ++iter) {
		
		if (cM->DetectCollision((*iter)->GetPos(), p2->GetPos(),
			O_WIDTH, O_HEIGHT, P_WIDTH, P_HEIGHT)) {
			gM->p1Win();
		}
	}
}

void ObstacleManager::Reset(){

	for (list<Obstacle*>::iterator iter = listOfS1->begin();
		iter != listOfS1->end(); ++iter) {
		(*iter)->Reset();
	}

	for (list<Obstacle*>::iterator iter = listOfS2->begin();
		iter != listOfS2->end(); ++iter) {
		(*iter)->Reset();
	}
}
