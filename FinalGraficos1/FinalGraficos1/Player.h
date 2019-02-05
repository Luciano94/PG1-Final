#ifndef PLAYER_H
#define PLAYER_H
#include <SFML\Graphics.hpp>
#include "GlobalDefinitions.h"

using namespace std;
using namespace Constants;

class Player{

protected:
	float speed;
	virtual void Input(float dt) = 0;
	virtual void BoundingCheck() = 0;
	
	sf::RectangleShape character;
	sf::Texture * texture;
public:
	Player(string texturePath);
	~Player();
	void Draw(sf::RenderWindow &win);
	virtual void Update(float dt)=0;
	sf::Vector2f GetPos();
};

#endif // !PLAYER_H
