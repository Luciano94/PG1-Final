#include "Player1.h"



Player1::Player1(string texturePath) :Player(texturePath) {
	character.setPosition(sf::Vector2f(P1_SPAWN_X, P1_SPAWN_Y));
}

void Player1::Update(float dt) {
	Input(dt);
	BoundingCheck();
}

void Player1::Input(float dt){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		character.move(speed * dt,0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		character.move(-speed * dt, 0);
}

void Player1::BoundingCheck(){
	if (character.getPosition().x < P1_LEFT_BOUNDING)
		character.setPosition(P1_LEFT_BOUNDING,W_HEIGHT - P_HEIGHT);
	if (character.getPosition().x > P1_RIGTH_BOUNDING)
		character.setPosition(P1_RIGTH_BOUNDING, W_HEIGHT - P_HEIGHT);
}

Player1::~Player1()
{
}
