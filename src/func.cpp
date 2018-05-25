#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "func.h"

bool InBounds(int num, int matches)
{
	return (1 <= num) && (num <= 10) && ((matches - num) >= 0);
}

char *IntToString(int n)
{
	int k, mid;
	char *string, ch;
	unsigned int len = 1;

	string = (char *)malloc(sizeof(char));

	if (n)
	{
		while (n != 0)
		{
			k = n % 10;

			string[len - 1] = (char)k + 48;

			++len;
			string = (char *)realloc(string, len * sizeof(char));

			n /= 10;
		}
	}
	else
	{
		string = (char *)realloc(string, 2 * sizeof(char));
		string[0] = '0';
		len = 2;
	}

	mid = len / 2;

	for (int i = 0; i < mid; ++i)
	{
		ch = string[i];
		string[i] = string[len - i - 2];
		string[len - i - 2] = ch;
	}

	string[len - 1] = '\0';

	return string;
}

void SinglePlay(RenderWindow *window, Sprite sp, Font font)
{
	gamer st[1];
	int matches = 100, x = 1, a;
	char *num, ch, *was;
	string str;

	Text text("", font, 40), turn("", font, 50), after_h("Try again", font, 40);

	text.setColor(Color::Color(0, 230, 0, 230));
	text.setStyle(Text::Bold);
	turn.setColor(Color::Cyan);
	turn.setStyle(Text::Bold);
	after_h.setColor(Color::Color(0, 230, 0, 230));
	after_h.setStyle(Text::Bold);

}

void RecordData(gamer *st, RenderWindow *window, Sprite sp, Font font, int mod)
{
	string str = "", ms;
	ms = "\n\n\t\t  Enter nickname of gamer #1:";
	int num = 0;

	Text name("", font, 45), text("", font, 40);
	text.setColor(Color::Color(0, 230, 0, 230));
	text.setStyle(Text::Bold);
	name.setColor(Color::Cyan);
	name.setStyle(Text::Bold);

	if (mod == 1) { text.setString("\n\n\t\t\t\tEnter your nickname:"); }
	else text.setString(ms);

	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window->close();
			}

			if (event.type == Event::TextEntered)
			{
				if (event.text.unicode < 128)
				{
					str += static_cast<char>(event.text.unicode);
					name.setString(str);
				}
			}
		}

		window->clear();

		window->draw(sp);

		window->draw(text);

		name.setPosition(230, 150);
		window->draw(name);

		window->display();
	}
}