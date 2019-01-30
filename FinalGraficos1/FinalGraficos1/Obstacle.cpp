#include "Obstacle.h"

Obstacle::Obstacle(string texturePath, float posX):speed(O_SPEED){
	texture = new sf::Texture();
	texture->loadFromFile(texturePath);
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
	else {
		obs.setPosition(obs.getPosition().x, W_HEIGHT + O_HEIGHT);
		isActive = false;
	}
}

void Obstacle::Draw(sf::RenderWindow & win){
	win.draw(obs);
}

void Obstacle::SetSpeed(float _speed) {
	speed = _speed;
}
