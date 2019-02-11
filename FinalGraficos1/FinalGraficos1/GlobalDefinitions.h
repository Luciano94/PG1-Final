#ifndef GLOBALDEFINITIONS_H
#define GLOBALDEFINITIONS_H
#include <iostream>
using namespace std;

namespace Constants {
	//Menu Options
	enum MenuOptions {
		Play = 0,
		HowTo,
		Credits,
		Exit,
		Counts,
	};
	//Game States
	enum GameStates {
		Menu = 0,
		HowToMenu,
		CreditsMenu,
		Gameplay,
		P1WinScreen,
		P2WinScreen,
		Count,
	};
	/*WINDOW*/
	const int W_WIDTH = 1200;
	const int W_HEIGHT = 600;
	const string W_TITTLE = "Death Race";
	//win 1
	const int W1_XL = 0;
	const int W1_XR = 599;
	//win 2
	const int W2_XL = 600;
	const int W2_XR = 1200;
	/*INTERFACE*/
	const int MENU_WIDTH = 1200;
	const int MENU_HEIGHT = 600;
	//Menu
	const string MENU_IMG = "../Assets/Images/Menu.png";
	//HowToMenu
	const string HOW_TO_IMG = "../Assets/Images/HowToPlay.png";
	//credits
	const string CREDITS_IMG = "../Assets/Images/Credits.png";
	//options menu
	const int OPT_X = 500;
	const int OPT_Y = 300;
	//Tittle
	const int TITTLE_X = 400;
	const int TITTLE_Y = 100;
	const int TITTLE_SIZE = 62;
	//Screen Division
	const int DIV_WIDTH = 1;
	const int DIV_HEIGHT = 600;
	const int DIV_SPAWN_X = 599;
	const int DIV_SPAWN_Y = 0;
	//UI
	const int FONT_SIZE = 24;
	const string KM_FONT = "../Assets/Fonts/FSEX300.ttf";
	const float KM_W1_X = 60;
	const float KM_W2_X = 660;
	//Enviroment
	const string ENV_LEFT = "../Assets/Sprites/Env.png";
	const string ENV_RIGTH = "../Assets/Sprites/Env2.png";
	//Enviroment W1
	const int SW1R_WIDTH = 60;
	const int SW1R_HEIGHT = 600;
	const int SW1R_SPAWN_X = 539;
	const int SW1R_SPAWN_Y = 0;
	const int SW1L_WIDTH = 60;
	const int SW1L_HEIGHT = 600;
	const int SW1L_SPAWN_X = 0;
	const int SW1L_SPAWN_Y = 0;
	//Enviroment W2
	const int SW2R_WIDTH = 60;
	const int SW2R_HEIGHT = 600;
	const int SW2R_SPAWN_X = 1140;
	const int SW2R_SPAWN_Y = 0;
	const int SW2L_WIDTH = 60;
	const int SW2L_HEIGHT = 600;
	const int SW2L_SPAWN_X = 601;
	const int SW2L_SPAWN_Y = 0;
	/*OBSTACLE*/
	const int O_SPEED_MIN = 300;
	const int O_SPEED_MAX = 400;
	const int O_WIDTH = 50;
	const int O_HEIGHT = 50;
	const int O_RESPAWNTIME = 5;
	const string O_TEXTURE = "../Assets/Sprites/Enemy.png";
	/*BOOST*/
	const int B_WIDTH = 60;
	const int B_HEIGHT = 60;
	const int B_SPEEDMIN = 200;
	const int B_SPEEDMAX = 250;
	const int B_MINTIME = 10;
	const int B_MAXTIME = 30;
	const int B_SPAWNX1 = 200;
	const int B_SPAWNX2 = 200;
	const int B_PLUS_SPEED = 100;
	const string B_TEXTURE = "../Assets/Sprites/PowerUp.png";
	/*PLAYER*/
	const int P_WIDTH = 60;
	const int P_HEIGHT = 60;
	const float P_SPEED = 500;
	//player 1
	const int P1_SPAWN_X = 270;
	const int P1_SPAWN_Y = 60;
	const int P1_LEFT_BOUNDING = 60;
	const int P1_RIGTH_BOUNDING = 480;
	const string P1_TEXTURE = "../Assets/Sprites/Player1.png";
	//player 2
	const int P2_SPAWN_X = 870;
	const int P2_SPAWN_Y = 60;
	const int P2_LEFT_BOUNDING = 660;
	const int P2_RIGTH_BOUNDING = 1080;
	const string P2_TEXTURE = "../Assets/Sprites/Player2.png";
}

#endif // !GLOBALDEFINITIONS_H

