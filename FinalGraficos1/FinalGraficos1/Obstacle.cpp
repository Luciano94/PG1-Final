#include "Obstacle.h"



Obstacle::Obstacle(string texturePath, int screen): screen(screen){
	speed = O_SPEED;
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

void Obstacle::Init(){
	srand(time(0));
	int x;
	if (screen == 1)
		x = rand() % (W1_XR - O_WIDTH) + W1_XL;
	else 
		x = rand() % (W2_XR - O_WIDTH) + W2_XL;
	
	cout << "X: " << x << " Y: " << W_HEIGHT + O_HEIGHT << endl;
	obs.setPosition(x, W_HEIGHT-O_HEIGHT);
}

void Obstacle::Draw(sf::RenderWindow & win){
	win.draw(obs);
}
