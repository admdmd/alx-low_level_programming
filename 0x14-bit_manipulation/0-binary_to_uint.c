#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - converts binary no to unsigned int
 * @b: binary code
 *
 * Return: corresponding unsigned int
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int x = 0;
	int y;

	if (b == NULL)
		return (0);
	for (y = 0; b[y]; y++)
	{
		if (b[y] < '0' || b[y] > '1')
			return (0);
		x = 2 * x + (b[y] - '0');
	}
	return (x);
}
