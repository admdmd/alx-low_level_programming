#include "main.h"
/**
 * Print_alphabet - Write a function that prints the alphabet, in lower case
 *
 * Return: Always 0.
 */
void print_alphabet(void);
{
	char alphabet = 'a';

	while (alphabet <= 'z')
	{
		_putchar(alphabet);
		alphabet++;
	}
	_putchar('\n');
}
