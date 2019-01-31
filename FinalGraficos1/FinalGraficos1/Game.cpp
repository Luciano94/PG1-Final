#include "Game.h"



Game::Game(){

}

void Game::Start(){
	window.create(sf::VideoMode(W_WIDTH, W_HEIGHT), W_TITTLE);
	dt = DeltaTime::GetInstance();
	ObsManager = ObstacleManager::GetInstance();
	UI = InterfaceManager::GetInstance();
	gm = GameManager::GetInstance();
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
		Draw();

		window.display();
	}
}

void Game::Stop(){
	delete p1;
	delete p2;
}

void Game::Draw(){
	p1->Draw(window);
	p2->Draw(window);
	UI->Draw(window);
	b2->Draw(window);
	b1->Draw(window);
	ObsManager->Draw(window);
}

void Game::CallUpdates(){
	dt->Update();
	b1->Update(dt->Get());
	b2->Update(dt->Get());
	gm->Update();
	UI->Update();
	ObsManager->Update(dt->Get());
	p1->Update(dt->Get());
	p2->Update(dt->Get());
}
