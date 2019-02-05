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
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		CallUpdates();
		CheckCollisions();
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
		case Constants::Menu:
			break;
		case Constants::Gameplay:
			p1->Draw(window);
			p2->Draw(window);
			b2->Draw(window);
			b1->Draw(window);
			ObsManager->Draw(window);
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

void Game::CallUpdates(){
	switch (gm->getActualState()) {
	case Constants::Menu:
		break;
	case Constants::Gameplay:
		b1->Update(dt->Get());
		b2->Update(dt->Get());
		ObsManager->Update(dt->Get());
		p1->Update(dt->Get());
		p2->Update(dt->Get());
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
	dt->Update();
	gm->Update();
	UI->Update();
}

void Game::CheckCollisions(){
	ObsManager->CheckCollisions(p1,p2);

	if (cM->DetectCollision(p1->GetPos(), b1->GetPos(),
		P_WIDTH, P_HEIGHT, B_WIDTH, B_HEIGHT)) {
		b1->Init();
		ObsManager->BoostSpeedS2(B_PLUS_SPEED);
	}

	if (cM->DetectCollision(p2->GetPos(), b2->GetPos(),
		P_WIDTH, P_HEIGHT, B_WIDTH, B_HEIGHT)) {
		b2->Init();
		ObsManager->BoostSpeedS1(B_PLUS_SPEED);
	}
}
