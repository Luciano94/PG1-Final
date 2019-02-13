#include "SoundManager.h"

SoundManager * SoundManager::instance = NULL;

SoundManager::SoundManager(){
	selectBuffer.loadFromFile(S_SELECT);
	selectSound.setBuffer(selectBuffer);
	selectSound.setVolume(50);
	selectSound.setLoop(false);

	enterBuffer.loadFromFile(S_ENTER);
	enterSound.setBuffer(enterBuffer);
	enterSound.setLoop(false);
	enterSound.setVolume(50);

	explosionBuffer.loadFromFile(S_EXPLOSION);
	explosionSound.setBuffer(explosionBuffer);
	explosionSound.setLoop(false);
	explosionSound.setVolume(50);

	pwUpBuffer.loadFromFile(S_POWERUP);
	pwUpSound.setBuffer(pwUpBuffer);
	pwUpSound.setLoop(false);
	pwUpSound.setVolume(50);

	gameplayMusic.openFromFile(M_GAMEPLAY);
	gameplayMusic.setLoop(true);
	gameplayMusic.setVolume(50);

	menuMusic.openFromFile(M_MENU);
	menuMusic.setLoop(true);
	menuMusic.setVolume(50);
}

SoundManager * SoundManager::GetInstance(){
	if (instance == NULL) {
		instance = new SoundManager();
	}
	return instance;
}

void SoundManager::PlayMenuMusic(){
	if (gameplayMusic.getStatus() == gameplayMusic.Playing) 
		gameplayMusic.stop();
	if(menuMusic.getStatus()!=menuMusic.Playing) 
		menuMusic.play();
}

void SoundManager::PlayGameplayMusic(){
	if (menuMusic.getStatus() == menuMusic.Playing) 
		menuMusic.stop();
	if(gameplayMusic.getStatus() != gameplayMusic.Playing)
		gameplayMusic.play();
}

void SoundManager::PlaySelectSound(){
	if (selectSound.getStatus() != selectSound.Playing)
		selectSound.play();
}

void SoundManager::PlayExplosionSound(){
	if (explosionSound.getStatus() != explosionSound.Playing)
		explosionSound.play();
}

void SoundManager::PlayPowerUpSound(){
	if(pwUpSound.getStatus() != pwUpSound.Playing)
		pwUpSound.play();
}

void SoundManager::PlayEnterSound(){
	if(enterSound.getStatus() != enterSound.Playing)
		enterSound.play();
}

void SoundManager::StopAllMusic(){
	if (menuMusic.getStatus() == menuMusic.Playing)
		menuMusic.stop();
	if (gameplayMusic.getStatus() == gameplayMusic.Playing)
		gameplayMusic.stop();
}

SoundManager::~SoundManager()
{
}
