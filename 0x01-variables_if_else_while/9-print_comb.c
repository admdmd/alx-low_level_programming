#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int number;
	char alphebet;

	for (number = 0; number < 10; number++)
		putchar(number + '0');

	for (alphebet = 'a'; alphebet <= 'f'; alphebet++)
		putchar(alphebet);
	putchar('\n');

	return (0);
}

