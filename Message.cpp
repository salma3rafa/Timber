#include "Message.h"
#include<iostream>
using namespace std;
Message::Message(string aFontFile, unsigned int aSize, float aPositionX, float aPositionY, string aString)
{
	loadFromFile(aFontFile);

	setFont(*this);
	setString(aString);
	setCharacterSize(aSize);
	setFillColor(Color::White);
	setPosition(aPositionX, aPositionY);
}