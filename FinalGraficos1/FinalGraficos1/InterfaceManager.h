#ifndef INTERFACEMANAGER_H
#define INTERFACEMANAGER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameManager.h"
#include "ObstacleManager.h"
#include "GlobalDefinitions.h"

using namespace std;
using namespace Constants;

class InterfaceManager
{
private:
	//credits
	sf::RectangleShape creditsImg;
	sf::Texture * creditsTexture;
	//How To Menu
	sf::RectangleShape howToImg;
	sf::Texture * howToTexture;
	//Main Menu 
	sf::RectangleShape menuImg;
	sf::Texture * menuTexture;
	vector<sf::Text> * options;
	sf::Text actOpt;
	MenuOptions menuOpt;
	//Gameplay
	sf::Texture * sideWalkLeft;
	sf::Texture * sideWalkRigth;
	sf::RectangleShape division;
	sf::RectangleShape sideWalkW1XR;
	sf::RectangleShape sideWalkW1XL;
	sf::RectangleShape sideWalkW2XR;
	sf::RectangleShape sideWalkW2XL;
	sf::RectangleShape yellowLineW1;
	sf::RectangleShape yellowLineW2;
	sf::Font fontKm;
	sf::Text KMTxtP1;
	sf::Text KMTxtP2;
	//Win Player1
	sf::Text winTxtP1;
	//Win Player2
	sf::Text winTxtP2;
	//managers
	GameManager * gm;
	ObstacleManager * obsM;

	InterfaceManager();
	static InterfaceManager * Instance;
public:
	static InterfaceManager * GetInstance();
	~InterfaceManager();
	void ChangueOptionL();
	void ChangueOptionR();
	MenuOptions MenuOpt();
	void Update();
	void Draw(sf::RenderWindow &win);
};
#endif

