#include "DeltaTime.h"

DeltaTime* DeltaTime::Instance = NULL;

DeltaTime::DeltaTime(){
	deltaTime = 0;
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
	return deltaTime;
}


DeltaTime::~DeltaTime(){
	delete Instance;
}
