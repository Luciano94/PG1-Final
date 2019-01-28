#include "DeltaTime.h"

DeltaTime* DeltaTime::Instance = nullptr;

DeltaTime::DeltaTime(){
	deltaTime = 0;
}

DeltaTime * DeltaTime::GetInstance(){
	if (Instance == nullptr) {
		Instance = new DeltaTime();
	}
	return Instance;
}

void DeltaTime::Update(){
	deltaTime = deltaclock.getElapsedTime().asSeconds();
	deltaclock.restart();
}

double DeltaTime::Get(){
	return deltaTime;
}


DeltaTime::~DeltaTime(){
	delete Instance;
}
