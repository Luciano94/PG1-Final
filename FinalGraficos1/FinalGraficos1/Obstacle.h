#ifndef OBSTACLE_H
#define OBSTACLE_H
#include<SFML/Graphics.hpp>
#include"GlobalDefinitions.h"
#include <iostream>

using namespace std;
using namespace Constants;
class Obstacle{
protected:
	float speed;
	sf::RectangleShape obs;
	sf::Texture * texture;
public:
	Obstacle(string texturePath);
	~Obstacle();
	void Update(float dt);
	virtual void Init()=0;
	void Draw(sf::RenderWindow &win);
};

#endif // !OBSTACLE_H
