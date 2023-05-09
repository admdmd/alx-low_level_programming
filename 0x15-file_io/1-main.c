#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code .
 *
 * @ac: Argumetns counter
 * @av: Arguments array
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	int res;
	char *content = "Best School !";

	if (ac < 2)
	{
		printf("Usage: %s filename [content]\n", av[0]);
		return (1);
	}
	res = create_file(av[1], av[2] ? av[2] : content);
	printf("%i\n", res);
	return (0);
}
