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

void SinglePlay(RenderWindow *window, Sprite sp, Font font);

#endif
