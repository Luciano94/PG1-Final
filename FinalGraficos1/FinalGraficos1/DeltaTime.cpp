#include "DeltaTime.h"

DeltaTime* DeltaTime::Instance = NULL;

DeltaTime::DeltaTime(){
	deltaTime = 0;
	pause = false;
}

DeltaTime * DeltaTime::GetInstance(){
	if (Instance == NULL) {
		Instance = new DeltaTime();
	}
	return Instance;
}

void DeltaTime::Update(){
	deltaTime = deltaclock.getElapsedTime().asSeconds();
	deltaclock.restart();
}

float DeltaTime::Get(){
	if (pause) return 0.0f;
	else return deltaTime;
}

void DeltaTime::PauseGame(){
	pause = !pause;
}


DeltaTime::~DeltaTime(){
	delete Instance;
}
