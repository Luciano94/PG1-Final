#ifndef OBSTACLE_H
#define OBSTACLE_H
#include<SFML/Graphics.hpp>
#include"GlobalDefinitions.h"
#include <iostream>

using namespace std;
using namespace Constants;
class Obstacle{
private:
	float speed;
	int screen;
	sf::RectangleShape obs;
	sf::Texture * texture;
public:
	Obstacle(string texturePath, int Screen);
	~Obstacle();
	void Update(float dt);
	void Init();
	void Draw(sf::RenderWindow &win);
};

#endif // !OBSTACLE_H
