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
	sf::RectangleShape environmentImg;
	sf::Texture * environmentTexture;
	sf::Texture * carTexture;
	sf::RectangleShape carPinkP1;
	sf::RectangleShape carPinkP2;
	sf::Font fontKm;
	sf::Text KMTxtP1;
	sf::Text KMTxtP2;
	int carsP1;
	int carsP2;
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
	void PlusCarsP1();
	void PlusCarsP2();
	void Draw(sf::RenderWindow &win);
};
#endif

