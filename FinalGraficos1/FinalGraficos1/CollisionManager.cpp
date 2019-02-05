#include "CollisionManager.h"

CollisionManager * CollisionManager::Instance = NULL;

CollisionManager::CollisionManager(){
}

CollisionManager * CollisionManager::GetInstance()
{
	if (Instance == NULL) {
		Instance = new CollisionManager();
	}
	return Instance;
}

bool CollisionManager::DetectCollision(sf::Vector2f box1, sf::Vector2f box2,
	int box1W, int box1H, int box2W, int box2H){
	sf::Vector2f diff = box1 - box2;
	float diffX = abs(diff.x);
	float diffY = abs(diff.y);

	if (diffX <= (box1W / 2 + box2W / 2) &&
		diffY <= (box1H / 2 + box2H / 2)) {
		return true;
	}
	else return false;
}

CollisionManager::~CollisionManager(){
}
