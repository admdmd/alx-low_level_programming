#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char alphebet;

	for (alphebet = 'z'; alphebet >= 'a'; alphebet--)
		putchar(alphebet);
	putchar('\n');

	return (0);
}
