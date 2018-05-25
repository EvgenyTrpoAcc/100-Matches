#ifndef _FUNC_H_
#define _FUNC_H_

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

struct gamer
{
    bool status;
    string name;
};

bool InBounds(int num, int matches);

char *IntToString(int n);

void SinglePlay(RenderWindow *window, Sprite sp, Font font);

void RecordData(gamer *st, RenderWindow *window, Sprite sp, Font font, int mod);

int II_Turn(int matches);

#endif
