#include "Obstacle.h"

Obstacle::Obstacle(float posX):speed(O_SPEED){
	texture = new sf::Texture();
	texture->loadFromFile(O_TEXTURE);
	obs.setSize(sf::Vector2f(O_WIDTH, O_HEIGHT));
	obs.setTexture(texture);
	obs.setPosition(posX, W_HEIGHT + O_HEIGHT);
	Init();
}

void Obstacle::Init(){
	respawn = (float)(rand() % O_RESPAWNTIME) + 1;
	actTime = 0;
	isActive = false;
}


Obstacle::~Obstacle(){
	delete texture;
}

void Obstacle::Update(float dt){
	if (isActive) Move(dt);
	else {
		actTime += dt;
		if (actTime >= respawn) {
			respawn = (float)(rand() % O_RESPAWNTIME) + 1;
			actTime = 0;
			isActive = true;
		}
	}

}

void Obstacle::Move(float dt){
	if (obs.getPosition().y > -O_HEIGHT)
		obs.move(0, -speed * dt);
	else 
		Reset();
}

void Obstacle::Draw(sf::RenderWindow & win){
	win.draw(obs);
}

void Obstacle::Reset(){
	obs.setPosition(obs.getPosition().x, W_HEIGHT + O_HEIGHT);
	isActive = false;
}

void Obstacle::SetSpeed(float _speed) {
	speed = _speed;
}

sf::Vector2f Obstacle::GetPos(){
	return obs.getPosition();
}
