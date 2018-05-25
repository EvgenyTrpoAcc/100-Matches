#include <iostream>

#include "func.h"

bool InBounds(int num, int matches)
{
	return (1 <= num) && (num <= 10) && ((matches - num) >= 0);
}
