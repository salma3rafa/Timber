#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Message :public Text, private Font
{
public:
	Message() {};
	Message(string aFontFile, unsigned int aSize, float aPositionX, float aPositionY, string aString);
};
#endif // !MESSAGE_H
