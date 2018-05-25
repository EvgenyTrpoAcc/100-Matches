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

			if (event.type == Event::TextEntered)
			{
				if (event.text.unicode == '1' || event.text.unicode == '2')
				{
					str += static_cast<char>(event.text.unicode);
					mod.setString(str);
					ch = event.text.unicode;
					str = "";
				}
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Return && (ch == '1'))
				{
					
				}
				else if (event.key.code == Keyboard::Return && (ch == '2'))
				{
					
				}
			}
		}

		window.clear();

		window.draw(sp_sprite);

		text.setString("MOD: ");
		text.setPosition(303, 210.5);
		window.draw(text);

		mod.setPosition(403, 195);
		window.draw(mod);

		text.setString("\t\t100 Matches\n\nChoose mode [1 or 2]\n1 - Single Play\n2 - Cooperative Play");
		text.setPosition(220, 0);
		window.draw(text);

		window.display();
	}

	return 0;
}
