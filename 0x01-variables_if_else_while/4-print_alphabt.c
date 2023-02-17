#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
char alphebet;


for (alphebet = 'a'; alphebet <= 'z'; alphebet++)
if (alphebet != 'q' && alphebet != 'e')
putchar(alphebet);
putchar('\n');

return (0);
}

