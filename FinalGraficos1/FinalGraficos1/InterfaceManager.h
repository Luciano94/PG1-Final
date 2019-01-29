#ifndef INTERFACEMANAGER_H
#define INTERFACEMANAGER_H
#include <SFML/Graphics.hpp>
#include "GlobalDefinitions.h"

using namespace std;
using namespace Constants;

class InterfaceManager
{
private:
	sf::RectangleShape division;
public:
	InterfaceManager();
	~InterfaceManager();
	void Draw(sf::RenderWindow &win);
};
#endif

