#include "main.h"

/**
 * get_endianness - checks the skewness
 *
 * Return: 0 if endianess is big ,and 1 if little endianess
 */
int get_endianness(void)
{
	unsigned int i;
	char *c;

	i = 1;
	c = (char *) &i;

	return ((int)*c);
}
