#include <iostream>

#include "func.h"

using namespace std;

int main()
{
	RenderWindow window(VideoMode(800, 450), "100 matches");
	string str;
	char ch;

	Font font;
	font.loadFromFile("Things/11776.otf");

	Text text("", font, 35), mod("", font, 50);

	text.setColor(Color::Color(0, 230, 0, 230));
	text.setStyle(Text::Bold);

	mod.setColor(Color::Cyan);
	mod.setStyle(Text::Bold);

	return 0;
}
