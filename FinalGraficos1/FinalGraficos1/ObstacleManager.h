#ifndef OBSTACLEMANAGER_H
#define OBSTACLEMANAGER_H
#include "Obstacle.h"
#include "GlobalDefinitions.h"
#include "Player1.h"
#include "Player2.h"
#include "CollisionManager.h"
#include "GameManager.h"
#include <list>

using namespace Constants;

class ObstacleManager
{
private:
	list<Obstacle*> * listOfS1;
	list<Obstacle*> * listOfS2;

	CollisionManager * cM;
	GameManager * gM;
	
	float obsSpeedS1;
	float obsSpeedS2;

	void CreateListOfS1();
	void CreateListOfS2();

	void DeleteListOfS2();
	void DeleteListOfS1();

	void DrawObs(sf::RenderWindow &win);
	void UpdateObs(float dt);
	ObstacleManager();
	static ObstacleManager * Instance;
public:
	static ObstacleManager * GetInstance();
	~ObstacleManager();
	void Draw(sf::RenderWindow &win);
	void Update(float dt);
	void CheckCollisions(Player1 * p1, Player2 * p2);
	void Reset();
	float GetSpeedS1();
	float GetSpeedS2();
	void BoostSpeedS1(float _speed);
	void BoostSpeedS2(float _speed);
};
#endif


