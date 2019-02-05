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
	/*Windows 1 Env*/
	sideWalkW1XR.setSize(sf::Vector2f(SW1R_WIDTH, SW1R_HEIGHT));
	sideWalkW1XR.setFillColor(sf::Color::Blue);
	sideWalkW1XR.setPosition(SW1R_SPAWN_X, SW1R_SPAWN_Y);
	sideWalkW1XL.setSize(sf::Vector2f(SW1L_WIDTH, SW1L_HEIGHT));
	sideWalkW1XL.setFillColor(sf::Color::Blue);
	sideWalkW1XL.setPosition(SW1L_SPAWN_X, SW1L_SPAWN_Y);
	/*Windows 2 Env*/
	sideWalkW2XR.setSize(sf::Vector2f(SW2R_WIDTH, SW2R_HEIGHT));
	sideWalkW2XR.setFillColor(sf::Color::Blue);
	sideWalkW2XR.setPosition(SW2R_SPAWN_X, SW2R_SPAWN_Y);
	sideWalkW2XL.setSize(sf::Vector2f(SW2L_WIDTH, SW2L_HEIGHT));
	sideWalkW2XL.setFillColor(sf::Color::Blue);
	sideWalkW2XL.setPosition(SW2L_SPAWN_X, SW2L_SPAWN_Y);
	/*screen division*/
	division.setSize(sf::Vector2f(DIV_WIDTH, DIV_HEIGHT));
	division.setFillColor(sf::Color::Magenta);
	division.setPosition(DIV_SPAWN_X, DIV_SPAWN_Y);
	/*kilometer font*/
	fontKm.loadFromFile(KM_FONT);
	/*Kilometer text player 1*/
	KMTxtP1.setFont(fontKm);
	KMTxtP1.setString("0 KM");
	KMTxtP1.setCharacterSize(FONT_SIZE);
	KMTxtP1.setFillColor(sf::Color::White);
	KMTxtP1.setStyle(sf::Text::Bold);
	KMTxtP1.setPosition(KM_W1_X,0);
	/*Kilometer text player 2*/
	KMTxtP2.setFont(fontKm);
	KMTxtP2.setString("0 KM");
	KMTxtP2.setCharacterSize(FONT_SIZE);
	KMTxtP2.setFillColor(sf::Color::White);
	KMTxtP2.setStyle(sf::Text::Bold);
	KMTxtP2.setPosition(KM_W2_X, 0);
	/*WinTxt P1*/
	winTxtP1.setFont(fontKm);
	winTxtP1.setString("PLAYER 1 WIN");
	winTxtP1.setCharacterSize(TITTLE_SIZE);
	winTxtP1.setFillColor(sf::Color::White);
	winTxtP1.setStyle(sf::Text::Bold);
	winTxtP1.setPosition(400,250);
	/*WinTxt P2*/
	winTxtP2.setFont(fontKm);
	winTxtP2.setString("PLAYER 2 WIN");
	winTxtP2.setCharacterSize(TITTLE_SIZE);
	winTxtP2.setFillColor(sf::Color::White);
	winTxtP2.setStyle(sf::Text::Bold);
	winTxtP2.setPosition(400, 250);
}



InterfaceManager::~InterfaceManager(){
}

void InterfaceManager::Update(){
	string km;
	switch (gm->getActualState()){
	case Constants::Menu:
		break;
	case Constants::Gameplay:
		km = to_string((int)(gm->GetTime() * obsM->GetSpeedS1())/10) + " KM";
		KMTxtP1.setString(km);
		km = to_string((int)(gm->GetTime() * obsM->GetSpeedS2())/10) + " KM";
		KMTxtP2.setString(km);
		break;
	case Constants::P1WinScreen:
		break;
	case Constants::P2WinScreen:
		break;
	case Constants::Count:
		break;
	default:
		break;
	}
}

void InterfaceManager::Draw(sf::RenderWindow & win){
	switch (gm->getActualState())
	{
	case Constants::Menu:
		break;
	case Constants::Gameplay:
		win.draw(division);
		win.draw(sideWalkW1XL);
		win.draw(sideWalkW1XR);
		win.draw(sideWalkW2XL);
		win.draw(sideWalkW2XR);
		win.draw(KMTxtP1);
		win.draw(KMTxtP2);
		break;
	case Constants::P1WinScreen:
		win.draw(winTxtP1);
		break;
	case Constants::P2WinScreen:
		win.draw(winTxtP2);
		break;
	case Constants::Count:
		break;
	default:
		break;
	}
}
