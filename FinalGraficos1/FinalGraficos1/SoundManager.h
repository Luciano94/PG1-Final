#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <SFML/Audio.hpp>
#include "GlobalDefinitions.h"

using namespace Constants;

class SoundManager{
private:
	//sounds	
	sf::SoundBuffer selectBuffer;
	sf::Sound selectSound;

	sf::SoundBuffer explosionBuffer;
	sf::Sound explosionSound;

	sf::SoundBuffer enterBuffer;
	sf::Sound enterSound;

	sf::SoundBuffer pwUpBuffer;
	sf::Sound pwUpSound;
	
	//music
	sf::Music menuMusic;
	sf::Music gameplayMusic;

	SoundManager();
	static SoundManager * instance;
public:
	static SoundManager * GetInstance();
	void PlayMenuMusic();
	void PlayGameplayMusic();
	void PlaySelectSound();
	void PlayExplosionSound();
	void PlayPowerUpSound();
	void PlayEnterSound();
	void StopAllMusic();
	~SoundManager();
};

#endif // !SOUNDMANAGER_H
