#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <SFML/Graphics.hpp>
#include "GlobalDefinitions.h"

using namespace std;
using namespace Constants;

class GameManager
{
private:
	sf::RectangleShape division;
	sf::Texture * texture;
public:
	GameManager(string texturePath);
	~GameManager();
	void Draw(sf::RenderWindow &win);
};

#endif // !GAMEMANAGER_H
