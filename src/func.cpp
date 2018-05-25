#include <iostream>

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
