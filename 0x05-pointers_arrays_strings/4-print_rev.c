#include "main.h"
#include<string.h>
/**
 * print_rev - print a string in reverse followed by a newline
 * @s: string
 */
void print_rev(char *s)
{
	int i, l;

	l = strlen(s);

	for (i = l - 1; i >= 0; i--)
		_putchar(*s);

	_putchar('\n');
}
