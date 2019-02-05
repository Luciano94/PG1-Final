#include "Input.h"

Input * Input::Instance = NULL;

Input * Input::GetInstance(){
	if (Instance == NULL) {
		Instance = new Input();
	}
	return Instance;
}

Input::Input(){
	gm = GameManager::GetInstance();
	UI = InterfaceManager::GetInstance();
	dT = DeltaTime::GetInstance();
	oM = ObstacleManager::GetInstance();
	inputDelay = 0.2f;
	actInputDelay = 0.0f;
}

Input::~Input(){
}

void Input::Update(float dt){
	if (actInputDelay < inputDelay) actInputDelay += dt;
	else {
		cout << actInputDelay << endl;
		switch (gm->getActualState()) {
		case GameStates::Menu:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				UI->ChangueOptionL();
				actInputDelay = 0.0f;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				UI->ChangueOptionR();
				actInputDelay = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				
				switch (UI->MenuOpt()){
				case MenuOptions::Play:
					gm->InitGame();
					oM->Reset();
					break;
				case MenuOptions::HowTo:
					//mostrar pantalla de controles
					break;
				case MenuOptions::Exit:
					gm->Exit();
					break;
				case MenuOptions::Credits:
					//mostrar creditos
					break;
				default:
					break;
				}
				actInputDelay = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				gm->Exit();
			}
			break;
		case GameStates::Gameplay:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
				dT->PauseGame();
				actInputDelay = 1.0f;
			}
			break;
		case GameStates::P1WinScreen:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				gm->GoToMenu();
				actInputDelay = 0.0f;
			}
			break;
		case GameStates::P2WinScreen:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				gm->GoToMenu();
				actInputDelay = 0.0f;
			}
			break;
		case GameStates::HowToMenu:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				gm->GoToMenu();
				actInputDelay = 0.0f;
			}
			break;
		default:
			break;
		}
	}
}
