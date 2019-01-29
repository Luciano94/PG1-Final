#include "ObstacleS1.h"



ObstacleS1::ObstacleS1(string texturePath):Obstacle(texturePath){
	Init();
}


ObstacleS1::~ObstacleS1(){
}

void ObstacleS1::Init(){
	srand(time(0));
	int x = rand() % (W1_XR - O_WIDTH) + W1_XL;
	obs.setPosition(x, W_HEIGHT - O_HEIGHT);
}
