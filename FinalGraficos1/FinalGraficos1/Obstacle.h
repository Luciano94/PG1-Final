#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <iostream>
#include<SFML/Graphics.hpp>
#include"GlobalDefinitions.h"

using namespace Constants;
using namespace std;


class Obstacle{
private:
	/*ATTRIBUTES*/
	float speed;
	float boostSpeed;
	float respawn;
	float actTime;
	bool isActive;
	sf::RectangleShape obs;
	sf::Texture * texture;

	void Init();
	void Move(float dt);
public:
	Obstacle(float posX);
	~Obstacle();
	void Update(float dt);
	void Draw(sf::RenderWindow &win);
	void Reset();
	void SetSpeed(float _speed);
	sf::Vector2f GetPos();
};

#endif // !OBSTACLE_H
