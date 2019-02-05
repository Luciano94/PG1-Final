#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class CollisionManager{
private:
	
	CollisionManager();
	static CollisionManager * Instance;
public:
	static CollisionManager * GetInstance();
	bool DetectCollision(sf::Vector2f box1,sf::Vector2f box2,int box1W, int box1H, int box2W, int box2H);
	~CollisionManager();
};
#endif

