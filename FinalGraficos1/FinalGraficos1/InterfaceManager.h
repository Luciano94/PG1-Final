#ifndef INTERFACEMANAGER_H
#define INTERFACEMANAGER_H
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "ObstacleManager.h"
#include "GlobalDefinitions.h"

using namespace std;
using namespace Constants;

class InterfaceManager
{
private:
	sf::RectangleShape division;
	sf::Font fontKm;
	sf::Text KMTxtP1;
	sf::Text KMTxtP2;

	GameManager * gm;
	ObstacleManager * obsM;


	InterfaceManager();
	static InterfaceManager * Instance;
public:
	static InterfaceManager * GetInstance();
	~InterfaceManager();
	void Update();
	void Draw(sf::RenderWindow &win);
};
#endif

