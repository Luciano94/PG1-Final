#include "Game.h"



Game::Game(){

}

void Game::Start(){
	window.create(sf::VideoMode(W_WIDTH, W_HEIGHT), W_TITTLE);
	dt = DeltaTime::GetInstance();
	ObsManager = ObstacleManager::GetInstance();
	UI = InterfaceManager::GetInstance();
	gm = GameManager::GetInstance();
	cM = CollisionManager::GetInstance();
	iM = Input::GetInstance();
	p1 = new Player1(P1_TEXTURE);
	p2 = new Player2(P2_TEXTURE);
	b1 = new Boost(W1_XL);
	b2 = new Boost(W2_XL);
}

Game::~Game(){

}

void Game::Update(){

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed || gm->BeClose())
				window.close();
		}
		window.clear();

		CallUpdates();
		Draw();

		window.display();
	}
}

void Game::Stop(){
	delete p1;
	delete p2;
}

void Game::Draw(){
	UI->Draw(window);
	
	switch (gm->getActualState()){
		case GameStates::Menu:
			break;
		case GameStates::Gameplay:
			p1->Draw(window);
			p2->Draw(window);
			b2->Draw(window);
			b1->Draw(window);
			ObsManager->Draw(window);
			break;
		case GameStates::P1WinScreen:
			break;
		case GameStates::P2WinScreen:
			break;
		case GameStates::Count:
			break;
		default:
			break;
	}
}

void Game::CallUpdates(){
	dt->Update();
	gm->Update();
	UI->Update();
	iM->Update(dt->Get());

	switch (gm->getActualState()) {
	case GameStates::Menu:
	break;
	case GameStates::Gameplay:
		CheckCollisions();
		b1->Update(dt->Get());
		b2->Update(dt->Get());
		ObsManager->Update(dt->Get());
		p1->Update(dt->Get());
		p2->Update(dt->Get());
	break;
	case GameStates::P1WinScreen:
		b1->Reset();
		b2->Reset();
	break;
	case GameStates::P2WinScreen:
		b1->Reset();
		b2->Reset();
	break;
	default:
		break;
	}
}

void Game::CheckCollisions(){
	ObsManager->CheckCollisions(p1,p2);

	if (cM->DetectCollision(p1->GetPos(), b1->GetPos(),
		P_WIDTH, P_HEIGHT, B_WIDTH, B_HEIGHT)) {
		b1->Init();
		ObsManager->BoostSpeedS2(B_PLUS_SPEED);
		UI->PlusCarsP2();
	}

	if (cM->DetectCollision(p2->GetPos(), b2->GetPos(),
		P_WIDTH, P_HEIGHT, B_WIDTH, B_HEIGHT)) {
		b2->Init();
		ObsManager->BoostSpeedS1(B_PLUS_SPEED);
		UI->PlusCarsP1();
	}
}
