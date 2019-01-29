#include "Obstacle.h"



Obstacle::Obstacle(string texturePath):speed(O_SPEED){
	texture = new sf::Texture();
	texture->loadFromFile(texturePath);
	obs.setSize(sf::Vector2f(O_WIDTH, O_HEIGHT));
	obs.setTexture(texture);
}


Obstacle::~Obstacle(){
	delete texture;
}

void Obstacle::Update(float dt){
	obs.move(0,-speed * dt);
}

void Obstacle::Draw(sf::RenderWindow & win){
	win.draw(obs);
}
