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
	/*Menu*/
	//HowTo
	howToTexture = new sf::Texture();
	howToTexture->loadFromFile(HOW_TO_IMG);
	howToImg.setSize(sf::Vector2f(MENU_WIDTH, MENU_HEIGHT));
	howToImg.setTexture(howToTexture);
	//credits
	creditsTexture = new sf::Texture();
	creditsTexture->loadFromFile(CREDITS_IMG);
	creditsImg.setSize(sf::Vector2f(MENU_WIDTH, MENU_HEIGHT));
	creditsImg.setTexture(creditsTexture);
	//Tittle
	menuTexture = new sf::Texture();
	menuTexture->loadFromFile(MENU_IMG);
	menuImg.setSize(sf::Vector2f(MENU_WIDTH, MENU_HEIGHT));
	menuImg.setTexture(menuTexture);
	//options
	options = new vector<sf::Text>(MenuOptions::Counts);
	for (int i = 0; i < MenuOptions::Counts; i++){
		options->at(i).setFont(fontKm);
		options->at(i).setCharacterSize(FONT_SIZE);
		options->at(i).setFillColor(sf::Color::White);
		options->at(i).setStyle(sf::Text::Bold);
		options->at(i).setPosition(OPT_X,OPT_Y);
	}
	options->at(0).setString("<    Play     >");
	options->at(1).setString("< How To Play >");
	options->at(2).setString("<   Credits   >");
	options->at(3).setString("<    Exit     >");
	menuOpt = MenuOptions::Play;
	actOpt = options->at(menuOpt);
	/*Enviroment*/
	environmentTexture = new sf::Texture();
	environmentTexture->loadFromFile(ENV_IMG);
	environmentImg.setSize(sf::Vector2f(MENU_WIDTH, MENU_HEIGHT));
	environmentImg.setTexture(environmentTexture);
	/*kilometer font*/
	fontKm.loadFromFile(KM_FONT);
	/*Kilometer text player 1*/
	carsP1 = 0;
	KMTxtP1.setFont(fontKm);
	KMTxtP1.setString("0 KMx0");
	KMTxtP1.setCharacterSize(FONT_SIZE);
	KMTxtP1.setFillColor(sf::Color::White);
	KMTxtP1.setStyle(sf::Text::Bold);
	KMTxtP1.setPosition(KM_W1_X,0);
	carTexture = new sf::Texture();
	carTexture->loadFromFile(B_TEXTURE);
	carPinkP1.setSize(sf::Vector2f(B_WIDTH/2, B_HEIGHT/2));
	carPinkP1.setTexture(carTexture);
	carPinkP1.setPosition(CAR_W1_X, 0);
	/*Kilometer text player 2*/
	carsP2 = 0;
	KMTxtP2.setFont(fontKm);
	KMTxtP2.setString("0 KMx0");
	KMTxtP2.setCharacterSize(FONT_SIZE);
	KMTxtP2.setFillColor(sf::Color::White);
	KMTxtP2.setStyle(sf::Text::Bold);
	KMTxtP2.setPosition(KM_W2_X, 0);
	carPinkP2.setSize(sf::Vector2f(B_WIDTH / 2, B_HEIGHT / 2));
	carPinkP2.setTexture(carTexture);
	carPinkP2.setPosition(CAR_W2_X, 0);
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
	delete options;
}

void InterfaceManager::ChangueOptionL(){
	if (menuOpt == MenuOptions::Play)
		menuOpt = MenuOptions::Exit;
	else
		menuOpt = (MenuOptions)(menuOpt - 1);

	actOpt = options->at(menuOpt);
}

void InterfaceManager::ChangueOptionR(){
	if (menuOpt == MenuOptions::Exit)
		menuOpt = MenuOptions::Play;
	else
		menuOpt = (MenuOptions)(menuOpt + 1);
	
	actOpt = options->at(menuOpt);
}

MenuOptions InterfaceManager::MenuOpt(){
	return menuOpt;
}

void InterfaceManager::Update(){
	string km;
	switch (gm->getActualState()){
	case GameStates::Menu:
	break;
	case GameStates::Gameplay:
		km = to_string((int)(gm->GetTime() * obsM->GetSpeedS1())/10) + " KMx" + to_string(carsP1);
		KMTxtP1.setString(km);
		km = to_string((int)(gm->GetTime() * obsM->GetSpeedS2())/10) + " KMx" + to_string(carsP2);
		KMTxtP2.setString(km);
		break;
	case GameStates::P1WinScreen:
		carsP1 = 0;
		carsP2 = 0;
	break;
	case GameStates::P2WinScreen:
		carsP1 = 0;
		carsP2 = 0;
	break;
	case GameStates::Count:
		break;
	default:
		break;
	}
}

void InterfaceManager::PlusCarsP1(){
	carsP1++;
}

void InterfaceManager::PlusCarsP2(){
	carsP2++;
}

void InterfaceManager::Draw(sf::RenderWindow & win){
	switch (gm->getActualState()){
	case GameStates::HowToMenu:
		win.draw(howToImg);
	break;
	case GameStates::CreditsMenu:
		win.draw(creditsImg);
	break;
	case GameStates::Menu:
		win.draw(menuImg);
		win.draw(actOpt);
	break;
	case GameStates::Gameplay:
		win.draw(environmentImg);
		win.draw(KMTxtP1);
		win.draw(KMTxtP2);
		win.draw(carPinkP1);
		win.draw(carPinkP2);
		break;
	case GameStates::P1WinScreen:
		win.draw(winTxtP1);
		break;
	case GameStates::P2WinScreen:
		win.draw(winTxtP2);
		break;
	default:
		break;
	}
}
