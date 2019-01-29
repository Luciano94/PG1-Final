#include "Player2.h"

Player2::Player2(string texturePath) :Player(texturePath){
	character.setPosition(sf::Vector2f(P2_SPAWN_X, P2_SPAWN_Y));
}


Player2::~Player2(){
}

void Player2::Update(float dt){
	Input(dt);
	BoundingCheck();
}

void Player2::Input(float dt){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		character.move(speed * dt, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		character.move(-speed * dt, 0);
}

void Player2::BoundingCheck(){
	if (character.getPosition().x < P2_LEFT_BOUNDING)
		character.setPosition(P2_LEFT_BOUNDING, 0);
	if (character.getPosition().x > P2_RIGTH_BOUNDING)
		character.setPosition(P2_RIGTH_BOUNDING, 0);
}
