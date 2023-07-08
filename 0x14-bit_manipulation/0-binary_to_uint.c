#include "main.h"

/**
 * binary_to_uint - converts binary number to integer
 * @b: binary.
 *
 * Return: unsigned int.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int teg;
	int count, base;

	if (!b)
		return (0);

	teg = 0;

	for (count = 0; b[count] != '\0'; count++)
		;

	for (count--, base = 1; count >= 0; count--, base *= 2)
	{
		if (b[count] != '0' && b[count] != '1')
		{
			return (0);
		}

		if (b[count] & 1)
		{
			teg += base;
		}
	}

	return (teg);
}
