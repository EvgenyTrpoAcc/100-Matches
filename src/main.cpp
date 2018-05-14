#include <iostream>

#include "func.h"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 450), "100 matches");
	string str;
	char ch;

	Font font;
	font.loadFromFile("Things/11776.otf");

	Text text("", font, 35), mod("", font, 50);

	text.setColor(Color(0, 230, 0, 230));
	text.setStyle(Text::Bold);

	mod.setColor(Color::Cyan);
	mod.setStyle(Text::Bold);

	Image sp;
	sp.loadFromFile("Things/sp.jpg");

	Texture sp_texture;
	sp_texture.loadFromImage(sp);

	Sprite sp_sprite;
	sp_sprite.setTexture(sp_texture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		window.clear();

		window.draw(sp_sprite);

		window.display();
	}

	return 0;
}