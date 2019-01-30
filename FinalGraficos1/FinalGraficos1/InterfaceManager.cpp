#include "InterfaceManager.h"

InterfaceManager * InterfaceManager::Instance = NULL;

InterfaceManager * InterfaceManager::GetInstance()
{
	if (Instance == NULL) {
		Instance = new InterfaceManager();
	}
	return Instance;
}

InterfaceManager::InterfaceManager(){
	/*GameManager*/
	gm = GameManager::GetInstance();
	/*ObstacleManager*/
	obsM = ObstacleManager::GetInstance();
	/*screen division*/
	division.setSize(sf::Vector2f(DIV_WIDTH, DIV_HEIGHT));
	division.setFillColor(sf::Color::Magenta);
	division.setPosition(DIV_SPAWN_X, DIV_SPAWN_Y);
	/*kilometer font*/
	fontKm.loadFromFile(KM_FONT);
	/*Kilometer text player 1*/
	KMTxtP1.setFont(fontKm);
	KMTxtP1.setString("0 KM");
	KMTxtP1.setCharacterSize(24);
	KMTxtP1.setFillColor(sf::Color::White);
	KMTxtP1.setStyle(sf::Text::Bold);
	KMTxtP1.setPosition(0,0);
	/*Kilometer text player 2*/
	KMTxtP2.setFont(fontKm);
	KMTxtP2.setString("0 KM");
	KMTxtP2.setCharacterSize(24);
	KMTxtP2.setFillColor(sf::Color::White);
	KMTxtP2.setStyle(sf::Text::Bold);
	KMTxtP2.setPosition(600, 0);
}



InterfaceManager::~InterfaceManager(){
}

void InterfaceManager::Update(){
	string km = to_string((int)(gm->GetTime() * obsM->GetSpeedS1())/10) + " KM";
	KMTxtP1.setString(km);
	km = to_string((int)(gm->GetTime() * obsM->GetSpeedS2())/10) + " KM";
	KMTxtP2.setString(km);
}

void InterfaceManager::Draw(sf::RenderWindow & win){
	win.draw(division);
	win.draw(KMTxtP1);
	win.draw(KMTxtP2);
}
