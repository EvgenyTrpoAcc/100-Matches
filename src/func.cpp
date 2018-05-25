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

	text.setColor(Color(0, 230, 0, 230));
	text.setStyle(Text::Bold);
	turn.setColor(Color::Cyan);
	turn.setStyle(Text::Bold);
	after_h.setColor(Color(0, 230, 0, 230));
	after_h.setStyle(Text::Bold);

	RecordData(st, window, sp, font, 1);

	num = IntToString(matches);
	was = IntToString(matches);

	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				free(was);
				free(num);
				window->close();
			}

			if (event.type == Event::TextEntered)
			{
				if (event.text.unicode < 128)
				{
					str += static_cast<char>(event.text.unicode);
					turn.setString(str);
					ch = event.text.unicode;
				}
			}

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::BackSpace)
				{
					str.clear();
					turn.setString(str);
				}

				if (event.key.code == Keyboard::Escape)
				{
					free(num);
					return;
				}

				if (event.key.code == Keyboard::Return && (x == 1) && (ch == 'y'))
				{
					st[0].status = true;
					--x;
					str.clear();
					turn.setString(str);
				}

				if (event.key.code == Keyboard::Return && (x == 1) && (ch == 'n'))
				{
					st[0].status = false;
					--x;
					str.clear();
					turn.setString(str);
				}

				if (event.key.code == Keyboard::Return && (st[0].status == true)) // Õîä ÷åëîâåêà
				{
					a = atoi(str.c_str());

					if (InBounds(a, matches))
					{
						matches -= a;
						st[0].status = false;
						free(num);
						free(was);
						num = IntToString(matches);
						was = IntToString(matches);
					}

					str.clear();
				}
			}
		}

		window->clear();

		window->draw(sp);

		if (x == 1) // Choice: to turn first or second
		{
			text.setString("\n\nDo you want to turn first ? [y or n]");
			text.setPosition(55, 0);
			window->draw(text);

			turn.setString(ch);
			turn.setPosition(350, 120);
			window->draw(turn);
		}

		if ((st[0].status == true) && (matches != 0))
		{
			text.setString("Turn of ");
			text.setPosition(260, 140);
			window->draw(text);

			text.setString(st[0].name);
			text.setPosition(395, 140);
			window->draw(text);

			turn.setString(str);
			turn.setPosition(342.5, 185);
			window->draw(turn);
		}

		text.setString("Matches:");
		text.setPosition(280, 0);
		window->draw(text);
		text.setString(num);
		text.setPosition(470, 0);
		window->draw(text);

		text.setString("After human:");
		text.setPosition(240, 40);
		window->draw(text);
		after_h.setString(was);
		after_h.setPosition(510, 40);
		window->draw(after_h);

		////
		//ii turn
		////

		if ((matches == 0) && (st[0].status == true))
		{
			text.setString("!!! YOU WIN !!!");
			text.setPosition(210, 160);
			window->draw(text);
		}
		else if ((matches == 0) && (st[0].status == false))
		{
			text.setString("...YOU LOSE...");
			text.setPosition(210, 160);
			window->draw(text);
		}

		window->display();
	}
}

void RecordData(gamer *st, RenderWindow *window, Sprite sp, Font font, int mod)
{
	string str = "", ms;
	ms = "\n\n\t\t  Enter nickname of gamer #1:";
	int num = 0;

	Text name("", font, 45), text("", font, 40);
	text.setColor(Color(0, 230, 0, 230));
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

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::BackSpace)
				{
					str.clear();
					name.setString(str);
				}
			}

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Return)
				{
					str.clear();
					st[num].name = name.getString();
					++num;
					if (num == 1)
					{
						(ms[ms.length() - 2] = '2');
						text.setString(ms);
					}

					if (num == mod) { return; }
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

int II_Turn(int matches)
{
	int ost;
	int a;

	if (matches == 100)
	{
		srand(time(NULL));
		a = rand() % 10 + 1;
		matches -= a;
	}
	else if (((matches % 11) == 0) && (matches > 10))
	{
		matches -= 10;
	}
	else if (matches == 12)
	{
		matches -= 10;
	}
	else if (matches == 1)
	{
		—matches;
	}
	else if ((matches < 100) && (((matches % 11) - 1) != matches))
	{
		ost = (matches % 11) - 1;
		matches -= ost;
	}
	else
	{
		a = matches - 1;
		matches -= a;
}

return matches;
}
}
