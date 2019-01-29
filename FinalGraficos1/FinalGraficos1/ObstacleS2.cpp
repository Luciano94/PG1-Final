#include "ObstacleS2.h"



ObstacleS2::ObstacleS2(string textrurePath):Obstacle(textrurePath){
	Init();
}


ObstacleS2::~ObstacleS2(){
}

void ObstacleS2::Init(){
	srand(time(0));
	int x = rand() % (W2_XR - O_WIDTH) + W2_XL;
	obs.setPosition(x, W_HEIGHT - O_HEIGHT);
}
