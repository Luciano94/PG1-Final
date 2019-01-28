#ifndef PLAYER_H
#define PLAYER_H
#include <SFML\Graphics.hpp>
#include "GlobalDefinitions.h"

using namespace std;
using namespace Constants;

class Player{

protected:
	float speed;
	
	sf::RectangleShape character;
	sf::Texture * texture;
public:
	Player(string texturePath);
	~Player();
	void Update();
	void Draw(sf::RenderWindow &win);
};

#endif // !PLAYER_H
