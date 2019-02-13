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
	sM = SoundManager::GetInstance();
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
				sM->PlaySelectSound();
				actInputDelay = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				UI->ChangueOptionR();
				sM->PlaySelectSound();
				actInputDelay = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				gm->Exit();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				sM->PlayEnterSound();
				switch (UI->MenuOpt()) {
					case MenuOptions::Play:
						gm->InitGame();
						oM->Reset();
					break;
					case MenuOptions::HowTo:
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
							gm->GoToHowTo();
						}
					break;
					case MenuOptions::Exit:
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
							gm->Exit();
						}
					break;
					case MenuOptions::Credits:
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
							gm->GoToCredits();
						}
					break;
				}
				actInputDelay = 0.0f;
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
		case GameStates::CreditsMenu:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				gm->GoToMenu();
				actInputDelay = 0.0f;
			}
		break;
		}
	}
}
