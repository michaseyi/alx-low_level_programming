#include "main.h"

/**
 * jack_bauer - Entry point
 * Description : prints out all minutes in a day
 * Return: (void)
 */

void jack_bauer(void)
{
	int a, b, c, d, i;

	a = 0;
	b = 0;
	c = 0;
	d = 0;
	for (i = 0; i < 1440; i++)
	{
		_putchar(a + '0');
		_putchar(b + '0');
		_putchar(':');
		_putchar(c + '0');
		_putchar(d + '0');
		_putchar('\n');
		if (d == 9) 
		{
			d = 0;
			if (c == 5)
			{
				c = 0;
				if (b == 9)
				{
					b = 0;
					a++;
				} else
				{
					b++;
				}
			} else 
			{
				c++
			}
		} else 
		{
			d++;
		}
	}
}

