#ifndef GLOBALDEFINITIONS_H
#define GLOBALDEFINITIONS_H

using namespace std;

namespace Constants {
	/*WINDOW*/
	const int W_WIDTH = 1200;
	const int W_HEIGHT = 600;
	const string W_TITTLE = "";
	//win 1
	const int W1_XL = 0;
	const int W1_XR = 599;
	//win 2
	const int W2_XL = 600;
	const int W2_XR = 1200;
	/*INTERFACE*/
	const int DIV_WIDTH = 1;
	const int DIV_HEIGHT = 600;
	const int DIV_SPAWN_X = 599;
	const int DIV_SPAWN_Y = 0;
	/*OBSTACLE*/
	const int O_SPEED = 20;
	const int O_WIDTH = 60;
	const int O_HEIGHT = 60;
	const string O_TEXTURE = "../Assets/Sprites/Player.png";
	/*PLAYER*/
	const int P_WIDTH = 60;
	const int P_HEIGHT = 60;
	const float P_SPEED = 300;
	//player 1
	const int P1_SPAWN_X = 270;
	const int P1_SPAWN_Y = 0;
	const int P1_LEFT_BOUNDING = 0;
	const int P1_RIGTH_BOUNDING = 540;
	const string P1_TEXTURE = "../Assets/Sprites/Player.png";
	//player 2
	const int P2_SPAWN_X = 870;
	const int P2_SPAWN_Y = 0;
	const int P2_LEFT_BOUNDING = 600;
	const int P2_RIGTH_BOUNDING = 1140;
	const string P2_TEXTURE = "../Assets/Sprites/Player.png";
}

#endif // !GLOBALDEFINITIONS_H

