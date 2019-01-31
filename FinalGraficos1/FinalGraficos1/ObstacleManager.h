#ifndef OBSTACLEMANAGER_H
#define OBSTACLEMANAGER_H
#include "Obstacle.h"
#include "GlobalDefinitions.h"
#include <list>

using namespace Constants;

class ObstacleManager
{
private:
	list<Obstacle*> * listOfS1;
	list<Obstacle*> * listOfS2;

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
	float GetSpeedS1();
	float GetSpeedS2();
	void SetSpeedS1(float _speed);
	void SetSpeedS2(float _speed);
};
#endif


