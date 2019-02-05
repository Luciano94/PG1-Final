#include "Boost.h"

Boost::Boost(int win): 
win(win){
	srand((unsigned)time(0));
	
	texture = new sf::Texture();
	texture->loadFromFile(B_TEXTURE);
	
	boost.setSize(sf::Vector2f(B_WIDTH, B_HEIGHT));
	boost.setTexture(texture);
	
	Init();
}

Boost::~Boost(){
	delete texture;
}

void Boost::Init(){
	boost.setPosition(-B_WIDTH, -B_HEIGHT);
	respawn = (float)(rand() % B_MAXTIME) + B_MINTIME;
	speed = (float)(rand() % B_SPEEDMIN) + B_SPEEDMAX;
	actTime = 0;
	isActive = false;
}

void Boost::Move(float dt){
	if (boost.getPosition().y > -B_HEIGHT) {
		boost.move(0, -speed * dt);
	}
	else {
		boost.setPosition(boost.getPosition().x, W_HEIGHT + B_HEIGHT);
		isActive = false;
	}
}

void Boost::Update(float dt){
	if (isActive) {
		Move(dt);
	} else {
		actTime += dt;
		if (actTime >= respawn) {
			float posx = (float)(rand() % (B_SPAWNX1 + win)) + (B_SPAWNX2 + win);
			if (posx > P2_RIGTH_BOUNDING)
				posx = P2_RIGTH_BOUNDING;
			boost.setPosition(posx, W_HEIGHT + B_HEIGHT);
			respawn = (float)(rand() % B_MAXTIME) + B_MINTIME;
			speed = (float)(rand() % B_SPEEDMIN) + B_SPEEDMAX;
			actTime = 0;
			isActive = true;
		}
	}
}

void Boost::Draw(sf::RenderWindow & win){
	win.draw(boost);
}

sf::Vector2f Boost::GetPos(){
	return boost.getPosition();
}
