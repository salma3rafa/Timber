#ifndef ANIMATE_H
#define ANIMATE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;



class Animate :public Sprite, private Texture
{
public:
	Animate() {};
	Animate(string aTextureFile, string aSoundFile, float aPositionX, float aPositionY);
	void setActive(bool aActive);
	bool getActive();
	void setSpeed(float aSpeed);
	void move(float aSeconds);
	void setDirection(int aDirection);
	void play(bool aLoop);
	void waitIfPlaying();
	void stop();
	int getDirection();
	float getSpeed();
	Sprite getSprite();
private:
	Sound m_Sound;
	SoundBuffer m_SoundBuffer;
	bool m_bSoundLoaded{ false };
	bool m_bActive{ false };
	float m_fSpeed{ 0.0f };
	int m_iDirection{ 1 };
};
#endif // !ANIMATE_H


